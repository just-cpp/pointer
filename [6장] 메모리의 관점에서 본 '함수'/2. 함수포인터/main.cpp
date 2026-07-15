#include <stdio.h>
#include <stdint.h>


// 사칙연산 수행을 위해 사용자가 호출하는 함수
// x: 연산에 사용될 정수형 데이터 1
// y: 연산에 사용될 정수형 데이터 2
// pFunc: 연산을 위해 호출될 콜백함수
int32_t Calc(int32_t x, int32_t y, int32_t (*pFunc)(int32_t, int32_t))
{
    // 콜백함수 호출 (데이터1, 데이터2)
    return pFunc(x, y);
}

// 덧셈함수
int32_t sum(int32_t x, int32_t y)
{
    return x + y;
}

// 뺄셈함수
int32_t subtract(int32_t x, int32_t y)
{
    return x - y;
}

// 곱셈함수
int32_t multifly(int32_t x, int32_t y)
{
    return x * y;
}

// 나눗셈함수
int32_t divide(int32_t x, int32_t y)
{
    return x / y;
}


int32_t main(int32_t argc, char** argv)
{
    // 덧셈함수 sum을 콜백함수로 전달
    int32_t nSum = Calc(10, 5, sum);

    // 덧셈함수 sum을 콜백함수로 전달
    int32_t nSubtract = Calc(10, 5, subtract);

    // 나눗셈함수 multifly을 콜백함수로 전달
    int32_t nMultifly = Calc(10, 5, multifly);

    // 나눗셈함수 divide을 콜백함수로 전달
    int32_t nDivide = Calc(10, 5, divide);

    printf("Result: %d %d %d %d\n", nSum, nSubtract, nMultifly, nDivide);


    return 0;
}