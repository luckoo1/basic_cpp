#if 0
/*
게임의 캐릭터는 아이템을 획득함에 따라 동작이 달라진다
아이템의 상태에 따라 달리기 공격하기 동작을 변경해야한다.
*/
#include <iostream>
using namespace std;

class Character
{
    int gold = 0;
    int item = 0;

public:
    void run() { cout << "Run" << endl; }
    void attack() { cout << "Attack" << endl; }
};

int main()
{
    Character *p = new Character;
    p->run();
    p->attack();
}
#endif

#if 0
/*
방법1
전통적 C방법
-item에 따른 조건 분기(if,switch)
모든 동작 함수에 조건 분기문이 필요
새로운 아이템 추가시 모든 동작함수에 분기문이 추가된다.
*/

#include <iostream>
using namespace std;

class Character
{
    int gold = 0;
    int item = 0;

public:
    //아이템의 획득에 따라 다르게 동작한다.
    void run()
    {
        if (item == 1)
        {
            cout << "Run" << endl;
        }
        else if (item == 2)
        {
            cout << "Fast Run" << endl;
        }
    }
    void attack()
    {
        if (item == 1)
        {
            cout << "Attack" << endl;
        }
        else if (item == 2)
        {
            cout << "Power Up Attack" << endl;
        }
    }
};

int main()
{
    Character *p = new Character;
    p->run();
    p->attack();
}

#endif

#if 0
/*
방법2
변하는 것을 가상함수로!
아이템 획득시의 동작 변경을 파생클래스에서 재정의
*/
#include <iostream>
using namespace std;

class Character
{
    int gold = 0;
    int item = 0;

public:
    void run() { runImp(); }
    void attack() { attackImp(); }

    virtual void runImp() {}
    virtual void attackImp() {}
};

class NormalCharacter : public Character
{
public:
    virtual void runImp() { cout << "Run" << endl; }
    virtual void attackImp() { cout << "Attack" << endl; }
};

class PowerItemCharacter : public Character //동작 변경을 파생클래스에서 재정의
{
public:
    virtual void runImp() { cout << "Fast Run" << endl; }
    virtual void attackImp() { cout << "Power Up Attack" << endl; }
};

int main()
{
    Character *p = new NormalCharacter;
    p->run();
    p->attack();

    p = new PowerItemCharacter;
    p->run();
    p->attack();
}
/*
하나의 캐릭터가 달리고 있었는데 기존의 캐릭터가 사라지고 새로운 캐릭터가 생기게되는거다.
예를들어 기존의 캐릭터가 gold가 1000이었다면 새로운 캐릭터는 돈이 없게될수도 있다.

기존 객체의 동작이 변경된 것이 아니라 동작이 변경된 새로운 객체가 생성된 것
객체에 대한 변화가 아닌 클래스에 의한 변화
*/
#endif

/*
방법3
상태에 따라 변경되는 동작들을 다른 클래스로 분리한다
동작의 인터페이스를 정의한다.
*/
#include <iostream>
using namespace std;

struct IState
{
    virtual void run() = 0;
    virtual void attack() = 0;

    virtual ~IState(){};
};

class Character
{
    int gold = 0;
    int item = 0;
    IState *state;

public:
    void changeState(IState *p) { state = p; }
    void run() { state->run(); }
    void attack() { state->attack(); }
};

class NormalState : public IState
{
    virtual void run() { cout << "Run" << endl; }
    virtual void attack() { cout << "Attack" << endl; }
};

class PowerItemstate : public IState
{
public:
    virtual void run() { cout << "Fast Run" << endl; }
    virtual void attack() { cout << "Power Up Attack" << endl; }
};

int main()
{
    NormalState ns;
    PowerItemstate ps;

    Character *p = new Character;
    p->changeState(&ns);
    p->run();
    p->attack();

    p->changeState(&ps); //아이템 획득시 상태바꾸기
    p->run();
    p->attack();
    //동작만 바뀌었지 상태(gold)는 바뀌지 않았다.
}

/*
item에 따른 run(),attack()함수의 동작을 정의한 클래스를 별도로 제공한다
객체의 속성은 유지하지만 동작을 변경할 수 있다.
클래스가 아닌 객체에 대한 변화다.

그런데... 전략패턴이랑 비슷한데????
*/

/*
그림필기
의도가 다르다

State Pattern의 의도
객체 자신의 내부 상태에 따라 행위(동작)를 변경하도록 한다.
객체는 마치 클래스를 바꾸는 것 처럼 보인다.

Strategy Pattern의 의도
다양한 알고리즘이 존재하면 이들 각각을 하나의 클래스로 캡슐화하여 알고리즘의 대체가 가능하도락한다.

즉
State Pattern은 동작
Strategy Pattern은 알고리즘을 변경
*/