---
title: Whisper.cpp Example
linkTitle: Whisper Example
weight: 10
---

Let's inspect whisper.cpp binaries as compiled for a RISCV-64 processor with vector extensions.
We'll start with this snippet from the function `whisper_full_with_state`.

```text
000cc166 57 77 80 0d     vsetvli                        a4,zero,e64,m1,ta,ma
000cc16a d7 a1 08 52     vid.v                          v3
000cc16e d7 30 00 5e     vmv.v.i                        v1,0x0
000cc172 93 06 80 03     li                             a3,0x38
000cc176 d7 e1 36 96     vmul.vx                        v3,v3,a3
000cc17a d6 86           c.mv                           a3,s5
000cc17c ce 97           c.add                          a5,s3
000cc17e 03 b6 07 18     ld                             a2,0x180(a5)
000cc182 31 06           c.addi                         a2,0xc
LAB_000cc184                                    XREF[1]:     000cc1a0(j)
000cc184 d7 f7 76 09     vsetvli                        a5,a3,e32,mf2,tu,ma
000cc188 07 71 36 06     vluxei64.v                     v2,(a2),v3
000cc18c 57 32 10 9e     vmv1r.v                        v4,v1
000cc190 13 97 37 00     slli                           a4,a5,0x3
000cc194 1d 8f           c.sub                          a4,a5
000cc196 0e 07           c.slli                         a4,0x3
000cc198 9d 8e           c.sub                          a3,a5
000cc19a d7 10 41 d2     vfwadd.wv                      v1,v4,v2
000cc19e 3a 96           c.add                          a2,a4
000cc1a0 f5 f2           c.bnez                         a3,LAB_000cc184
000cc1a2 d3 07 00 f2     fmv.d.x                        fa5,zero
000cc1a6 57 77 80 0d     vsetvli                        a4,zero,e64,m1,ta,ma
000cc1aa 57 d1 07 42     vfmv.s.f                       v2,fa5
000cc1ae d7 10 11 06     vfredusum.vs                   v1,v1,v2
000cc1b2 d7 14 10 42     vfmv.f.s                       fs1,v1
```

## Advisor Output

Signatures:
* Element width is = 64 bits
* Vector element index: vid.v
    * often used in generating a vector of offsets for indexing
* Element width is = 32 bits
    * Vector multiplier is fractional, MUL = f2
* Vector unordered indexed load: vluxei64.v
* Vector register move/copy: vmv1r.v
* Element width is = 64 bits
* FP register to vector register element 0
* Vector floating point reduction: vfredusum.vs
* Vector register element 0 to FP register
* Significant opcodes, in the order they appear:
    * vsetvli,vid.v,vmv.v.i,vmul.vx,vsetvli,vluxei64.v,vmv1r.v,vfwadd.wv,c.bnez,vsetvli,vfmv.s.f,vfredusum.vs,vfmv.f.s
* Significant opcodes, in alphanumeric order:
    * c.bnez,vfmv.f.s,vfmv.s.f,vfredusum.vs,vfwadd.wv,vid.v,vluxei64.v,vmul.vx,vmv.v.i,vmv1r.v,vsetvli,vsetvli,vsetvli
* At least one loop exists

### Similarity Analysis

Compare the clipped example to the database of vectorized examples.

The best match is id=588 [0.687]= bnez,vfadd.vv,vle8.v,vlseg2e64.v,vmsne.vi,vmv.v.i,vmv1r.v,vse64.v,vsetvli,vsetvli,vsetvli

The clip is similar to the reference example `data/gcc_riscv_testsuite/rvv/autovec/struct/mask_struct_load-1_rv64gcv:test_f64_f64_i8_2`

#### Reference C Source

```c
void test_f64_f64_i8_2(double *__restrict dest, double *__restrict src, int8_t *__restrict cond, intptr_t n)
{
  for (intptr_t i = 0; i < n; ++i)
    if (cond[i])
      dest[i] = src[i * 2] + src[i * 2 + 1];
}
```

#### Reference Compiled Assembly Code

```text
2932	blez	a3,2970 <test_f64_f64_i8_2+0x3e>
2936	vsetvli	a5,zero,e64,m1,ta,ma
293a	vmv.v.i	v4,0
293e	vsetvli	a5,a3,e8,mf8,ta,ma
2942	vle8.v	v0,(a2)
2946	vmv1r.v	v1,v4
294a	slli	a6,a5,0x4
294e	slli	a4,a5,0x3
2952	sub	a3,a3,a5
2954	add	a2,a2,a5
2956	vmsne.vi	v0,v0,0
295a	vlseg2e64.v	v2,(a1),v0.t
295e	vsetvli	zero,zero,e64,m1,tu,mu
2962	add	a1,a1,a6
2964	vfadd.vv	v1,v3,v2,v0.t
2968	vse64.v	v1,(a0),v0.t
296c	add	a0,a0,a4
296e	bnez	a3,293e <test_f64_f64_i8_2+0xc>
2970	ret	
```

## Manual analysis

The matched C code is not that good a match.  The Advisor suggests that this is a floating point add
reduction loop over 32-bit floats into a 64 bit double result, with a relatively complex indexing calculation
to access the addends.

The path forward is to add custom training examples until we converge on a decent match.  We can do that by adding
a new training function to the database:

```c
#include <stdint.h>
double reduce_floats(float *p, uint32_t count)
{
    double result = 0.0;
    for (int i = 0; i < count; i++)
    {
        result += p[i * 14];
    }
    return result;
}
```

Rebuild the database with `generator.py`, `ingest.py`, and `sample_analytics.py`.  We can then rerun the Advisor - but we don't get a better match!
In fact compiling this training example with `GCC 15.0`, `-O3`, and `-march=rv64gcv` doesn't produce any vector instructions at all.
We need to add one more compilation option, `-ffast-math`, to convince the compiler that vectorization is desired.

After adding `-ffast-math` to the relevant `BUILD` file, we get a much better Advisor output:

## Advisor Output - with fast-math

### Similarity Analysis

Compare the clipped example to the database of vectorized examples.

The best match is id=1532 [0.957]= bnez,vfmv.f.s,vfmv.s.f,vfredusum.vs,vfwadd.wv,vid.v,vluxei64.v,vmul.vx,vmv.v.i,vmv1r.v,vsetvli,vsetvli,vsetvli,vsll.vi

The clip is similar to the reference example `data/custom_testsuite/structs/reduction_rv64gcv:reduce_floats`

## Notes

* The `whisper.cpp` binary was compiled with `-O3` and `-ffast-math`.  This is an example of iteratively reconstructing the toolchain
  until we can generate something close to the observed code.
* The actual C source likely does not contain anything like `p[i * 14]`.  It is much more likely to be iterating over an array of
  structs, each 56 bytes long, and summing a 32 bit count field within that structure.
* There likely isn't much of a gain to be had with vectorizing this loop if VLEN is 128 bits.  Only two elements can be
  processed per iteration, with 10 instructions per iteration.  The scalar code handles one element per iteration in five instructions,
  so any possible gain is due to a tradeoff between code size and branch handling.

  ## Reconciling with Ghidra

  This reduction example decomposes the loop into three segments:

  1. A setup section before the loop initializing:
      * a double result vector `v1` to zero
      * a pointer to the first addend in `a2`, 
      * a vector of relative offsets `v1 = (0, 1, ...) * 0x38`
  2. The loop body:
      * `a5` = number of addends that fit into a vector register
      * `v2` = an indexed load of addends
      * `v1 += v2`
      * `a4 = 0x38 * a5`
      * `a2 += a4`  ; adjust the address of the next first addend
  3. The loop post-processing
      * `v2 = 0.0`
      * `v1[0] = v2[0] +/v1`  ; where `+/` sums the elements of a single vector into the first element of the result vector
      * `fs1 = v1[0]`


The original C code might look like this:

```c
struct astruct {
  uint32_t field0x00[3];
  float    field0x0c;
  uint32_t field0x10[10];
};
// sizeof astruct = 0x38
double reduce_floats(struct astruct* p, uint32_t count)
{
    double result = 0.0;
    for (int i = 0; i < count; i++)
    {
        result += p[i].count;
    }
    return result;
}
```