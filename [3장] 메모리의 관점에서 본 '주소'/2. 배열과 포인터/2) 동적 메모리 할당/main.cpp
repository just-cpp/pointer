#include <stdio.h>
#include <stdint.h>
#include <malloc.h>


int32_t main(int32_t argc, char** argv)
{
    int32_t* ptr = NULL;

    ptr = (int32_t*)malloc(sizeof(int32_t) * 3);

    ptr[0] = 100;
    ptr[1] = 200;
    ptr[2] = 300;

    printf("ptr[0]: address: 0x%p, value: %d\n", &ptr[0], ptr[0]);
    printf("ptr[1]: address: 0x%p, value: %d\n", &ptr[1], ptr[1]);
    printf("ptr[2]: address: 0x%p, value: %d\n", &ptr[2], ptr[2]);

    printf("\n");

    printf("ptr: 0x%p, &ptr[0]: 0x%p\n", ptr, &ptr[0]);

    free((void*)ptr);


    return 0;
}