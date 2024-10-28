#!/usr/bin/python3
"""
Associate handler functions with opcodes
and provide suggestions on how to interpret the code
"""
import logging
from IPython.display import display, Markdown
import opcodes

def get_immediate_args(operand: str):
    """
    Parse an immediate operand like 'a4, 0x10',
    returning ('a4', 16)
    """
    logging.basicConfig(level=logging.DEBUG)
    logger = logging
    args = operand.split(',')
    if len(args) != 2:
        logger.error(f"Too few arguments in {operand}")
        return None
    (reg, raw_value) = args
    if raw_value.startswith('0x'):
        value = int(raw_value[2:], 16)
    else:
        value = int(raw_value)
    return (reg, value)

class Report():
    """
    Collects items inferred from a listing.
    Each item should be in Markdown format
    """

    def __init__(self):
        self.items = []
    def add(self, item):
        """
        Add a new markdown fragment to the report
        """
        self.items.append(item)

    def render(self):
        """
        Render the report as text or formatted via IPython if active
        """
        if 'Markdown' in globals():
            print(display(Markdown('\n'.join(self.items))))
        else:
            print('\n'.join(self.items))

class OpcodeHandler():
    """
    Collect analytic callbacks associated with key RISCV-64 instruction opcodes
    """
    def __init__(self, parser):
        logger = logging.getLogger('OpcodeHandler')
        if not logger.hasHandlers():
            handler = logging.StreamHandler()
            formatter = logging.Formatter('%(levelname)-8s [%(filename)s:%(lineno)d] %(message)s')
            handler.setFormatter(formatter)
            logger.addHandler(handler)
        logger.setLevel(logging.WARNING)
        self.logger = logger
        self.parser = parser
        self.dispatch = {}
        self.context = {}
        self.local_addresses = []
        self.local_labels = []
        self.significant_opcodes = []
        self.base_opcode_signature = None
        self.sorted_opcode_signature = None
        self.report = Report()
        self.register('li', self.load_immediate_handler)
        self.register('vsetvli', self.vset_handler)
        self.register('vsetivli', self.vseti_handler)
        for op in ('vle8.v', 'vle16.v', 'vle32.v', 'vle64.v',
                   'vluxei8.v', 'vluxei16.v', 'vluxei32.v', 'vluxei64.v',
                   'vloxei8.v', 'vloxei16.v', 'vloxei32.v', 'vloxei64.v',
                   'vl1r.v', 'vl1re8.v', 'vl1re16.v', 'vl1re32.v', 'vl1re64.v',
                   'vl2r.v', 'vl2re8.v', 'vl2re16.v', 'vl2re32.v', 'vl2re64.v',
                   'vl4r.v', 'vl4re8.v', 'vl4re16.v', 'vl4re32.v', 'vl4re64.v',
                   'vl8r.v', 'vl8re8.v', 'vl8re16.v', 'vl8re32.v', 'vl8re64.v'):
            self.register(op, self.vload_handler)
        for op in ('vse8.v', 'vse16.v', 'vse32.v', 'vse64.v',
                   'vsuxei8.v', 'vsuxei16.v', 'vsuxei32.v', 'vsuxei64.v',
                   'vsoxei8.v', 'vsoxei16.v', 'vsoxei32.v', 'vsoxei64.v',
                   'vs1r.v', 'vs2r.v', 'vs4r.v', 'vs8r.v'):
            self.register(op, self.vstore_handler)
        self.register('vid.v', self.vid_handler)
        self.register('vid.vm', self.vid_handler)
        for op in opcodes.CONDITIONAL_BRANCH_OPCODES:
            self.register(op, self.conditional_branch_handler)
        for op in ('vmv1r.v', 'vmv2r.v', 'vmv4r.v', 'vmv8r.v',
                   'vfmv.s.f', 'vfmv.f.s'):
            self.register(op, self.vmv_handler)
        for op in ('vredsum.vs', 'vredmaxu.vs', 'vredmax.vs',
                     'vredminu.vs', 'vredmin.vs', 'vredand.vs',
                     'vredor.vs', 'vredxor.vs',
                     'vwredsumu.vs', 'vwredsum.vs',
                     'vfredosum.vs', 'vfredusum.vs', 'vfredmax.vs', 'vfredmin.vs',
                     'vfwredosum.vs', 'vfwredusum.vs'):
            self.register(op, self.v_reduction_handler)
        for op in ('vslideup.vx', 'vslideup.vi',
                   'vslidedown.vx', 'vslidedown.vi',
                   'vslide1up.vx', 'vslide1down.vx',
                   'vfslide1up.vf', 'vfslide1down.vf'):
            self.register(op, self.v_slide_handler)
        for op in ('vrgather.vv', 'vrgatherei16.vv'):
            self.register(op, self.v_gather_handler)

    def add_label(self, label):
        """
        Ghidra branches reference labels, not addresses
        """
        self.logger.info("Adding a new local label %s", label)
        self.local_labels.append(label)

    def register(self, instr, callback):
        """
        Add a handler to an instruction
        """
        if instr not in self.dispatch:
            self.logger.debug(f"register {callback} for instruction {instr}")
            self.dispatch[instr] = [callback,]
        else:
            self.logger.debug(f"Add the callback {callback} to the " +
                              f"existing registration for {instr}")
            self.dispatch[instr].append(callback)

    def invoke(self, addr, instr, operand):
        """
        Invoke all handlers defined for a given instruction op
        """
        self.local_addresses.append(addr)
        if instr in opcodes.VECTOR_OPCODES:
            self.significant_opcodes.append(instr)
        if instr in self.dispatch:
            for d in self.dispatch[instr]:
                d(addr, instr, operand)

    def load_immediate_handler(self, addr, instr, operand):
        """
        Handle load immediate instructions
        """
        self.logger.debug(f"Handling a load immediate instruction {addr}\t{instr}\t{operand}")

    def conditional_branch_handler(self, addr, instr, operand):
        """
        Handle conditional branch instructions
        """
        self.logger.debug(f"Handling a branch instruction {addr}\t{instr}\t{operand}")
        branch_target = self.parser.get_local_branch_target(operand)
        self.logger.debug("Looking for the branch target %s", branch_target)
        if branch_target in self.local_labels or branch_target in self.local_addresses:
            self.significant_opcodes.append(instr)
            self.logger.debug("Adding a loop detection to the context report")
            self.context['has_loop'] = True

    def vset_handler(self, _addr, _instr, operand):
        """
        Handle vsetvli instructions
        """
        args = operand.split(',')
        length_reg = args[1]
        if length_reg in self.context:
            self.report.add(f"* Vector length is likely = {self.context[length_reg]}")
        sew_str = args[2]
        if sew_str in ('e8', 'e16', 'e32', 'e64'):
            sew = int(sew_str[1:])
            self.context['SEW'] = sew
            self.report.add(f"* Element width is = {sew_str[1:]} bits")
        mul = args[3][1:]
        if mul in ('2', '4', '8'):
            self.context['MUL'] = int(mul)
            self.report.add(f"* Vector registers are grouped with MUL = {mul}")
        elif mul in ('f2', 'f4', 'f8'):
            self.context['MUL'] = 1.0/int(mul[1])
            self.report.add(f"    * Vector multiplier is fractional, MUL = {mul}")
        else:
            if 'MUL' in self.context:
                del self.context['MUL']

    def vseti_handler(self, _addr, _instr, operand):
        """
        Handle vsetivli instructions
        """
        args = operand.split(',')
        length = args[1]
        self.report.add(f"* Vector length set to = {length}")
        sew_str = args[2]
        if sew_str in ('e8', 'e16', 'e32', 'e64'):
            sew = int(sew_str[1:])
            self.context['SEW'] = sew
            self.report.add(f"* Element width is = {sew_str[1:]} bits")
        mul = args[3][1:]
        if mul in ('2', '4', '8'):
            self.context['MUL'] = int(mul)
            self.report.add(f"* Vector registers are grouped with MUL = {mul}")
        elif mul in ('f2', 'f4', 'f8'):
            self.context['MUL'] = 1.0/int(mul[1])
            self.report.add(f"    * Vector multiplier is fractional, MUL = {mul}")
        else:
            if 'MUL' in self.context:
                del self.context['MUL']

    def get_element_size(self, instr, prefix, suffix):
        """
        extract the element size in bits from instruction opcodes
        """
        start = len(prefix)
        end = len(suffix)
        return int(instr[start:-end])

    def vload_handler(self, _addr, instr, _operand):
        """
        Vector load instructions
        """
        if 'MUL' in self.context:
            lmul = self.context['MUL']
        else:
            lmul = 1
        sew = self.context['SEW']
        if instr in ('vle8.v', 'vle16.v', 'vle32.v', 'vle64.v'):
            self.report.add(f"* Vector load: {instr}")
            ew = self.get_element_size(instr, 'vle', '.v')
            emul = (ew/sew)*lmul
            if emul > 1:
                self.report.add("    * Vector load is to multiple registers")
        elif instr in ('vluxei8.v', 'vluxei16.v', 'vluxei32.v', 'vluxei64.v'):
            self.report.add(f"* Vector unordered indexed load: {instr}")
            ew = self.get_element_size(instr, 'vluxei', '.v')
            emul = (ew/sew)*lmul
            if emul > 1:
                self.report.add("    * Vector indexed load is to multiple registers")
        elif instr in ('vloxei8.v', 'vloxei16.v', 'vloxei32.v', 'vloxei64.v'):
            self.report.add(f"* Vector ordered indexed load: {instr}")
            ew = self.get_element_size(instr, 'vloxei', '.v')
            emul = (ew/sew)*lmul
            if emul > 1:
                self.report.add("    * Vector indexed load is to multiple registers")
        elif instr in ('vl1r.v', 'vl1re8.v', 'vl1re16.v', 'vl1re32.v', 'vl1re64.v'):
            self.report.add(f"* Vector whole register load: {instr}")
        elif instr in ('vl2r.v', 'vl2re8.v', 'vl2re16.v', 'vl2re32.v', 'vl2re64.v',
                       'vl4r.v', 'vl4re8.v', 'vl4re16.v', 'vl4re32.v', 'vl4re64.v',
                       'vl8r.v', 'vl8re8.v', 'vl8re16.v', 'vl8re32.v', 'vl8re64.v'):
            self.report.add(f"* Vector multiple whole register load: {instr}")

    def vstore_handler(self, _addr, instr, _operand):
        """
        Vector store instructions
        """
        if 'MUL' in self.context:
            lmul = self.context['MUL']
        else:
            lmul = 1
        sew = self.context['SEW']
        if instr in ('vse8.v', 'vse16.v', 'vse32.v', 'vse64.v'):
            self.report.add(f"* Vector store: {instr}")
            ew = self.get_element_size(instr, 'vse', '.v')
            emul = (ew/sew)*lmul
            if emul > 1:
                self.report.add("    * Vector store is from multiple registers")
        elif instr in ('vsuxei8.v', 'vsuxei16.v', 'vsuxei32.v', 'vsuxei64.v'):
            self.report.add(f"* Vector unordered indexed store: {instr}")
            ew = self.get_element_size(instr, 'vsuxei', '.v')
            emul = (ew/sew)*lmul
            if emul > 1:
                self.report.add("    * Vector indexed store is from multiple registers")
        elif instr in ('vsoxei8.v', 'vsoxei16.v', 'vsoxei32.v', 'vsoxei64.v'):
            self.report.add(f"* Vector ordered indexed store: {instr}")
            ew = self.get_element_size(instr, 'vsoxei', '.v')
            emul = (ew/sew)*lmul
            if emul > 1:
                self.report.add("    * Vector indexed store is from multiple registers")
        elif instr in ('vs1r.v', 'vs2r.v', 'vs4r.v', 'vs8r.v'):
            self.report.add(f"* Vector whole register(s) store: {instr}")
            self.report.add("    * Warning: these instructions ignore vset and must be used " +
                            " in contexts aware of vlen.")

    def vid_handler(self, _addr, instr, _operand):
        """
        Vector Element Index Instruction
        """
        if instr in ('vid.v', 'vid.vm'):
            self.report.add(f"* Vector element index: {instr}")
            self.report.add("    * often used in generating a vector of offsets for indexing")

    def vmv_handler(self, _addr, instr, _operand):
        """
        Vector move or copy instruction
        """
        if instr in ('vmv1r.v', 'vmv2r.v', 'vmv4r.v', 'vmv8r.v'):
            mul = instr[3]
            self.report.add(f"* Vector register move/copy: {instr}")
            if mul != '1':
                self.report.add("    * Multiple vector registers are moved")
            return
        if instr == 'vfmv.s.f':
            self.report.add("* FP register to vector register element 0")
            return
        if instr == 'vfmv.f.s':
            self.report.add("* Vector register element 0 to FP register")

    def v_reduction_handler(self, _addr, instr, _operand):
        """
        Vector reduction
        """
        if instr in ('vredsum.vs', 'vredmaxu.vs', 'vredmax.vs',
                     'vredminu.vs', 'vredmin.vs', 'vredand.vs',
                     'vredor.vs', 'vredxor.vs'):
            self.report.add(f"* Vector integer reduction: {instr}")
            return
        if instr in ('vwredsumu.vs', 'vwredsum.vs'):
            self.report.add(f"* Vector integer widening reduction: {instr}")
            return
        if instr in ('vfredosum.vs', 'vfredusum.vs', 'vfredmax.vs', 'vfredmin.vs'):
            self.report.add(f"* Vector floating point reduction: {instr}")
            return
        if instr in ('vfwredosum.vs', 'vfwredusum.vs'):
            self.report.add(f"* Vector widening floating point reduction: {instr}")

    def v_slide_handler(self, _addr, instr, _operand):
        """
        The slide instructions move elements up and down a vector register group
        """
        if instr in ('vslideup.vx', 'vslideup.vi'):
            self.report.add(f"* Vector integer slideup: {instr}")
            return
        if instr in ('vslidedown.vx', 'vslidedown.vi'):
            self.report.add(f"* Vector integer slidedown: {instr}")
            return
        if instr in ('vslide1up.vx'):
            self.report.add(f"* Vector integer slide1up: {instr}")
            return
        if instr in ('vslide1down.vx'):
            self.report.add(f"* Vector integer slide1down: {instr}")
            return
        if instr in ('vfslide1up.vf', 'vfslide1down.vf'):
            self.report.add(f"* Vector floating point slide: {instr}")
 
    def v_gather_handler(self, _addr, instr, _operand):
        """
        The vector register gather instructions read elements from a
        first source vector register group at locations given by a
        second source vector register group. 
        """
        if instr in ('vrgather.vv', 'vrgatherei16.vv'):
            self.report.add(f"* Vector gather: {instr}")


    def summary_report(self):
        """
        Generate a report 
        """
        report = []
        self.base_opcode_signature = ','.join(self.significant_opcodes)
        report.append(f"* Significant opcodes, in the order they appear:\n    * {self.base_opcode_signature}")
        tmp = self.significant_opcodes
        tmp.sort()
        self.sorted_opcode_signature = ','.join(tmp)
        report.append(f"* Significant opcodes, in alphanumeric order:\n    * {self.sorted_opcode_signature}")
        if 'has_loop' in self.context:
            report.append("* At least one loop exists")
        return report
