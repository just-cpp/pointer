#include <stdio.h>
#include <stdint.h>
#include <memory.h>


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


void PrintInfo(void* pData)
{
    // 호출자가 TCar 타입 변수의 주소를 넘기든, TBike 타입 변수의 주소를 넘기든 두 구조체 모두 첫번째 필드로 
    // TMobile 타입의 변수가 선언되어 있다.
    //
    //     ...
    //     struct TMobile      mobile;
    //     ...
    //
    struct TMobile* pMobile = (struct TMobile*)pData;

    // pMobile의 nType 필드에 들어 있는 값으로 데이터 판별
    if(pMobile->nType == MT_CAR)
    {
        // 매개변수 pData를 TCar 구조체 타입의 데이터로 캐스팅
        struct TCar* car       = (struct TCar*)pData;
        printf("car address: 0x%p, Name: %s, Doors: %d\n", car, car->mobile.sName, car->nDoors);
    }
    else
    {
        // 매개변수 pData를 TBike 구조체 타입의 데이터로 캐스팅
        struct TBike* bike     = (struct TBike*)pData;
        printf("bike address: 0x%p, Name: %s, Wheels: %d\n", bike, bike->mobile.sName, bike->nWheels);
    }
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



    printf("car1 address: 0x%p, size: %zu\n", &car1, sizeof(car1));
    PrintInfo((void*)&car1);

    printf("bike1 address: 0x%p, size: %zu\n", &bike1, sizeof(bike1));
    PrintInfo((void*)&bike1);


    return 0;
}
