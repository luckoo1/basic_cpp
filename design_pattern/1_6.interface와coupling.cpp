#if 0
#include <iostream>
using namespace std;

class Camera
{
public:
    void take() { cout << "take picture" << endl; }
};

class People
{
public:
    void useCamera(Camera *p) { p->take(); }
};

int main()
{
    People p;
    Camera c;
    p.useCamera(&c);
}
#endif

#if 0
//HD카메라가 추가됨
#include <iostream>
using namespace std;

class Camera
{
public:
    void take() { cout << "take picture" << endl; }
};

class HDCamera //추가됨
{
public:
    void take() { cout << "take HD picture" << endl; }
};

class People
{
public:
    void useCamera(Camera *p) { p->take(); }
    void useCamera(HDCamera *p) { p->take(); } //추가해야함
};

int main()
{
    People p;
    Camera c;
    p.useCamera(&c);

    HDCamera hc; //추가됨
    p.useCamera(&hc);
}

/*
HD카메라가 추가되어서
기존의 People class내부의 코드가 수정이 가해짐
OCP에 좋지 못한 Design이다
*/

/*
OCP(Open Closed Principle, 개방폐쇄의 법칙)
기능 확장에는 열려있고(Open),코드수정에는 닫혀있어야(Close),한다는 이론(Principle)
새로운 기능이 추가되어도 기존 코드의 수정이 없도록 만들어야 한다는 규칙
*/

/*
People과 Camera는 강하게 결합되어 있다

강한결합(tightly Coupling)
객체가 서로 상호작용할 때 서로에 대해서 잘 알고(클래스 이름등)있는 것
교체/확장이 불가능한 경직된 디자인
*/
#endif

#if 0
#include <iostream>
using namespace std;
/*
제품(카메라)를 먼저 만들지말고
제품의 인터페이스(규칙,계약)을 먼저 설계하자
*/

//규칙 : 모든 카메라는 아래 클래스로부터 파생되어야한다.

class ICamera
{
public:
    virtual void take() = 0;
};

//카메라가 없어도 카메라를 사용하는 코드를 만들수 있다.
class People
{
public:
    void useCamera(ICamera *p) { p->take(); }
}
/*
진짜 카메라가 없어도 규칙의 포인터를 받음
나는 규칙대로만 썼다.
이제 밑에는 규칙을 지키는 모든 카메라가 올 수 있다
*/
#endif

#if 0
#include <iostream>
using namespace std;

class ICamera
{
public:
    virtual void take() = 0;
};

class People
{
public:
    void useCamera(ICamera *p) { p->take(); }
};
//이제 카메라를 만들때 ICamera로부터 상속받으면 된다.
class Camera : public ICamera
{
public:
    void take() { cout << "take picture" << endl; }
};

class HDCamera : public ICamera
{
public:
    void take() { cout << "take HD picture" << endl; }
};

class UHDCamera : public ICamera
{
public:
    void take() { cout << "take UHD picture" << endl; }
};

//카메라가 추가되어도 people에는 어떠한 수정도 없다.

int main()
{
    People p;

    Camera c;
    p.useCamera(&c);

    HDCamera hc;
    p.useCamera(&hc);

    UHDCamera uhc;
    p.useCamera(&uhc);
}

/*
약한 결합(Loosely Coupling,느슨한 결합)
객체가 서로 상호작용하지만, 서로에 대해 잘 알지 못한다
교체/확장 가능한 유연한 디자인
객체는 상호간에 인터페이스를 통해서 통신해야한다
Client는 구현에 의존하지 말고 인터페이스에 의존한다.

useCamera(ICamera *p)사용했다.
*/

/*
1.public을 쓰기싫어서 struct사용
struct ICamera
{
    virtual void take() = 0;
};

2.define을 사용
#define interface struct
interface ICamera
{
    virtual void take() = 0;
};
*/

/*
규칙 : 모든 카메라는 아래 클래스로부터 파생되어야한다.
위의 표현보다는
"모든 카메라는 아래 인터페이스를 구현해야한다"라는 표현을 쓰자
*/
#endif

#include <iostream>
using namespace std;

class ICamera
{
public:
    virtual void take() = 0;
    virtual ~ICamera() {} //가상소멸자를 무조건 만들어야지!
};

class People
{
public:
    void useCamera(ICamera *p) { p->take(); }
};

class Camera : public ICamera
{
public:
    void take() { cout << "take picture" << endl; }
};

class HDCamera : public ICamera
{
public:
    void take() { cout << "take HD picture" << endl; }
};

class UHDCamera : public ICamera
{
public:
    void take() { cout << "take UHD picture" << endl; }
};

int main()
{
    People p;

    Camera c;
    p.useCamera(&c);

    HDCamera hc;
    p.useCamera(&hc);

    UHDCamera uhc;
    p.useCamera(&uhc);
}