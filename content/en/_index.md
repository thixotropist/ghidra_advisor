---
title: Ghidra Advisor for RISCV-64 Vector Extensions
---

{{< blocks/cover title="Ghidra Advisor" image_anchor="bottom" height="auto" >}}
Optimizing compilers can transform simple loops into hard-to-understand instruction sequences.
Can we train AI advisors or humans how to translate vector instruction sequences into something
useful for cybersecurity evaluation?
{{< /blocks/cover >}}

{{% blocks/section color='white' %}}

## Introduction

We'll use the RISC-V Vector instruction extension set as an example.  It is a 'vector length agnostic'
SIMD architecture, where the same instruction sequence can handle vector lengths of 128, 256, 512, or more bits.
The [Sophgo sg2380](https://sg2380.org/#Application-Scenarios) processor is a good example of this class, with
applications in video surveillance and image processing - eventually perhaps even autonomous munitions.

{{< alert title="Note" >}}The sg2380 has 16 cores capable of handling 128 bit vectors and four cores capable of handling 512 bit vectors.{{< /alert >}}

Ghidra - as of release 11.2 - doesn't handle RISCV vector extensions at all well.  What can we do now to
prepare a future version of Ghidra to do a better job?  Improving Ghidra will take some time, so we
will work with compiler toolchains likely to be used in production sometime in the near future.  For now,
that's gcc 15 with -O3 optimization and machine architectures of rv64gcv at a minimum.

We will use a couple of reference binaries as exemplars for Ghidra analysis:

* The [Whisper.cpp](https://github.com/ggerganov/whisper.cpp.git) voice-to-text inference engine.  This is a good
  example of using Machine Learning models for voice recognition and translation.  It uses vector math extensively.
* The [Data Path Development Kit - DPDK](https://core.dpdk.org/doc/) framework for network processing applications
  like routers and firewalls.  This has very little vector math.  Optimizing compilers can still find a reason to
  translate many simple loops into complex vector instruction sequences.

## Using this site

The simplest way to use this site is to browse through the examples, looking for the patterns in how
the reference compiler translates simple C code into sequences of RISC-V instructions.  Most patterns
are built with two machine architectures, with and without vector instructions enabled.

More advanced users can use the sqlite3 database of precompiled patterns help translate vector instruction
sequences back into C code.  The Jupyter Lab notebook `Advisor.ipynb` can take a Ghidra disassembly sample
from your clipboard and compare it to several thousand training set examples.  This likely won't provide
a solid match, but can provide useful context.

The most advanced users will extend the sqlite3 training set database with a complete RISC-V ecosystem
when analyzing a particular executable binary

* A `gcc`, `binutils`, and `glibc` compiler toolchain built from source, iteratively configured to produce code close
  to that observed in the binary under evaluation.
* a qemu user-space emulator configured to implement the target hardware architecture, including things
  like the actual vector length(s) supported in the binary
* a qemu system emulator configured to implement the target hardware architecture, with any custom kernel modules
  required by the executable.

{{% /blocks/section %}}
