#include <stdio.h>
#include <stdint.h>


int32_t main(int32_t argc, char** argv)
{
    unsigned char memory[] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a };
    printf("memory: 0x%p\n\n", &memory[0]);


    // 'unsigned char*'형 주소를 'uint8_t*' 형 주소로 캐스팅하여 주소와 값 출력
    uint8_t* ptr8 = (uint8_t*)&memory[0];
    printf("ptr8: 0x%p, value: 0x%x\n", ptr8, *ptr8);


    // 'unsigned char*'형 주소를 'uint16_t*' 형 주소로 캐스팅하여 주소와 값 출력
    uint16_t* ptr16 = (uint16_t*)&memory[0];
    printf("ptr16: 0x%p, value: 0x%x\n", ptr16, *ptr16);


    // 'unsigned char*'형 주소를 'uint32_t*' 형 주소로 캐스팅하여 주소와 값 출력
    uint32_t* ptr32 = (uint32_t*)&memory[0];
    printf("ptr32: 0x%p, value: 0x%x\n", ptr32, *ptr32);


    return 0;
}