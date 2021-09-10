#if 0
#include <iostream>
using namespace std;
//endl의 정확한 원리는 함수이다

int main()
{
    cout << endl;
    endl(cout); //이렇게 적어도 된다.
}
#endif

#if 0
#include <cstdio>

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
    ostream &operator<<(char c)
    {
        printf("%c", c);
        return *this;
    }
    //3.아래 추가
    ostream &operator<<(ostream &(*f)(ostream &))
    {
        f(*this);
        /*
        4.
        "cout.operator<<(endl)"이니깐
        f가 가리키는게 endl
        this가 가리키는건 cout 
        그러면
        ostream &endl(ostream &os)
        {
            os << '\n';
            return os;
        }
        위의 함수에서 os가 cout이 된다.
        그럼"os << '\n';"부분은
        cout<<'\n'이 된다.
        cout은 char출력가능하다
        */
        return *this;
    }
};

ostream cout;

//1.
ostream &endl(ostream &os)
{
    os << '\n';
    return os;
}

int main()
{
    cout << endl;
    /*
    2.
    이렇게 적으면
    cout.operator<<(endl)
    endl은 함수이니깐
    cout.operator<<(함수포인터)
    이런모양이 되는거다
    */
}

/*
5.
여기서 질문이 그러면 그냥
cout<<'\n'하면되자나
아니면 const char* endl ='\n'
하면되는거 아냐?

답변
cout<<"A"<<tab<<"B"<<endl;이거 가능한가?
tab을 쓰고싶다
*/
#endif
#if 0
#include <cstdio>

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
    ostream &operator<<(char c)
    {
        printf("%c", c);
        return *this;
    }

    ostream &operator<<(ostream &(*f)(ostream &))
    {
        f(*this);
        return *this;
    }
};

ostream cout;

ostream &endl(ostream &os)
{
    os << '\n';
    return os;
}

//여기 tab함수 추가
ostream &tab(ostream &os)
{
    os << '\t'; //이렇게 수정

    return os;
}

int main()
{
    cout << 'A' << tab << 'B' << endl;
}

//이제 cout << menu도 추가해볼가
#endif
#if 0
#include <cstdio>

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
    ostream &operator<<(char c)
    {
        printf("%c", c);
        return *this;
    }

    ostream &operator<<(ostream &(*f)(ostream &))
    {
        f(*this);
        return *this;
    }
};

ostream cout;

ostream &endl(ostream &os)
{
    os << '\n';
    return os;
}

ostream &tab(ostream &os)
{
    os << '\t';
    return os;
}
//여기 menu함수 추가

ostream &menu(ostream &os)
{
    os << "1.아이폰";
    os << "2.아이패드";
    return os;
}

int main()
{
    cout << 'A' << tab << 'B' << endl;
    cout << menu;
}
#endif
//1.
//일단 표준에 있는걸 주석으로 막아보자
//우리가 만든 ostream을 주석으로 막은 것
/*
#include <cstdio>

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
    ostream &operator<<(char c)
    {
        printf("%c", c);
        return *this;
    }

    ostream &operator<<(ostream &(*f)(ostream &))
    {
        f(*this);
        return *this;
    }
};

ostream cout;

ostream &endl(ostream &os)
{
    os << '\n';
    return os;
}
*/
/*
2.cout과 endl은 C++표준이라서 사용이 가능하지 당연히
tab이랑 menu는 우리가 만든건다
근데 잘 실행된다
endl을 함수로 설계한거는
사용자에게 tab이나 menu같이 사용자가 원하는 모든것을 만들어서 쓰게하기 위해서다
*/
#include <iostream>
using namespace std;

ostream &tab(ostream &os)
{
    os << '\t';
    return os;
}
//여기 menu함수 추가

ostream &menu(ostream &os)
{
    os << "1.I_phone";
    os << "2.I_pad";
    return os;
}

int main()
{
    cout << 'A' << tab << 'B' << endl;
    cout << menu;
}

/*
정리
1.endl은 함수이다
cout<<endl;
endl(cout)

2.hex,dec,alpha 등은 모두 함수다
입출력 조정자 함수(i/o manipulator)
cout<<hex<<10<<endl;

사용자가 직접 만들 수 있다
tab 예제
*/