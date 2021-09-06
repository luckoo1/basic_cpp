if
    0
//C style
#include <cstdlib>

        int
        main()
    {
        int *p = (int *)malloc(100);
        //malloc함수는 return값이 void 포인터니깐 캐스팅해서 받아야한다.
        //"(int *)"으로 캐스팅 해줌
    }
#endif

#if 0
//C++ style
#include <iostream>
#include <cstdlib>


int main()
{
    int *p = static_cast<int *>(malloc(100));
    //malloc(100)이 void포인터로 리턴받아서 void포인터니깐
    //"int *"로 casting하겠다는 뜻이다.
}


//그럼 이러한 static_cast가 왜 나왔을까? 알아보자
#endif
#if 0


//기존 캐스팅의 문제점을 알아보자
//캐스팅이 위험한 경우 1
int main()
{
    int n = 3;
    double *p = &n;
    //int주소나 double의 주소는 4바이트다
    //그래도 int의 주소를 double 포인터에 담는건 error다
    //그럼 아래와 같이 쓰면 어떨까


    double *p = (double *)&n;
    //이건 문제없이 돌아간다.
    //38분가량의 그림 필기에 넣기
    //int메모리에 1000번지 n이고 3이담긴 4바이트 메모리가 생긴다.
    //포인터 변수 type가 double인 p가 생기는데
    //이 p에 1000번지를 담았다.
    //컴파일러는 p는 1000번지를 가리키는데 따라가면 double이 있다고 생각한다.
    *p = 3.4;


    //38분가량의 그림 필기에 넣기(이어지는 필기)
    //위와 같이 적으면 1000번지에다가 3.4를 넣는데
    //double이 8바이트라서 8바이트에 넣으려고 한다.
    //나는 4바이트는 할당한적이 있는데 8바이트 할당한적이 없다.


    //만약에 4바이트 밑에 추가되는 칸(1004번지)에 다른 변수가 있었다면
    //그 변수를 덮어쓸수도 있다.
    //실행결과가 이상해질수 있다.


    //잘못된 메모리 참조가 나올수도 있다.


    //위의 코드는 상당히 위험한 코드다.
    //다른 타입(연관성이 없는)의 주소를 담는 포인터는 위험하다.
}

#endif

#if 0
//캐스팅이 위험한 경우 2


int main()
{
    const int c = 10;


    int *p = &c; //error
    //상수의 주소는 비상수를 가리키는 포인터에 담을 수 없다.
    const int *p = &c; //이렇게 써야한다
    //40:30그림 필기


    *p = 20;
}
#endif

#if 0
#include <iostream>


int main()
{
    const int c = 10;


    int *p = (int *)&c; //OK


    *p = 20;


    std::cout << *p << std::endl; //미정의동작인듯??
}


//이러한 문제점들이 C에 있었다.
//이제 C++ casting알아보자.

#endif

/*
c casting은 버그 가능서이 있는 경우도 캐스팅을 허용하는 경우가 많다.
c++ casting 4가지가 있다.
static_cast : 컴파일 시간 캐스팅
dynamic_cast : 실행 시간 캐스팅
reinterpret_cast : 컴파일 시간 캐스팅
const_cast : 컴파일 시간 캐스팅
*/

//////////////////////////////////////////////////////////////////////////////////
#if 0
/*
1.static_cast
가장 기본적인 캐스팅 위험성을 내포한 경우는 캐스팅 안됨
void*->다른타입*
연관성 있는 타입 허용
*/
#include <cstdlib>


int main()
{
    int *p1 = static_cast<int *>(malloc(100));
    //malloc이 void포인터 반환임
    //C++진영에서는 void포인터를 int로 바꾸는 작업이 필요하다가 판단해서 허용해준다.


    int n = 3;
    double *p2 = static_cast<double *>(&n);
    //C++ 컴파일러는 이걸 위험하다 판단해서 error를 띄운다.
    //"int*에서 double로 변환할 수 없다"라는 error가 뜬다.


    /////////////////////////////////////////////////////////////////////////////////////////////


    //그런데 double포인터에 int를 담는게 필요한 경우가 있을수도 있다.
    double *p2 = reinterpret_cast<double *>(&n);
    //문제없다.
    //위험하지만 혹시 이런게 필요하면 써라. 위험을 감수할려면 써라
    /*
    2. reinterpret_cast
    메모리 재해석
    서로 다른 타입의 주소를 캐스팅
    포인터와 정수간 캐스팅
    */


    const int c = 10;
    int *p3 = static_cast<int *>(&c); //error가 뜬다.
    //상수의 주소를 비상수 포인터에 담으려고 해서 error
    int *p3 = reinterpret_cast<int *>(&c); //error가 뜬다.
    //reinterpret_cast는 서로 다른 type면 성공하는데 const가 있으면 안된다.
    int *p3 = const_cast<int *>(&c); //OK
    //const를 없애주는 cast


    /*
    3.cosnt_cast
    객체의 상수성을 제거하는 캐스팅
    */


    //C++ 캐스팅은 용도별로 분리해서 개발자의 의도를 파악할 수 있다.


    /*
    4.dynamic_cast
    down cast를 막기위해 사용
    RTTI 기능
    상속을 배운 후 설명
    */
}
#endif

//casting사용예제 살펴보자

int main()
{
    const int c = 10;
    double *p = &c; //error
    //아래와 같이 바꾸면 작동한다.
    double *p = (double *)&c; //OK

    //////////////////////////////////////////////////////////////////////////////
    //이걸 c++ 캐스팅으로 생각해보자

    double *p = static_cast<double *>(&c);
    //위와 같이 적으면 어떻게 될까
    //static_cast 자체내에서 error

    double *p = reinterpret_cast<double *>(&c);
    //위와 같이 적으면 어떻게 될까
    //다른 타입이긴 하지만 c가 상수다
    //reinterpret_cast는 상수 제거가 불가능해서 error

    double *p = const_cast<double *>(&c);
    //위와 같이 적으면 어떻게 될까
    //const_cast 상수성은 제거가 가능한데 서로 다른 타입이라서 error

    //아래와 같이 써야한다.
    double *p = reinterpret_cast<double *>(const_cast<int *>(&c));
    //const_int로 const버리면 결과로 int 포인터 나온다.
    //int 포인터를 reinterpret_cast를 이용해서 double 포인터로 바꾸겠다는 뜻
}