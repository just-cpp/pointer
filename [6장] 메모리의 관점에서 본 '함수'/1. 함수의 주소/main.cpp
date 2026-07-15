#include <stdio.h>
#include <stdint.h>


void PrintInfo(unsigned char* pData)
{
    // ...
}  


int32_t main(int32_t argc, char** argv)
{
    // main 함수의 주소 출력
    printf("main(): 0x%p\n", main);

    // PrintInfo 함수의 주소 출력
    printf("PrintInfo(): 0x%p\n", PrintInfo);


    return 0;
}