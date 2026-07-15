#include <stdint.h>
#include <malloc.h>


int32_t* alloc_memory(int32_t count)
{
    int32_t* pMemory = (int32_t*)malloc(sizeof(int32_t) * count);

    return pMemory;
}


void free_memory(int32_t* pPtr)
{
    free((void*)pPtr);
}


void set_memory(int32_t* pPtr, int index, int value)
{
    pPtr[index] = value;
}


int32_t main(int32_t argc, char** argv)
{
    int32_t* pPtr = alloc_memory(3);

    set_memory(pPtr, 1, 100);

    free_memory(pPtr);

    pPtr = NULL;


    return 0;
}