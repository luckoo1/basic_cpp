#include <iostream>

/*
정리
기존 메모리(변수)에 새로운 이름(alias)을 부여하는 것
그림참조

레퍼런스 변수는 메모리를 할당하지 않는가?
단순한 코드의 경우 메모리를 사용하지 않는다.
복잡한 경우(함수 인자로 사용되거나 할때) 상황에 따라 내부적으로 포인터를 사용하기도 한다.
C++ 표준 문서는 레퍼런스의 동작만 정의할뿐 구현은 정의하고 있지 않다.

반드시 초기화 되어야한다.
*/

int main()
{
    int n = 10;  //메모리 할당
    int *p = &n; //

    int &r = n;                   //r은 reference변수
    r = 20;                       //결국 n에 넣는것
    std::cout << &n << std::endl; //0x61ff04
    std::cout << &r << std::endl; //0x61ff04
    std::cout << n << std::endl;  //20이 나옴

    int &r2; //error 기존메모리가 없으니깐
}