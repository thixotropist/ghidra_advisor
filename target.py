#!/usr/bin/python3
"""
Provide utility functions for working with Bazel targets and paths.

The top level Bazel repository or module is `training_set`.  That name doesn't get used much,
since there is no current external entity that might refer to it.

The dependent external repositories are:

* `gcc_riscv_testsuite` includes Gnu Compiler Suite test cases for RISCV autovectorization.
  This is mostly a snapshot of the GCC source repository with added Bazel build files
  and some links useful in aligning with Bazel naming conventions.
    * This repository is included as a subdirectory, so Bazel's name for this repository is `//gcc_riscv_testsuite`
* `gcc_riscv_suite` and `fedora_syslibs` provide the RISCV 64 bit compiler suite.  These are
  needed to process the GCC riscv test suite into C, assembly, and compiled binary training set
  components.
    * Bazel's names for these external repositories are `@gcc_riscv_suite//` and `@fedora_syslibs//`

GCC test case files exist within the `gcc_riscv_testsuite` repository.  Bazel BUILD files have been
added to this repository to make some of those files accessible via Bazel subpackages and targets.

For example, `rvv/autovec/reduc` is a subpackage within `//gcc_riscv_testsuite`.  It's Bazel name
is `//gcc_riscv_testsuite/rvv/autovec/reduc`

The BUILD file
within that subpackage defines 20 Bazel targets - ten libraries with two machine architectures
defined for each:

LIBS = ["reduc-{}".format(index) for index in (1,2,3,4,5,6,7,8,9,10)]

[
    cc_library(
        name = "{}_{}_libs".format(lib,march),
        srcs = ["{}.c".format(lib)],
        hdrs = glob(["reduc*.h"]),
        includes = ["."],
    )
    for lib in LIBS
    for march in MARCH_SET
]

# select only the shared object libraries for analysis
[
    cc_shared_library(
        name = "{}_{}".format(lib,march),
        deps = [":{}_{}_libs".format(lib,march)],
    )
    for lib in LIBS
    for march in MARCH_SET
]

This pattern generates 40 target rules from the 10 source files.  

* The 20 cc_library rules create both .so and .a libraries, and if requested on the command line
  will generate .i and .s compiler intermediate files.
* The 20 cc_shared_library rules select only the .so libraries, and will not generate .i or .s compiler intermediate files.

We need both cpp intermediate outputs (e.g., reduc-1_rv64gcv.i) and objdump outputs ((e.g., reduc-1_rv64gcv_objdump)),
so our generator.py script must first build the Bazel target //gcc_riscv_testsuite/rvv/autovec/reduc:reduc-1_rv64gcv_libs
then //gcc_riscv_testsuite/rvv/autovec/reduc:reduc-1_rv64gcv, and then
//gcc_riscv_testsuite/rvv/autovec/reduc:reduc-1_rv64gcv_objdump_generator

"""

import sys
import re
import logging
from bazel import Bazel

logging.basicConfig(level=logging.WARNING,
                    format='%(levelname)-8s [%(filename)s:%(lineno)d] %(message)s')
logger = logging

# This prefix follows MODULE.bazel implementation
INTERNAL_REPO_PREFIX = "bazel-bin"
DATA_DIR = "data"

class InternalRepo():
    """
    A Bazel subproject holding a testsuite repo
    """

    def __init__(self, name):
        self.name = name
        self.path = f"{DATA_DIR}/{name}"

    def build_path(self) -> str:
        """
        Workspace directory of build artifacts from this repo
        """
        return f"{INTERNAL_REPO_PREFIX}/{self.name}"

class Package():
    """
    A package or subpackage found within a Bazel repository
    """

    all_packages = []
    targets = []
    LIB_PAT = re.compile(r'/([\w-]+):([\w-]+)')

    def __init__(self, name: str, repo: InternalRepo):
        # name is something like rvv/autovec/reduc
        self.name = name
        # a repo.name is something like gcc_riscv_testsuite
        self.repo = repo
        # a bazel_name concatenates the two, to form something like @gcc_riscv_testsuite//rvv/autovec/reduc
        self.bazel_name = f"//{repo.name}/{name}"
        # location of data objects derived from this package
        self.path = f"{repo.path}/{name}"
        # targets that generate both .a and .so library types and temporary .i and .s files
        self.base_targets = []
        # targets that select only sharable .so library types and and no temporaries
        self.sharable_targets = []

        logger.info(f"New Package:\n\t(name={name}, repo={repo.name}, bazel_name={self.bazel_name},")
        logger.info(f"\tpath={self.path},")
        # add this package to the class list of packages
        Package.all_packages.append(self)

    def build_path(self) -> str:
        """
        Workspace directory of build artifacts from this package.
        This will be something like bazel-out/k8-opt/bin/external/_main~_repo_rules~gcc_riscv_testsuite/reduc
        """
        return f"{self.repo.build_path()}/{self.name}"

    @classmethod
    def get_packages(cls):
        """
        Get all current packages
        """
        return Package.all_packages

    def add_target(self, target):
        """
        add a new targets within this package
        """
        self.targets.append(target)

    def find_libraries(self):
        """
        Query Bazel to find all target libraries defined within this package
         library targets look like @gcc_riscv_testsuite//rvv/autovec/reduc:reduc-10_rv64gc
         where the source library has a machine architecture concatenated
        """
        bazel = Bazel()
        result = bazel.query(f"kind('cc_shared_library rule', {self.bazel_name}:*)")
        if result.returncode != 0:
            logger.error(f"Failed to find libraries within {self.bazel_name}")
            sys.exit()
        libs = []
        for line in result.stdout.splitlines():
            m = re.search(Package.LIB_PAT, line)
            if m:
                libs.append(f"{self.bazel_name}:{m.group(2)}")
        self.sharable_targets = libs
        return libs

    def find_base_libraries(self):
        """
        Query Bazel to find all base library targets. Building these directly
        will generate temporary files like .i and .s files
        """
        bazel = Bazel()
        result = bazel.query(f"kind('cc_library rule', {self.bazel_name}:*)")
        if result.returncode != 0:
            logger.error(f"Failed to find base libraries within {self.bazel_name}")
            sys.exit()
        libs = []
        for line in result.stdout.splitlines():
            logger.info(f"searching {line} for a library")
            m = re.search(Package.LIB_PAT, line)
            if m:
                logger.info(f"found a new library {m.group(2)}")
                libs.append(f"{self.bazel_name}:{m.group(2)}")
        self.base_targets = libs
        return libs

class Target():
    """
    A single Bazel target defined by a package or subpackage BUILD file
    """
    MACHINE_ARCHS = (
    "rv64gc",   # baseline generic
    "rv64gcv",  #   + vector support
    )

    # targets can be base cc_library or cc_shared_library.
    # We assume base library targets end in '_libs'
    SHARABLE_MARCH_PAT = re.compile(r"//[\-\w\/]+:([\-\w\/]+)_(.*)")
    BASE_MARCH_PAT = re.compile(r"//[\-\w\/]+:([\-\w\/]+)_(.*)_libs")

    def __init__(self, bazel_name: str, package: Package, sharable: bool):
        self.name = bazel_name
        self.package = package
        if sharable:
            march_pat = Target.SHARABLE_MARCH_PAT
            suffix = ''
        else:
            march_pat = Target.BASE_MARCH_PAT
            suffix = '_libs'
        m = re.search(march_pat, bazel_name)
        if not m:
            logger.error("Unable to find the machine architecture suffix in target " + bazel_name)
            sys.exit()
        self.march = m.group(2)
        self.base_name = m.group(1)
        self.target_name = self.base_name + '_' + self.march + suffix
        self.sharable = sharable

        if self.march not in self.MACHINE_ARCHS:
            logger.error("Unrecognized machine architecture " + self.march)
            sys.exit()

    def build_path(self) -> str:
        """
        Workspace directory of build artifacts for this target
        """
        return f"{self.package.build_path()}/_objs/{self.target_name}/{self.base_name}"
