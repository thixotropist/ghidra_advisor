#include <stddef.h>

static const char from[] = "This is an example of a longish string to be copied onto the stack";
char to[99];

// copy with length known to compiler
#define MEMCPY_CONST(N)             \
void memcpy_##N ()            \
{                                   \
    __builtin_memcpy(to, from, N);   \
}

MEMCPY_CONST(7);
MEMCPY_CONST(15);
MEMCPY_CONST(31);
MEMCPY_CONST(63);
MEMCPY_CONST(127);
MEMCPY_CONST(255);

void memcpy_variable(unsigned int n)
{
    __builtin_memcpy (to, from, n);
}