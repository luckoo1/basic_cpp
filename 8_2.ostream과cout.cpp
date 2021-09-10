#if 0
#include <iostream>
using namespace std;

namespace std
{
    class ostream
    {

    };
    ostream cout; //2.cout이라는 객체 있는 격
}
//3.std namespace안에 ostream이라는 class가 있고 cout이라는 객체가 있는 격이다.

int main()
{
    int n = 10;
    double d = 3.4;

    cout << n; //4.cout.operator<<(n)
    //5.즉 cout에 멤버함수 "operator<<"가 불리는거구 인자로 n이 들어간다
    cout << d;
}

//1.cout은 객체다.
//  cout.찍으면 멤버함수들이 보인다.
#endif
#if 0
#include <iostream>
using namespace std;

namespace std
{
    class ostream
    {
        //2.실제로 이안에 이런 operator가 있는거다
        operator<<(int);    //int버전
        operator<<(double); //double버전
    };
    ostream cout;
}

int main()
{
    int n = 10;
    double d = 3.4;

    //1.
    cout << n; //cout.operator<<(n)
    //이건 int버전
    cout << d; //cout.operator<<(d)
    //이건 double버전
}
#endif

#include <iostream>
using namespace std;

int main()
{
    int n = 10;
    double d = 3.4;
    //실제로 이렇게 쓰는거와 같다
    cout.operator<<(n);
    cout.operator<<(d);
}
/*
cout은 ostream타입의 객체

<<연잔사를 각각의 primitive타입에 대해서 연산자 오버로딩한 것
cout<<5 =>cout.operator<<(int)
cout<<3.4 =>cout.operator<<(double)
*/