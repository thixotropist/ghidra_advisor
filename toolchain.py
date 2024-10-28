"""
This Toolchain class includes everything needed for Bazel crosscompilation
except for the Bazel wrapper itself
"""

class Toolchain():
    """
    A Bazel toolchain consists of a compiler suite like GCC 15.0.0, a sysroot containing include
    files and linker context, and a set of compiler/linker defaults.  With RISCV processors you
    also want to support multiple microarchitectures, with the `march` compiler option.  During
    a Ghidra analysis you usually want a toolchain configured to be as close as possible to the
    toolchain used to build the binary under test.  Instead, this project uses the developmental
    tip of the GCC compiler suite.  This should help identify future Ghidra challenges.

    The biggest challenges in toolchain debugging tend to involve linking and loading, where
    `gcc` or `g++` implicitly invokes `collect2`, `ld`, `ar`, and various linker scripts.
    It is very hard to prove that these implicit dependencies are taken from the imported
    toolchain and not from the host linker environment.  The dynamic libraries (`.so`) needed
    for toolchain executables can be a similar headache.
    """

    # Bazel targets used to test the toolchain environment
    REFERENCE_C_PGM = '//test:helloworld'
    REFERENCE_CPP_PGM = '//test:helloworld++'

    # The default risc-v 64 bit platform, roughly tracking an SiFive SDK
    DEFAULT_RISCV64_PLATFORM = '//platforms:riscv_gcc'

    # a bazel-generated platform representing the local development system
    LOCAL_HOST_PLATFORM = '@local_config_platform//:host'
