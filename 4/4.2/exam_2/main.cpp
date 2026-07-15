#include <stdio.h>
#include <stdint.h>


void divide(int32_t nNum1, int32_t nNum2, int32_t* pDivide, int32_t* pMod)
{
        *pDivide = nNum1 / nNum2;

        *pMod = nNum1 % nNum2;
}


int32_t main(int32_t argc, char** argv)
{
    int32_t nResult_Divide = 0;

    int32_t nResult_Mod = 0;

    divide(100, 50, &nResult_Divide, &nResult_Mod);

    printf("Divide: %d, Mod: %d\n", nResult_Divide, nResult_Mod);


    return 0;
}