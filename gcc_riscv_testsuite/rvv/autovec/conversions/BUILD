load("//:variables.bzl", "MARCH_SET")
package(default_visibility = ["//visibility:public"])

LIBS = (
    "vzext-rv64gcv",
    "vsext-rv64gcv",
    "vncvt-rv64gcv",
    "vfwcvt-rv64gcv",
    "vfwcvt-itof-rv64gcv",
    "vfwcvt-ftoi-rv64gcv",
    "vfncvt-rv64gcv",
    "vfncvt-itof-rv64gcv",
    "vfncvt-ftoi-rv64gcv",
    "vfcvt_rtz-rv64gcv",
    "vfcvt-itof-rv64gcv",
    "vec-widen-float16-int64",
    "vec-narrow-int64-float16",
)

[
    cc_library(
        name = "{}_{}_libs".format(lib,march),
        srcs = ["{}.c".format(lib)],
        hdrs = [
            "vzext-template.h",
            "vsext-template.h",
            "vncvt-template.h",
            "vfwcvt-template.h",
            "vfwcvt-itof-template.h",
            "vfwcvt-ftoi-template.h",
            "vfncvt-template.h",
            "vfncvt-itof-template.h",
            "vfncvt-ftoi-template.h",
            "vfcvt_rtz-template.h",
            "vfcvt-itof-template.h",
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
