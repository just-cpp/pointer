#include <stdio.h>
#include <stdint.h>


int32_t main(int32_t argc, char** argv)
{
    int32_t a[3] = { 0, 0, 0 };

    int32_t* ptr = a;


    printf("address 0: 0x%p 0x%p\n", ptr, &a[0]); 
    *ptr = 100;
    ptr++;

    printf("address 1: 0x%p 0x%p\n", ptr, &a[1]);
    *ptr = 200;
    ptr++;

    printf("address 2: 0x%p 0x%p\n", ptr, &a[2]);
    *ptr = 300;


    return 0;
}