#!/usr/bin/python3
"""
Ingest reference C ffunctions and their compiled assembly code
into a pattern database
"""

import logging
import os
import re
import argparse
from sample import Sample
from objdump import Objdump
from elfutils import ElfFile
from cpputils import CppFile

logging.basicConfig(level=logging.INFO)
logger = logging
DATA_DIR = "./data"

LIB_FILE_NAME_PATTERN = re.compile(r"(.+)_(rv64[^\.]+)\.so")

def ingest_dir(basedir, files):
    """
    Ingest all lib*.so files within this directory
    """
    for f in files:
        logger.debug("Found a file: " + f)
        m = re.match(LIB_FILE_NAME_PATTERN, f)
        if m:
            libpath = f"{basedir}/{f}"
            # base_name example:  'reduc-8'
            base_name = m.group(1)
            arch = m.group(2)
            libsource = f"{base_name}_{arch}.i"
            libdump = f"{base_name}_{arch}_objdump"
            logger.debug("Found a library file: " + f)
            namespace = f"{basedir}/{base_name}"

            # extract global function names from this library
            lib_file = ElfFile(libpath)
            # Create samples for all functions found within
            for fun in lib_file.function_names:
                Sample(namespace, arch, fun)
            # open the corresponding preprocessed C file to get the function bodies
            if not os.path.exists(f"{basedir}/{libsource}"):
                logger.error('Unable to locate ' + f"{basedir}/{libsource}")
            else:
                source = CppFile(f"{basedir}/{libsource}")
                for (fun_name, source) in source.functions.items():
                    logger.debug(f"searching for Sample({namespace}, {arch}, {fun_name})")
                    s = Sample.find(namespace, arch, fun_name)
                    if s:
                        logger.debug(f"updating the source for Sample({namespace}," +
                                      f" {arch}, {fun_name})")
                        s.set_source(source)
                    else:
                        logger.warning(f"Unable to locate Sample({namespace}," +
                                         f" {arch}, {fun_name})")
            # open the corresponding objdump file
            if not os.path.exists(f"{basedir}/{libdump}"):
                logger.error('Unable to locate ' + f"{basedir}/{libdump}")
            else:
                objdump = Objdump(f"{basedir}/{libdump}")
                for (fun_name, fun_impl) in objdump.functions.items():
                    s = Sample.find(namespace, arch, fun_name)
                    if s:
                        s.set_assembly(fun_impl)

parser = argparse.ArgumentParser(
                    prog='Ingest',
                    description='Process contents of a sample data directory into the Sample database')

EXCLUDE_DIRS = ('.git',)
for (dirpath, dirnames, filenames) in os.walk('data', topdown=True):
    dirnames[:] = [d for d in dirnames if d not in EXCLUDE_DIRS]
    ingest_dir(dirpath, filenames)

# Search through the data directory for any library files,
# extracting the global function names found within.
# This forms the reference set of functions.

# For each extracted assembly block, extract some features like number of vset opcode variants

# Show what we have generated
Sample.display_all()

# Check for anomalies to be fixed
Sample.check_all()

# Build the database
Sample.build_database()
