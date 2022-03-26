/*
-객체지향 프로그래밍에서 변하는 것을 분리하는 방법
변하는 것을 가상함수로(1_10.공통성과가변성의분리_Template_Method_가상함수.cpp)
변하지 않는 것을 다른 클래스로(1_11.공통성과가변성의분리_클래스.cpp)
*/

/*
1.
변하지 않은 코드(전체 흐름)안에 있는
변해야 하는 부분(정책)은 분리하는 것이 좋다

-객체지향 프로그래밍에서 변하는 것을 분리하는 방법
변하는 것을 가상함수로
변하지 않는 것을 다른 클래스로

-변하는 것을 클래스로 분리할 때
교체 가능해야 한다-약한 결합,인터페이스 기반 통신
IValidator 인터페이스 설계
*/
#if 0
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct IValidator
{
    virtual bool validate(string s, char c) = 0;
    virtual bool iscomplete(string s) { return true; }
    virtual ~IValidator() {}
};

/*
2
주민번호 : 801까지 입력했는데 새롭게 1을 입력했다 이게 유효한건가?
"virtual bool validate(string s, char c)"에서 s에 801받고 c에 1받은격이다.
주민번호 입력이 다 끝나면 확인버튼을 누른다.
*/

class Edit
{
    string data;
    IValidator *pVal = 0; //추가

public:
    void setValidator(IValidator *p) //추가
    {
        pVal = p;
    }
    /*
    3.
    Edit는 내부적으로 Validator를 가지고 있는데
    set으로 들어오면 초기화가 되고 아니면 validator가 없다.
    */

    string getData()
    {
        data.clear();
        while (1)
        {
            char c = getch();
            /*
            5.
            엔터가 입력되었는데
            validator가 없으면 break;
            iscomplete(data)가 true를 만족하면 break;
            즉, 주민번호 13자리를 다 입력해야 탈출가능해짐
            */
            if (c == 13 && (pVal == 0 || pVal->iscomplete(data)))
            {
                break;
            }
            /*
            4.
            validation정책이 없으면(pVal == 0) 그냥진행하고
            혹시 있다면
            "pVal->validate(data, c)" 즉 validation정책한다
            지금까지 입력된게 data인데 c가 왔으니깐 입력받아도 되냐 물어본격
            값의 유효성여부를 확인하는 것을 Edit가 직접하는게 아니라
            Validator라는 외부클래스한테 위임하고 있다.
            어떻게 validation할지는 setValidator()에 와야지 알 수 있다.
            */
            if (pVal == 0 || pVal->validate(data, c))
            {
                data.push_back(c);
                cout << c;
            }
        }
        cout << endl;
        return data;
    }
};
/*
6.
IValidator의 파생클래스를 만들어서 인터페이스 구현이 가능해짐
*/

int main()
{
    Edit edit;

    while (1)
    {
        string s = edit.getData();
        cout << s << endl;
    }
}
#endif

#if 0
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct IValidator
{
    virtual bool validate(string s, char c) = 0;
    virtual bool iscomplete(string s) { return true; }
    virtual ~IValidator() {}
};

class Edit
{
    string data;
    IValidator *pVal = 0;

public:
    void setValidator(IValidator *p)
    {
        pVal = p;
    }

    string getData()
    {
        data.clear();
        while (1)
        {
            char c = getch();

            if (c == 13 && (pVal == 0 || pVal->iscomplete(data)))
            {
                break;
            }

            if (pVal == 0 || pVal->validate(data, c))
            {
                data.push_back(c);
                cout << c;
            }
        }
        cout << endl;
        return data;
    }
};

class LimitDigitValidator : public IValidator
{
    int value;

public:
    LimitDigitValidator(int n) : value(n)
    {
    }

    virtual bool validate(string s, char c)
    {
        return s.size() < value && isdigit(c);
        /*
        1.
        value가 13이라고 가정했을때
        s의 길이가 13보다 작고 숫자가 들어오면 true로 리턴
        */
    }
};

int main()
{
    Edit edit;
    //2.
    LimitDigitValidator v(5); //5자리까지 입력받겠다.
    edit.setValidator(&v);    //edit의 정책은 이걸 써라

    while (1)
    {
        string s = edit.getData();
        cout << s << endl;
    }
}
/*
3.

위의 코드는 3자리까지 입력하고 enter쳐도 입력이 들어간다.
5이하의 코드까지 다 허용해주니깐 가능한거다.

"if (c == 13 && (pVal == 0 || pVal->iscomplete(data)))"여기가 항상 true니깐

나는 위의 코드에서
"virtual bool validate(string s, char c)"만 재정의해줬다.
*/
#endif

#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct IValidator
{
    virtual bool validate(string s, char c) = 0;
    virtual bool iscomplete(string s) { return true; }
    virtual ~IValidator() {}
};

class Edit
{
    string data;
    IValidator *pVal = 0;

public:
    void setValidator(IValidator *p)
    {
        pVal = p;
    }

    string getData()
    {
        data.clear();
        while (1)
        {
            char c = getch();

            if (c == 13 && (pVal == 0 || pVal->iscomplete(data)))
            {
                break;
            }

            if (pVal == 0 || pVal->validate(data, c))
            {
                data.push_back(c);
                cout << c;
            }
        }
        cout << endl;
        return data;
    }
};

class LimitDigitValidator : public IValidator
{
    int value;

public:
    LimitDigitValidator(int n) : value(n) {}

    virtual bool validate(string s, char c)
    {
        return s.size() < value && isdigit(c);
    }

    virtual bool iscomplete(string s) //재정의
    {
        return s.size() == value;
    }
};

int main()
{
    Edit edit;
    LimitDigitValidator v(5);
    edit.setValidator(&v);

    while (1)
    {
        string s = edit.getData();
        cout << s << endl;
    }
}

/*
-객체지향 프로그래밍에서 변하는 것을 분리하는 방법
변하는 것을 가상함수로(1_10.공통성과가변성의분리_Template_Method_가상함수.cpp)
변하지 않는 것을 다른 클래스로(1_11.공통성과가변성의분리_클래스.cpp)

뭐가 더 좋을까??
*/
