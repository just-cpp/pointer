#include <stdio.h>
#include <stdint.h>
#include <malloc.h>


int32_t main(int32_t argc, char** argv)
{
    int32_t* ptr = NULL;

    ptr = (int32_t*)malloc(sizeof(int32_t));

    *ptr = 100;

    printf("address: 0x%p, value: %d\n", ptr, *ptr);

    free((void*)ptr);

    printf("address: 0x%p, value: %d\n", ptr, *ptr);


    return 0;
}