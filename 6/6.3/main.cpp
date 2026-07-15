// Visual C++에서 fopen 함수 사용으로 인한 컴파일러 오류 방지
#if defined(_MSC_VER)
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <stdio.h>
#include <stdint.h>
#include <memory.h>
#include <string.h>


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


// 파일 저장을 위해 직접 호출되는 함수
//
// pFName: 저장될 파일명
// pData: 저장될 데이터
// pWrite: 실제 저장 로직을 처리하는 콜백함수
int32_t StoreInfo(const char* pFName, void* pData, void (*pWrite)(FILE*, void*))
{
    FILE* fp = fopen(pFName, "wb");
    if(!fp)
        return -1;

    // 콜백함수 호출 (파일포인터, 저장될 데이터)
    pWrite(fp, pData);

    fclose(fp);

    return 0;
}


// TCar 구조체 타입의 데이터를 파일에 저장하기 위한 콜백함수
void WriteCar(FILE* fp, void* pData)
{
    struct TCar* car = (struct TCar*)pData;

    int32_t nLen = (int32_t)strlen(car->mobile.sName);
    fwrite(&nLen, 1, sizeof(nLen), fp);
    fwrite(car->mobile.sName, 1, strlen(car->mobile.sName), fp);
    fwrite(&car->nDoors, 1, sizeof(car->nDoors), fp);
    fwrite(&car->nCC, 1, sizeof(car->nCC), fp);
    fwrite(&car->nFuelEconomy, 1, sizeof(car->nFuelEconomy), fp);
}

// TBike 구조체 타입의 데이터를 파일에 저장하기 위한 콜백함수
void WriteBike(FILE* fp, void* pData)
{
    struct TBike* bike = (struct TBike*)pData;

    int32_t nLen = (int32_t)strlen(bike->mobile.sName);
    fwrite(&nLen, 1, sizeof(nLen), fp);
    fwrite(bike->mobile.sName, 1, strlen(bike->mobile.sName), fp);
    fwrite(&bike->nWheels, 1, sizeof(bike->nWheels), fp);
    fwrite(&bike->nIsMTB, 1, sizeof(bike->nIsMTB), fp);
    fwrite(&bike->nWeight, 1, sizeof(bike->nWeight), fp);
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


    // car.dat 파일에 car1 구조체 변수의 데이터 저장
    StoreInfo("car.dat", (void*)&car1, WriteCar);

    // bike.dat 파일에 bike1 구조체 변수의 데이터 저장
    StoreInfo("bike.dat", (void*)&bike1, WriteBike);


    return 0;
}
