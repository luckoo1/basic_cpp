#if 0
/*
Decorator_Pattern
실행시간에 객체에 기능을 추가 할때 사용하는 패턴

우주선이 미사일을 발사하는데 Item획득시 미사일을 옆으로도 쏘게하고싶다.
기존의 동작을 유지하고 새로운 동작이 추가된다.
*/
#include <iostream>
using namespace std;

class SpaceCraft
{
    int color;
    int speed;

public:
    void Fire() { cout << "Space Craft Missile Shot" << endl; }
};

int main()
{
    SpaceCraft sc;
    sc.Fire();
}
#endif

#if 0
//상속을 통한 기능의 추가
#include <iostream>
using namespace std;

class SpaceCraft
{
    int color;
    int speed;

public:
    void Fire() { cout << "Missile Shot" << endl; }
};

class LeftMissile : public SpaceCraft
{
public:
    void Fire()
    {
        SpaceCraft::Fire(); //기존기능 수행
        cout << "Left Missile Shot" << endl;
    }
};

int main()
{
    SpaceCraft sc;
    sc.Fire();

    LeftMissile lm; //아이템 먹으면 객체 생성
    lm.Fire();
}

/*
상속에 의한 기능 추가
객체가 아닌 클래스에 기능을 추가
실행 시간이 아닌 코드 작성시에 기능이 추가됨

sc객체랑 전혀 상관이 없는 lm객체가 생성되었다. 옳지못한 코드이다.
*/
#endif

#if 0
//구성(Composition)통한 기능의 추가
#include <iostream>
using namespace std;

class SpaceCraft
{
    int color;
    int speed;

public:
    void Fire() { cout << "Missile Shot" << endl; }
};

class LeftMissile
{
    SpaceCraft *craft; //멤버로 포인터를 가지고 있다.

public:
    LeftMissile(SpaceCraft *p) : craft(p)
    {
    }
    void Fire()
    {
        craft->Fire(); //기존 기능 수행
        cout << "Left Missile Shot" << endl;
    }
};

int main()
{
    SpaceCraft sc;
    sc.Fire();

    LeftMissile lm(&sc); //기존객체(sc)에 기능이 추가됨
    lm.Fire();
}

/*
기능 추가 방법

상속에 의한 기능 추가
기능추가 대상 : 클래스
기능 추가 시점 : 코드작성시

구성에 의한 기능추가
기능추가 대상 : 객체
기능 추가 시점 : 실행시간

상속은 경직되고 유연성이 부족하지만
구성은 유연성이 많다.
*/
#endif

#if 0
#include <iostream>
using namespace std;

class SpaceCraft
{
    int color;
    int speed;

public:
    void Fire() { cout << "Missile Shot" << endl; }
};

class LeftMissile
{
    SpaceCraft *craft;

public:
    LeftMissile(SpaceCraft *p) : craft(p)
    {
    }
    void Fire()
    {
        craft->Fire();
        cout << "Left Missile Shot" << endl;
    }
};

class RightMissile
{
    SpaceCraft *craft;

public:
    RightMissile(SpaceCraft *p) : craft(p)
    {
    }
    void Fire()
    {
        craft->Fire();
        cout << "Right Missile Shot" << endl;
    }
};

int main()
{
    SpaceCraft sc;
    sc.Fire();

    LeftMissile lm(&sc);
    lm.Fire();

    RightMissile rm(&sc);
    rm.Fire();
}
//오른쪽과 왼쪽 동시에 아이템을 획득해서 동시에 발사하고싶다!
#endif

#if 0
#include <iostream>
using namespace std;

class SpaceCraft
{
    int color;
    int speed;

public:
    void Fire() { cout << "Missile Shot" << endl; }
};

class LeftMissile
{
    SpaceCraft *craft;

public:
    LeftMissile(SpaceCraft *p) : craft(p)
    {
    }
    void Fire()
    {
        craft->Fire();
        cout << "Left Missile Shot" << endl;
    }
};

class RightMissile
{
    SpaceCraft *craft;

public:
    RightMissile(SpaceCraft *p) : craft(p)
    {
    }
    void Fire()
    {
        craft->Fire();
        cout << "Right Missile Shot" << endl;
    }
};

int main()
{
    SpaceCraft sc;
    sc.Fire();

    LeftMissile lm(&sc);
    lm.Fire();

    RightMissile rm(&lm); //sc대신에 lm을 보내고 싶다
    //기능추가된 객체에 다시 기능을 추가하고 싶다.
    //그런데 이건 LeftMissile의 멤버가 SpaceCraft *craft;라서 보낼 수가 없다.
    rm.Fire();
}
/*
우주선(sc)과 우주선에 기능을 추가하는 클래스들은 공통의 기반클래스가 있어야 한다.
그리고 멤버로 기반클래스(Component)의 클래스의 포인터를 받아야 한다.

우주선과 기능추가 객체는 동일한 기반 클래스를 가져야 한다.
그림필기 1
*/
#endif

#if 0
#include <iostream>
using namespace std;

//우주선과 기능추가객체의 공통의 기반 클래스
struct Component
{
    virtual void Fire() = 0;
    virtual ~Component(){};
};

class SpaceCraft : public Component //파생
{
    int color;
    int speed;

public:
    void Fire() { cout << "Missile Shot" << endl; }
};

class LeftMissile : public Component //파생
{
    Component *craft;

public:
    LeftMissile(Component *p) : craft(p)
    {
    }
    void Fire()
    {
        craft->Fire();
        cout << "Left Missile Shot" << endl;
    }
};

class RightMissile : public Component //파생
{
    Component *craft;

public:
    RightMissile(Component *p) : craft(p)
    {
    }
    void Fire()
    {
        craft->Fire();
        cout << "Right Missile Shot" << endl;
    }
};

int main()
{
    SpaceCraft sc;
    LeftMissile lm(&sc);
    RightMissile rm(&lm);

    rm.Fire();
}
#endif

/*
SpaceCraft는 우주선 자체지만
LeftMissile과 RightMissile은 우주선에 기능을 추가하는 것
즉 꾸며주는 객체들이다.
LeftMissile과 RightMissile에 똑같이 생긴 동일한 기능이 있다
기반클래스를 또 만들어 보자
그림필기2
*/
#include <iostream>
using namespace std;

struct Component
{
    virtual void Fire() = 0;
    virtual ~Component(){};
};

class SpaceCraft : public Component
{
    int color;
    int speed;

public:
    void Fire() { cout << "Missile Shot" << endl; }
};

//기능 추가 클래스의 공통의 기반 클래스
class IDecorator : public Component
{
    Component *craft;

public:
    IDecorator(Component *p) : craft(p) {}
    void Fire()
    {
        craft->Fire();
    }
};

class LeftMissile : public IDecorator
{

public:
    LeftMissile(Component *p) : IDecorator(p)
    {
    }
    void Fire()
    {
        IDecorator::Fire(); //기반 클래스 안에 있는걸 불러온다
        cout << "Left Missile Shot" << endl;
    }
};

class RightMissile : public IDecorator
{

public:
    RightMissile(Component *p) : IDecorator(p)
    {
    }
    void Fire()
    {
        IDecorator::Fire(); //기반 클래스 안에 있는걸 불러온다
        cout << "Right Missile Shot" << endl;
    }
};

int main()
{
    SpaceCraft sc;
    LeftMissile lm(&sc);
    RightMissile rm(&lm);

    rm.Fire();
}
/*
Decorator_Pattern의 의도
객체에 동적으로 새로운 서비를 추가할 수 있게 한다
기능 추가를 위해 서브 클래스를 사용하는 것보다 융통성 있는 방법을 제공한다.
*/