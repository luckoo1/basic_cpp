//c와 다른 c++변수의 특징

#include <iostream>
//4★멤버초기화(C++11)
struct Point
{
    int x = 0;
    int y = 0;
};

/*바로 초기화를 못해서 아래와 같이 사용했다.
struct Point
{
    int x;
    int y;
};
*/
//

int main()
{
    //5★c에서는 구조체 사용시 아래와 같이 적었다.
    struct Point p1; //c style
    //아래와 같이 그냥 사용이 가능
    Point p2; //c++ style

    //1★2진수 표기법과 자릿수 표기법이 c++11부터 가능
    int n1 = 0x10;      //0x를 앞에 붙여서 16진수로 만들었다.
    int n2 = 0b10;      //0b를 붙여서 2진수로 만들었다(c언어는 안됨,c++11에서 등장)
    int n3 = 1'000'000; //자리수를 표현하기 위해서 '사용(c++11부터 가능)

    foo();
    int n3 = 0; //2★함수를 호출하고 변수를 선언하면 에러가 발생하던 시절이 있었다.
                //함수 중간에 변수선언가능
                //

    bool b = true; //3★bool타입
}