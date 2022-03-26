//그림필기
/*
Template_Method
변하는 것을 가상함수로 만들었다
변하는 것을 변경하고 싶으면 파생클래스를 만들어라

상속기반이다.
*/
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Edit
{
    string data;

public:
    virtual bool validate(char c)
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

            if (validate(c))
            {
                data.push_back(c);
                cout << c;
            }
        }
        cout << endl;
        return data;
    }
};

class AddressEdit : public Edit
{
public:
    virtual bool validate(char c)
    {
        return true;
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
Strategy pattern

IValidator라는 기반 클래스를 두어서 변하는 것을 파생 클래스로 뽑아낸다
상속이 아닌 구성(composition)을 쓴다
*/

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
1.
Strategy pattern은 정책을 실행시간에 바꿀수 있다
아래와 같은 방법을 사용
LimitDigitValidator v(5);
edit.setValidator(&v);
template method는 실행시간에 정책변경이 불가능하다.
정책을 변경하려면
AddressEdit edit;
AddressEdit2 edit2;
AddressEdit3 edit3;과 같이
추가해줘야한다.
즉 새로운 AddressEdit를 만들어 준거다.

2.
여러줄을 입력받는 multiedit가 있다고 가정해보자
multiedit가 IValidator정책을 쓸 수 있다.
다른 클래스에서도 IValidator정책을 쓸 수 있다.

하지만 AddressEdit가 쓰고 있는 이 정책은
    virtual bool validate(char c)
    {
        return true;
    }
AddressEdit안에 멤버함수로 있다 
AddressEdit만 이 정책을 사용할 수 있지 다른 곳에서는 쓸 수 없다.

위에 설명에 대한 내생각
Edit의 멤버함수로 AddressEdit있으니깐
Edit를 상속받아야지만 쓸 수 있는데
만약에 MultiEdit class가 새로생겼다면
이 MultiEdit class안에서 또 AddressEdit를 멤버함수로 넣고 가상함수로 만들어줘야 하잖아

3.
전략패턴은
정책을 재사용할 수 있고
실행 시간에 정책을 교체할 수 있다.
구성(composition)을 사용하는 기법이 위의 장점이 있다.

4.
상속기반의 패턴은 유연성이 떨어지고 실행시간에 무언가를 교체하는 것이 불가능
하지만 실행시간에 교체가 필요없는 경우에는 이게 낫다.
예를 들어 도형편집기 코딩에서 사각형을 어떻게 그릴지는 다른사람이 알 필요는 없고 바뀔일도 없다.
재사용성이 필요없는거다.

5.
재사용성이 필요하고 실행시간에 정책을 교체해야하면 전략패턴 그게 아니면 template method
*/

/*
1.
template method
모든 파생클래스의 공통적인 특징을 기반클래스에 넣고
템플릿 메소드에서 알고리즘 골격을 정의("virtual void Draw() final")
    cout << "Mutex lock" << endl;
    DrawImp();
    cout << "mutex unlock" << endl;
이건 공통의 부분이잖아
전체흐름이 여기에 있다.

2.
알고리즘의 여러 단계중 일부는 서브 클래스에서 구현-훅(hook메소드)
DrawImp();부분은 서브클래스가 책임을 진다.
DrawImp()를 보통 hook메소드라고 부른다.
파생클래스가 재정의한다.

사실
protected:
    virtual void DrawImp() = 0;
    {
        cout << "Draw Shape" << endl;
    }
처럼 "=0;"추가하는 것이 좋다.
shape가 실제로 그려지는게 아니잖아.
순수가상함수가 좋다
아래와 같이 순수가상함수 넣어줌

3.
알고리즘의 구조를 유지하면서 서브클래스에서 특정 단계를 재정의

그림필기3
*/

#include <iostream>
#include <vector>
using namespace std;

class Shape
{
protected:
    virtual void DrawImp() = 0; //이게 hook method

public:
    virtual void Draw() final //이게 template method
    {
        cout << "Mutex lock" << endl;
        DrawImp(); //이게 operation
        cout << "mutex unlock" << endl;
    }
    virtual Shape *Clone() = 0;
};

class Rect : public Shape
{
public:
    virtual void DrawImp() override { cout << "Draw Rect" << endl; }
    virtual Shape *Clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
    virtual void DrawImp() override { cout << "Draw Circle" << endl; }
    virtual Shape *Clone() { return new Circle(*this); }
};

int main()
{
    vector<Shape *> v;

    while (1)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 1)
        {
            v.push_back(new Rect);
        }
        else if (cmd == 2)
        {
            v.push_back(new Circle);
        }
        else if (cmd == 8)
        {
            cout << "index >>";
            int k;
            cin >> k;
            v.push_back(v[k]->Clone());
        }
        else if (cmd == 9)
        {
            for (auto p : v)
            {
                p->Draw();
            }
        }
    }
}

/*
전략패턴
알고리즘의 군을 정의하고, 각각을 캡슐화해서 교환해서 사용할 수 있도록 만든다.
LimitDigitValidator을 정의하고 IValidator정책을 다양하게 사용할 수 있는거다.

전략패턴을 활용하면 클라인트와는 독립적으로 알고리즘을 변경할 수 있다.
그림필기4
client는 인터페이스를 통해서 validation을 쓰고 있다.

excute가
    virtual bool validate(string s, char c)
    {
        return s.size() < value && isdigit(c);
    }
다.
*/

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

    virtual bool iscomplete(string s)
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