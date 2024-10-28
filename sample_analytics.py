#!/usr/bin/python3
"""
Analyze a pattern database
"""
import sqlite3
import logging
from analytics import Analysis, DisassemblyMode

logging.basicConfig(level=logging.INFO)
logger = logging

con = sqlite3.connect("Samples.db")
cur = con.cursor()

# create a table linking samples with vector instruction sequences
cur.execute("DROP TABLE IF EXISTS signatures")
cur.execute("CREATE TABLE signatures(id INTEGER PRIMARY KEY AUTOINCREMENT, " +
            "sample_id INTEGER, signature_type TEXT, signature_value TEXT)")

# select all samples where machine arch contains 'rv64gcv'
cur.execute("SELECT id,assembly FROM sample WHERE arch like '%rv64gcv%'")
CHUNK_SIZE = 100
SAMPLE_COUNT = 0
signatures = []
while True:
    samples = cur.fetchmany(CHUNK_SIZE)
    if not samples:
        break
    # collect the list of vector ops found in the sample's assembly code
    for sample in samples:
        SAMPLE_COUNT += 1
        opcode_sequence = []
        sample_id = sample[0]
        assembly = sample[1]
        logger.debug(f"analyzing id={sample_id}, assembly=\n{assembly}")
        analysis = Analysis(assembly, mode=DisassemblyMode.DATABASE)
        sigs = analysis.get_signatures()
        for sig in sigs.items():
            signatures.append((sample_id, sig[0], sig[1]))

logger.debug(f"Generated signatures: {signatures}")
for op in signatures:
    logger.debug(f"Attempting to insert {op}")
    cur.execute("INSERT INTO signatures (sample_id, signature_type, signature_value) VALUES (?, ?, ?)",
                    op)
con.commit()

print(f"Number of rv64gcv samples found: {SAMPLE_COUNT}")
