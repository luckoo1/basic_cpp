#if 0
//헤더파일 주석으로 막고 cout만들어보자
//#include <iostream>
//using namespace std;

//ostream class만들고 
class ostream
{
};

ostream cout;//cout객체 만들었다.

int main()
{
    cout << 3;
    cout << 3.4;
}
#endif
#if 0
#include <cstdio> //3.헤더 추가
class ostream
{
public:
    //2. void operator<<()를 만들었다.
    void operator<<(int n) { printf("%d", n); }
    void operator<<(double d) { printf("%f", d); }
};

ostream cout;

int main()
{
    cout << 3;
    //1.이게 돌아가게 할려면 cout.operator<<(3)
    //이런격이 되어야한다.
    cout << 3.4;
}

/*
모든 primitive타입에 대해서 operator<<()연산자 함수 제공
*/
#endif

#if 0
#include <cstdio>
class ostream
{
public:
    //2.리턴을 ostream으로 하게 만들고
    ostream operator<<(int n)
    {
        printf("%d", n);
        return *this; //3.리턴this추가함
    }
    ostream operator<<(double d)
    {
        printf("%f", d);
        return *this;
    }
    //4.위와 같이 리턴하면 임시객체리턴이다
};

ostream cout;

int main()
{
    cout << 3;
    cout << 3.4;
    cout << 3 << 4; //1.cout의 장점은 연속적으로 출력하는거다.
}
#endif

#if 0
#include <cstdio>
class ostream
{
public:
    //참조타입으로 리턴하게 했다
    ostream &operator<<(int n)
    {
        printf("%d", n);
        return *this;
    }
    ostream &operator<<(double d)
    {
        printf("%f", d);
        return *this;
    }
};

ostream cout;

int main()
{
    cout << 3;
    cout << 3.4;
    cout << 3 << 4;
}
/*
리턴 값이 중요 : 자기 자신을 참조로 리턴한다
여러개를 연속적으로 출력할 수 있게 된다

실제로 화면에 출력하는 원리는?
각 OS가 제공하는 시스템 콜 사용
windows : windows API사용-WriteFile()
linux : linux system call 사용-write() 
*/
#endif
#if 0
#include <cstdio>
//이런 ostream이 namespace std안에있다.
namespace std
{
    class ostream
    {
    public:
        ostream &operator<<(int n)
        {
            printf("%d", n);
            return *this;
        }
        ostream &operator<<(double d)
        {
            printf("%f", d);
            return *this;
        }
    };

    ostream cout;
}

int main()
{
    std::cout << 3;
    std::cout << 3.4;
    std::cout << 3 << 4;
}
#endif

//1998년 표준화 이전
class ostream
{
};

//1998년 표준화 이후
template <typename T, typename Traits = char_traits<T>>
class basic_ostream
{
    //operator<<()
    //......
};

typedef basic_ostream<char> ostream;
typedef basic_ostream<wchar_t> wostream;
/*
유니코드도 고려하려고 template쓴다
일반 문자열 쓸때면 ostream
유니코드 쓸려면 wotream
*/
ostream cout;
wostream wcout;

#include <iostream>
#include <string>
int main()
{
    std::cout << "hello";
    std::wcout << L"hello"; //유니코드

    std::string s1 = "hello";
    std::wstring s2 = L"hello";
}

/*
정리
cout의 정확한 타입은 ostream이 아닌 basic_ostream템플릿
typedef basic_ostream<char> ostream;
typedef basic_ostream<wchar_t> wostream;

유니코드 출력
ostream cout;
wostream wcout;
*/