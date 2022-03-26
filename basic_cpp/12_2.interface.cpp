#if 0
#include <iostream>

class Camera
{
public:
    void take()
    {
        std::cout << "take picture" << std::endl;
    }
};

class People
{
public:
    void useCamera(Camera *p)
    {
        p->take();
    }
};

int main()
{
    People p;
    Camera c1;
    p.useCamera(&c1);
}

#if 0
//1. 새로운 카메라가 나왔다!
#include <iostream>

class Camera
{
public:
    void take()
    {
        std::cout << "Camera take picture" << std::endl;
    }
};

class HDCamera //2. 새로운 HD 카메라
{
public:
    void take()
    {
        std::cout << "HD Camera take picture" << std::endl;
    }
};

class People
{
public:
    void useCamera(Camera *p)
    {
        p->take();
    }
    //4."HDCamera *p"추가했다.
    void useCamera(HDCamera *p)
    {
        p->take();
    }
};

int main()
{
    People p;
    Camera c1;
    p.useCamera(&c1);
    //3.새로운 HD카메라 구매했다.
    HDCamera c2;
    p.useCamera(&c2);
}

/*
나중에 추가된 HDCamera코드때문에 people class가 변경되었다.

강한결합(tightly coupling)
하나의 클래스가 다른 클래스를 사용할 떄 서로의 이름을 직접 사용하는것
교체 불가능하고 확장성이 없다.
useCamera에서 "Camera* p"같이 직접 이름을 사용한다.
*/

#if 0
#include <iostream>
/*
1.
사람과 카메라사이의 규칙을 설계하자
모든 카메라는 ICamera부터 파생되어야 한다.
즉 ICamera로부터 파생될려면 모두 take를 멤버함수로 가져야한다.
*/
class ICamera
{
public:
    virtual void take() = 0;
};

class People
{
public:
    void useCamera(ICamera *p) //2.추상클래스의 포인터로 만들었다.
    {
        p->take();
    }
};
/*
7.
내생각
ICamera*p에 upcasting으로 camera c1이 들어갓다.
p->take()를 하려했는데 take()가 가상함수니깐
p객체 자체를 보고 take()를 호출하는게 아니라
p의 메모리를 조사해서 take()를 호출한다.
*/

//3.모든 카메라는 규칙을 지켜야한다.

class Camera : public ICamera
{
public:
    virtual void take() override //4.반드시 take를 만들어야지
    {
        std::cout << "Camera take picture" << std::endl;
    }
};

class HDCamera : public ICamera
{
public:
    virtual void take() override //5.반드시 take를 만들어야지
    {
        std::cout << "HD Camera take picture" << std::endl;
    }
};

//6.이제 카메라 추가가 자유로워졌다.

class UHDCamera : public ICamera
{
public:
    virtual void take() override
    {
        std::cout << "UHD Camera take picture" << std::endl;
    }
};
int main()
{
    People p;

    Camera c1;
    p.useCamera(&c1);

    HDCamera c2;
    p.useCamera(&c2);

    UHDCamera c3;
    p.useCamera(&c3);
}

/*
설계를 할때
사람과 카메라가 지켜야하는 규칙을 설계했다
사람이 카메라를 사용하는데
"void useCamera(ICamera *p)"로 만들었다.
*/

/*
그림필기 참조
약한 결합(loosely coupling)
하나의 클래스가 다른 클래스를 사용할때 인터페이스(추상 클래스)를 사용하는것
교체가능하고 확장성이 높다
*/

#include <iostream>
//아래의 것이 인터페이스
class ICamera
{
public:
    virtual void take() = 0;
    virtual ~ICamera() {} //소멸자도 가상으로 만들어줬다.
};

/*
아래와 같이 struct를 사용할 수도 있다.
struct ICamera
{
    virtual void take() = 0;
    virtual ~ICamera() {}
};
*/

/*
아래와 같이 사용할 수도 있다.
#define interface struct
interface ICamera
{
    virtual void take() = 0;
    virtual ~ICamera() {}
};
*/

class People
{
public:
    void useCamera(ICamera *p)
    {
        p->take();
    }
};

class Camera : public ICamera
{
public:
    virtual void take() override
    {
        std::cout << "Camera take picture" << std::endl;
    }
};
class HDCamera : public ICamera
{
public:
    virtual void take() override
    {
        std::cout << "HD Camera take picture" << std::endl;
    }
};
class UHDCamera : public ICamera
{
public:
    virtual void take() override
    {
        std::cout << "UHD Camera take picture" << std::endl;
    }
};
int main()
{
    People p;

    Camera c1;
    p.useCamera(&c1);

    HDCamera c2;
    p.useCamera(&c2);

    UHDCamera c3;
    p.useCamera(&c3);
}

/*
"모든 카메라는 ICamera부터 파생되어야 한다."
라는 말대신에
모든 카메라는 ICamera 인터페이스를 구현해야 한다.

객체지향 디자인은 인터페이스를 만들고 이 인터페이스를 통신하면서 교체가능하게 만들어가야한다.
*/