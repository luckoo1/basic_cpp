#if 0
class Animal
{
    int age;
};

class Dog : public Animal
{
    int color;
};

int main()
{
    Dog d;

    Dog *p1 = &d; //ok

    double *p2 = &d; //ng

    Animal *p3 = &d; //ok(upcasting)
    //기반클래스 포인터에 파생클래스의 주소를 담을 수 있다.
    //그림필기
}

/*
//그림필기
탐색기의 예를 생각해보자
Folder와 File이 있다

Folder안에는 Folder와 File이 들어갈수 있다.
vector<File*>
vector<Folder*>

그래서 Folder와 File의 공통의 기반class Item을 만들었다
vector<Item*>하면 Folder와 File을 담을 수 있다.
*/

/*
Folder와 File뿐 아니라 Folder도 보관하려면 File과 Folder의 공통의 기반 클래스가 있어야한다.
*/

/*
//그림필기
파워포인트에 사각형과 원이 있다.
Rect class와 Circle class가 있다
사각형과 원을 묶을수 있으니깐, Group이란 class가 있고 사각형과 원이 다 들어가야한다.
사각형과 원의 기반클래스 Shape를 두고 그걸 보관하게 했다.
Group이라는 클래스에 vector<Shape*>를 두어서 사각형과 원을 보관했다.

작은 Group을 큰 Group을 넣을 수 있다
Item이라는 공통의 기반 클래스를 만들었다
vector<Item*>을 만들었다
*/
#endif

#if 0
#include <iostream>
using namespace std;

class Animal
{
    int Age;

public:
    void Cry() { cout << "Animal Cry" << endl; }
};

class Dog : public Animal
{
    int color;

public:
    //Override(오버라이드)
    //파생클래스에 기반클래스의 멤버함수를 재정의하는 것
    void Cry() { cout << "Dog Cry" << endl; }
};

int main()
{
    Dog d;
    Animal *p = &d;

    p->Cry();//Animal Cry
}
#endif

#include <iostream>
using namespace std;

class Animal
{
    int Age;

public:
    virtual void Cry() { cout << "Animal Cry" << endl; } //virtual 추가
};

class Dog : public Animal
{
    int color;

public:
    //Override(오버라이드)
    //파생클래스에 기반클래스의 멤버함수를 재정의하는 것
    virtual void Cry() override { cout << "Dog Cry" << endl; }
};

int main()
{
    Dog d;
    Animal *p = &d;

    p->Cry(); //Dog Cry
}
/*
기반 클래스 포인터로 파생 클래스를 가리킬때
파생 클래스가 재정의한 함수가 호출되게 하려면 반드시 가상함수로 만들어야한다.
*/