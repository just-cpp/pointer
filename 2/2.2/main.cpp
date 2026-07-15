#include <stdio.h>
#include <stdint.h>


int32_t main(int32_t argc, char** argv)
{
    int32_t a = 10;
    int64_t b = 10;

    // a, b에 저장될 데이터의 크기 출력
    printf("size a: %zu\n", sizeof(a)); // size a: 4
    printf("size b: %zu\n", sizeof(b)); // size b: 8


    int32_t* c = &a;
    int64_t* d = &b;

    // 포인터 변수 c와 d의 크기 출력
    printf("size c: %zu\n", sizeof(c)); // size c: 4
    printf("size d: %zu\n", sizeof(d)); // size d: 4


    // 변수 c와 d에 들어 있는 a와 b의 주소 출력
    printf("address of c: 0x%p\n", c);  // address of a: 0x0055FD04
    printf("address of d: 0x%p\n", d);  // address of d: 0x0055FCF4


    return 0;
}