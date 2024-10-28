#!/usr/bin/python
"""
Collect RISCV-64 vector opcodes
"""

VECTOR_OPCODES = '''
vaaddu.vv
vaaddu.vx
vaadd.vv
vaadd.vx
vadc.vim
vadc.vvm
vadc.vxm
vadd.vi
vadd.vv
vadd.vx
vamoaddei16.v
vamoaddei32.v
vamoaddei64.v
vamoaddei8.v
vamoandei16.v
vamoandei32.v
vamoandei64.v
vamoandei8.v
vamomaxei16.v
vamomaxei32.v
vamomaxei64.v
vamomaxei8.v
vamomaxuei16.v
vamomaxuei32.v
vamomaxuei64.v
vamomaxuei8.v
vamominei16.v
vamominei32.v
vamominei64.v
vamominei8.v
vamominuei16.v
vamominuei32.v
vamominuei64.v
vamominuei8.v
vamoorei16.v
vamoorei32.v
vamoorei64.v
vamoorei8.v
vamoswapei16.v
vamoswapei32.v
vamoswapei64.v
vamoswapei8.v
vamoxorei16.v
vamoxorei32.v
vamoxorei64.v
vamoxorei8.v
vand.vi
vand.vv
vand.vx
vasubu.vv
vasubu.vx
vasub.vv
vasub.vx
vcompress.vm
vcpop.m
vdivu.vv
vdivu.vx
vdiv.vv
vdiv.vx
vdotu.vv
vdot.vv
vfadd.vf
vfadd.vv
vfclass.v
vfcvt.f.xu.v
vfcvt.f.x.v
vfcvt.rtz.x.f.v
vfcvt.rtz.xu.f.v
vfcvt.x.f.v
vfcvt.xu.f.v
vfdiv.vf
vfdiv.vv
vfdot.vv
vfirst.m
vfmacc.vf
vfmacc.vv
vfmadd.vf
vfmadd.vv
vfmax.vf
vfmax.vv
vfmerge.vfm
vfmin.vf
vfmin.vv
vfmsac.vf
vfmsac.vv
vfmsub.vf
vfmsub.vv
vfmul.vf
vfmul.vv
vfmv.f.s
vfmv.s.f
vfmv.v.f
vfncvt.f.f.w
vfncvt.f.xu.w
vfncvt.f.x.w
vfncvt.rod.f.f.w
vfncvt.rtz.x.f.w
vfncvt.rtz.xu.f.w
vfncvt.x.f.w
vfncvt.xu.f.w
vfnmacc.vf
vfnmacc.vv
vfnmadd.vf
vfnmadd.vv
vfnmsac.vf
vfnmsac.vv
vfnmsub.vf
vfnmsub.vv
vfrdiv.vf
vfrec7.v
vfredmax.vs
vfredmin.vs
vfredosum.vs
vfredusum.vs
vfrsqrt7.v
vfrsub.vf
vfsgnjn.vf
vfsgnjn.vv
vfsgnj.vf
vfsgnj.vv
vfsgnjx.vf
vfsgnjx.vv
vfslide1down.vf
vfslide1up.vf
vfsqrt.v
vfsub.vf
vfsub.vv
vfwadd.vf
vfwadd.vv
vfwadd.wf
vfwadd.wv
vfwcvt.f.f.v
vfwcvt.f.xu.v
vfwcvt.f.x.v
vfwcvt.rtz.x.f.v
vfwcvt.rtz.xu.f.v
vfwcvt.x.f.v
vfwcvt.xu.f.v
vfwmacc.vf
vfwmacc.vv
vfwmsac.vf
vfwmsac.vv
vfwmul.vf
vfwmul.vv
vfwnmacc.vf
vfwnmacc.vv
vfwnmsac.vf
vfwnmsac.vv
vfwredosum.vs
vfwredusum.vs
vfwsub.vf
vfwsub.vv
vfwsub.wf
vfwsub.wv
vid.v
viota.m
vl1re16.v
vl1re32.v
vl1re64.v
vl1r.v
vl2re16.v
vl2re32.v
vl2re64.v
vl2r.v
vl4re16.v
vl4re32.v
vl4re64.v
vl4r.v
vl8re16.v
vl8re32.v
vl8re64.v
vl8r.v
vle1024ff.v
vle1024.v
vle128ff.v
vle128.v
vle16ff.v
vle16.v
vle256ff.v
vle256.v
vle32ff.v
vle32.v
vle512ff.v
vle512.v
vle64ff.v
vle64.v
vle8ff.v
vle8.v
vlm.v
vloxei16.v
vloxei32.v
vloxei64.v
vloxei8.v
vloxseg2ei16.v
vloxseg2ei32.v
vloxseg2ei64.v
vloxseg2ei8.v
vloxseg3ei16.v
vloxseg3ei32.v
vloxseg3ei64.v
vloxseg3ei8.v
vloxseg4ei16.v
vloxseg4ei32.v
vloxseg4ei64.v
vloxseg4ei8.v
vloxseg5ei16.v
vloxseg5ei32.v
vloxseg5ei64.v
vloxseg5ei8.v
vloxseg6ei16.v
vloxseg6ei32.v
vloxseg6ei64.v
vloxseg6ei8.v
vloxseg7ei16.v
vloxseg7ei32.v
vloxseg7ei64.v
vloxseg7ei8.v
vloxseg8ei16.v
vloxseg8ei32.v
vloxseg8ei64.v
vloxseg8ei8.v
vlse1024.v
vlse128.v
vlse16.v
vlse256.v
vlse32.v
vlse512.v
vlse64.v
vlse8.v
vlseg2e1024.v
vlseg2e128.v
vlseg2e16ff.v
vlseg2e16.v
vlseg2e256ff.v
vlseg2e256.v
vlseg2e32ff.v
vlseg2e32.v
vlseg2e512ff.v
vlseg2e512.v
vlseg2e64ff.v
vlseg2e64.v
vlseg2e8ff.v
vlseg2e8.v
vlseg3e1024.v
vlseg3e128.v
vlseg3e16ff.v
vlseg3e16.v
vlseg3e256ff.v
vlseg3e256.v
vlseg3e32ff.v
vlseg3e32.v
vlseg3e512ff.v
vlseg3e512.v
vlseg3e64ff.v
vlseg3e64.v
vlseg3e8ff.v
vlseg3e8.v
vlseg4e1024.v
vlseg4e128.v
vlseg4e16ff.v
vlseg4e16.v
vlseg4e256ff.v
vlseg4e256.v
vlseg4e32ff.v
vlseg4e32.v
vlseg4e512ff.v
vlseg4e512.v
vlseg4e64ff.v
vlseg4e64.v
vlseg4e8ff.v
vlseg4e8.v
vlseg5e1024.v
vlseg5e128.v
vlseg5e16ff.v
vlseg5e16.v
vlseg5e256ff.v
vlseg5e256.v
vlseg5e32ff.v
vlseg5e32.v
vlseg5e512ff.v
vlseg5e512.v
vlseg5e64ff.v
vlseg5e64.v
vlseg5e8ff.v
vlseg5e8.v
vlseg6e1024.v
vlseg6e128.v
vlseg6e16ff.v
vlseg6e16.v
vlseg6e256ff.v
vlseg6e256.v
vlseg6e32ff.v
vlseg6e32.v
vlseg6e512ff.v
vlseg6e512.v
vlseg6e64ff.v
vlseg6e64.v
vlseg6e8ff.v
vlseg6e8.v
vlseg7e1024.v
vlseg7e128.v
vlseg7e16ff.v
vlseg7e16.v
vlseg7e256ff.v
vlseg7e256.v
vlseg7e32ff.v
vlseg7e32.v
vlseg7e512ff.v
vlseg7e512.v
vlseg7e64ff.v
vlseg7e64.v
vlseg7e8ff.v
vlseg7e8.v
vlseg8e1024.v
vlseg8e128.v
vlseg8e16ff.v
vlseg8e16.v
vlseg8e256ff.v
vlseg8e256.v
vlseg8e32ff.v
vlseg8e32.v
vlseg8e512ff.v
vlseg8e512.v
vlseg8e64ff.v
vlseg8e64.v
vlseg8e8ff.v
vlseg8e8.v
vlsseg2e1024.v
vlsseg2e128.v
vlsseg2e16.v
vlsseg2e256.v
vlsseg2e32.v
vlsseg2e512.v
vlsseg2e64.v
vlsseg2e8.v
vlsseg3e1024.v
vlsseg3e128.v
vlsseg3e16.v
vlsseg3e256.v
vlsseg3e32.v
vlsseg3e512.v
vlsseg3e64.v
vlsseg3e8.v
vlsseg4e1024.v
vlsseg4e128.v
vlsseg4e16.v
vlsseg4e256.v
vlsseg4e32.v
vlsseg4e512.v
vlsseg4e64.v
vlsseg4e8.v
vlsseg5e1024.v
vlsseg5e128.v
vlsseg5e16.v
vlsseg5e256.v
vlsseg5e32.v
vlsseg5e512.v
vlsseg5e64.v
vlsseg5e8.v
vlsseg6e1024.v
vlsseg6e128.v
vlsseg6e16.v
vlsseg6e256.v
vlsseg6e32.v
vlsseg6e512.v
vlsseg6e64.v
vlsseg6e8.v
vlsseg7e1024.v
vlsseg7e128.v
vlsseg7e16.v
vlsseg7e256.v
vlsseg7e32.v
vlsseg7e512.v
vlsseg7e64.v
vlsseg7e8.v
vlsseg8e1024.v
vlsseg8e128.v
vlsseg8e16.v
vlsseg8e256.v
vlsseg8e32.v
vlsseg8e512.v
vlsseg8e64.v
vlsseg8e8.v
vluxei16.v
vluxei32.v
vluxei64.v
vluxei8.v
vluxseg2ei16.v
vluxseg2ei32.v
vluxseg2ei64.v
vluxseg2ei8.v
vluxseg3ei16.v
vluxseg3ei32.v
vluxseg3ei64.v
vluxseg3ei8.v
vluxseg4ei16.v
vluxseg4ei32.v
vluxseg4ei64.v
vluxseg4ei8.v
vluxseg5ei16.v
vluxseg5ei32.v
vluxseg5ei64.v
vluxseg5ei8.v
vluxseg6ei16.v
vluxseg6ei32.v
vluxseg6ei64.v
vluxseg6ei8.v
vluxseg7ei16.v
vluxseg7ei32.v
vluxseg7ei64.v
vluxseg7ei8.v
vluxseg8ei16.v
vluxseg8ei32.v
vluxseg8ei64.v
vluxseg8ei8.v
vlxei1024.v
vlxei128.v
vlxei16.v
vlxei256.v
vlxei32.v
vlxei512.v
vlxei64.v
vlxei8.v
vmacc.vv
vmacc.vx
vmadc.vi
vmadc.vim
vmadc.vv
vmadc.vvm
vmadc.vx
vmadc.vxm
vmadd.vv
vmadd.vx
vmand.mm
vmandn.mm
vmaxu.vv
vmaxu.vx
vmax.vv
vmax.vx
vmerge.vim
vmerge.vvm
vmerge.vxm
vmfeq.vf
vmfeq.vv
vmfge.vf
vmfgt.vf
vmfle.vf
vmfle.vv
vmflt.vf
vmflt.vv
vmfne.vf
vmfne.vv
vminu.vv
vminu.vx
vmin.vv
vmin.vx
vmnand.mm
vmnor.mm
vmor.mm
vmorn.mm
vmsbc.vv
vmsbc.vvm
vmsbc.vx
vmsbc.vxm
vmsbf.m
vmseq.vi
vmseq.vv
vmseq.vx
vmsgtu.vi
vmsgtu.vx
vmsgt.vi
vmsgt.vx
vmsif.m
vmsleu.vi
vmsleu.vv
vmsleu.vx
vmsle.vi
vmsle.vv
vmsle.vx
vmsltu.vv
vmsltu.vx
vmslt.vv
vmslt.vx
vmsne.vi
vmsne.vv
vmsne.vx
vmsof.m
vmulhsu.vv
vmulhsu.vx
vmulhu.vv
vmulhu.vx
vmulh.vv
vmulh.vx
vmul.vv
vmul.vx
vmv1r.v
vmv2r.v
vmv4r.v
vmv8r.v
vmv.s.x
vmv.v.i
vmv.v.v
vmv.v.x
vmv.x.s
vmxnor.mm
vmxor.mm
vnclipu.wi
vnclipu.wv
vnclipu.wx
vnclip.wi
vnclip.wv
vnclip.wx
vncvt.x.x.w
vneg.v
vnmsac.vv
vnmsac.vx
vnmsub.vv
vnmsub.vx
vnot.v
vnsra.wi
vnsra.wv
vnsra.wx
vnsrl.wi
vnsrl.wv
vnsrl.wx
vor.vi
vor.vv
vor.vx
vqmaccsu.vv
vqmaccsu.vx
vqmaccus.vx
vqmaccu.vv
vqmaccu.vx
vqmacc.vv
vqmacc.vx
vredand.vs
vredmaxu.vs
vredmax.vs
vredminu.vs
vredmin.vs
vredor.vs
vredsum.vs
vredxor.vs
vremu.vv
vremu.vx
vrem.vv
vrem.vx
vrgatherei16.vv
vrgather.vi
vrgather.vv
vrgather.vx
vrsub.vi
vrsub.vx
vs1r.v
vs2r.v
vs4r.v
vs8r.v
vsaddu.vi
vsaddu.vv
vsaddu.vx
vsadd.vi
vsadd.vv
vsadd.vx
vsbc.vvm
vsbc.vxm
vse1024.v
vse128.v
vse16.v
vse256.v
vse32.v
vse512.v
vse64.v
vse8.v
vsetivli
vsetvl
vsetvli
vsext.vf2
vsext.vf4
vsext.vf8
vslide1down.vx
vslide1up.vx
vslidedown.vi
vslidedown.vx
vslideup.vi
vslideup.vx
vsll.vi
vsll.vv
vsll.vx
vsmul.vv
vsmul.vx
vsm.v
vsoxei1024.v
vsoxei128.v
vsoxei16.v
vsoxei256.v
vsoxei32.v
vsoxei512.v
vsoxei64.v
vsoxei8.v
vsoxseg2ei1024.v
vsoxseg2ei128.v
vsoxseg2ei16.v
vsoxseg2ei256.v
vsoxseg2ei32.v
vsoxseg2ei512.v
vsoxseg2ei64.v
vsoxseg2ei8.v
vsoxseg3ei1024.v
vsoxseg3ei128.v
vsoxseg3ei16.v
vsoxseg3ei256.v
vsoxseg3ei32.v
vsoxseg3ei512.v
vsoxseg3ei64.v
vsoxseg3ei8.v
vsoxseg4ei1024.v
vsoxseg4ei128.v
vsoxseg4ei16.v
vsoxseg4ei256.v
vsoxseg4ei32.v
vsoxseg4ei512.v
vsoxseg4ei64.v
vsoxseg4ei8.v
vsoxseg5ei1024.v
vsoxseg5ei128.v
vsoxseg5ei16.v
vsoxseg5ei256.v
vsoxseg5ei32.v
vsoxseg5ei512.v
vsoxseg5ei64.v
vsoxseg5ei8.v
vsoxseg6ei1024.v
vsoxseg6ei128.v
vsoxseg6ei16.v
vsoxseg6ei256.v
vsoxseg6ei32.v
vsoxseg6ei512.v
vsoxseg6ei64.v
vsoxseg6ei8.v
vsoxseg7ei1024.v
vsoxseg7ei128.v
vsoxseg7ei16.v
vsoxseg7ei256.v
vsoxseg7ei32.v
vsoxseg7ei512.v
vsoxseg7ei64.v
vsoxseg7ei8.v
vsoxseg8ei1024.v
vsoxseg8ei128.v
vsoxseg8ei16.v
vsoxseg8ei256.v
vsoxseg8ei32.v
vsoxseg8ei512.v
vsoxseg8ei64.v
vsoxseg8ei8.v
vsra.vi
vsra.vv
vsra.vx
vsrl.vi
vsrl.vv
vsrl.vx
vsse1024.v
vsse128.v
vsse16.v
vsse256.v
vsse32.v
vsse512.v
vsse64.v
vsse8.v
vsseg2e1024.v
vsseg2e128.v
vsseg2e16.v
vsseg2e256.v
vsseg2e32.v
vsseg2e512.v
vsseg2e64.v
vsseg2e8.v
vsseg3e1024.v
vsseg3e128.v
vsseg3e16.v
vsseg3e256.v
vsseg3e32.v
vsseg3e512.v
vsseg3e64.v
vsseg3e8.v
vsseg4e1024.v
vsseg4e128.v
vsseg4e16.v
vsseg4e256.v
vsseg4e32.v
vsseg4e512.v
vsseg4e64.v
vsseg4e8.v
vsseg5e1024.v
vsseg5e128.v
vsseg5e16.v
vsseg5e256.v
vsseg5e32.v
vsseg5e512.v
vsseg5e64.v
vsseg5e8.v
vsseg6e1024.v
vsseg6e128.v
vsseg6e16.v
vsseg6e256.v
vsseg6e32.v
vsseg6e512.v
vsseg6e64.v
vsseg6e8.v
vsseg7e1024.v
vsseg7e128.v
vsseg7e16.v
vsseg7e256.v
vsseg7e32.v
vsseg7e512.v
vsseg7e64.v
vsseg7e8.v
vsseg8e1024.v
vsseg8e128.v
vsseg8e16.v
vsseg8e256.v
vsseg8e32.v
vsseg8e512.v
vsseg8e64.v
vsseg8e8.v
vssra.vi
vssra.vv
vssra.vx
vssrl.vi
vssrl.vv
vssrl.vx
vssseg2e1024.v
vssseg2e128.v
vssseg2e16.v
vssseg2e256.v
vssseg2e32.v
vssseg2e512.v
vssseg2e64.v
vssseg2e8.v
vssseg3e1024.v
vssseg3e128.v
vssseg3e16.v
vssseg3e256.v
vssseg3e32.v
vssseg3e512.v
vssseg3e64.v
vssseg3e8.v
vssseg4e1024.v
vssseg4e128.v
vssseg4e16.v
vssseg4e256.v
vssseg4e32.v
vssseg4e512.v
vssseg4e64.v
vssseg4e8.v
vssseg5e1024.v
vssseg5e128.v
vssseg5e16.v
vssseg5e256.v
vssseg5e32.v
vssseg5e512.v
vssseg5e64.v
vssseg5e8.v
vssseg6e1024.v
vssseg6e128.v
vssseg6e16.v
vssseg6e256.v
vssseg6e32.v
vssseg6e512.v
vssseg6e64.v
vssseg6e8.v
vssseg7e1024.v
vssseg7e128.v
vssseg7e16.v
vssseg7e256.v
vssseg7e32.v
vssseg7e512.v
vssseg7e64.v
vssseg7e8.v
vssseg8e1024.v
vssseg8e128.v
vssseg8e16.v
vssseg8e256.v
vssseg8e32.v
vssseg8e512.v
vssseg8e64.v
vssseg8e8.v
vssubu.vv
vssubu.vx
vssub.vv
vssub.vx
vsub.vv
vsub.vx
vsuxei1024.v
vsuxei128.v
vsuxei16.v
vsuxei256.v
vsuxei32.v
vsuxei512.v
vsuxei64.v
vsuxei8.v
vsuxseg2ei1024.v
vsuxseg2ei128.v
vsuxseg2ei16.v
vsuxseg2ei256.v
vsuxseg2ei32.v
vsuxseg2ei512.v
vsuxseg2ei64.v
vsuxseg2ei8.v
vsuxseg3ei1024.v
vsuxseg3ei128.v
vsuxseg3ei16.v
vsuxseg3ei256.v
vsuxseg3ei32.v
vsuxseg3ei512.v
vsuxseg3ei64.v
vsuxseg3ei8.v
vsuxseg4ei1024.v
vsuxseg4ei128.v
vsuxseg4ei16.v
vsuxseg4ei256.v
vsuxseg4ei32.v
vsuxseg4ei512.v
vsuxseg4ei64.v
vsuxseg4ei8.v
vsuxseg5ei1024.v
vsuxseg5ei128.v
vsuxseg5ei16.v
vsuxseg5ei256.v
vsuxseg5ei32.v
vsuxseg5ei512.v
vsuxseg5ei64.v
vsuxseg5ei8.v
vsuxseg6ei1024.v
vsuxseg6ei128.v
vsuxseg6ei16.v
vsuxseg6ei256.v
vsuxseg6ei32.v
vsuxseg6ei512.v
vsuxseg6ei64.v
vsuxseg6ei8.v
vsuxseg7ei1024.v
vsuxseg7ei128.v
vsuxseg7ei16.v
vsuxseg7ei256.v
vsuxseg7ei32.v
vsuxseg7ei512.v
vsuxseg7ei64.v
vsuxseg7ei8.v
vsuxseg8ei1024.v
vsuxseg8ei128.v
vsuxseg8ei16.v
vsuxseg8ei256.v
vsuxseg8ei32.v
vsuxseg8ei512.v
vsuxseg8ei64.v
vsuxseg8ei8.v
vwaddu.vv
vwaddu.vx
vwaddu.wv
vwaddu.wx
vwadd.vv
vwadd.vx
vwadd.wv
vwadd.wx
vwcvtu.x.x.v
vwcvt.x.x.v
vwmaccsu.vv
vwmaccsu.vx
vwmaccus.vx
vwmaccu.vv
vwmaccu.vx
vwmacc.vv
vwmacc.vx
vwmulsu.vv
vwmulsu.vx
vwmulu.vv
vwmulu.vx
vwmul.vv
vwmul.vx
vwredsumu.vs
vwredsum.vs
vwsubu.vv
vwsubu.vx
vwsubu.wv
vwsubu.wx
vwsub.vv
vwsub.vx
vwsub.wv
vwsub.wx
vxor.vi
vxor.vv
vxor.vx
vzext.vf2
vzext.vf4
vzext.vf8
'''.split()

# Conditional branch opcodes include pseudoinstructions that may be
# generated by objdump
CONDITIONAL_BRANCH_OPCODES = '''
beq
bne
blt
bge
bltu
bgeu
bgt
ble
bgtu
bleu
beqz
bnez
blez
bgez
bltz
bgtz
c.beqz
c.bnez
'''.split()

REDUCTION_OPCODES = '''
vfredmax.vs
vfredmin.vs
vfredosum.vs
vfredusum.vs
vfwredosum.vs
vfwredusum.vs
vredand.vs
vredmaxu.vs
vredmax.vs
vredminu.vs
vredmin.vs
vredor.vs
vredsum.vs
vredxor.vs
vwredsumu.vs
vwredsum.vs
'''