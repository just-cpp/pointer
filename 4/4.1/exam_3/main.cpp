#include <stdio.h>
#include <stdint.h>


void divide(int32_t nNum1, int32_t nNum2, int32_t nDivide)
{
    printf("divide() - nDivide: addr 0x%p, value %d\n", &nDivide, nDivide);

    nDivide = nNum1 / nNum2;
}


int32_t main(int32_t argc, char** argv)
{
    int32_t nResult = 0;

    printf("main(): before - nResult: addr 0x%p, value %d\n", &nResult, nResult);

    divide(100, 50, nResult);

    printf("main(): after - nResult: addr 0x%p, value %d\n", &nResult, nResult);


    return 0;
}