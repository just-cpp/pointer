#include <stdio.h>
#include <stdint.h>


#if defined(_MSC_VER)
    #define PACKED_BEGIN __pragma(pack(push, 1))
    #define PACKED_END   __pragma(pack(pop))
    #define PACKED
#else
    #define PACKED_BEGIN
    #define PACKED_END
    #define PACKED __attribute__((packed))
#endif


PACKED_BEGIN
struct PACKED TTest
{
    char                a;
    int32_t             b;
    int16_t             c;
    int32_t             d;
    int64_t             e;
};
PACKED_END



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