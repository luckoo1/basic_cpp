#if 0
#include <iostream>
using namespace std;

class Complex
{
    int re, im; //실수부,허수부

public:
    Complex(int r = 0, int i = 0) : re(r), im(i)
    {
    }
    void print() const
    {
        cout << re << ", " << im << endl;
    }
};

int main()
{
    int n = 3 + 4;

    Complex c1(1, 1);
    Complex c2(2, 2);
    Complex c3 = c1 + c2; //error
    /*
    이걸 되게 하고싶다.
    c1.operator+(c2)
    c1안에 operator+라는 함수에 c2라는 인자를 넣는 구조

    일단 "operator+()"없으니깐...
    "operator+(c1,c2)"를 찾아본다.

    결론적으로 컴파일러는
    operator+(c2)
    operator(c1,c2)
    이렇게 찾고 없으니깐 error를 띄운다.
    */
}

/*
a+b코드에서 
a,b가 모두 pirmitive type(int,double 등)일 경우 : 덧셈 수행
a,b중 하나라도 user define type일 경우 : operator+()함수를 찾게 된다.

c1+c2코드를 컴파일러가 해석하는 방법
operator+(c2)함수를 찾게 된다 => 멤버함수검색
operator(c1,c2)함수를 찾게 된다 => 멤버가 아닌 일반함수 검색
*/
#endif

//"operator+함수" 구현해보자
#include <iostream>
using namespace std;

class Complex
{
    int re, im; //실수부,허수부

public:
    Complex(int r = 0, int i = 0) : re(r), im(i)
    {
    }
    void print() const
    {
        cout << re << ", " << im << endl;
    }

    Complex operator+(const Complex &c)
    {
        Complex temp(re + c.re, im + c.im);
    }
};

int main()
{
    int n = 3 + 4;

    Complex c1(1, 1);
    Complex c2(2, 2);
    Complex c3 = c1 + c2;
    //c1.operator+(c2)
    //c1이 가지고 있는 멤버함수 중에서 operator+()함수를 찾게되고 인자를 c2로 보내려한다.
    //c1(자기자신)인자에다가 c2를 더한다.
}