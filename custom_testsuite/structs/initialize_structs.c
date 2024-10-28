#include <stdint.h>

struct btype{
    uint64_t field0;
    uint64_t field8;
};

// initialize two arrays of structs with a constant derived from the index
#define DEF_INIT_2(N) \
void init_2_##N (uint64_t* a, struct btype* b) \
{                                              \
    for (uint16_t i = 0; i < N; i++)         \
        {                                      \
            uint64_t value = (uint64_t)i << 40;         \
            a[i] = value;                      \
            b[i].field0 = value;               \
        }                                      \
}

DEF_INIT_2(2)
DEF_INIT_2(32)
DEF_INIT_2(99)

#define DEF_INIT_1(N) \
void init_1_##N (struct btype* b) \
{                                              \
    for (uint16_t i = 0; i < N; i++)           \
        {                                      \
            uint64_t value = (uint64_t)i << 40;\
            b[i].field0 = value;               \
        }                                      \
}

DEF_INIT_1(2)
DEF_INIT_1(32)
DEF_INIT_1(99)

#define DEF_INIT_CONST_1(N) \
void init_const_1_##N (struct btype* b) \
{                                              \
    for (uint16_t i = 0; i < N; i++)           \
        {                                      \
            b[i].field0 = 0;                   \
            b[i].field8 = 1;                   \
        }                                      \
}

DEF_INIT_CONST_1(2)
DEF_INIT_CONST_1(32)
DEF_INIT_CONST_1(99)

#define DEF_XFORM_COPY(N) \
void init_copy_##N (uint64_t* a, struct btype* b) \
{                                              \
    for (uint16_t i = 0; i < N; i++)           \
        {                                      \
            b[i].field0 = a[i];                \
        }                                      \
}
DEF_XFORM_COPY(2)
DEF_XFORM_COPY(32)
DEF_XFORM_COPY(99)
