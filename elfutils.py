#!/usr/bin/python3
"""
Process ELF files (executable and library)
"""

import subprocess
import logging
import re
from enum import Enum

logging.basicConfig(level=logging.INFO,
                format='%(levelname)-8s [%(filename)s:%(lineno)d] %(message)s')
logger = logging

class ElfFile():
    """
    Scan an ELF file for global symbols using objdump.  Don't use readelf because it
    silently truncates longer symbols
    """

    function_pattern = re.compile(r'[0-9a-f]{16} \w\s+F\s+\.text\s+[0-9a-f]{16}\s+(\S+)')

    IGNORE_SYMS = (
        '.hidden',
        '_start',
        'register_tm_clones',
        'deregister_tm_clones',
        'frame_dummy',
        '__do_global_dtors_aux',
    )

    def __init__(self, file_name):
        self.function_names = []
        logger.debug(f"Initializing an ElfFile from {file_name}")
        result = subprocess.run(['objdump', '-tw', file_name],
                check=True, capture_output=True, encoding='utf8')
        if result.returncode != 0:
            logger.error(f"Failed to extract symbols from {file_name}")
        for line in result.stdout.splitlines():
            _m = re.search(self.function_pattern, line)
            if _m and _m.group(1) not in ElfFile.IGNORE_SYMS and not \
                _m.group(1).startswith('__'):
                self.function_names.append(_m.group(1))
        logger.info(f"Found {len(self.function_names)} functions")
