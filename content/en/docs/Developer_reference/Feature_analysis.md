---
title: Feature Analysis
linkTitle: Feature Analysis
weight: 30
---

At a very high level the Advisor tries to translate between two languages - C or C++ source code that a human might write
and the sequence of assembly language instructions a compiler generates.  Compilers are very good at the forward translation
from C to assembly.  We want something that works in the reverse direction - suggesting C or other source code
that might have been compiled into specific assembly sequences.

The Advisor tries to brute-force this reverse translation by compiling a reference set of C sources into binaries, extracting
the instructions with `objdump` into a database, then looking for the best match to the instructions copied into the clipboard.
The GCC compiler test suite gives us thousands of reference C functions to start with.

Some features are easy to recognize.

* if the assembly listing includes a backwards branch instruction and branch target, then the source code likely
  contains a vectorized loop.
* if the assembly listing includes an instruction matching `vred*`, `vfred*` `vwred*`, then the source code likely
  contains a vectorized reduction loop reading a vector and emitting a scalar.

Other features are mostly distractions, adding entropy that we would like to ignore:

* The local choice of registers to hold intermediate values
* The specific loop termination branch condition - a test against a counter, an input pointer,
  or an output pointer are all equally valid but only one will be implemented.
* Instruction ordering is often arbitrary inside a loop, as counters and pointers are incremented/decremented.
* The compiler may reorder instructions to minimize the impact of memory latency.
* The compiler will change the emitted instructions for inlined function depending on what it knows at compile
  time.  This is especially true when the compiler knows the exact number of loop iterations, the alignment of
  operands, and the minimum size of vector registers.
* The compiler will change the emitted instructions based on the local 'register pressure' - whether or not there are lots
  of free vector registers.
* The compiler (or inline header macros) will translate a simple loop into multiple code blocks evaluated at run time.
  If the count is small, a scalar implementation is used.  If the count is large one or more vector blocks are used.
* The compiler writers sometimes have to guess whether to optimize for instruction count, minimal branches, or memory
  accesses.

And some features are harder to recognize but useful for the Ghidra user:

* Operand type is sometimes set at runtime, not encoded into the instruction opcode.
* Compilers can emit completely different code if the machine architecture indicates a vector length of greater than 128 bits.
* Vector registers may be grouped based on runtime context, so that the number of registers read or written must be inferred
  from instruction flows.
* The compiler will accept intrinsic vector functions - not all vector loops have a C counterpart.

