---
title: Whisper Deep Dive
linkTitle: Whisper Deep Dive
weight: 20
---

This exercise mocks up a forensic analysis of a hypothetical voice to text application believed to be
based on `Whisper.cpp`.  The previous examples applied Advisor to fairly random vector instruction sequences
found in a `Whisper.cpp` compilation without much identifying metadata.  This time we will do things more
methodically, using a specific `Whisper.cpp` release built with specific build instructions, analyzed in Ghidra in both stripped
and unstripped binary formats.  Dependent libraries `libc`, `libm`, and `libstdc++` will be imported into Ghidra from the toolchain
used to construct the whisper executable.  Once we have trained Advisor to help with the known-source whisper application, we might
be better able to use in in analyzing potentially malicious whisper-like applications.

This is an iterative process, where we take some initial guesses into how the application-under-test (AUT) was built, rebuild our whisper
reference model the same way, then adjust either the reference model or the build parameters until we see similar key patterns
in our AUT and reference models.

The initial guesses are:

* Similar to Whisper.cpp release 1.7.1
* Built for RISCV64 cores with the rva22 profile plus vector extensions, something like the SiFive P670 cores within a SG2380 processor.
* Built with gcc 15.0.0 with march=rv64gcv, fast-math, and O3 options for a linux-like OS.
* dynamically linked with libc, libm, libstdc++ as of mid 2024.

It's worthwhile establishing key structures used by Whisper - and likely by any malicious code forked from Whisper.

Inspecting the reference source code suggests these structures:

* whisper_context
* whisper_state - created by `whisper_init_state(struct whisper_context * ctx)`
* whisper_context_params