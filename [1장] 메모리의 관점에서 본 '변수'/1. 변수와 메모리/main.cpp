#include <stdio.h>


int main(int argc, char** argv)
{
    // 정수형 변수 a 선언
    int a  = 10;


    // 변수 a에 들어 있는 값을 정수로 출력
    printf("value: %d\n", a);

    // // 변수 a의 크기 출력
    printf("size: %zu\n", sizeof(a));

    // 변수 a의 주소 출력
    printf("address: 0x%p\n", &a);


     return 0;
}