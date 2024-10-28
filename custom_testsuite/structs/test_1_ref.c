void test_1_ref(unsigned long long *in, unsigned long long *out, unsigned int size)
{
    int i;
    int upper_index = size - 1;
    for (i=0; i < size; i++) {
        out[i] = in[upper_index - i];
    }
}