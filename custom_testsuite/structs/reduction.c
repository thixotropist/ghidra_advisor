#include <stdint.h>

double reduce_floats(float *p, uint32_t count)
{
    double result = 0.0;
    for (int i = 0; i < count; i++)
    {
        result += p[i * 14];
    }
    return result;
}
