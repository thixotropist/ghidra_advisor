#!/usr/bin/python3
"""
Provide the logic invoked by the Advisor Jupyter lab notebook
"""

import sqlite3
import subprocess
from difflib import SequenceMatcher

from IPython.display import display, Markdown
from analytics import Analysis, DisassemblyMode

ACTIVE_SIGNATURE = 'Opcodes, sorted'
CHUNK_SIZE = 100

def render(text: str):
    """
    Display Markdown text within a Jupyter Lab notebook
    """
    display(Markdown(text))

class Advisor():
    """
    All of the work is performed on initialization
    """
    def __init__(self, source=None):
        if source:
            sample = source
        else:
            # On a wayland system this copies from the clipboard into the sample variable
            result = subprocess.run(['wl-paste',],check=True, capture_output=True, encoding='utf8')
            sample = result.stdout
        clean_sample = [s.strip() for s in sample.splitlines()]
        report = []
        report.append("## Clipboard Contents to Analyze")
        report.append("```text")
        report.append(f"{'\n'.join(clean_sample)}")
        report.append("```")
        analyzer = Analysis(sample, DisassemblyMode.GHIDRA)
        report.extend(analyzer.get_markdown())
        report.append('\n')
        signature = analyzer.get_signature(ACTIVE_SIGNATURE)

        con = sqlite3.connect("Samples.db")
        cur = con.cursor()
        cur.execute("SELECT sample_id, signature_type, signature_value FROM signatures")
        best_match_ratio = -1
        best_match_id = -1
        best_match_vector = None
        while True:
            refs = cur.fetchmany(CHUNK_SIZE)
            if not refs:
                break
            # collect the list of vector ops found in the sample's assembly code
            for ref in refs:
                ref_id = ref[0]
                if ref[1] != ACTIVE_SIGNATURE:
                    continue
                ref_vector = ref[2].split(',')
                ref_vector.sort()
                ref_vector = ','.join(ref_vector)
                if ref_vector != "":
                    ratio = SequenceMatcher(None, signature, ref_vector).ratio()
                    if ratio > best_match_ratio:
                        best_match_ratio = ratio
                        best_match_id = ref_id
                        best_match_vector = ref_vector

        report.append("## Similarity Analysis")
        report.append("\nCompare the clipped example to the database of vectorized examples.\n")
        if best_match_id == -1:
            report.append(">Warning: The best match found using the " +
                          ACTIVE_SIGNATURE +
                          f" signature was only {best_match_ratio:5}")
        else:
            report.append(f"The best match is id={best_match_id} [{best_match_ratio:.3f}]= {best_match_vector}")
            cur_source = con.cursor()
            cur_source.execute(f"select source, assembly, namespace, arch, name from sample where id={best_match_id}")
            (source, assembly, namespace, arch, name) = cur_source.fetchone()
            report.append("\n")
            report.append(f"The clip is similar to the reference example `{namespace}_{arch}:{name}`")
            report.append("### Reference C Source")
            report.append("```")
            report.append(source)
            report.append("```")
            report.append("### Reference Compiled Assembly Code\n```text\n")
            report.append(assembly)
            report.append("```")
            render('\n'.join(report))
        self.report = report

if __name__ == '__main__':
    import argparse
    parser = argparse.ArgumentParser(
                    prog='Ghidra Advisor',
                    description='Examine ghidra assembly listings to help interpretation')
    parser.add_argument('filename')
    args = parser.parse_args()
    with open(args.filename, 'r', encoding='utf8') as f:
        advisor = Advisor(f.read())
        print('\n'.join(advisor.report))
