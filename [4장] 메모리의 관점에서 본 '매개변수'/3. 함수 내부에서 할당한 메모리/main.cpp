#include <stdio.h>
#include <stdint.h>
#include <malloc.h>


void alloc_memory(int32_t count, int32_t** ppMemory)
{
    *ppMemory = (int32_t*)malloc(sizeof(int32_t) * count);
}

void set_memory(int32_t* pPtr, int index, int value)
{
    pPtr[index] = value;
}

void free_memory(int32_t** ppPtr)
{
    free((void*)*ppPtr);

    *ppPtr = NULL;
}


int32_t main(int32_t argc, char** argv)
{
    int32_t* pPtr = NULL;


    alloc_memory(3, &pPtr);

    printf("alloc_memory: 0x%p\n", pPtr);

    set_memory(pPtr, 1, 100);

    free_memory(&pPtr);

    printf("free_memory: 0x%p\n", pPtr);


    return 0;
}