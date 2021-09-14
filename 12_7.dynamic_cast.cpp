#if 0
class Animal
{
public:
    virtual ~Animal() {}
};

class Dog : public Animal
{
public:
    int color;
};

//아래 함수는 Animal뿐만 아니라 Animal의 파생클래스도 가질 수 있다.
void foo(Animal *p)
{
    //혹시 p가 Dog라면 color를 바꾸고 싶다
    p->color = 10;
    //animal type로는 파생클래스의 고유한멤버에 접근이 불가능
    //error뜬다
}

int main()
{
    Animal a;
    foo(&a);
    Dog d;
    foo(&d);
}
#endif

#if 0
#include <iostream>

class Animal
{
public:
    virtual ~Animal() {}
};

class Dog : public Animal
{
public:
    int color;
};

void foo(Animal *p)
{
    //1. p를 dog type로 캐스팅해야한다.
    //upcating된 코드를 다시 자신의 type로 바꾸는것이 downcasting인데
    Dog *pDog = static_cast<Dog *>(p);
    //p가 dog일때는 문제가 없지만 p가 animal이면 문제가 된다.

    std::cout << pDog << std::endl;
    /*
    실행결과
    0x61ff1c //animal의 주소
    0x61ff14 //dog의 주소
    다른주소가 나온다.
    */
}

int main()
{
    Animal a;
    foo(&a);
    Dog d;
    foo(&d);
}

/*
down casting
upcasting된 포인터를 원래의 타입으로 캐스팅하는것

static_cast
컴파일 시간에 캐스팅
기반 클래스의 포인터가 실제 어떤 타입의 객체를 가리키는지 조사할 수 없다.
*/
#endif

#if 0
#include <iostream>

class Animal
{
public:
    virtual ~Animal() {}
};

class Dog : public Animal
{
public:
    int color;
};

void foo(Animal *p)
{

    Dog *pDog = dynamic_cast<Dog *>(p);
    std::cout << pDog << std::endl;
    /*
    실행결과
    0
    0x61ff14
    */
}

int main()
{
    Animal a;
    foo(&a);
    Dog d;
    foo(&d);
}
/*
dynamic_cast
실행시간 캐스팅
잘못된 down casting사용시 0반환
가상함수가 없는 타입은 dynamic_cast를 사용할 수 없다.

dynamic_cast원리가 결국은 가상함수 테이블을 조사하는거다
가상함수가 없으면 dynamic_cast사용이 불가능
*/
#endif

#if 0
#include <iostream>
class Animal
{
public:
    virtual ~Animal() {}
};

class Dog : public Animal
{
public:
    int color;
};

void foo(Animal *p)
{
    //밑의 코드처럼 조사 이후에 static_cast사용 가능
    if (typeid(*p) == typeid(Dog))
    {
        Dog *pdog = static_cast<Dog *>(p);
    }
}

int main()
{
    Animal a;
    foo(&a);
    Dog d;
    foo(&d);
}
#endif