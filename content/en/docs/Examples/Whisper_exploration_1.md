---
title: Whisper Exploration Example
linkTitle: Whisper Exploration
weight: 20
---

How do we move forward when the Advisor doesn't provide a lot of help?  We'll start with an example
taken from Whisper.cpp's main routine.

```cpp
pFVar26 = local_460;
vsetivli_e64m1tama(2);
local_700 = (FILE *)local_c0._40_8_;
local_6f8 = pFVar34->_IO_read_ptr;
auVar45 = vle64_v(avStack_470);
vmv_v_i(in_v4,0);
auVar46 = vle64_v(&local_700);
vse64_v(in_v4,avStack_470);
auVar47 = vslidedown_vi(auVar45,1);
auVar46 = vslidedown_vi(auVar46,1);
local_4e0 = (FILE *)vmv_x_s(auVar46);
auVar46 = vle64_v(&local_700);
pcVar20 = (char *)vmv_x_s(auVar47);
local_4d8 = local_88;
local_c0._40_8_ = vmv_x_s(auVar45);
pFVar34->_IO_read_ptr = pcVar20;
local_4e8 = (FILE *)vmv_x_s(auVar46);
local_460 = (FILE *)0x0;
local_88 = pFVar26;
std::vector<>::~vector((vector<> *)&local_4e8);
std::vector<>::~vector(avStack_470);
std::_Rb_tree<>::_M_erase((_Rb_tree_node *)local_490);
```

This clearly isn't a loop.  Instead it is some sort of initialization sequence that allows
vector instructions to slightly optimize the code.  The advisor results aren't very helpful:

```text
Signatures:

    Vector length set to = 0x2
    Element width is = 64 bits
    Vector load: vle64.v
    Vector load: vle64.v
    Vector store: vse64.v
    Vector integer slidedown: vslidedown.vi
    Vector integer slidedown: vslidedown.vi
    Vector load: vle64.v
    Significant operations, in the order they appear:
        vsetivli,vle64.v,vmv.v.i,vle64.v,vse64.v,vslidedown.vi,vslidedown.vi,vmv.x.s,vle64.v,vmv.x.s,vmv.x.s,vmv.x.s
    Significant operations, in alphanumeric order:
        vle64.v,vle64.v,vle64.v,vmv.v.i,vmv.x.s,vmv.x.s,vmv.x.s,vmv.x.s,vse64.v,vsetivli,vslidedown.vi,vslidedown.vi

Similarity Analysis

Compare the clipped example to the database of vectorized examples.

The best match is id=1889 [0.652]= vmv.v.i,vmv.x.s,vmv.x.s,vmv.x.s,vse8.v,vsetivli,vsetivli,vsetivli,vsetvli

The clip is similar to the reference example data/custom_testsuite/builtins/string_rv64gcv:bzero_15

```

This suggests several Advisor improvements:

* explicitly report that no loops are found, and that the stanza is likely a vector optimization of
  scalar instruction transforms.
* add a quick explanation of what vslidedown.vi does
* the vmv instructions need annotation, especially any that load constants into registers.

A manual analysis suggests that the vector instructions manipulate pairs of 64 bit pointers,
variously copying them, zeroing them, or copying first or second elements of the pair into
scalar registers.  That probably means we want simple C++ vector manipulation functions in our
set of custom patterns.
