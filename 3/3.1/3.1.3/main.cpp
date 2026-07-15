#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>


int32_t main(int32_t argc, char** argv)
{
    int32_t a = 100;

    int32_t* ptr = NULL;


    // rand() 함수 사용을 위한 난수 패턴 초기화
    srand((uint32_t)time(NULL));

    // 무작위 숫자 생성
    int32_t random = rand();

    printf("random: %d\n", random);


    // random가 짝수이면 1(메모리 할당), 아니면 0(변수 a의 주소 대입)
    int32_t allocate = ((random % 2) == 0 ? 1 : 0);

    if(allocate == 1)
        ptr = (int32_t*)malloc(sizeof(int32_t));   // 메모리 할당
    else
        ptr = &a;    // 변수 a의 주소 대입


    // ptr에 들어 있는 주소의 메모리에 있는 값을 200으로 변경
    *ptr = 200;

    printf("address: 0x%p, value: %d\n", ptr, *ptr);


    if(allocate == 1)     // 메모리가 할당되었으면 할당된 메모리 반납
    {
        free((void*)ptr);
        ptr = NULL;
    }

    // ptr이 NULL이 아닐 경우, 즉, allocate가 0일 경우에만 수행되어야 한다!
    if(ptr != NULL)
    {
        *ptr = 300;
        printf("address: 0x%p, value: %d\n", ptr, *ptr);
    }


    return 0;
}