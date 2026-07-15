#include <stdio.h>
#include <stdint.h>
#include <stddef.h>


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
struct PACKED TTest_packed_O
{
    char                a;
    int32_t             b;
    int16_t             c;
    int32_t             d;
    int64_t             e;
};
PACKED_END


struct TTest_packed_X
{
    char                a;
    int32_t             b;
    int16_t             c;
    int32_t             d;
    int64_t             e;
};


int32_t main(int32_t argc, char** argv)
{
    struct TTest_packed_O test_packed_O;
    struct TTest_packed_X test_packed_X;


    printf("%s", "OFFSET\n");

    // packing된 경우 필드 a와 b의 Offset 출력 
    printf("Packed O: offsetof(a) = %zu\n", offsetof(struct TTest_packed_O, a));
    printf("Packed O: offsetof(b) = %zu\n", offsetof(struct TTest_packed_O, b));

    // packing되지 않은 경우 필드 a와 b의 Offset 출력
    printf("Packed X: offsetof(a) = %zu\n", offsetof(struct TTest_packed_X, a));
    printf("Packed X: offsetof(b) = %zu\n", offsetof(struct TTest_packed_X, b));


    printf("%s", "\n");


    printf("%s", "ADDRESS\n");

    // packing된 경우 필드 b의 계산된 주소와 직접 구한 주소를 출력
    unsigned char* ptr = (unsigned char*)&test_packed_O;
    ptr = &ptr[offsetof(struct TTest_packed_O, b)];
    printf("Packed O: ptr: 0x%p, &test.b: 0x%p\n", ptr, &test_packed_O.b);

    // packing되지 않은 경우 필드 b의 계산된 주소와 직접 구한 주소를 출력
    ptr = (unsigned char*)&test_packed_X;
    ptr = &ptr[offsetof(struct TTest_packed_X, b)];
    printf("Packed X: ptr: 0x%p, &test.b: 0x%p\n", ptr, &test_packed_X.b);


    return 0;
}