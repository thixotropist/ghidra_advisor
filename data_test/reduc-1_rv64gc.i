#0 "external/_main~_repo_rules~gcc_riscv_testsuite/rvv/autovec/reduc/reduc-1.c"
#0 "<built-in>"
#0 "<command-line>"
#1 "external/gcc_riscv_suite~/usr/include/stdc-predef.h" 1 3 4
#0 "<command-line>" 2
#1 "external/_main~_repo_rules~gcc_riscv_testsuite/rvv/autovec/reduc/reduc-1.c"



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
#5 "external/_main~_repo_rules~gcc_riscv_testsuite/rvv/autovec/reduc/reduc-1.c" 2
#29 "external/_main~_repo_rules~gcc_riscv_testsuite/rvv/autovec/reduc/reduc-1.c"

#29 "external/_main~_repo_rules~gcc_riscv_testsuite/rvv/autovec/reduc/reduc-1.c"
int8_t __attribute__((noinline, noclone)) reduc_plus_int8_t (int8_t *a, int n)
{
  int8_t r = 0;
  for (int i = 0; i < n; ++i)
    r += a[i];
  return r;
}

int16_t __attribute__((noinline, noclone)) reduc_plus_int16_t (int16_t *a, int n)
{
  int16_t r = 0;
  for (int i = 0; i < n; ++i)
    r += a[i];
  return r;
}

int32_t __attribute__((noinline, noclone)) reduc_plus_int32_t (int32_t *a, int n)
{
  int32_t r = 0;
  for (int i = 0; i < n; ++i)
    r += a[i];
  return r;
}

int64_t __attribute__((noinline, noclone)) reduc_plus_int64_t (int64_t *a, int n)
{
  int64_t r = 0;
  for (int i = 0; i < n; ++i)
    r += a[i];
  return r;
}

uint8_t __attribute__((noinline, noclone)) reduc_plus_uint8_t (uint8_t *a, int n)
{
  uint8_t r = 0;
  for (int i = 0; i < n; ++i)
    r += a[i];
  return r;
}

uint16_t __attribute__((noinline, noclone)) reduc_plus_uint16_t (uint16_t *a, int n)
{
  uint16_t r = 0;
  for (int i = 0; i < n; ++i)
    r += a[i];
  return r;
}

uint32_t __attribute__((noinline, noclone)) reduc_plus_uint32_t (uint32_t *a, int n)
{
  uint32_t r = 0;
  for (int i = 0; i < n; ++i)
    r += a[i];
  return r;
}

uint64_t __attribute__((noinline, noclone)) reduc_plus_uint64_t (uint64_t *a, int n)
{
  uint64_t r = 0;
  for (int i = 0; i < n; ++i)
    r += a[i];
  return r;
}

_Float16 __attribute__((noinline, noclone)) reduc_plus__Float16 (_Float16 *a, int n)
{
  _Float16 r = 0;
  for (int i = 0; i < n; ++i)
    r += a[i];
  return r;
}

float __attribute__((noinline, noclone)) reduc_plus_float (float *a, int n)
{
  float r = 0;
  for (int i = 0; i < n; ++i)
    r += a[i];
  return r;
}

double __attribute__((noinline, noclone)) reduc_plus_double (double *a, int n)
{
  double r = 0;
  for (int i = 0; i < n; ++i)
    r += a[i];
  return r;
}

#66 "external/_main~_repo_rules~gcc_riscv_testsuite/rvv/autovec/reduc/reduc-1.c"
int8_t __attribute__((noinline, noclone)) reduc_max_int8_t (int8_t *a, int n)
{
  int8_t r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] > r ? a[i] : r;
  return r;
}

int16_t __attribute__((noinline, noclone)) reduc_max_int16_t (int16_t *a, int n)
{
  int16_t r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] > r ? a[i] : r;
  return r;
}

int32_t __attribute__((noinline, noclone)) reduc_max_int32_t (int32_t *a, int n)
{
  int32_t r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] > r ? a[i] : r;
  return r;
}

int64_t __attribute__((noinline, noclone)) reduc_max_int64_t (int64_t *a, int n)
{
  int64_t r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] > r ? a[i] : r;
  return r;
}

uint8_t __attribute__((noinline, noclone)) reduc_max_uint8_t (uint8_t *a, int n)
{
  uint8_t r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] > r ? a[i] : r;
  return r;
}

uint16_t __attribute__((noinline, noclone)) reduc_max_uint16_t (uint16_t *a, int n)
{
  uint16_t r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] > r ? a[i] : r;
  return r;
}

uint32_t __attribute__((noinline, noclone)) reduc_max_uint32_t (uint32_t *a, int n)
{
  uint32_t r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] > r ? a[i] : r;
  return r;
}

uint64_t __attribute__((noinline, noclone)) reduc_max_uint64_t (uint64_t *a, int n)
{
  uint64_t r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] > r ? a[i] : r;
  return r;
}

_Float16 __attribute__((noinline, noclone)) reduc_max__Float16 (_Float16 *a, int n)
{
  _Float16 r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] > r ? a[i] : r;
  return r;
}

float __attribute__((noinline, noclone)) reduc_max_float (float *a, int n)
{
  float r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] > r ? a[i] : r;
  return r;
}

double __attribute__((noinline, noclone)) reduc_max_double (double *a, int n)
{
  double r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] > r ? a[i] : r;
  return r;
}

int8_t __attribute__((noinline, noclone)) reduc_min_int8_t (int8_t *a, int n)
{
  int8_t r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] < r ? a[i] : r;
  return r;
}

int16_t __attribute__((noinline, noclone)) reduc_min_int16_t (int16_t *a, int n)
{
  int16_t r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] < r ? a[i] : r;
  return r;
}

int32_t __attribute__((noinline, noclone)) reduc_min_int32_t (int32_t *a, int n)
{
  int32_t r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] < r ? a[i] : r;
  return r;
}

int64_t __attribute__((noinline, noclone)) reduc_min_int64_t (int64_t *a, int n)
{
  int64_t r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] < r ? a[i] : r;
  return r;
}

uint8_t __attribute__((noinline, noclone)) reduc_min_uint8_t (uint8_t *a, int n)
{
  uint8_t r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] < r ? a[i] : r;
  return r;
}

uint16_t __attribute__((noinline, noclone)) reduc_min_uint16_t (uint16_t *a, int n)
{
  uint16_t r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] < r ? a[i] : r;
  return r;
}

uint32_t __attribute__((noinline, noclone)) reduc_min_uint32_t (uint32_t *a, int n)
{
  uint32_t r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] < r ? a[i] : r;
  return r;
}

uint64_t __attribute__((noinline, noclone)) reduc_min_uint64_t (uint64_t *a, int n)
{
  uint64_t r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] < r ? a[i] : r;
  return r;
}

_Float16 __attribute__((noinline, noclone)) reduc_min__Float16 (_Float16 *a, int n)
{
  _Float16 r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] < r ? a[i] : r;
  return r;
}

float __attribute__((noinline, noclone)) reduc_min_float (float *a, int n)
{
  float r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] < r ? a[i] : r;
  return r;
}

double __attribute__((noinline, noclone)) reduc_min_double (double *a, int n)
{
  double r = 13;
  for (int i = 0; i < n; ++i)
    r = a[i] < r ? a[i] : r;
  return r;
}

#106 "external/_main~_repo_rules~gcc_riscv_testsuite/rvv/autovec/reduc/reduc-1.c"
int8_t __attribute__((noinline, noclone)) reduc_and_int8_t (int8_t *a, int n)
{
  int8_t r = 13;
  for (int i = 0; i < n; ++i)
    r &= a[i];
  return r;
}

int16_t __attribute__((noinline, noclone)) reduc_and_int16_t (int16_t *a, int n)
{
  int16_t r = 13;
  for (int i = 0; i < n; ++i)
    r &= a[i];
  return r;
}

int32_t __attribute__((noinline, noclone)) reduc_and_int32_t (int32_t *a, int n)
{
  int32_t r = 13;
  for (int i = 0; i < n; ++i)
    r &= a[i];
  return r;
}

int64_t __attribute__((noinline, noclone)) reduc_and_int64_t (int64_t *a, int n)
{
  int64_t r = 13;
  for (int i = 0; i < n; ++i)
    r &= a[i];
  return r;
}

uint8_t __attribute__((noinline, noclone)) reduc_and_uint8_t (uint8_t *a, int n)
{
  uint8_t r = 13;
  for (int i = 0; i < n; ++i)
    r &= a[i];
  return r;
}

uint16_t __attribute__((noinline, noclone)) reduc_and_uint16_t (uint16_t *a, int n)
{
  uint16_t r = 13;
  for (int i = 0; i < n; ++i)
    r &= a[i];
  return r;
}

uint32_t __attribute__((noinline, noclone)) reduc_and_uint32_t (uint32_t *a, int n)
{
  uint32_t r = 13;
  for (int i = 0; i < n; ++i)
    r &= a[i];
  return r;
}

uint64_t __attribute__((noinline, noclone)) reduc_and_uint64_t (uint64_t *a, int n)
{
  uint64_t r = 13;
  for (int i = 0; i < n; ++i)
    r &= a[i];
  return r;
}

int8_t __attribute__((noinline, noclone)) reduc_ior_int8_t (int8_t *a, int n)
{
  int8_t r = 13;
  for (int i = 0; i < n; ++i)
    r |= a[i];
  return r;
}

int16_t __attribute__((noinline, noclone)) reduc_ior_int16_t (int16_t *a, int n)
{
  int16_t r = 13;
  for (int i = 0; i < n; ++i)
    r |= a[i];
  return r;
}

int32_t __attribute__((noinline, noclone)) reduc_ior_int32_t (int32_t *a, int n)
{
  int32_t r = 13;
  for (int i = 0; i < n; ++i)
    r |= a[i];
  return r;
}

int64_t __attribute__((noinline, noclone)) reduc_ior_int64_t (int64_t *a, int n)
{
  int64_t r = 13;
  for (int i = 0; i < n; ++i)
    r |= a[i];
  return r;
}

uint8_t __attribute__((noinline, noclone)) reduc_ior_uint8_t (uint8_t *a, int n)
{
  uint8_t r = 13;
  for (int i = 0; i < n; ++i)
    r |= a[i];
  return r;
}

uint16_t __attribute__((noinline, noclone)) reduc_ior_uint16_t (uint16_t *a, int n)
{
  uint16_t r = 13;
  for (int i = 0; i < n; ++i)
    r |= a[i];
  return r;
}

uint32_t __attribute__((noinline, noclone)) reduc_ior_uint32_t (uint32_t *a, int n)
{
  uint32_t r = 13;
  for (int i = 0; i < n; ++i)
    r |= a[i];
  return r;
}

uint64_t __attribute__((noinline, noclone)) reduc_ior_uint64_t (uint64_t *a, int n)
{
  uint64_t r = 13;
  for (int i = 0; i < n; ++i)
    r |= a[i];
  return r;
}

int8_t __attribute__((noinline, noclone)) reduc_xor_int8_t (int8_t *a, int n)
{
  int8_t r = 13;
  for (int i = 0; i < n; ++i)
    r ^= a[i];
  return r;
}

int16_t __attribute__((noinline, noclone)) reduc_xor_int16_t (int16_t *a, int n)
{
  int16_t r = 13;
  for (int i = 0; i < n; ++i)
    r ^= a[i];
  return r;
}

int32_t __attribute__((noinline, noclone)) reduc_xor_int32_t (int32_t *a, int n)
{
  int32_t r = 13;
  for (int i = 0; i < n; ++i)
    r ^= a[i];
  return r;
}

int64_t __attribute__((noinline, noclone)) reduc_xor_int64_t (int64_t *a, int n)
{
  int64_t r = 13;
  for (int i = 0; i < n; ++i)
    r ^= a[i];
  return r;
}

uint8_t __attribute__((noinline, noclone)) reduc_xor_uint8_t (uint8_t *a, int n)
{
  uint8_t r = 13;
  for (int i = 0; i < n; ++i)
    r ^= a[i];
  return r;
}

uint16_t __attribute__((noinline, noclone)) reduc_xor_uint16_t (uint16_t *a, int n)
{
  uint16_t r = 13;
  for (int i = 0; i < n; ++i)
    r ^= a[i];
  return r;
}

uint32_t __attribute__((noinline, noclone)) reduc_xor_uint32_t (uint32_t *a, int n)
{
  uint32_t r = 13;
  for (int i = 0; i < n; ++i)
    r ^= a[i];
  return r;
}

uint64_t __attribute__((noinline, noclone)) reduc_xor_uint64_t (uint64_t *a, int n)
{
  uint64_t r = 13;
  for (int i = 0; i < n; ++i)
    r ^= a[i];
  return r;
}
