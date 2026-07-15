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


    // 변수 c에 들어있는 값과 그 값을 주소로 하는 메모리(a)에 들어 있는 값 출력
    printf("주소 0x%p 번지에 들어 있는 값은 %d 입니다\n", c, *c);


    // 변수 c에 들어 있는 값을 주소로 하는 메모리(a)에 접근해서 거기에 들어 있는 값 변경
    *c = 20;

    // 변수 c에 들어 있는 값을 주소로 출력하고, 그 주소의 메모리에 있는 값을 정수로 출력
    printf("주소 0x%p 번지에 들어 있는 값은 %d 입니다\n", c, *c);

    // 변수 a와 b에 들어 있는 값을 정수로 출력
    printf("a와 b에 들어 있는 값은 각각 %d, %d 입니다\n", a, b);


     return 0;
}
