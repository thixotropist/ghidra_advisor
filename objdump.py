#!/usr/bin/python3
"""
extract assembly code from an objdump invocation
"""
import re
import logging
from instr_parse import InstrParser

class Objdump():
    """
    Read the output of the objdump utility to identify functions within.
    """
    FUNCTION_PAT = re.compile(r"^[0-9a-f]+\s\<(\w+)\>:")
    INSTR_PAT = InstrParser.OBJDUMP_INST_PAT

    def __init__(self, file_name):
        """
        Process a single preprocessed C file to build a dictionary
        of function names and assembly instructions.
        """
        logger = logging.getLogger('Objdump')
        if not logger.hasHandlers():
            handler = logging.StreamHandler()
            formatter = logging.Formatter('%(levelname)-8s [%(filename)s:%(lineno)d] %(message)s')
            handler.setFormatter(formatter)
            logger.addHandler(handler)
        logger.setLevel(logging.WARNING)

        with open(file_name, encoding="utf-8") as infile:
            logger.info("Opened %s", file_name)
            line = infile.readline()
            fun_name = None
            fun_body = []
            self.functions = {}
            while line:
                line.rstrip()
                logger.debug("Examining %s", line)
                # search for the start of functions
                match_fun = re.search(Objdump.FUNCTION_PAT, line)
                if match_fun:
                    fun_name = match_fun.group(1)
                    logger.debug("Found the function %s", fun_name)
                    line = infile.readline()
                    within_function = True
                    while within_function:
                        if not line:
                            # end of file
                            logger.debug("End of this function")
                            self.functions[fun_name] = "\n".join(fun_body)
                            infile.close()
                            return
                        # blank lines mark the end of a function
                        if line == "\n":
                            logger.debug("End of this function")
                            self.functions[fun_name] = "\n".join(fun_body)
                            fun_body = []
                            line = infile.readline()
                            within_function = False
                            continue
                        logger.debug("Looking for opcodes in %s", line)
                        match_line = re.search(Objdump.INSTR_PAT, line)
                        if match_line:
                            addr = match_line.group(1)
                            opcode = match_line.group(2)
                            instr = match_line.group(3)
                            logger.debug("Adding an opcode: %s", match_line.group(1))
                            fun_body.append(f"{addr}\t{opcode}\t{instr}")
                        else:
                            logger.debug("Not adding %s", line)
                        line = infile.readline()
                else:
                    line = infile.readline()

if __name__ == '__main__':
    scanner = Objdump('data_test/librvv_reduc-1_rv64gc.objdump')
    for (k,v) in scanner.functions.items():
        print(k + ':')
        for l in v.splitlines():
            print("\t" + l)
