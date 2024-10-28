#0 "custom_testsuite/builtins/string.c"
#0 "<built-in>"
#0 "<command-line>"
#1 "external/gcc_riscv_suite~/usr/include/stdc-predef.h" 1 3 4
#0 "<command-line>" 2
#1 "custom_testsuite/builtins/string.c"
#1 "/run/user/1000/bazel/external/gcc_riscv_suite~/bin/../lib/gcc/riscv64-unknown-linux-gnu/15.0.0/include/stddef.h" 1 3 4
#145 "/run/user/1000/bazel/external/gcc_riscv_suite~/bin/../lib/gcc/riscv64-unknown-linux-gnu/15.0.0/include/stddef.h" 3 4

#145 "/run/user/1000/bazel/external/gcc_riscv_suite~/bin/../lib/gcc/riscv64-unknown-linux-gnu/15.0.0/include/stddef.h" 3 4
typedef long int ptrdiff_t;
#214 "/run/user/1000/bazel/external/gcc_riscv_suite~/bin/../lib/gcc/riscv64-unknown-linux-gnu/15.0.0/include/stddef.h" 3 4
typedef long unsigned int size_t;
#329 "/run/user/1000/bazel/external/gcc_riscv_suite~/bin/../lib/gcc/riscv64-unknown-linux-gnu/15.0.0/include/stddef.h" 3 4
typedef int wchar_t;
#425 "/run/user/1000/bazel/external/gcc_riscv_suite~/bin/../lib/gcc/riscv64-unknown-linux-gnu/15.0.0/include/stddef.h" 3 4
typedef struct
{
  long long __max_align_ll __attribute__((__aligned__ (__alignof__ (long long))));
  long double __max_align_ld __attribute__((__aligned__ (__alignof__ (long double))));
#436 "/run/user/1000/bazel/external/gcc_riscv_suite~/bin/../lib/gcc/riscv64-unknown-linux-gnu/15.0.0/include/stddef.h" 3 4
} max_align_t;
#2 "custom_testsuite/builtins/string.c" 2


#3 "custom_testsuite/builtins/string.c"
static char a[128];







void bzero_7 ()
{
  __builtin_bzero (a, 7);
};

void bzero_15 ()
{
  __builtin_bzero (a, 15);
};

void bzero_31 ()
{
  __builtin_bzero (a, 31);
};

void bzero_63 ()
{
  __builtin_bzero (a, 63);
};

void bzero_127 ()
{
  __builtin_bzero (a, 127);
};

void bzero_255 ()
{
  __builtin_bzero (a, 255);
};

void bzero_variable (unsigned int n)
{
  __builtin_bzero (a, n);
}

long unsigned int __strlen (const char *s)
{
  return __builtin_strlen (s);
}

char *__strcpy (char *restrict d, const char *restrict s)
{
  return __builtin_strcpy (d, s);
}

char *__strncpy (char *restrict d, const char *restrict s, size_t n)
{
  return __builtin_strncpy (d, s, n);
}

char *__strchr (const char *s, int c)
{
  return __builtin_strchr (s, c);
}
