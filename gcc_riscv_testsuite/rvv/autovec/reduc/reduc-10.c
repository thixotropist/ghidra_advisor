/* { dg-do compile } */
/* { dg-additional-options "-march=rv32gcv_zvfh -mabi=ilp32d -mrvv-vector-bits=scalable --param vect-epilogues-nomask=0 -fno-signaling-nans" } */

#include <stdint-gcc.h>

#define DEF_REDUC_FMAXMIN(TYPE, NAME, MAXMIN_OP)                               \
  TYPE __attribute__ ((noinline, noclone))                                     \
  reduc_##NAME##_##TYPE (TYPE *a, int n)                                       \
  {                                                                            \
    TYPE r = -0.0;                                                              \
    for (int i = 0; i < n; ++i)                                                \
      r = MAXMIN_OP (r, a[i]);                                                 \
    return r;                                                                  \
  }

#define TEST_FMAXMIN(T)                                                        \
  T (float, max, __builtin_fmaxf)                                              \
  T (double, max, __builtin_fmax)                                              \
  T (float, min, __builtin_fminf)                                              \
  T (double, min, __builtin_fmin)


TEST_FMAXMIN (DEF_REDUC_FMAXMIN)

/* { dg-final { scan-assembler-times {vfredmax\.vs\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+} 2 } } */
/* { dg-final { scan-assembler-times {vfredmin\.vs\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+} 2 } } */
