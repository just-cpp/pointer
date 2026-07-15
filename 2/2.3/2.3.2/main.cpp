#include <stdio.h>
#include <stdint.h>


int32_t main(int32_t argc, char** argv)
{
    int8_t a = 100;

    // 데이터 변수 a의 주소를 'int8_t*'형 포인터 변수에 저장
    int8_t* a_ptr8 = &a;

    // 데이터 변수 a의 주소를 'int32_t*'형 포인터 변수에 저장
    int32_t* a_ptr32 = (int32_t*)a_ptr8;


    printf("CHECK1: ");

    // 두 포인터 변수에 들어 있는 주소값 비교
    if(a_ptr8 == (int8_t*)a_ptr32)    // 혹은 if((int32_t*)a_ptr8 == a_ptr32)
        printf("EQUAL\n");
    else
        printf("DIFFERENT\n");

    // 두 포인터 변수에 들어 있는 주소값 출력
    printf("a_ptr8: 0x%p,  a_ptr32: 0x%p\n\n", a_ptr8, a_ptr32);


    // 'int8_t*'형 포인터 변수 증가 연산 수행
    a_ptr8++;

    // 'int32_t*'형 포인터 변수 증가 연산 수행 
    a_ptr32++;


    printf("CHECK2: ");

    // 두 포인터 변수에 들어 있는 주소값 비교
    if(a_ptr8 == (int8_t*)a_ptr32)    // 혹은 if((int32_t*)a_ptr8 == a_ptr32)
        printf("EQUAL\n");
    else
        printf("DIFFERENT\n");

    // 두 포인터 변수에 들어 있는 주소값 출력
    printf("a_ptr8: 0x%p,  a_ptr32: 0x%p\n\n", a_ptr8, a_ptr32);


    return 0;
}