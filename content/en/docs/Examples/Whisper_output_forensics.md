---
title: Whisper Output Forensics
linkTitle: Whisper Output Forensics
weight: 101
---

You might expect Whisper to use a lot of vector instructions in its inference engine, and it definitely does.
Are vector instructions common enough to complicate Whisper forensic analysis, looking at functions an
adversary is likeliest to target?  For this example we will make a deep dive into the function `output_txt`,
since malicious code might want to review and alter dictated text.

This code also lets us examine how RISCV vector instructions are used to implement the `libstdc++` vector library functions.

```c++
const char * whisper_full_get_segment_text(struct whisper_context * ctx, int i_segment) {
    return ctx->state->result_all[i_segment].text.c_str();
}

static bool output_txt(struct whisper_context * ctx, const char * fname, const whisper_params & params, std::vector<std::vector<float>> pcmf32s) {
    std::ofstream fout(fname);
    if (!fout.is_open()) {
        fprintf(stderr, "%s: failed to open '%s' for writing\n", __func__, fname);
        return false;
    }
    fprintf(stderr, "%s: saving output to '%s'\n", __func__, fname);
    const int n_segments = whisper_full_n_segments(ctx);
    for (int i = 0; i < n_segments; ++i) {
        const char * text = whisper_full_get_segment_text(ctx, i);
        std::string speaker = "";
        if (params.diarize && pcmf32s.size() == 2)
        {
            const int64_t t0 = whisper_full_get_segment_t0(ctx, i);
            const int64_t t1 = whisper_full_get_segment_t1(ctx, i);
            speaker = estimate_diarization_speaker(pcmf32s, t0, t1);
        }
        fout << speaker << text << "\n";
    }
    return true;
}
```

The key elements of this function are:

* text is collected in segments and stored in the context variable `ctx`
* text segments are retrieved with the function `whisper_full_get_segment_text`
* text is copied into an output stream `fout`

The `params.diarize` code block matters only if voice is collected
in stereo and Whisper has been asked to differentiate between speakers.

The Ghidra decompiler shows four vector instruction sets starting with a `vset*` instruction.
The first of these is a simple initialization:

```c
vsetivli_e64m1tama(2);
vmv_v_i(in_v1,0);
vse64_v(in_v1,auStack_90);
vse64_v(in_v1,auStack_80);
```

These instructions initialize two adjacent 16 byte blocks of memory to zero.  These are likely
four 64 bit pointers or counters embedded within structures.

The next vector stanza is:

```c
vsetivli_e64m1tama(2);
lStack_2e0 = lStack_288;
uStack_2d8 = local_280[0];
auVar24 = vle64_v(&lStack_2e0);
auVar25 = vle64_v(&lStack_2e0);
auVar24 = vslidedown_vi(auVar24,1);
lStack_2a8 = vmv_x_s(auVar25);
local_2a0[0] = vmv_x_s(auVar24);
```

This one is puzzling, as it appears to load two 64 bit values twice, then store them into separate scalar registers.

The next stanza looks like a simple `memcpy` expansion:

```c
do {
    lVar18 = vsetvli_e8m8tama(lStack_288);
    auVar24 = vle8_v(puVar16);
    lStack_288 = lStack_288 - lVar18;
    puVar16 = (ulong *)((long)puVar16 + lVar18);
    vse8_v(auVar24,puVar20);
    puVar20 = (ulong *)((long)puVar20 + lVar18);
} while (lStack_288 != 0);
```

The final stanza is the interesting one:

```c
pcVar17 = text;
do {
    vsetvli_e8m1tama(0);
    pcVar17 = pcVar17 + lVar18;
    auVar24 = vle8ff_v(pcVar17);
    auVar24 = vmseq_vi(auVar24,0);
    lVar19 = vfirst_m(auVar24);
    lVar18 = in_vl;
    } while (lVar19 < 0);
std::__ostream_insert<>(pbVar12,text,(long)(pcVar17 + (lVar19 - (long)text)));
```

This appears to be a vector implementation of `strlen(text)` requested by `std::__ostream_insert<>`.

Our hypothetical adversary would want to evaluate `*text` and reset the `text` pointer to the maliciously altered output string.

The current Advisor classifies these four stanzas as:

* some sort of initializer
* some sort of shuffle
* `memcpy`
* `strlen`

A Ghidra user would likely ignore the initializer and the shuffle as doing something benign and obscure within the I/O subsystem,
recognize the `memcpy` and `strlen` for what they are, then concentrate on any unexpected manipulations of the `*text` string.
