#include <stddef.h>

static char a[128];

#define BZERO_CONST(N)       \
void bzero_##N ()            \
{                            \
    __builtin_bzero(a, N);   \
}

BZERO_CONST(7);
BZERO_CONST(15);
BZERO_CONST(31);
BZERO_CONST(63);
BZERO_CONST(127);
BZERO_CONST(255);

void bzero_variable(unsigned int n)
{
    __builtin_bzero(a, n);
}

long unsigned int __strlen(const char* s)
{
    return __builtin_strlen(s);
}

char* __strcpy(char *restrict d, const char *restrict s)
{
    return __builtin_strcpy(d, s);
}

char* __strncpy(char *restrict d, const char *restrict s, size_t n)
{
    return __builtin_strncpy(d, s, n);
}

char* __strchr(const char* s, int c)
{
    return __builtin_strchr(s, c);
}