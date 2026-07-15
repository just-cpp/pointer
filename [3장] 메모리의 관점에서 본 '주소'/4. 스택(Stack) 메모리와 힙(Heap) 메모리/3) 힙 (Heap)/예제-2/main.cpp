#include <stdio.h>
#include <stdint.h>
#include <malloc.h>


int32_t g_val = 100;


int32_t main(int32_t argc, char** argv)
{
    int32_t l_val[3] = { 100, 200, 300 };

    int32_t* l_ptr_1 = l_val;

    int32_t* l_ptr_2 = (int32_t*)malloc(sizeof(int32_t) * 3);

    l_ptr_2[0] = 100;

    printf("g_val - addr: 0x%p, value: %d\n", &g_val, g_val);
    printf("l_val - addr: 0x%p, value: %d\n", l_val, l_val[0]);
    printf("l_ptr_1 - addr: 0x%p, value: 0x%p\n", &l_ptr_1, l_ptr_1);
    printf("l_ptr_2 - addr: 0x%p, value: 0x%p\n", &l_ptr_2, l_ptr_2);

    free((void*)l_ptr_2);


    return 0;
}