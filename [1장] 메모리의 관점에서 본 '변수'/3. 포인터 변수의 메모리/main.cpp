#include <stdio.h>


int main(int argc, char** argv)
{
    int a = 10;

    int b = a;

    int* c = &a; 


    // 변수 a에 들어 있는 값을 정수(%d)로 출력
    printf("a: %d\n", a);

    // 변수 b에 들어 있는 값을 정수(%d)로 출력
    printf("b: %d\n", b);

    // 변수 c에 들어 있는 값을 주소(%p)로 출력
    printf("c: 0x%p\n", c);


    // 데이터 변수 a의 메모리 크기 출력
    printf("size a: %zu\n", sizeof(a));

    // 데이터 변수 b의 메모리 크기 출력
    printf("size b: %zu\n", sizeof(b));

    // 포인터 변수 c의 메모리 크기 출력
    printf("size c: %zu\n", sizeof(c));


     return 0;
}