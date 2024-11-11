
"""
Routines for analyzing vector instruction sequences given a Ghidra disassembly listing fragment
"""
import re
import logging
from opcode_handler import OpcodeHandler
from instr_parse import DisassemblyMode, InstrParser

class Analysis():
    """
    Collect analyses of a snippet of RISC-V vector code
    """
    def __init__(self, disassembly_fragment: str, mode:DisassemblyMode):
        """
        Process the disassembly snippet line by line,
        giving each extractor a look at instructions and labels.

        The assembly code can be raw objdump disassembly output,
        raw Ghidra listing view clips, or the normalized code
        stored in the sqlite3 database
        """
        logger = logging.getLogger('Analysis')
        if not logger.hasHandlers():
            handler = logging.StreamHandler()
            formatter = logging.Formatter('%(levelname)-8s [%(filename)s:%(lineno)d] %(message)s')
            handler.setFormatter(formatter)
            logger.addHandler(handler)
        logger.setLevel(logging.WARNING)
        self.logger = logger
        self.parser = InstrParser(mode)
        self.opcode_handler = OpcodeHandler(self.parser)
        if not disassembly_fragment:
            self.logger.warning('Missing disassembly text!')
            return
        self.logger.debug("Analyzing disassembly fragment %s", disassembly_fragment)
        for l in disassembly_fragment.splitlines():
            self.logger.debug("Matching disassembly line %s", l)
            m = re.search(self.parser.inst_pat, l)
            if m:
                addr = m.group(1)
                inst = m.group(2)
                operand = m.group(3)
                self.logger.debug("Matched instruction %s %s %s", addr, inst, operand)
                self.opcode_handler.invoke(addr, inst, operand)
                continue
            if mode == DisassemblyMode.GHIDRA:
                m = re.search(self.parser.label_pat, l)
                if m:
                    label = m.group(1)
                    self.logger.debug("Found an interior label: %s", m.group(1))
                    self.opcode_handler.add_label(label)
        # finish by adding traits
        if 'has_loop' in self.opcode_handler.context:
            self.opcode_handler.significant_opcodes.append('_loop')

    def display(self):
        """
        Print the results
        """
        print("Signatures:")
        self.opcode_handler.report.render()

    def get_markdown(self):
        """
        Collect results as Markdown text
        """
        result = ["Signatures:",]
        result.extend(self.opcode_handler.report.items)
        result.extend(self.opcode_handler.summary_report())
        return result

    def get_signature(self, name:str):
        """
        return a single signature name and signature
        """
        if name == 'Opcodes, ordered':
            return ','.join(self.opcode_handler.significant_opcodes)
        if name == 'Opcodes, sorted':
            tmp = self.opcode_handler.significant_opcodes
            tmp.sort()
            return ','.join(tmp)
        return None

    def get_signatures(self):
        "Return the collected signatures as a dict"
        sigs = {}
        sigs['Opcodes, ordered'] = self.get_signature('Opcodes, ordered')
        sigs['Opcodes, sorted'] = self.get_signature('Opcodes, sorted')
        return sigs
