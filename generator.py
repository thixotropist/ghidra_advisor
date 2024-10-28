#!/usr/bin/python3
"""
Generate training set for vector extension recognition.

Test packages are imported as libraries from an external repository
adapted from GCC RISCV compiler test suite.  For each package we
build sharable object libraries for each of several machine architectures.
These sharable object libraries are processed through objdump to get
the assembly code components of training sets.

We pair that assembly code with the C code that generated it.  We need
all macros expanded, requiring some obscure Bazel build options to save
compilation temporaries like foo.i and foo.s

Bazel's treatment of external repositories can vary from release to release,
making some of the path definitions a bit fragile.

"""

import logging
import os
import sys
import subprocess
import shutil
import re
from bazel import Bazel
from toolchain import Toolchain
import target

logging.basicConfig(level=logging.WARNING,
                format='%(levelname)-8s [%(filename)s:%(lineno)d] %(message)s')
logger = logging

PLATFORM = Toolchain.DEFAULT_RISCV64_PLATFORM

bazel = Bazel()

# the global name Bazel needs to find test suite source packages
TESTSUITE_REPO = "gcc_riscv_testsuite"

# register the testsuite target packages we will process
test_repo = target.InternalRepo(TESTSUITE_REPO)
top_package = target.Package("rvv/autovec", test_repo)
reduc_package = target.Package("rvv/autovec/reduc", test_repo)
struct_package = target.Package("rvv/autovec/struct", test_repo)
builtin_package = target.Package("rvv/autovec/builtin", test_repo)
gather_scatter_package = target.Package("rvv/autovec/gather-scatter", test_repo)
conversions_package = target.Package("rvv/autovec/conversions", test_repo)
vls_package = target.Package("rvv/autovec/vls-vlmax", test_repo)

# register a custom testsuite where we build samples as we find them

custom_repo = target.InternalRepo("custom_testsuite")
struct_package = target.Package("structs", custom_repo)
builtins_package = target.Package("builtins", custom_repo)
# The DPDK package currently is more distraction than useful elements in a training set.
# GCC makes plenty of obscure optimizations, but very few vector optimizations in
# critical path contexts.
# dpdk_package = target.Package("dpdk", custom_repo)

# fully linked executables end up here
BIN_DIR = 'bazel-bin'

INDENT_FIXUP_PAT_1 = re.compile(r"}} void ")
INDENT_FIXUP_PAT_2 = re.compile(r"} void ")

def indent_cpp_file(filename):
    """
    Normalize the cpp output to make function identification easier.
    Indent sometimes needs some post processing with sed
    """
    _result = subprocess.run(['indent', '-l999', '-npsl', '-bap', '-st',
                            filename],
        check=True, capture_output=True, encoding='utf8')
    if _result.returncode != 0:
        logger.error(f"indentation correction of {filename} failed")
    source = _result.stdout
    # add missing line breaks
    source = re.sub(INDENT_FIXUP_PAT_1, "    }\n}\n\nvoid ", source)
    source = re.sub(INDENT_FIXUP_PAT_2, "}\n\nvoid ", source)
    with open(filename, 'w', encoding='utf8') as outfile:
        outfile.write(source)

logger.debug("Iterating over target packages and libraries")
for p in target.Package.all_packages:
    if not os.path.exists(p.path):
        logger.debug("Creating " + p.path)
        result = subprocess.run(['mkdir', '-p', p.path],
                                check=True, capture_output=False, encoding='utf8')
    logger.debug("Building base libraries to capture temporaries like *.i")
    # base library target names end in _libs and refer to both .so and .a library forms
    for t_name in p.find_base_libraries():
        logger.debug(f"Adding a new target: {t_name}")
        t = target.Target(t_name, p, sharable=False)
        logger.debug("New base library: " + t_name)
        logger.debug("Testing for the existence of " + f"{p.path}/{t_name}.i")
        # remove trailing '_libs' from target name
        target_root = t.target_name[:-5]
        if not os.path.exists(f"{p.path}/{target_root}.i"):
            logger.debug(f"Building {t_name}")

            result = bazel.execute(PLATFORM, f"{t_name}", copt=f"-march={t.march}",
                                    operation='build', mode='opt', save_temps=True)
            if result.returncode != 0:
                logger.error(f"Bazel build of {t_name} failed")
                sys.exit()
            logger.debug("Copying build files into data directory")
            shutil.copyfile(f"{t.build_path()}.i",
                f"{p.path}/{target_root}.i")
            indent_cpp_file(f"{p.path}/{target_root}.i")

    logger.debug("building sharable library targets within " + p.name)
    for t_name in p.find_libraries():
        logger.debug("New target: " + t_name)
        t = target.Target(t_name, p, sharable=True)
        logger.debug("processing " + t_name + ", package = " + t.package.name +
                    ", target = " + t.target_name + ", march = " + t.march)
        logger.debug("Testing for the existence of " + f"{p.path}/{t.target_name}.so")
        if not os.path.exists(f"{p.path}/{t.target_name}.so"):
            logger.debug(f"Building {t.name}")
            result = bazel.execute(PLATFORM, f"{t.name}", copt=f"-march={t.march}",
                                    operation='build', mode='opt', save_temps=False)
            if result.returncode != 0:
                logger.error(f"Bazel build of {target} failed")
                sys.exit()

            shutil.copyfile(f"{BIN_DIR}/{t.package.repo.name}/{t.package.name}/lib{t.target_name}_libs.so",
                            f"{p.path}/{t.target_name}.so")
            logger.debug(f"objdumping {p.path}/{t.target_name}.so")

            # disassemble this sharable object file
            result = bazel.execute(PLATFORM, f"{t.name}_objdump", operation='build',
                                   copt=f"-march={t.march}", mode='opt')
            if result.returncode != 0:
                logger.error(f"Bazel objdump of {t.name} failed")
                sys.exit()
            shutil.copyfile(f"{BIN_DIR}/{t.package.repo.name}/{t.package.name}/{t.target_name}_objdump",
                            f"{p.path}/{t.target_name}_objdump")
