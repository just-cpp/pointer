#include <stdint.h>


int32_t divide(int32_t nNum1, int32_t nNum2)
{
    int32_t nDivide = nNum1 / nNum2;

    return nDivide;
}


int32_t main(int32_t argc, char** argv)
{
    int32_t nResult = divide(100, 50);


    return 0;
}