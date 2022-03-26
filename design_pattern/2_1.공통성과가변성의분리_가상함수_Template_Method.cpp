/*
-객체지향 프로그래밍에서 변하는 것을 분리하는 방법
변하는 것을 가상함수로(1_10.공통성과가변성의분리_Template_Method_가상함수.cpp)
변하지 않는 것을 다른 클래스로(1_11.공통성과가변성의분리_클래스.cpp)
*/

#if 0
#include <iostream>
#include <string>
using namespace std;

class Edit
{
    string Data;

public:
    string getData()
    {
        cin >> Data;
        return Data;
    }
};

int main()
{
    Edit edit;

    while (1)
    {
        string s = edit.getData();
        cout << s << endl;
    }
}

/*
나이를 입력받는 경우를 가정해보자
나이는 숫자니깐 문자를 받으면안된다

입력값을 validation을 위한 코드 추가
한자씩 입력받아야한다.
*/
#endif

#if 0
/*
이제 주소를 입력받는다고 가정해보자
문자와 숫자를 다 바꿔야한다.
*/
#include <iostream>
#include <string>
#include <conio.h> //getch() : 한자씩 입력받는 함수
using namespace std;

class Edit
{
    string data;

public:
    string getData()
    {
        data.clear();
        while (1)
        {
            char c = getch();
            if (c == 13)
                break;

            if (isdigit(c))//숫자 확인
            {
                data.push_back(c);
                cout << c;
            }
        }
        cout << endl;
        return data;
    }
};
#endif

#if 0
/*
이제 주소를 입력받는다고 가정해보자
문자와 숫자를 다 바꿔야한다.
*/
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Edit
{
    string data;

public:
    string getData()
    {
        data.clear();
        while (1)
        {
            char c = getch();
            if (c == 13)
                break;

            if (isdigit(c)) //validation정책을 바꿔야한다.
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
Edit는 보통 라이브러리 내부의 클래스
validation을 변경하기 위해서 
함부로 "if (isdigit(c))" 부분을 변경해선 안된다.
설계를 할때 validation부분을 외부에서 교체할수 있게 제공해야한다.

validation 교체를 위한 방법은 크게 2가지가 있다.
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
/*
변하지 않은 코드(전체 흐름)안에 있는
변해야 하는 부분(정책)은 분리하는 것이 좋다.

변해야 하는 부분(validation 정책)을 별도의 가상 함수로 분리하자.
*/

/*
변하는 것(Validation 정책)을 가상 함수로 분리할때의 장점
Validation 정책을 변경하고 싶다면 Edit의 파생 클래스를 만들어서 validata() 가상함수를 재정의하면 된다.
*/

#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Edit
{
    string data;

public:
    virtual bool validate(char c) //변해야 하는 부분(정책)은 분리
    {
        return isdigit(c);
    }

    string getData()
    {
        data.clear();
        while (1)
        {
            char c = getch();
            if (c == 13)
                break;

            if (validate(c)) //변경
            {
                data.push_back(c);
                cout << c;
            }
        }
        cout << endl;
        return data;
    }
};

//내부코드변경이 아닌 확장이다
class AddressEdit : public Edit
{
public:
    virtual bool validate(char c)
    {
        return true; //true로 리턴해서 문자도 받게했다.
    }
};

int main()
{
    AddressEdit edit;

    while (1)
    {
        string s = edit.getData();
        cout << s << endl;
    }
}
/*
Template Method Pattern
*/