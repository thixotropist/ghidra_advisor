#!/usr/bin/python
"""
Collect samples pairing C source and generated assembly
"""
import sqlite3
class Sample():
    """
    A training set element pairing source code with machine architecture and disassembly
    """
    all_samples = []
    def __init__(self, name_space, arch, name):
        self.arch = arch
        self.name_space = name_space
        self.name = name
        self.source = None
        self.assembly = None
        self.metadata = {}
        Sample.all_samples.append(self)

    @classmethod
    def find(cls, name_space, arch, name):
        """
        Locate an existing sample with matching name and name_space
        """
        for s in Sample.all_samples:
            if s.name == name and s.name_space == name_space and s.arch == arch:
                return s
        return None

    @classmethod
    def display_all(cls):
        """
        Display all current samples
        """
        print(f"Total samples = {len(Sample.all_samples)}")
        for s in Sample.all_samples:
            s.display()

    def set_source(self, source):
        """
        set the C source code
        """
        self.source = source

    def set_assembly(self, assembly):
        """
        Set the objdump'd disassembly for this sample
        """
        self.assembly = assembly

    @classmethod
    def check_all(cls):
        """
        Look for incomplete samples
        """
        print("Sample:check_all")
        source_missing = []
        assembly_missing = []
        for s in Sample.all_samples:
            if s.source is None:
                source_missing.append(s)
            if s.assembly is None:
                assembly_missing.append(s)
        if len(source_missing) == 0:
            print("\tNo functions are missing source code")
        else:
            print("Samples missing source code:")
            for s in source_missing:
                print(f"\tSample(namespace={s.name_space}, arch={s.arch}, function={s.name})")
        if len(assembly_missing) == 0:
            print("\tNo functions are missing assembly code")
        else:
            print("Samples missing assembly code:")
            for s in assembly_missing:
                print(f"\tSample(namespace={s.name_space}, arch={s.arch}, function={s.name})")

    def display(self):
        """
        Display a single sample
        """
        print(f"Sample(namespace={self.name_space}, arch={self.arch}, function={self.name})")
        print("Source:")
        if self.source:
            for s in self.source.split("\n"):
                print("\t" + s)
        else:
            print("\t *** No source found ***")
        print("Assembly code:")
        if self.assembly:
            for s in self.assembly.split("\n"):
                print("\t" + s)
        else:
            print("\t *** No assembly found ***")

    @classmethod
    def build_database(cls):
        """
        create an sqlite3 database of Samples
        """
        con = sqlite3.connect("Samples.db")
        cur = con.cursor()

        cur.execute("DROP TABLE IF EXISTS sample")
        cur.execute("CREATE TABLE IF NOT EXISTS sample(id INTEGER PRIMARY KEY AUTOINCREMENT, namespace TEXT, arch TEXT, name TEXT, source TEXT, assembly TEXT)")
        for s in Sample.all_samples:
            cur.execute("INSERT INTO sample (namespace, arch, name, source, assembly) VALUES (?, ?, ?, ?, ?)", (s.name_space, s.arch, s.name, s.source, s.assembly))
        con.commit()
