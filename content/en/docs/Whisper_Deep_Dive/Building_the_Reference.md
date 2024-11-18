---
title: Building the Reference Model
linkTitle: Building the Reference Model
weight: 10
---

We start by importing `Whisper.cpp` into our Bazel build environment.  We may eventually want a full fork of the
code, but not until we are sure of the base release and what directions that fork will need to take.

This import starts with a simple addition to our MODULE.bazel workspace file:

```text
# MODULE.bazel
http_archive = use_repo_rule("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
# whisper.cpp is an open source voice-to-text inference app built on Meta's LLaMA model.
# It is a useful exemplar of autovectorization of ML code with some examples of hand-coded
# riscv intrinsics.
http_archive(
    name = "whisper_cpp",
    urls = ["https://github.com/ggerganov/whisper.cpp/archive/refs/tags/v1.7.1.tar.gz"],
    strip_prefix = "whisper.cpp-1.7.1/",
    build_file = "//:whisper-cpp.BUILD",
    sha256 = "97f19a32212f2f215e538ee37a16ff547aaebc54817bd8072034e02466ce6d55"
)
```

Next we add `whisper-cpp.BUILD` to show how to build libraries and binaries.  The instructions
for whisper library include these stanzas:

```text
c_library(
    name = "whisper",
    srcs = [
        "ggml/src/ggml.c",
        "ggml/src/ggml-aarch64.c",
        "ggml/src/ggml-alloc.c",
        "ggml/src/ggml-backend.cpp",
        "ggml/src/ggml-backend-impl.h",
        "ggml/src/ggml-impl.h",
        "ggml/src/ggml-quants.c",
        "src/whisper.cpp",
    ],
    copts = [
        "-I%s/include" % EXTERNAL_PATH,
        "-I%s/ggml/include" % EXTERNAL_PATH,
        "-I%s/ggml/src" % EXTERNAL_PATH,
        "-pthread",
        "-O3",
        "-ffast-math",
    ],
    ...
    defines = [
        "NDEBUG",
        "_XOPEN_SOURCE=600",
        "_GNU_SOURCE",
        "__FINITE_MATH_ONLY__=0",
        "__riscv_v_intrinsic=0",
    ],
    ...
)
cc_binary(
    name = "main",
    srcs = [
        "examples/common.cpp",
        "examples/common.h",
        "examples/common-ggml.cpp",
        "examples/common-ggml.h",
        "examples/dr_wav.h",
        "examples/grammar-parser.cpp",
        "examples/grammar-parser.h",
        "examples/main/main.cpp",
    ],
    ...
        deps = [
        "whisper",
    ],
)
```

Now we can build the reference app using our existing RISCV-64 toolchain:

```text
$ bazel build --platforms=//platforms:riscv_gcc --copt='-march=rv64gcv' @whisper_cpp//:main
...
$ file bazel-bin/external/_main~_repo_rules~whisper_cpp/main
bazel-bin/external/_main~_repo_rules~whisper_cpp/main: ELF 64-bit LSB executable, \
UCB RISC-V, RVC, double-float ABI, version 1 (GNU/Linux), \
dynamically linked, interpreter /lib/ld-linux-riscv64-lp64d.so.1, \
for GNU/Linux 4.15.0, not stripped

$ readelf -A bazel-bin/external/_main~_repo_rules~whisper_cpp/main
Attribute Section: riscv
File Attributes
  Tag_RISCV_stack_align: 16-bytes
  Tag_RISCV_arch: "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_v1p0_zicsr2p0_zifencei2p0_zmmul1p0_zaamo1p0_zalrsc1p0_zve32f1p0_zve32x1p0_zve64d1p0_zve64f1p0_zve64x1p0_zvl128b1p0_zvl32b1p0_zvl64b1p0"
  Tag_RISCV_priv_spec: 1
  Tag_RISCV_priv_spec_minor: 11

```

The final step is to locate the toolchain libraries used in this build, so that we can load them into Ghidra.  They are usually cached in a per-user
location.  We'll search for the RISCV libstdc++ toolchain library:

```console
$ bazel info
...
output_base: /run/user/1000/bazel
output_path: /run/user/1000/bazel/execroot/_main/bazel-out
package_path: %workspace%
release: release 7.4.0
...
$ find /run/user/1000 -name libstdc++\*
...
/run/user/1000/bazel/external/gcc_riscv_suite~/riscv64-unknown-linux-gnu/lib/libstdc++.so.6.0.33
...
/run/user/1000/bazel/external/gcc_riscv_suite~/riscv64-unknown-linux-gnu/lib/libstdc++.so.6
/run/user/1000/bazel/external/gcc_riscv_suite~/riscv64-unknown-linux-gnu/lib/libstdc++.so
```

We will want to load libstdc++.so.6 into Ghidra before we load the reference app.