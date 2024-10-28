#0 "gcc_riscv_testsuite/rvv/autovec/gather-scatter/scatter_store_64-1.c"
#0 "<built-in>"
#0 "<command-line>"
#1 "external/gcc_riscv_suite~/usr/include/stdc-predef.h" 1 3 4
#0 "<command-line>" 2
#1 "gcc_riscv_testsuite/rvv/autovec/gather-scatter/scatter_store_64-1.c"



#1 "/run/user/1000/bazel/external/gcc_riscv_suite~/bin/../lib/gcc/riscv64-unknown-linux-gnu/15.0.0/include/stdint-gcc.h" 1 3 4
#34 "/run/user/1000/bazel/external/gcc_riscv_suite~/bin/../lib/gcc/riscv64-unknown-linux-gnu/15.0.0/include/stdint-gcc.h" 3 4

#34 "/run/user/1000/bazel/external/gcc_riscv_suite~/bin/../lib/gcc/riscv64-unknown-linux-gnu/15.0.0/include/stdint-gcc.h" 3 4
typedef signed char int8_t;


typedef short int int16_t;


typedef int int32_t;


typedef long int int64_t;


typedef unsigned char uint8_t;


typedef short unsigned int uint16_t;


typedef unsigned int uint32_t;


typedef long unsigned int uint64_t;




typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;
typedef long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef short unsigned int uint_least16_t;
typedef unsigned int uint_least32_t;
typedef long unsigned int uint_least64_t;



typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef long unsigned int uint_fast16_t;
typedef long unsigned int uint_fast32_t;
typedef long unsigned int uint_fast64_t;




typedef long int intptr_t;


typedef long unsigned int uintptr_t;




typedef long int intmax_t;
typedef long unsigned int uintmax_t;
#5 "gcc_riscv_testsuite/rvv/autovec/gather-scatter/scatter_store_64-1.c" 2
#33 "gcc_riscv_testsuite/rvv/autovec/gather-scatter/scatter_store_64-1.c"

#33 "gcc_riscv_testsuite/rvv/autovec/gather-scatter/scatter_store_64-1.c"
void __attribute__((noinline, noclone)) f_int8_t (int8_t *restrict dest, int8_t *restrict src, uint8_t *restrict indices)
{
  for (int i = 0; i < 128; ++i)
    dest[indices[i]] = src[i] + 1;
} void __attribute__((noinline, noclone)) f_uint8_t (uint8_t *restrict dest, uint8_t *restrict src, uint8_t *restrict indices)
{
  for (int i = 0; i < 128; ++i)
    dest[indices[i]] = src[i] + 1;
} void __attribute__((noinline, noclone)) f_int16_t (int16_t *restrict dest, int16_t *restrict src, uint16_t *restrict indices)
{
  for (int i = 0; i < 128; ++i)
    dest[indices[i]] = src[i] + 1;
} void __attribute__((noinline, noclone)) f_uint16_t (uint16_t *restrict dest, uint16_t *restrict src, uint16_t *restrict indices)
{
  for (int i = 0; i < 128; ++i)
    dest[indices[i]] = src[i] + 1;
} void __attribute__((noinline, noclone)) f__Float16 (_Float16 *restrict dest, _Float16 *restrict src, uint16_t *restrict indices)
{
  for (int i = 0; i < 128; ++i)
    dest[indices[i]] = src[i] + 1;
} void __attribute__((noinline, noclone)) f_int32_t (int32_t *restrict dest, int32_t *restrict src, uint32_t *restrict indices)
{
  for (int i = 0; i < 128; ++i)
    dest[indices[i]] = src[i] + 1;
} void __attribute__((noinline, noclone)) f_uint32_t (uint32_t *restrict dest, uint32_t *restrict src, uint32_t *restrict indices)
{
  for (int i = 0; i < 128; ++i)
    dest[indices[i]] = src[i] + 1;
} void __attribute__((noinline, noclone)) f_float (float *restrict dest, float *restrict src, uint32_t *restrict indices)
{
  for (int i = 0; i < 128; ++i)
    dest[indices[i]] = src[i] + 1;
} void __attribute__((noinline, noclone)) f_int64_t (int64_t *restrict dest, int64_t *restrict src, uint64_t *restrict indices)
{
  for (int i = 0; i < 128; ++i)
    dest[indices[i]] = src[i] + 1;
} void __attribute__((noinline, noclone)) f_uint64_t (uint64_t *restrict dest, uint64_t *restrict src, uint64_t *restrict indices)
{
  for (int i = 0; i < 128; ++i)
    dest[indices[i]] = src[i] + 1;
} void __attribute__((noinline, noclone)) f_double (double *restrict dest, double *restrict src, uint64_t *restrict indices)
{
  for (int i = 0; i < 128; ++i)
    dest[indices[i]] = src[i] + 1;
}
