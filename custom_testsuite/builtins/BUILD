load("//:variables.bzl", "MARCH_SET")
package(default_visibility = ["//visibility:public"])

LIBS = (
    "memcpy",
    "string",
    )
[
    cc_library(
        name = "{}_{}_libs".format(lib,march),
        srcs = ["{}.c".format(lib)],
        hdrs = [
            ],
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

# Perform an objdump disassembly for each machine architecture and sharable object libary
[
    genrule(
        name = "{}_{}_objdump_generator".format(lib,march),
        srcs = [
            ":{}_{}".format(lib,march),
            "//toolchains:gcc_riscv_objdump",
            "@gcc_riscv_suite//:compiler_files",
        ],
        outs = [
            ":{}_{}_objdump".format(lib,march),
        ],
        cmd = "$(location //toolchains:gcc_riscv_objdump) -d $(location :{}_{}) >".format(lib,march) +
                "$(location :{}_{}_objdump)".format(lib,march),
    )
    for lib in LIBS
    for march in MARCH_SET
]
