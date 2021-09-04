#if 0
#include <iostream>

struct Point
{
    int x, y;
};

int main()
{
    //변수 초기화
    int n1 = 0;
    int n2(0); //()초기화 c++에서 지원

    //배열 초기화
    int x[2] = {1, 2};

    //구조체 초기화
    Point p = {1, 2};
}
//초기화 방법이 제각각이라는 생각을 했다.
#endif

#include <iostream>

struct Point
{
    int x, y;
};

int main()
{
    //일관된 초기화 : 초기화 방법이 다 같다.

    //direct initializaion(다이렉트 초기화)

    //변수 초기화
    int n1{0};

    //배열 초기화
    int x[2]{1, 2};

    //구조체 초기화
    Point p{1, 2};

    //copy initializaion(카피 초기화)

    //변수 초기화
    int n1 = {0};

    //배열 초기화
    int x[2] = {1, 2};

    //구조체 초기화
    Point p = {1, 2};
}

//★정리1
//기존초기화 방식의 문제점
//1. 변수의 종류에 따라 초기화 방법이 다르다(배열,구초제,일반 변수 등)
//2. 동적 할당된 배열을 초기화 할 수 없다.
//3. 클래스 안에 배열 멤버를 초기화 할 수 없다.

//★정리2
//모든 종류의 변수를 하나의 일관된 형태로 초기화 하자
//uniform initalization
//중괄호 초기화(brace init)라고도 부른다
//direct initializaion : 초기화시에 = 을 사용하지 않는 것
//copy initializaion : 초기화시에 =를 사용하는 것

int main()
{
    int n1 = 3.4;
    //이건 잘못된 코드다.
    //하지만 함시적 형변환이 되어서 문제없이 형변환이 된다.

    int n2{3.4}; //컴파일 에러가 발생한다.

    char c1{100}; //OK
    char c2{300}; //error 300은 1바이트로 표현이 불가
    //데이터 손실이 발생하면 에러가 발생한다.
    int n3{};
    //brace init이 권장된다.
}