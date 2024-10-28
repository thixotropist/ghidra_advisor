"""
Collect assembly listing parsing code.  We need to handle objdump,
Ghidra, and database formats of assembly listings
"""
import sys
import re
import logging
from enum import Enum

class DisassemblyMode(Enum):
    """
    Objdump and ghidra generate somewhat different listing formats.
    The database uses a simplified, converged third format.
    This enumeration class helps identify the format.
    """
    OBJDUMP = 1
    GHIDRA = 2
    DATABASE = 3

class InstrParser():
    """
    Collect regexes needed to parse RISCV assembly instruction listings
    """

    HEX_REGEX = r'[0-9a-f]{8,16}'
    OBJDUMP_ADDR_REGEX = r'[0-9a-f]{2,8}'
    OBJDUMP_OPCODE_BYTES_REGEX = r'[a-f0-9]{4,8}'
    OBJDUMP_INST_PAT = re.compile(fr'({OBJDUMP_ADDR_REGEX}):\s+{OBJDUMP_OPCODE_BYTES_REGEX}\s+([a-z0-9\.]+)\s+(\S+)')
    OBJDUMP_BRANCH_3ARG_PAT = re.compile(fr'\S+,\S+,({OBJDUMP_ADDR_REGEX})')
    OBJDUMP_BRANCH_2ARG_PAT = re.compile(fr'\S+,({OBJDUMP_ADDR_REGEX})')
    GHIDRA_OPCODE_BYTES_REGEX = r'(?:[0-9a-f]{2} [0-9a-f]{2} ){1,2}'
    GHIDRA_ADDR_REGEX = r'[0-9a-f]{6,8}'
    GHIDRA_INST_PAT = re.compile(fr'\s+({GHIDRA_ADDR_REGEX})\s{GHIDRA_OPCODE_BYTES_REGEX}\s+([a-z0-9\.]+)\s+(\S+)')
    GHIDRA_BRANCH_3ARG_PAT = re.compile(fr'\S+,\S+,(LAB_{HEX_REGEX})')
    GHIDRA_BRANCH_2ARG_PAT = re.compile(fr'\S+,(LAB_{HEX_REGEX})')
    GHIDRA_LABEL_PAT = re.compile(fr'^\s*(LAB_{HEX_REGEX})\s+')
    DATABASE_INST_PAT = re.compile(fr'({OBJDUMP_ADDR_REGEX})\s+([a-z0-9\.]+)\s+(\S+)')

    def __init__(self, mode):
        logger = logging.getLogger('InstrParser')
        if not logger.hasHandlers():
            handler = logging.StreamHandler()
            formatter = logging.Formatter('%(levelname)-8s [%(filename)s:%(lineno)d] %(message)s')
            handler.setFormatter(formatter)
            logger.addHandler(handler)
        logger.setLevel(logging.WARNING)
        self.logger = logger
        self.mode = mode
        if mode == DisassemblyMode.OBJDUMP:
            self.logger.info("Configuring for objdump disassembly")
            self.inst_pat = self.OBJDUMP_INST_PAT
        elif mode == DisassemblyMode.GHIDRA:
            self.logger.info("Configuring for Ghidra disassembly")
            self.inst_pat = self.GHIDRA_INST_PAT
            self.label_pat = self.GHIDRA_LABEL_PAT
        elif mode == DisassemblyMode.DATABASE:
            self.inst_pat = self.DATABASE_INST_PAT
        else:
            self.logger.error("Unrecognized format mode found - abort")
            sys.exit()

    def get_local_branch_target(self, operand):
        """
        Extract the target of a branch instruction.  This may be either a Ghidra label
        or a hex address
        """
        if self.mode == DisassemblyMode.GHIDRA:
            m = re.search(self.GHIDRA_BRANCH_3ARG_PAT, operand)
            if m:
                branch_target = m.group(1)
                return branch_target
            m = re.search(self.GHIDRA_BRANCH_2ARG_PAT, operand)
            if m:
                branch_target = m.group(1)
                return branch_target
        elif self.mode in (DisassemblyMode.OBJDUMP, DisassemblyMode.DATABASE):
            m = re.search(self.OBJDUMP_BRANCH_3ARG_PAT, operand)
            if m:
                branch_target = m.group(1)
                return branch_target
            m = re.search(self.OBJDUMP_BRANCH_2ARG_PAT, operand)
            if m:
                branch_target = m.group(1)
                return branch_target
        self.logger.error("Unrecognized format mode found - abort")
        sys.exit()
