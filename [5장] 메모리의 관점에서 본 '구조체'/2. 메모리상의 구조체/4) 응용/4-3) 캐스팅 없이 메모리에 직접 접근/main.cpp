#include <stdio.h>
#include <stdint.h>
#include <memory.h>
#include <stddef.h>


enum { MT_NONE, MT_CAR, MT_BIKE };


struct TMobile
{
    uint8_t             nType;          // 구조체의 종류
    char                sName[30];      // 등록 이름
};

struct TCar
{
    struct TMobile      mobile;         // TMobile 구조체

    uint8_t             nDoors;         // 문 개수
    uint32_t            nCC;            // 배기량
    float               nFuelEconomy;   // 연비
};

struct TBike
{
    struct TMobile      mobile;         // TMobile 구조체

    uint8_t             nWheels;        // 바퀴 개수
    uint8_t             nIsMTB;         // MTB 타입 여부
    float               nWeight;        // 무게
};


void PrintInfo(unsigned char* pData)
{
    // TMobile, TCar 또는 TBike로의 캐스팅 없이 메모리의 값을 직접 읽는다.
    uint8_t nType    = *pData;
    char* pModelName = (char*)&pData[1];
    uint8_t nCount   = *(uint8_t*)&pData[31];

    if(nType == MT_CAR)
        printf("car address: 0x%p, Name: %s, Doors: %d\n", pData, pModelName, nCount);
    else
        printf("bike address: 0x%p, Name: %s, Wheels: %d\n", pData, pModelName,  nCount);
}  


int32_t main(int32_t argc, char** argv)
{
    // struct TCar 타입의 변수 car1

    struct TCar car1;
    memset(&car1, 0, sizeof(car1));

    car1.mobile.nType   = MT_CAR;
    snprintf(car1.mobile.sName, 30, "%s", "My Car");

    car1.nDoors         = 4;
    car1.nCC            = 2000;
    car1.nFuelEconomy   = 15.2f;


    // struct TBike 타입의 변수 bike1

    struct TBike bike1;
    memset(&bike1, 0, sizeof(bike1));

    bike1.mobile.nType   = MT_BIKE;
    snprintf(bike1.mobile.sName, 30, "%s", "My Bike");
    bike1.nWheels       = 2;
    bike1.nIsMTB        = 0;
    bike1.nWeight       = 12.9f;


    // 구조체 TCar의 nDoors 필드 오프셋 출력
    printf("offsetof(nDoors) = %zu\n", offsetof(struct TCar, nDoors));

    // 구조체 TBike의 nWheels 필드 오프셋 출력
    printf("offsetof(nWheels) = %zu\n", offsetof(struct TBike, nWheels));


    printf("car1 address: 0x%p, size: %zu\n", &car1, sizeof(car1));

    // car1의 주소를 unsigned char* 타입으로 전달
    PrintInfo((unsigned char*)&car1);


    printf("bike1 address: 0x%p, size: %zu\n", &bike1, sizeof(bike1));

    // bike1의 주소를 unsigned char* 타입으로 전달
    PrintInfo((unsigned char*)&bike1);


    return 0;
}
