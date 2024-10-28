#0 "gcc_riscv_testsuite/rvv/autovec/builtin/strcmp.c"
#0 "<built-in>"
#0 "<command-line>"
#1 "external/gcc_riscv_suite~/usr/include/stdc-predef.h" 1 3 4
#0 "<command-line>" 2
#1 "gcc_riscv_testsuite/rvv/autovec/builtin/strcmp.c"



int __attribute__((noipa)) foo (const char *s, const char *t)
{
  return __builtin_strcmp (s, t);
}
