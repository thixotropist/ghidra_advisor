        000a9524 57 78 08 0c     vsetvli                        a6,a6,e8,m1,ta,ma  
        000a9528 63 5b a7 06     bge                            a4,a0,LAB_000a959e
        000a952c 57 70 08 0d     vsetvli                        zero,a6,e32,m1,ta,ma 
        000a9530 d7 32 00 5e     vmv.v.i                        v5,0x0
        000a9534 53 07 00 f0     fmv.w.x                        fa4,zero
        000a9538 89 06           c.addi                         a3,0x2
        000a953a 89 07           c.addi                         a5,0x2
        000a953c 01 45           c.li                           a0,0x0
        000a953e 97 98 06 00     auipc                          a7,0x69
        000a9542 83 b8 28 52     ld                             a7,0x522(a7=>->ggml_table_f32_f16)               = 00119408
                             LAB_000a9546                                    XREF[1]:     000a9594(j)  
        000a9546 57 70 08 0c     vsetvli                        zero,a6,e8,m1,ta,ma  
        000a954a 07 82 06 02     vle8.v                         v4,(a3)
        000a954e 87 80 07 02     vle8.v                         v1,(a5)
        000a9552 03 d6 e7 ff     lhu                            a2,-0x2(a5)
        000a9556 03 d7 e6 ff     lhu                            a4,-0x2(a3)
        000a955a 05 25           c.addiw                        a0,0x1
        000a955c 0a 06           c.slli                         a2,0x2
        000a955e 0a 07           c.slli                         a4,0x2
        000a9560 57 a1 40 ee     vwmul.vv                       v2,v4,v1
        000a9564 57 70 90 0c     vsetvli                        zero,zero,e16,m2,ta,ma 
        000a9568 46 97           c.add                          a4,a7
        000a956a 46 96           c.add                          a2,a7
        000a956c 57 81 22 c6     vwredsum.vs                    v2,v2,v5
        000a9570 87 26 07 00     flw                            fa3,0x0(a4=>ggml_table_f32_f16)                  = ??
        000a9574 87 27 06 00     flw                            fa5,0x0(a2=>ggml_table_f32_f16)                  = ??
        000a9578 57 70 00 cd     vsetivli                       zero,0x0,e32,m1,ta,ma 
        000a957c 93 87 27 02     addi                           a5,a5,0x22
        000a9580 d3 f7 d7 10     fmul.s                         fa5,fa5,fa3,dyn
        000a9584 93 86 26 02     addi                           a3,a3,0x22
        000a9588 57 27 20 42     vmv.x.s                        a4,v2
        000a958c d3 76 07 d0     fcvt.s.w                       fa3,a4,dyn
        000a9590 43 f7 f6 70     fmadd.s                        fa4,fa3,fa5,fa4,dyn
        000a9594 e3 49 65 fa     blt                            a0,t1,LAB_000a9546
