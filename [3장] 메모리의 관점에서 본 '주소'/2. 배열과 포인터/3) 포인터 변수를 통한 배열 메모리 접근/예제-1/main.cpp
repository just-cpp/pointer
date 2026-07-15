#include <stdio.h>
#include <stdint.h>


int32_t main(int32_t argc, char** argv)
{
    int32_t a[3] = { 0, 0, 0 };

    int32_t* ptr = a;


    ptr[0] = 100;
    ptr[1] = 200;
    ptr[2] = 300;


    printf("ptr[0]: address: 0x%p, value: %d\n", &ptr[0], ptr[0]);
    printf("ptr[1]: address: 0x%p, value: %d\n", &ptr[1], ptr[1]);
    printf("ptr[2]: address: 0x%p, value: %d\n", &ptr[2], ptr[2]);


    return 0;
}