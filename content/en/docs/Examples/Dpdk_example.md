---
title: DPDK Network Example
linkTitle: DPDK Example
weight: 20
---

Are network appliances improved with autovectorization?  We can examine code examples taken from the
DPDK network project to find out.
We'll start with code that uses vector gather and slide operations in what *might* be a key datapath routine.
The binary `dpdk_l3fwd` is an example of a layer 3 forwarding engine.  It includes the function `rx_recv_pkts`,
which appears to be selected from the DPDK source file `drivers/net/iavf/iavf_rxtx.c`.

This function includes several vector stanzas that use `vrgather` and `vslide1down`.

We will make things a bit easier by including the preprocessed source file `drivers/net/iavf/iavf_rxtx.c`
in our custom dataset under `data/custom_testsuite/dpdk`.  This brings all of the relevant DPDK header files
inline.

The first vector stanza to examine is:

```text
LAB_0053c12e             XREF[2]:     0053be34(j), 0053be42(j)  
0053c12e 73 2e 20 c2     csrrs        t3,vlenb,zero
0053c132 57 73 80 0d     vsetvli      t1,zero,e64,m1,ta,ma 
0053c136 b3 0e c0 41     neg          t4,t3
0053c13a 93 58 3e 00     srli         a7,t3,0x3
0053c13e 3e 97           c.add        a4,a5
0053c140 d7 a1 08 52     vid.v        v3
0053c144 93 87 0e 04     addi         a5,t4,0x40
0053c148 93 86 f8 ff     addi         a3,a7,-0x1
0053c14c 33 67 f7 20     sh3add       a4,a4,a5
0053c150 d7 c1 36 0e     vrsub.vx     v3,v3,a3
0053c154 5a 97           c.add        a4,s6
0053c156 3b 8f 1b 41     subw         t5,s7,a7
0053c15a a2 86           c.mv         a3,s0
0053c15c 81 47           c.li         a5,0x0
LAB_0053c15e             XREF[1]:     0053c172(j)  
0053c15e 07 71 87 02     vl1re64.v    v2,(a4)
0053c162 bb 87 17 01     addw         a5,a5,a7
0053c166 76 97           c.add        a4,t4
0053c168 d7 80 21 32     vrgather.vv  v1,v2,v3
0053c16c a7 80 86 02     vs1r.v       v1,(a3)
0053c170 f2 96           c.add        a3,t3
0053c172 e3 76 ff fe     bgeu         t5,a5,LAB_0053c15e
```

This sequence suggests a load/permute/store operation on 64 bit elements.  There are lots of complications:

* The function `rx_recv_pkts` has static inline attributes, so it has likely been merged with other functions
* There are no obvious candidates for the gcc C source code that generates this `vrgather` pattern.
* This may be an artifact of using snapshots of gcc and dpdk.
* The `vs1r.v` instruction is a whole register store variant that ignores `vsetvli` settings.

Analysis of this snippet is easier with emulation:
* The assembly fragment is copied into a new source file, `emulations/test_1.S`
* The assembly source is converted into a subroutine
* Instrumentation is added to store intermediate values into global data variables.
* A `main.c` driver routine is added, to provide input and output vectors and
  instrumentation printouts.
* A RISCV-64 executable is built
* A RISCV-64 QEMU userspace emulator is built and configured
* The RISCV-64 executable is run to see what permutations are generated
* The RISCV-64 executable is run with alternate values for VLEN, to show that the results
  are stable regardless of the vector hardware implementation.

Process this Ghidra assembly fragment through the current Advisor:

```md
Signatures:
* Element width is = 64 bits
* Vector element index: vid.v
    * often used in generating a vector of offsets for indexing
* Vector whole register load: vl1re64.v
* Vector gather: vrgather.vv
* Vector whole register(s) store: vs1r.v
* Significant opcodes, in the order they appear:
    * vsetvli,vid.v,vrsub.vx,vl1re64.v,vrgather.vv,vs1r.v,bgeu
* Significant opcodes, in alphanumeric order:
    * bgeu,vid.v,vl1re64.v,vrgather.vv,vrsub.vx,vs1r.v,vsetvli
* At least one loop exists

## Similarity Analysis

Compare the clipped example to the database of vectorized examples.

The best match is id=1689 [0.860]= vid.v,vle16.v,vrgather.vv,vrsub.vi,vse16.v,vsetivli

The clip is similar to the reference example `data/gcc_riscv_testsuite/rvv/autovec/vls-vlmax/perm-4_rv64gcv:permute_vnx2hi`

### Reference C Source

void permute_vnx2hi(vnx2hi values1, vnx2hi values2, vnx2hi *out)
{
  vnx2hi v = __builtin_shufflevector (values1, values2, (2) - 1 - (0), (2) - 2 - (0));
  *(vnx2hi *) out = v;
} __attribute__((noipa))
```

Gcc's `__builtin_shufflevector` with the given mask reverses the order of a vector of two 16 bit values.
The signature match of 0.86 suggests this is just a hint of what is going on here.

After rewriting the Ghidra sample as a riscv64 assembly routine, we get:

```as
    .section .data.test_1
    .globl cntr, vl, src_incr, dst_incr, src_start, dst_start
    .globl cnt_limit
dst_incr:
    .dword  0
vl:
    .dword  0
src_incr:
    .dword  0
cntr:
    .dword  0
src_start:
    .dword  0
dst_start:
    .dword  0
cnt_limit:
    .word  0

    .section        .text.test_1,"ax",@progbits
    .globl test_1
    .type  test_1, @function

test_1:
    csrrs          t3,vlenb,zero
    lui            t6,%hi(dst_incr)
    addi           t6,t6,%lo(dst_incr)
    sd             t3,(t6)                # ->dst_incr
    vsetvli        t1,zero,e64,m1,ta,ma
    sd             t1,8(t6)               # ->vl
    neg            t4,t3
    sd             t4,16(t6)              # ->src_incr
    srli           a7,t3,0x3
    sd             a7,24(t6)              # ->cntr
    vid.v          v3
    addi           a5,t4,0x40
    addi           a3,a7,-0x1
    add            a0,a5,a0
    sd             a0,32(t6)              # ->src_start
    vrsub.vx       v3,v3,a3
    c.li           t5,0x8
    subw           t5,t5,a7
    sw             t5,48(t6)              # ->cnt_limit
    vs1r.v         v3,(a2)
    c.li           a5,0x0
    sd             a1,40(t6)              # ->dst_start
LAB_0053c15e:
    vl1re64.v      v2,(a0)
    addw           a5,a5,a7
    c.add          a0,t4
    vrgather.vv    v1,v2,v3
    vs1r.v         v1,(a1)
    add            a1,a1,t3
    bgeu           t5,a5,LAB_0053c15e
    ret

.globl get_vlenb
.type  get_vlanb, @function

get_vlanb:
    csrrs          a0,vlenb,zero
    srli           a2,a0,0x3
    ret
```

The main routine to exercise this is:

```c
#include <stdio.h>
extern void test_1(unsigned long long *, unsigned long long *, unsigned long long *);
extern void test_1_ref(unsigned long long *in, unsigned long long *out, unsigned int size);
extern long long cntr, vl, src_incr, dst_incr, src_start, dst_start;
extern long cnt_limit;
int main(void)
{
    unsigned long long in_vector[8] = {90,91,92,93,94,95,96,97};
    unsigned long long out_vector[8] = {0,0,0,0,0,0,0,0};
    unsigned long long shuffle_vector[4] = {0,0,0,0};
    printf("Initializing\n");
    printf("in_vector_addr: %16p\n", (void*)in_vector);
    printf("out_vector_addr: %16p\n", (void*)out_vector);
    test_1(in_vector, out_vector, shuffle_vector);
    printf("cntr: %lld\n", cntr);
    printf("vl: %lld\n", vl);
    printf("src_incr: 0x%llx\n", src_incr);
    printf("dst_incr: 0x%llx\n", dst_incr);
    printf("src_start: %p\n", (void*)src_start);
    printf("dst_start: %p\n", (void*)dst_start);
    printf("cnt_limit: 0x%lx\n", cnt_limit);
    printf("shuffle vector: %lld, %lld, %lld, %lld\n", shuffle_vector[0], shuffle_vector[1], shuffle_vector[2], shuffle_vector[3]);
    printf("out vector: %lld, %lld, %lld, %lld, ", out_vector[0], out_vector[1], out_vector[2], out_vector[3]);
    printf("%lld, %lld, %lld, %lld\n", out_vector[4], out_vector[5], out_vector[6], out_vector[7]);
    printf("Assembly version Complete, starting reference version\n");
    /* Once the assembly mockup returns a good value, try a C equivalent
    test_1_ref(in_vector, out_vector, 8);
    printf("out vector: %lld, %lld, %lld, %lld, ", out_vector[0], out_vector[1], out_vector[2], out_vector[3]);
    printf("%lld, %lld, %lld, %lld\n", out_vector[4], out_vector[5], out_vector[6], out_vector[7]);
    */
}
```

The QEMU VLEN variable and microarchitecture extensions are configured on the command line.
The following requests the VLEN=128 minimum basic register size.

```console
$ export QEMU_CPU=rv64,zba=true,zbb=true,v=true,vlen=128,vext_spec=v1.0,rvv_ta_all_1s=true,rvv_ma_all_1s=true
```

Build and run with:

```console
training_set$ bazel build --platforms=//platforms:riscv_gcc emulations:test_1
INFO: Analyzed target //emulations:test_1 (0 packages loaded, 0 targets configured).
INFO: Found 1 target...
Target //emulations:test_1 up-to-date:
  bazel-bin/emulations/test_1

training_set$ qemu-riscv64-static -L /opt/riscvx/sysroot -E LD_LIBRARY_PATH=/opt/riscvx/sysroot/riscv64-unknown-linux-gnu/lib/ bazel-bin/emulations/test_1
Initializing
in_vector_addr:   0x2aaaab2aaab0
out_vector_addr:   0x2aaaab2aaaf0
cntr: 2
vl: 2
src_incr: 0xfffffffffffffff0
dst_incr: 0x10
src_start: 0x2aaaab2aaae0
dst_start: 0x2aaaab2aaaf0
cnt_limit: 0x6
shuffle vector: 1, 0, 0, 0
out vector: 97, 96, 95, 94, 93, 92, 91, 90
Complete!
```

Repeat with VLEN=256 and the same executable binary, to see if the results are stable:

```console
$ export QEMU_CPU=rv64,zba=true,zbb=true,v=true,vlen=256,vext_spec=v1.0,rvv_ta_all_1s=true,rvv_ma_all_1s=true

training_set$ qemu-riscv64-static -L /opt/riscvx/sysroot -E LD_LIBRARY_PATH=/opt/riscvx/sysroot/riscv64-unknown-linux-gnu/lib/ bazel-bin/emulations/test_1
Initializing
in_vector_addr:   0x2aaaab2aaab0
out_vector_addr:   0x2aaaab2aaaf0
cntr: 4
vl: 4
src_incr: 0xffffffffffffffe0
dst_incr: 0x20
src_start: 0x2aaaab2aaad0
dst_start: 0x2aaaab2aaaf0
cnt_limit: 0x4
shuffle vector: 3, 2, 1, 0
out vector: 97, 96, 95, 94, 93, 92, 91, 90
Complete!
```

So now the permutation is clear - this snippet copies a vector of 64 bit values - likely pointers - from one location to another *in the reverse order*.
The source pointer advances backwards, starting `vl` elements before the end, while the
destination pointer advances forwards, starting at the first element.  The reverse-copy
operation is stable with VLEN of 128 or 256 bits.

Next we can add `test_1_ref.c`, a C routine which should compile to something much closer to the
sample binary:

```c
void test_1_ref(unsigned long long *in, unsigned long long *out, unsigned int size)
{
    int i;
    int upper_index = size - 1;
    for (i=0; i < size; i++) {
        out[i] = in[upper_index - i];
    }
}
```

## Record the new example

We want to add `test_1_ref` to the training set database, so copy it into `custom_testsuite/structs`, update the
BUILD file there, then rerun the analysis:

```console
./generator.py 
./ingest.py 
./sample_analytics.py 
./advisor.py data_test/advisor_tests/gather2.ghidra
...
The best match is id=1864 [0.926]= bgeu,bltu,bne,vid.v,vl1re64.v,vrgather.vv,vrsub.vx,vs1r.v,vsetvli

The clip is similar to the reference example `data/custom_testsuite/structs/test_1_ref_rv64gcv:test_1_ref`
```

The extra branch instructions clutter the signature match result somewhat.

## Feature extraction

What generalized features does this example provide?

1. There is a single loop
2. The loop includes one vector load, one vector store, and one vector gather
   operation.
3. The loop exit condition depends on a scalar counter advancing to equal or
   exceed a fixed limit value, without a dependency on vector element values.
4. Source and destination pointers increment with different values
5. The loop setup identifies the SEW as 64 bits.  This is unchanged throughout
   the sample code.  This implies that this `vs1r.v` instruction is equivalent to
   a `vse64.v` instruction.
6. The `bgeu` instruction terminating the loop could be encoded as `bleu` with
   reversed operands.  More generally, the loop termination could have been
   implemented in several different ways.

Register assignments appear to be:

| Assignment | Register | Initializations |
| --------- | --------- | ------ |
| Source address | a4 | |
| Source address increment | t4 | = (-vlenb) |
| Destination address | a3 | |
| Destination address increment | t3 | = vlenb |
| Loop counter | a5 | =0 |
| Loop counter increment | a7 | vlenb>>3 |
| Loop counter limit | t5 | |
| Source vector register | v2 | |
| Destination vector register | v1 | |
| Gather index vector register | v3 | depends on vlenb |

The vector gather index register v3 depends on vl, the number
of 64 bit elements that fit within a vector register.

* if vlen = 128 - or vlenb = 16 - then v3 = (1,0)
* if vlen = 256 - or vlenb = 32 - then v3 = (3,2,1,0)

It is not at all clear whether the compiler knows the size of the
source vector, or whether the code works as intended when
the source vector size is odd or smaller than the size of a vector
register.

We can resolve that by looking at Ghidra's decompiler window.
The vector instruction stanza actually begins earlier, executing the vector instructions
only after a test of vlenb.

### Examination of test_1_ref

GCC 15 compiles `test_1_ref.c` into something more complex than the assembly code stanza
we analyzed.  The single-line loop becomes three loops - a scalar loop to handle
relatively small vector sizes, then a vector loop to handle an integer number of VLEN strips, finally a second
scalar loop to handle any remaining elements.  For the code stanza passed in for analysis the
input and output vectors appear to have a fixed size known to the compiler - 64 bytes.  This implies
no scalar loops needed for VLEN=128 bits or VLEN=256 bits.  The code stanza would generate
a buffer overflow error for VLEN>512 bits.

```c
void test_1_ref(ulonglong *in,ulonglong *out,ulong size)
{
  ulonglong *pIn;
  ulonglong *puVar1;
  long lVar2;
  ulonglong uVar3;
  ulong uVar4;
  ulong uVar5;
  int iVar6;
  undefined auVar7 [256];
  undefined auVar8 [256];
  ulong in_vlenb;
  ulonglong *pOut;
  
  gp = &__global_pointer$;
  if (size != 0) {
    uVar5 = (ulong)((int)size + -1);
    if (((uVar5 < 0xd) || (uVar5 < (ulong)(long)((int)(in_vlenb >> 3) + -1))) ||
       ((lVar2 = uVar5 + 1, in + (lVar2 - (size & 0xffffffff)) < out + (size & 0xffffffff) &&
        (out < in + lVar2)))) {
      pIn = in + uVar5;
      pOut = out;
      do {
        uVar3 = *pIn;
        puVar1 = pOut + 1;
        pIn = pIn + -1;
        *pOut = uVar3;
        pOut = puVar1;
      } while (puVar1 != out + (size & 0xffffffff));
    }
    else {
      vsetvli_e64m1tama(0);
      auVar8 = vid_v();
      auVar8 = vrsub_vx(auVar8,(in_vlenb >> 3) - 1);
      lVar2 = lVar2 * 8 + -in_vlenb + (long)in;
      iVar6 = (int)(in_vlenb >> 3);
      uVar4 = 0;
      pOut = out;
      do {
        auVar7 = vl1re64_v(lVar2);
        uVar4 = (ulong)((int)uVar4 + iVar6);
        lVar2 = lVar2 + -in_vlenb;
        auVar7 = vrgather_vv(auVar7,auVar8);
        vs1r_v(auVar7,pOut);
        pOut = (ulonglong *)((long)pOut + in_vlenb);
      } while (uVar4 <= (ulong)(long)((int)size - iVar6));
      if (size != uVar4) {
        pOut = in + (uVar5 - uVar4);
        pIn = out + uVar4;
        do {
          uVar3 = *pOut;
          uVar4 = (ulong)((int)uVar4 + 1);
          pOut = pOut + -1;
          *pIn = uVar3;
          pIn = pIn + 1;
        } while (uVar4 < size);
        return;
      }
    }
  }
  return;
}
```

The scalar loop consists of about 22 bytes, or 7 instructions.  The full vector function takes up 180 bytes.
There is little reason to believe that vectorization actually improves this code, especially for vector
harts holding only two 64 bit objects per vector register.

### Summary

There is no visible reason to enable full autovectorization for datapath network routing code like DPDK.
It *might* make sense to vectorize lockable critical regions or specific critical path code.
Vector replacement of utility functions like memcpy or strncmp would still make sense.
If someone created an AI-adaptive network appliance the math inference engine portions would likely be improved
with vectorization.
