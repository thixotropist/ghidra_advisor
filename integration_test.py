#!/usr/bin/python3
"""
Verify that the toolchain frameworks are functional
"""
import unittest
import subprocess
import logging
import re
from cpputils import CppFile
from bazel import Bazel
from toolchain import Toolchain
from target import InternalRepo, Package
from analytics import Analysis
from instr_parse import InstrParser, DisassemblyMode
from advisor import Advisor

logging.basicConfig(level=logging.INFO)
logger = logging

class T0BazelEnvironment(unittest.TestCase):
    """
    Verify the Bazel crosscompiler framework and dependencies are present
    """
    @classmethod
    def setUpClass(cls):
        """
        Initialize a toolchain test environment
        """
        cls.bazel = Bazel()
        # fully linked executables end up here
        cls.binDir = 'bazel-bin'
        # object files (*.o) end up here
        cls.objDir = f'{cls.binDir}/_objs'

    def test_01_local_helloworld(self):
        """
        A local host toolchain (x86_64) build of helloworld.  Assumes we have gcc installed
        locally, so we are mostly exercising a minimal Bazel environment without crosscompiler
        toolchains
        """
        result = self.bazel.execute(Toolchain.LOCAL_HOST_PLATFORM, Toolchain.REFERENCE_C_PGM,
                                    operation='build', mode='dbg')
        self.assertEqual(0, result.returncode,
            f'bazel {Toolchain.LOCAL_HOST_PLATFORM} build of {Toolchain.REFERENCE_C_PGM} failed')

    def test_02_verify_platforms(self):
        """
        Search Bazel workspace for the key platform riscv_gcc.  The term 'platform'
        generally refers to a specific product environment.
        """
        result = self.bazel.query("//platforms:*")

        self.assertRegex(result.stdout, r'riscv_gcc',
                         "riscv64 default user space platform is defined")

    def test_03_verify_toolchains(self):
        """
        Search Bazel workspace for key toolchain riscv64-gcc.  The term 'toolchain'
        refers to the compiler suite, a sysroot of /usr/include and linker files, a base
        microarchitecture, and other compiler defaults
        """
        result = self.bazel.query("//toolchains:riscv64-gcc")

        self.assertRegex(result.stdout, r'riscv64\-gcc',
                         "riscv64 default gcc toolchain is defined")

    def test_03_verify_subprojects(self):
        """
        Verify the existence of subprojects to this workspace.
        .
        """

        result = self.bazel.query("@gcc_riscv_suite//:bin/riscv64-unknown-linux-gnu-gcc")
        self.assertRegex(result.stdout, r'riscv64\-unknown\-linux\-gnu\-gcc',
                         "riscv64 gcc compiler suite is loaded")

        result = self.bazel.query("kind('cc_library rule', //gcc_riscv_testsuite/rvv/autovec/reduc:*)")
        self.assertRegex(result.stdout, r'reduc-1_rv64gcv',
                         "gcc compiler riscv testsuite is loaded")

    def test_05_riscv64_build(self):
        """
        riscV64 C build of helloworld, with checks to see if a compatible toolchain was
        invoked.  This test assumes that the local host version of `file` can
        recognize riscv-64 object files.
        """
        platform = Toolchain.DEFAULT_RISCV64_PLATFORM
        result = self.bazel.execute(platform, Toolchain.REFERENCE_C_PGM,
                                    operation='build', mode='opt')
        self.assertEqual(0, result.returncode,
            f'bazel {platform} build of {Toolchain.REFERENCE_C_PGM} failed')

        executable_file = f'{self.binDir}/test/helloworld'
        logger.info(f"Running: file {executable_file}")
        result = subprocess.run(['file', executable_file],
            check=True, capture_output=True, encoding='utf8')
        self.assertRegex(result.stdout, 'ELF 64-bit LSB executable, UCB RISC-V',
            f'//platforms:{platform} compilation generated an unexpected executable file format')

    def test_04_riscv64_cpp_build(self):
        """
        riscV64 C++ build of helloworld++, with checks to see if a compatible toolchain was
        invoked
        """
        platform = Toolchain.DEFAULT_RISCV64_PLATFORM
        result = self.bazel.execute(platform, Toolchain.REFERENCE_CPP_PGM,
                                    operation='build', mode='opt')
        self.assertEqual(0, result.returncode,
            f'bazel {platform} build of {Toolchain.REFERENCE_C_PGM} failed')

        executable_file = f'{self.binDir}/test/helloworld++'
        logger.info(f"Running: file {executable_file}")
        result = subprocess.run(['file', executable_file],
            check=True, capture_output=True, encoding='utf8')
        self.assertRegex(result.stdout, 'ELF 64-bit LSB executable, UCB RISC-V',
            f'//platforms:{platform} compilation generated an unexpected executable file format')

class T1TestTargets(unittest.TestCase):
    """
    Verify target.py functions
    """
    def test_01_all(self):
        """
        Libraries are built in (*.a, *.so) pairs with (*.i, *.s) temporaries.
        We want the (*.so) libraries for objdump, and the (*.i) temporaries.
        The easiest way to do this is to build the base target and then the regular target
        """
        repo = InternalRepo("gcc_riscv_testsuite")
        package = Package("rvv/autovec/reduc", repo)
        libs = package.find_libraries()
        self.assertGreater(len(libs), 0,
                           "Failed to find any shared libraries within " + package.bazel_name)
        libs = package.find_base_libraries()
        self.assertGreater(len(libs), 0,
                           "Failed to find any base libraries within " + package.bazel_name)

class T2ImportTestSuites(unittest.TestCase):
    """
    generate training materials from the GCC riscv vector reduction test suite
    """
    @classmethod
    def setUpClass(cls):
        """
        Initialize a toolchain test environment
        """
        cls.bazel = Bazel()
        # fully linked executables end up here
        cls.binDir = 'bazel-bin'
        # object files (*.o) end up here
        cls.objDir = f'{cls.binDir}/_objs'

    def test_01_vector_generation(self):
        """
        Build vector library and obdjump exemplars, then verify vector instructions were generated
        """
        platform = Toolchain.DEFAULT_RISCV64_PLATFORM
        for target in (
            '//gcc_riscv_testsuite/rvv/autovec/reduc:reduc-1_rv64gcv',
            '//gcc_riscv_testsuite/rvv/autovec/reduc:reduc-1_rv64gcv_objdump_generator'):
            result = self.bazel.execute(platform, target, copt="-march=rv64gcv",
                                    operation='build', mode='opt')
            self.assertEqual(0, result.returncode,
                f'bazel {platform} build of{target} failed')
        result = subprocess.run(['readelf', '-A',
                                 'bazel-bin/gcc_riscv_testsuite/rvv/autovec/reduc/libreduc-1_rv64gcv.so'],
            check=True, capture_output=True, encoding='utf8')
        self.assertRegex(result.stdout, r'Tag_RISCV_arch:.*_v1p0',
                         "Bazel build did not respect march")
        result = subprocess.run(['grep', 'vsetvli',
                                 'bazel-bin/gcc_riscv_testsuite/rvv/autovec/reduc/reduc-1_rv64gcv_objdump'],
            check=True, capture_output=True, encoding='utf8')
        self.assertGreater(len(result.stdout), 1000,
                           "Not enough vsetvli instructions found in reference target's objdump")

    def test_02_nonvector_generation(self):
        """
        Build non-vector library and obdjump exemplars, then verify vector instructions were *not* generated
        """
        platform = Toolchain.DEFAULT_RISCV64_PLATFORM
        for target in (
            '//gcc_riscv_testsuite/rvv/autovec/reduc:reduc-1_rv64gc',
            '//gcc_riscv_testsuite/rvv/autovec/reduc:reduc-1_rv64gc_objdump_generator'):
            result = self.bazel.execute(platform, target, copt="-march=rv64gc",
                                    operation='build', mode='opt')
            self.assertEqual(0, result.returncode,
                f'bazel {platform} build of {target} failed')
        result = subprocess.run(['readelf', '-A',
                                 'bazel-bin/gcc_riscv_testsuite/rvv/autovec/reduc/libreduc-1_rv64gc.so'],
            check=True, capture_output=True, encoding='utf8')
        self.assertNotRegex(result.stdout, r'Tag_RISCV_arch:.*_v1p0',
                         "Bazel build did not respect march")
        result = subprocess.run(['grep', 'vsetvli',
                                 'bazel-bin/gcc_riscv_testsuite/rvv/autovec/reduc/reduc-1_rv64gc_objdump'],
            check=False, capture_output=True, encoding='utf8')
        self.assertEqual(len(result.stdout), 0,
                           "Found vsetvli instructions in  anon-vector reference target's objdump")

    def test_03_cppfile_file_ingest(self):
        """
        verify function extraction from various cpp outputs
        """

        cases = (
            ('reduc-1_rv64gcv.i', 57),
            ('strcmp_rv64gcv.i', 1),
            ('scalable-1_rv64gcv.i',1)
        )
        for file, count in cases:
            case = CppFile(f"data_test/{file}")
            self.assertEqual(len(case.functions), count,
                            f"Not enough functions recognized in data_test/{file}")

    def test_05_cppfile_get_function_signature(self):
        """
        Extracting the function signature can be a pain, since we aren't using
        a full C parser to resolve function names and type names
        """
        test_cases = (
            ('long unsigned int __strlen(const char *s)',
                ('long unsigned int',
                '__strlen',
                '(const char *s)'),
            ),
            ('void __attribute__((noinline, noclone)) reduc_plus_int16_t (int16_t (*restrict a)[(1024 / sizeof (int16_t))], int16_t *restrict r, int n)',
                ('void',
                'reduc_plus_int16_t',
                '(int16_t *a[64], int16_t *restrict r, int n)'
                )
            )
        )
        for case in test_cases:
            line = case[0]
            (ret_type, name, params) = case[1]
            item = CppFile.get_function_signature(line)
            self.assertEqual(item[1], name,
                             'Failed to extract the function name from ' + line)
            self.assertEqual(item[2], params,
                             'Failed to extract the parameter list from ' + line)
            self.assertEqual(item[0], ret_type,
                             'Failed to extract the return type from ' + line)

    def test_05_cppfile_function_search(self):
        """
        Read the output of the C preprocessor to verify function signatures
        """
        case = CppFile("data_test/string_rv64gcv.i")
        simple_return = case.functions['__strlen']
        self.assertEqual(simple_return.splitlines()[0], 'long unsigned int __strlen(const char *s)',
                         'Failed to find the function signature for __strlen')
        composite_return = case.functions['__strcpy']
        self.assertEqual(composite_return.splitlines()[0], 'char * __strcpy(char *restrict d, const char *restrict s)',
                         'Failed to find the function signature for __strcpy')


class T3Signatures(unittest.TestCase):
    """
    Generate signatures from both objdump and Ghidra disassembly listings
    """

    def test_02_objdump_inst_parsing(self):
        """
        The regexes used for objdump parsing need a lot of testing.
        """
        branch_3_inst = ' 1184: fed762e3 bltu a4,a3,1168 <reduc_plus_int8_t+0x18>'
        m = re.search(InstrParser.OBJDUMP_INST_PAT,branch_3_inst)
        self.assertIsNotNone(m, 'Bad regex for matching an objdump branch instruction')

    def test_101_ghidra_loop_detection(self):
        """
        Loop detection depends on local backwards branches
        """
        forward_branch = """
        000a9524 57 78 08 0c     vsetvli  a6,a6,e8,m1,ta,ma  
        000a9528 63 5b a7 06     bge      a4,a0,LAB_000a959e
        """
        loop_branch = """
                             LAB_000a9546              XREF[1]: 000a9594(j)  
        000a9546 57 70 08 0c     vsetvli  zero,a6,e8,m1,ta,ma  
        000a9594 e3 49 65 fa     blt      a0,t1,LAB_000a9546
        """
        analyzer = Analysis(forward_branch, DisassemblyMode.GHIDRA)
        sigs = analyzer.get_signature('Opcodes, sorted')
        self.assertNotIn('_loop', sigs,
                        "The absence of loops should be identified")
        analyzer = Analysis(loop_branch, DisassemblyMode.GHIDRA)
        sigs = analyzer.get_signature('Opcodes, sorted')
        self.assertIn('_loop', sigs,
                        "Loops should be identified")

    def test_102_objdump_analysis(self):
        """
        Loop detection depends on local backwards branches
        """
        forward_branch = """
    1150:       04b05a63  blez    a1,11a4 <reduc_plus_int8_t+0x54>
        """
        loop_branch = """
    1168:       86ae     mv      a3,a1
    1184:       fed762e3 bltu    a4,a3,1168 <reduc_plus_int8_t+0x18>
        """
        analyzer = Analysis(forward_branch, DisassemblyMode.OBJDUMP)
        sigs = analyzer.get_signature('Opcodes, sorted')
        self.assertNotIn('_loop', sigs,
                        "Forward branches should not be considered loops")

        analyzer = Analysis(loop_branch, DisassemblyMode.OBJDUMP)
        sigs = analyzer.get_signature('Opcodes, sorted')
        self.assertIn('_loop', sigs,
                        "Loops should be identified")

    def test_110_ghidra(self):
        """
        Collect signatures from the Ghidra listing of a whisper.cpp function
        """
        with open('data_test/signature_tests/ghidra_sample.s', 'r', encoding='utf8') as f:
            disassembly = f.read()
        ghidra_analyzer = Analysis(disassembly, DisassemblyMode.GHIDRA)
        ghidra_analyzer.opcode_handler.summary_report()
        opcodes_sorted = ghidra_analyzer.opcode_handler.sorted_opcode_signature
        opcodes_ordered = ghidra_analyzer.opcode_handler.base_opcode_signature
        self.assertEqual(opcodes_sorted, '_loop,vle8.v,vle8.v,vmv.v.i,vmv.x.s,vsetivli,vsetvli,' +
                         'vsetvli,vsetvli,vsetvli,vwmul.vv,vwredsum.vs',
                         'Found incorrect opcodes_sorted signature extracted from Ghidra test')
        self.assertEqual(opcodes_ordered, 'vsetvli,vsetvli,vmv.v.i,vsetvli,vle8.v,vle8.v,' +
                         'vwmul.vv,vsetvli,vwredsum.vs,vsetivli,vmv.x.s,_loop',
                         'Found incorrect opcodes_ordered signature extracted from Ghidra test')

    def test_120_objdump(self):
        """
        Collect signatures from the objdump listing of a real function
        """
        with open('data_test/signature_tests/objdump_sample.s', 'r', encoding='utf8') as f:
            disassembly = f.read()
        objdump_analyzer = Analysis(disassembly, DisassemblyMode.OBJDUMP)
        objdump_analyzer.opcode_handler.summary_report()
        opcodes_sorted = objdump_analyzer.opcode_handler.sorted_opcode_signature
        opcodes_ordered = objdump_analyzer.opcode_handler.base_opcode_signature
        self.assertEqual(opcodes_sorted, '_loop,vadd.vv,vle8.v,vmv.s.x,vmv.v.i,vmv.x.s' +
                         ',vredsum.vs,vsetvli,vsetvli,vsetvli,vslide1up.vx',
                         'Found incorrect opcodes_sorted signature extracted from objdump test')
        self.assertEqual(opcodes_ordered, 'vsetvli,vmv.v.i,vslide1up.vx,vsetvli,vle8.v,' +
                         'vadd.vv,vsetvli,vmv.s.x,vredsum.vs,vmv.x.s,_loop',
                         'Found incorrect opcodes_ordered signature extracted from objdump test')

class T4Advisor(unittest.TestCase):
    """
    Exercise the Advisor class
    """
    def test_01_loop(self):
        """
        Generate a report, no tests
        """
        with open("data_test/advisor_tests/loop1.ghidra", "r", encoding="utf8") as f:
            sample = f.read()
        advisor = Advisor(sample)
        print('\n'.join(advisor.report))

if __name__ == '__main__':

    unittest.main()
