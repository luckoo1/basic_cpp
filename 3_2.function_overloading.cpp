#if 0
int square(int a)
{
    return a * a;
}

int main()
{
    square(3);
    square(3.4);//0.4가 버려지고 실행은 된다.
    //문제가 있다고 생각했다.
}

#endif

#if 0
int square(int a)
{
    return a * a;
}

int square(double a)
{
    return a * a;
}
//c에서는 똑같은 이름의 함수 2개를 만들 수 없었다.
//함수이름이 같아도 인자의 타입이나 갯수가 다르면
//똑같은 함수 2개이상 생성 가능
//컴파일러가 알아서 자동으로 맞는 함수로 보내준다.
int main()
{
    square(3);
    square(3.4);
}
//함수 사용자 입장에서는 동일한 함수처럼 보이게 되므로
//일관된 형태의 라이브러리를 구축할 수 있다.
#endif

#if 0
//OK
void f1(int a) {}
void f1(double a) {}

//OK
void f2(int a) {}
void f2(int a, int b) {}

//error
void f3(int a) {}
void f3(int a, int b = 10) {}
//f3(1);과 같이 전달하면 어느 함수로 갈지 판단이 불가능

//error
int f4(int a) { return 0; }
double f4(int a) { return 0; }
//f4(0);와 같이 호출했을때
//리턴타입만 다르니깐 어디로 갈지 판단이 불가능
#endif
#include <iostream>
void f1(int n)
{
    std::cout << "int" << std::endl;
}

void f1(int *p)
{
    std::cout << "int *" << std::endl;
}

int main()
{
    f1(0);        //int
    f1((int *)0); //int*
    f1(nullptr);  //int*
    //포인터 0을 나타낼때 nullptr을 사용해야하는 이유
    //nullptr시간에 배웠던 내용
}