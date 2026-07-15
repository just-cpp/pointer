#include <stdio.h>
#include <stdint.h>


void divide(int32_t nNum1, int32_t nNum2, int32_t nDivide)
{
    nDivide = nNum1 / nNum2;
}


int32_t main(int32_t argc, char** argv)
{
    int32_t nResult = 0;

    divide(100, 50, nResult);

    printf("RESULT: %d\n", nResult);


    return 0;
}