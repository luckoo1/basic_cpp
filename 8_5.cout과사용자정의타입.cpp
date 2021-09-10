#if 0
#include <iostream>
using namespace std;

class Complex
{
    int re, im;

public:
    Complex(int r = 0, int i = 0) : re(r), im(i) {}
    void print() const
    {
        cout << re << ", " << im << endl;
    }
};

int main()
{
    Complex c(1, 1);
    c.print(); //기존에 이렇게 출력하는걸 했는데
    cout << c; //이렇게 출력은 안될까?
}
#endif
#if 0
#include <iostream>
using namespace std;

class Complex
{
    int re, im;

public:
    Complex(int r = 0, int i = 0) : re(r), im(i) {}
};

int main()
{
    Complex c(1, 1);
    cout << c;
    /*
    cout.operator<<(c)
    위에처럼 보내니깐
    operator<<함수에서 인자를 Complex로 갖는격
    cout.operator<<(Complex)
    cout안에 operator<<()에서 Complex받는게 있으면 된다.
    ostream class 멤버함수에 operator<<()넣으면 된다
    ostream class는 우리가 만든게 아니니 멤버함수에 operator<<()추가가 불가능
    
    operator<<(cout,c)
    전역함수로 하자!
    */
}
#endif

#include <iostream>
using namespace std;

class Complex
{
    int re, im;

public:
    Complex(int r = 0, int i = 0) : re(r), im(i) {}
    friend ostream &operator<<(ostream &, const Complex &); //3.freind로 private접근하게 해주었따
};
/*
2.
첫번째 인자로 cout이니깐 ostream &os적었는데
정확히는 basic_ostream이라도 typedef하고 있어서 적어도 괜찮다.
"typedef basic_ostream<char> ostream;"
*/
ostream &operator<<(ostream &os, const Complex &c)
{
    os << c.re << "i+" << c.im;
    return os;
}

int main()
{
    Complex c(3, 2);
    //1.
    cout << c; // operator<<(cout,c)
    //cout<<c<<endl;방식처럼 써야하니깐 ostream방식으로 리턴하게 하자
}

/*
사용자 정의 타입을 cout으로 출력하는 방법
operator<<()함수를 일반 함수로 제공하면 된다
*/

/*
추가질문!
ostream &operator<<(ostream &os, const Complex &c)에서
왜 const가 두번째 인자만 붙을까?
"const ostream &os"하면 상수객체 된다
상수객체는 상수멤버함수만 부를 수 있다.
os.operator<<(3);
C++표준에서 operator<<()는 상수함수가 아니다
c의 값은 꺼내기만 하면되니깐!
*/