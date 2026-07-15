#include <stdio.h>
#include <stdint.h>


int32_t main(int32_t argc, char** argv)
{
    int32_t a[3] = { 0, 0, 0 };

    a[0] = 100;
    a[1] = 200;
    a[2] = 300;

    printf("a[0]: address: 0x%p, value: %d\n", &a[0], a[0]);
    printf("a[1]: address: 0x%p, value: %d\n", &a[1], a[1]);
    printf("a[2]: address: 0x%p, value: %d\n", &a[2], a[2]);

    printf("\n");

    printf("a: 0x%p, &a[0]: 0x%p\n", a, &a[0]);


    return 0;
}