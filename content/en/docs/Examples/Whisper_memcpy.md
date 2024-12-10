---
title: Whisper Memcpy
linkTitle: Whisper Memcpy
weight: 50
---

Is it easy to recognize vector expansions of libc functions like `memcpy`?

Let's locate some explicit invocations of `memcpy` within Whisper and
see what the Advisor has to say.

```c++
struct whisper_context * whisper_init_from_buffer_with_params_no_state(void * buffer, size_t buffer_size, struct whisper_context_params params) {
    struct buf_context {
        uint8_t* buffer;
        size_t size;
        size_t current_offset;
    };
    loader.read = [](void * ctx, void * output, size_t read_size) {
        buf_context * buf = reinterpret_cast<buf_context *>(ctx);

        size_t size_to_copy = buf->current_offset + read_size < buf->size ? read_size : buf->size - buf->current_offset;

        memcpy(output, buf->buffer + buf->current_offset, size_to_copy);
        buf->current_offset += size_to_copy;

        return size_to_copy;
    };
};
```

This source example shows a few traits:

* the number of bytes to copy is not in general known at compile time
* the buffer type is `uint8_t*`
* there are no alignment guarantees

GCC 15 compiles the lambda stored in loader.read as
`whisper_init_from_buffer_with_params_no_state::{lambda(void*,void*,unsigned_long)#1}::_FUN`.
The relevant Ghidra listing window instruction sequence (trimmed of address and whitespace) is:

```as
LAB_000b0be2
    vsetvli  a3,param_3,e8,m8,ta,ma  
    vle8.v   v8,(a4)
    c.sub    param_3,a3
    c.add    a4,a3
    vse8.v   v8,(param_2)
    c.add    param_2,a3
    c.bnez   param_3,LAB_000b0be2
```

Copying the Ghidra listing to the clipboard and running the Advisor gives us:

```text
Clipboard Contents to Analyze

LAB_000b0be2                                    XREF[1]:     000b0bf4(j)
000b0be2 d7 76 36 0c     vsetvli                        a3,param_3,e8,m8,ta,ma
000b0be6 07 04 07 02     vle8.v                         v8,(a4)
000b0bea 15 8e           c.sub                          param_3,a3
000b0bec 36 97           c.add                          a4,a3
000b0bee 27 84 05 02     vse8.v                         v8,(param_2)
000b0bf2 b6 95           c.add                          param_2,a3
000b0bf4 7d f6           c.bnez                         param_3,LAB_000b0be2

Signatures:

    Element width is = 8 bits
    Vector registers are grouped with MUL = 8
    Vector load: vle8.v
        Vector load is to multiple registers
    Vector store: vse8.v
        Vector store is from multiple registers
    At least one loop exists
    Significant operations, in the order they appear:
        vsetvli,vle8.v,vse8.v,_loop
    Significant operations, in alphanumeric order:
        _loop,vle8.v,vse8.v,vsetvli

Similarity Analysis

Compare the clipped example to the database of vectorized examples.

The best match is id=1873 [1.000]= _loop,vle8.v,vse8.v,vsetvli

The clip is similar to the reference example data/custom_testsuite/builtins/memcpy_rv64gcv:memcpy_255
Reference C Source

void memcpy_255()
{
  __builtin_memcpy (to, from, 255);
};

Reference Compiled Assembly Code

65e	auipc	a3,0x2
662	ld	a3,-1678(a3)
666	auipc	a2,0x0
66a	addi	a2,a2,82
66e	li	a4,255
672	vsetvli	a5,a4,e8,m8,ta,ma
676	vle8.v	v8,(a2)
67a	sub	a4,a4,a5
67c	add	a2,a2,a5
67e	vse8.v	v8,(a3)
682	add	a3,a3,a5
```

The Advisor has matched the vector instruction loop to the GCC `__builtin_memcpy` test case where the
number of bytes to transfer is large (255).  The individual scalar instructions are not the same.

This example shows something important that we probably want to add to the Advisor's report:

The `vsetvli` instruction includes the `m8` multiplier option, which means vector operations cover groups of 8
registers.  The `vle8.v` only references vector register `v8`, but the loads and stores affect the 8
registers `v8` through `v15`.  If the `__builtin_memcpy` appeared in an inline code fragment, where
there may be more pressure on vector register availability, we might have seen very similar code
with multipliers of `m4`, `m2`, or `m1`.

What does the Ghidra decompiler show for this instruction sequence?

```c
  do {
    lVar3 = vsetvli_e8m8tama(uVar1);
    auVar4 = vle8_v(lVar2);
    uVar1 = uVar1 - lVar3;
    lVar2 = lVar2 + lVar3;
    vse8_v(auVar4,param_2);
    param_2 = (void *)((long)param_2 + lVar3);
  } while (uVar1 != 0);
```

What would we like Ghidra's decompiler to show instead?  Something like:

```c
__builtin_memcpy(param_2, lvar2, uVar1);
```

That's not quite correct, as `__builtin_memcpy` doesn't mutate the values `param_2` or `lvar2`.
