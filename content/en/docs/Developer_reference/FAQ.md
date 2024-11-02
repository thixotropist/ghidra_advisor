---
title: Frequently Asked Questions
linkTitle: FAQ
weight: 1000
---

Why Bazel?
: Bazel does a good job of managing cross-compiler builds and build caches together,
  where the cross-compiler toolchain can be switched easily.

How do I compile with support for RISCV Instruction Set Architecture extensions?
: The binutils and gcc base code need to support those extensions first.
  The gcc compiler uses the `-march=` command line option to identify which
  extensions to apply for a given compilation. For example `-march=rv32gcv` says
  vector instructions are supported, while `-march=rv32gc` excludes vector instructions.

What machine architectures are currently implemented?
: The `variables.bzl` file sets `MARCH_SET = ("rv64gc", "rv64gcv")`.  Most sources are then
  compiled with and without vector support.

Are all RISCV vector binaries runnable on all vector hardware threads?
: Not always.  By default GCC will build for a minimum vector register length (`VLEN`) of 128 bits,
  which should be portable across all general purpose RISCV harts.  If `_zvl512b` were
  added to the `-march` setting, GCC will know that vector registers are bigger and can unroll
  loops more aggressively - generating code that will fail on 128 bit vector harts.  This can
  get complicated when processors have both 128 bit and 512 bit cores, like the sg2380.

Aren't vector extensions unlikely to be used in programs that don't do vector math?
: No.  Vector extensions are very likely to be found in inlined utilities like memcpy and strncmp.
  Most simple loops over arrays of structs can be optimized with vector instructions.
