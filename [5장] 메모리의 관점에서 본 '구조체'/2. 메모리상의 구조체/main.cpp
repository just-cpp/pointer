#include <stdio.h>
#include <stdint.h>


struct TTest
{
    char                a;  // 1 byte
    int32_t             b;  // 4 byte
    int16_t             c;  // 2 byte
    int32_t             d;  // 4 byte
    int64_t             e;  // 8 byte
};


int32_t main(int32_t argc, char** argv)
{
    struct TTest test;

    printf("test: 0x%p (%zu)\n\
        a (char): 0x%p (%zu)\n\
        b (int32_t): 0x%p (%zu)\n\
        c (int16_t): 0x%p (%zu)\n\
        d (int32_t): 0x%p (%zu)\n\
        e (int64_t): 0x%p (%zu)\n",
        &test, sizeof(test),
        &test.a, sizeof(test.a),
        &test.b, sizeof(test.b),
        &test.c, sizeof(test.c),
        &test.d, sizeof(test.d),
        &test.e, sizeof(test.e));

    return 0;
}
