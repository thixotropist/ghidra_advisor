0000000000001150 <reduc_plus_int8_t>:
    1150:       04b05a63                blez    a1,11a4 <reduc_plus_int8_t+0x54>
    1154:       0c0077d7                vsetvli a5,zero,e8,m1,ta,ma
    1158:       5e003157                vmv.v.i v2,0
    115c:       c2202773                csrr    a4,vlenb
    1160:       40e00633                neg     a2,a4
    1164:       3a2060d7                vslide1up.vx    v1,v2,zero
    1168:       86ae                    mv      a3,a1
    116a:       87ae                    mv      a5,a1
    116c:       00b77463                bgeu    a4,a1,1174 <reduc_plus_int8_t+0x24>
    1170:       c22027f3                csrr    a5,vlenb
    1174:       0807f057                vsetvli zero,a5,e8,m1,tu,ma
    1178:       02050107                vle8.v  v2,(a0)
    117c:       95b2                    add     a1,a1,a2
    117e:       953a                    add     a0,a0,a4
    1180:       021100d7                vadd.vv v1,v1,v2
    1184:       fed762e3                bltu    a4,a3,1168 <reduc_plus_int8_t+0x18>
    1188:       0c0077d7                vsetvli a5,zero,e8,m1,ta,ma
    118c:       4701                    li      a4,0
    118e:       42076157                vmv.s.x v2,a4
    1192:       021120d7                vredsum.vs      v1,v1,v2
    1196:       42102557                vmv.x.s a0,v1
    119a:       0185151b                slliw   a0,a0,0x18
    119e:       4185551b                sraiw   a0,a0,0x18
    11a2:       8082                    ret
    11a4:       4501                    li      a0,0
    11a6:       8082                    ret
