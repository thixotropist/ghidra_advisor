---
title: Ghidra Examination
linkTitle: Ghidra Examination
weight: 30
---

We want to know how we can use `Advisor` to untangle vectorized instruction sequences.  We've seen that
`Advisor` can help with simple loops and builtin functions like memcpy.  Now we want to tackle vectorized
'shuffle' code, where GCC turns a sequence of simple assignments or initializations into a much more obscure
sequence of vector instructions.

We'll assume the Ghidra user wishes to search for malicious behavior adjacent to the `output_txt` function,
called by `main` after the voice-to-text inference engine has crunched the numbers.

The first step is to locate the `main` routine in our stripped binary.  There is no `main` symbol left after
stripping, so we need to find a path from the entry point to `main` in the unstripped binary first.  The entry point is
the symbol `_start` or `entry`.

In the unstripped binary:

```c
void _start(void)
{
...
  gp = &__global_pointer$;
  uVar1 = _PREINIT_0();
  __libc_start_main(0x2649e,in_stack_00000000,&stack0x00000008,0,0,uVar1,&stack0x00000000);
  ebreak();
  main();
  return;
}
```

While the stripped binary is:

```c
void entry(void)
{
  undefined8 uVar1;
  undefined8 in_stack_00000000;
  
  gp = &__global_pointer$;
  uVar1 = _PREINIT_0();
  __libc_start_main(0x2649e,in_stack_00000000,&stack0x00000008,0,0,uVar1,&stack0x00000000);
  ebreak();
  FUN_0001e758();
  return;
}
```

So we know that `main` is `FUN_0001e758`.

In the source code, `main` calls `output_txt`.  There is no `output_txt` symbol in either stripped or non-stripped binaries, so
this function has apparently been converted into inline code deep within `main`.

There are several different paths forward for examination.  Sometimes the best approach is to explore a short distance along each likely path,
backtracking or switching paths when we get stuck.  For this exercise we want to know how to make `Advisor` useful in at least some of those
cases where we get stuck.

Paths available:

* Search for C strings as literals, then find where they are used.  This will often give printf or logging utility functions.
* Search for C++ string constructors given literals as input.  Start to identify standard library string objects in the code.
* Look for initialization or print functions recognizable either from symbol names or printf formatting strings.
* Start to identify recurring structures passed by pointers.  This can include context, state, and parameter structures

Let's start with a routine that touches several of those paths.  This is the basic decompiled output from the stripped binary,
for a function that gets called a lot by our identified `main` routine.  Peeking into the unstripped binary, we see that its signature
is `void __thiscall std::string::string<>(string *this,char *cStr,allocator *param_2)` - a C++ basic_string constructor given a literal
C string as input.  Note that there is actually no allocator passed into the function.

```c
void FUN_000542e0(undefined8 *param_1,undefined *param_2)

{
  undefined *puVar1;
  long lVar2;
  undefined *puVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined auVar6 [256];
  long in_vl;
  
  gp = &__global_pointer$;
  puVar5 = param_1 + 2;
  *param_1 = puVar5;
  if (param_2 == (undefined *)0x0) {
                    /* WARNING: Subroutine does not return */
    std::__throw_logic_error("basic_string: construction from null is not valid");
  }
  puVar1 = param_2;
  lVar4 = 0;
  do {
    vsetvli_e8m1tama(0);
    puVar1 = puVar1 + lVar4;
    auVar6 = vle8ff_v(puVar1);
    auVar6 = vmseq_vi(auVar6,0);
    lVar2 = vfirst_m(auVar6);
    lVar4 = in_vl;
  } while (lVar2 < 0);
  puVar1 = puVar1 + (lVar2 - (long)param_2);
  puVar3 = puVar1;
  if (puVar1 < (undefined *)0x10) {
    if (puVar1 == (undefined *)0x1) {
      *(undefined *)(param_1 + 2) = *param_2;
      goto LAB_00054326;
    }
    if (puVar1 == (undefined *)0x0) goto LAB_00054326;
  }
  else {
    puVar5 = (undefined8 *)operator.new((ulong)(puVar1 + 1));
    param_1[2] = puVar1;
    *param_1 = puVar5;
  }
  do {
    lVar4 = vsetvli_e8m8tama(puVar3);
    auVar6 = vle8_v(param_2);
    puVar3 = puVar3 + -lVar4;
    param_2 = param_2 + lVar4;
    vse8_v(auVar6,puVar5);
    puVar5 = (undefined8 *)((long)puVar5 + lVar4);
  } while (puVar3 != (undefined *)0x0);
  puVar5 = (undefined8 *)*param_1;
LAB_00054326:
  param_1[1] = puVar1;
  *(undefined *)((long)puVar5 + (long)puVar1) = 0;
  return;
}
```

The exercise here is to recover the `basic_string` internal structure and identify the two vector stanzas.

The Advisor identifies the first vector stanza as a `builtin_strlen` and the second as a `builtin_memcpy`.
The std::string structure is 0x20 bytes and consists of a char*, a 64 bit string length, and a 16 byte union field.  If the string
with null termination is less than 16 bytes in length, it is stored directly in the 16 byte union field.  Otherwise, new memory is allocated
for the copy and a pointer is stored in the first 8 bytes of the union.

The next step is easy enough to make the Advisor unnecessary.  A `std::vector` copy constructor involves two vector instruction stanzas.

The new vector has three 64 bit pointer fields, all of which need to be zeroed.  GCC 15 does that with:

```c
  vsetivli_e64m1tama(2);
  vmv_v_i(in_v1,0);
  ...
  vse64_v(in_v1,this);
  *(undefined8 *)&this->field_0x10 = 0;
```

That's a little bit odd, since it is using three vector instructions to replace two scalar instructions, followed by a separate scalar store instruction.
It could alternatively used three scalar store instructions or three vector instructions with an `m2` LMUL multiplier option.  Perhaps this is an example of
incomplete or over-eager optimization, or an optimization from a RISC-V vendor who knows that vector instructions can be executed in parallel with scalar instructions.

A little later in the copy constructor a `builtin_memcpy` vector stanza occurs, to copy the contents of the original vector into the newly initialized vector.

This suggests:

* vector stanzas like `builtin_memcpy`, `builtin_strlen`, and vector instructions to zero 16 bytes are common and fairly easy to recognize, either by eye or Advisor.
  Adding more builtin functions to the exemplar directory makes good sense.
* vector stanzas often occur in initialization sequences, where they can be difficult to untangle from associated C++ object initializations.
  If we want to tackle this, we also need examples of stdlibc++ initializations, especially for vectors, maps, and iostreams.
* we need more examples of less common vector stanzas, including gather and slide operations.
