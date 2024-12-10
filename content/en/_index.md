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

More advanced users can use the sqlite3 database of precompiled patterns to help translate vector instruction
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

###  Advanced Usage Scenario

There are a lot of arbitrary decisions in a project like this, so we will pick an overall advanced scenario
to shape those decisions.

We assume a corporation is evaluating a voice-activated and AI-adaptive router-firewall appliance and
asked its resident Ghidra user to evaluate its executables.  Initial inspection suggests the vendor has adopted a
multi-core RISCV-64 processor with vector instructions, a GCC-15 toolchain, and a linux real time OS.  Our Ghidra user
believes the product under test has library code somewhat similar to `Whisper.cpp` for the voice recognition and AI-adaptive
elements and `DPDK`-like code for the router/firewall functions.

## Interim Conclusions

Ghidra users are most likely to encounter RISCV vector instruction sequences in three circumstances:

1. Inline expansion of utility functions similar to `memcpy` or `strlen`.  These are common in source code and generally easy for
   humans and the Advisor to recognize.
2. Auto-vectorized simple loops that have been 'strip-mined' by the compiler for faster execution.  These are also common in optimized
   code.  The Advisor can recognize many of these, while their diversity can make it difficult for humans to untangle.  Optimized loops
   over arrays of structures can be especially confusing when the compiler has optimized index, offset, and loop termination calculations.
3. Optimization of scalar code, where the compiler has replaced simple scalar instructions initializing a data structure with fewer vector
   instructions.  The most common example is initializing two consecutive 64 bit elements to zero.  Also common are vector sequences
   initializing two adjacent integers to (0,1) or (false, true).  These vector sequences are fairly easy for both humans and Advisor to
   recognize - but it can be far more difficult to figure out just *what* fields or objects have been initialized.

The biggest surprise of this study was the prevalence of that third case - how often optimizing compilers could obfuscate initialization
code that was likely far from the critical data path.  Using Ghidra to completely analyze the main routine of a Whisper.cpp application requires
first analysis of optimized libstdc++ `string`, `vector`, `map`, and `iostream` inlined code.  That analysis will hopefully identify the type and layout
of objects allocated on the stack and heap. After that Advisor can associate initialization vector instructions with those objects.
At that point the Ghidra user can look at such objects to decide if they are relevant to their specific analysis task.

{{% /blocks/section %}}
