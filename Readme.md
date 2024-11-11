# README

>Note: The complete documentation for this project can be found at https://thixotropist.github.io/ghidra_advisor/

What tool might help Ghidra users interpret confusing listing and decompiler views?
Modern compilers can optimize simple C code into confusing instruction sequences.
This is especially true when the compiler unrolls loops into vector or SIMD instructions.

This work-in-progress project sketches a Jupyter Lab notebook running next to Ghidra.
A Ghidra user can copy an assembly code fragment from the listing window to the clipboard, then run
the Jupyter notebook `Advisor.ipynb`.  The python code extracts features from that
fragment and renders a Jupyter notebook report.  This report includes:

* Reference C source code that compiles to something with similar assembly language features.
  The reference C code comes from the GCC source test files plus the object dump disassembly
  listings after optimized compilation.
* Annotation of selected instructions, especially vector extension instructions
* Basic type inferencing

We want to keep the initial scope manageable and usable sometime in 2026.
We also want the Advisor to help with projects where Ghidra has the most current limitations -
where any advice is going to be useful.

Our initial scope focuses on RISCV-64 processors supporting vector instructions.  The binaries
we will 'train' on include:

* Whisper.cpp - a voice to text inference engine expected to benefit from aggressive optimization.
* Data Plane Development Kit - a networking framework where aggressive optimization produces
  obscure and complex instruction sequences
* openssl - a network library expected to benefit greatly from optimization with
  vector crypto instructions.
* glibc - library functions like memcpy and strncpy can be rendered inline with optimized
  instruction sequences.

We will use a developmental snapshot of GCC-15 and binutils to get a peek at the newest optimizations.
The build system will be bazel, as it has good support for crosscompilers and dependency handling.

## Usage

A basic user will import a small database of `(source,disassembly)` pairs along with this source
code, using their desktop clipboard to compare Ghidra disassembly listing stanzas with the database
pairs.

An advanced user will also import a customizable cross-compiler toolchain, adjusting the compiler
parameters to something close to what they think the binary-under-test might have been built with.
They will regenerate the `(source,disassembly)` database with that customized compiler, hoping that it
improves the pattern matching.

The advanced user will also add custom patterns to the database, then iterate those custom patterns
until the generated assembly language gets close to the patterns observed in Ghidra.
