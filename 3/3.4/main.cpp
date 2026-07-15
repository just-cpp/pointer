#include <stdint.h>
#include <malloc.h>


int32_t g_val = 100;

static int32_t _n = 0;


int32_t main(int32_t argc, char** argv)
{
    int32_t l_val[3] = { 100, 200, 300 };

    int32_t* l_ptr_1 = l_val;

    int32_t* l_ptr_2 = (int32_t*)malloc(sizeof(int32_t) * 3);

    l_ptr_2[0] = 100;

    free((void*)l_ptr_2);


    return 0;
}