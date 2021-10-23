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
    c1안에 operator+라는 멤버함수에 c2라는 인자를 넣는 구조

    일단 "operator+()"없으니깐...
    "operator+(c1,c2)"라는 일반함수를 찾아본다.

    결론적으로 컴파일러는
    c1의 멤버함수 : operator+(c2) 
    일반함수 : operator+(c1,c2)
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
//#######################################################################

//"operator+함수" 구현해보자
//멤버함수로 구현하는 법
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
        cout << re << "i+" << im << endl;
    }

    Complex operator+(const Complex &c)
    {
        Complex temp(re + c.re, im + c.im);
        //객체자신(c1)의 re + c2의 re, 객체자신(c1)의 im + c2의 im
        //그럼 temp라는 complex객체가 c1,c2의 실수부와 c1,c2의 허수부를 각각 더한걸로 된다.
        return temp;
    }
};

int main()
{
    int n = 3 + 4;

    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3 = c1 + c2;
    c3.print();
    //c1.operator+(c2)
    //c1이 가지고 있는 멤버함수 중에서 operator+()함수를 찾게되고 인자를 c2로 보내려한다.
    //c1(자기자신)인자에다가 c2를 더한다.
}
//#######################################################################

//일반함수로 구현하는 법

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
        cout << re << "i+" << im << endl;
    }
};
//일반함수를 만들었다.
Complex operator+(const Complex &c1, const Complex &c2)
{
    Complex temp(c1.re + c2.re, c1.im + c2.im); //이상태로 컴파일하면 error
    return temp;
}
//re와 im은 일반함수는 멤버데이터에 불가능하다.

int main()
{
    int n = 3 + 4;

    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3 = c1 + c2;

    c3.print();
}
//#######################################################################

//일반함수로 구현하는 법

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
        cout << re << "i+" << im << endl;
    }
    friend Complex operator+(const Complex &c1, const Complex &c2);
    //Complex operator+만은 private에 접근할수 있게 해달라!
};

Complex operator+(const Complex &c1, const Complex &c2)
{
    Complex temp(c1.re + c2.re, c1.im + c2.im);
    return temp;
}

int main()
{
    int n = 3 + 4;

    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3 = c1 + c2;

    c3.print();
}

/*
정리
멤버함수로 구현
+는 이항연산자이지만 "operator+()함수의 인자는 하나"이다.

멤버함수가 아닌 함수로 구현하기
"operator+()의 함수 인자는 2개"가 된다
일반적으로 "friend함수로 등록"
*/
//#######################################################################

#include <iostream>

class Complex
{
    int re, im; //실수부,허수부

public:
    Complex(int r = 0, int i = 0) : re(r), im(i)
    {
    }
    void print() const
    {
        std::cout << re << "i+" << im << std::endl;
    }
};

int operator+(int a, int b) //인자가 모두 primitive 타입인 경우는 오버로딩 할 수 없다.
{
    return a - b;
}

int main()
{
    Complex c1, c2;

    Complex c3 = c1 + c2;
    Complex c4 = c1 + 5;
    Complex c5 = 5 + c1;
}

Complex operator+(const Complex &c, int n)
{
    //......
}

/*
연산자 오버로딩 정리
1. 인자가 모두 primitive 타입인 경우는 오버로딩 할 수 없다
2. 다음의 연산자는 오버로딩 할 수 없다.
.* :: ?: sizeof typeid, static_cast,dynamic_cast,reinterpret_cast,const_cast
멤버접근연산자(.) : C++20부터 operator overloading 가능
3.멤버함수와 멤버가 아닌 일반 함수로 제공할 수 있다.
4.모두 제공할 경우 : 멤버함수가 우선적으로 사용된다.
5.첫번째 인자가 user define type가 아닌 경우는 일반 함수로만 만들 수 있다.
    Complex c3 = c1 + c2; //operator+(c1, c2)
    Complex c4 = c1 + 5;  //operator+(c1, int)
    //c1.operator+(c1, int)도 마찬가지다.

    아래의 경우는 연산자 오버로딩이 불가능
    Complex c5 = 5 + c1;  //operator+(int, c1)
    //5.operator+(Complex)이렇게는 사용이 안되잖아 5가 객체가 아니니깐!(멤버함수로는 불가능)
    operator+(int,Complex)방식으로 해야지 가능(일반함수로만 가능)
6.멤버함수로만 오버로딩 가능한 연산자 : =,(),[],->
7.새로운 연산자를 만들거나,인자의 개수를 변경하거나,연산자 우선순위를 변경할 수 없다.
   ex) int operator+(int a,int b,Complex c1)과 같이 더하기를 3개로 만드는 것 불가능
   ex) int operator+*(int a,int b,Complex c1)와 같이 "+*"을 사용하는 것 불가능
8.default parameter를 사용할수 없다.
   ex) c.operator+()와 같이 사용이 불가능
       Complex operator+(const Complex& c, int n)과 같이 사용
*/

/*
반드시 알아 두어야 하는 연산자들
<< : cout의 원리
++ : STL 반복자를 만드는 원리. 구현과정에서 많은 것을 배울 수 있다
-> : 스마트 포인터
() : 함수객체
[] :객체를 배열처럼 보이게 한다.
= : 복사생성자와 유사한 개념(Shallow copy/deep copy)
string클래스 예제
*/