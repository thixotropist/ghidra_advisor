---
title: Advisor Dependencies
linkTitle: Dependencies
weight: 10
---

## Ghidra

* Ghidra 11.3_DEV with the RISCV-64 [isa_ext](https://github.com/thixotropist/ghidra/tree/isa_ext) branch.
Without this branch Ghidra is stuck with a never-ratified older version of RISCV support.

## Bazel

* [Bazel 7.4](https://github.com/bazelbuild/bazel/releases)

Bazel builds in this workspace generate output in the temporary directory `/run/user/1000/bazel`, as specified in `.bazelrc`.
This override can be changed or removed. 

## Toolchain

* [binutils 2.42.50](https://sourceware.org/git/binutils-gdb)
* [gcc 15.0](https://gcc.gnu.org/git/gcc)
* glibc developmental version 2.39.9000
* sysroot - a stripped down linux sysroot derived from the sysroot bootstrap in
  [riscv-gnu-toolchain](https://github.com/riscv-collab/riscv-gnu-toolchain)

The toolchain is packaged locally as a Bazel module named `gcc_riscv_suite`, version 15.0.0.
This module depends on a second module, `fedora_syslibs` version 40.0.0.  These are served out of a local
Bazel module repository.
The `gcc_riscv_suite` and `fedora_syslibs` modules wrap a 42 MB and 4.0 MB tarball, respectively.

## Emulators

Two qemu emulators are used, both built from source shortly after the 9.0.50 release.
* `qemu-riscv64` provides user space emulation, which is very useful for exploring the behavior of
  particularly confusing assembly code sequences.
* `qemu-system-riscv64` provides full RISCV-64 VM hosting.  This is more narrowly useful when testing
  binaries like DPDK which require non-standard kernel options or kernel modules.
    * The RISCV-64 VM used here is based on an Ubuntu 24.04 disk image and the `u-boot.bin` boot loader.
      This boot loader is critical for RISCV VMs, since the emulated BIOS firmware provides the kernel
      with the definitive set of RISCV extensions available to the hardware threads (aka harts)

## Jupyter

* jupyterlab 4.1.1

## System

* Fedora 40 with wayland graphics.
* Python 3