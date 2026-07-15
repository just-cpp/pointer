#include <stdio.h>
#include <stdint.h>
#include <malloc.h>


void test()
{
    int32_t* l_ptr_2 = (int32_t*)malloc(sizeof(int32_t) * 3);

    printf("l_ptr_2 - addr: 0x%p, value: 0x%p\n", &l_ptr_2, l_ptr_2);
}


int32_t main(int32_t argc, char** argv)
{
    test();


    return 0;
}