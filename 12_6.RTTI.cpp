//Run Time Type Information
#if 0
#include <iostream>
#include <typeinfo>

class Animal
{
};

class Dog : public Animal
{
};

//1.아래 함수는 Animal뿐만 아니라 Animal의 파생클래스도 가질 수 있다.
void foo(Animal *p)
{
    //2.정말 Animal인지? dog인지 cat인지 어떻게 알까??

    //4.
    //const std::type_info &t2 = typeid(p); //이렇게하면 무조건 Animal type나온다.
    const std::type_info &t1 = typeid(*p);
    std::cout << t1.name() << std::endl; //"class Animal"로 결과가 나온다
}

int main()
{
    Animal a;
    foo(&a);
    Dog d;
    foo(&d);
}
/*
3.
Run Time Type Information(RTTI)
실행 시간에 타입의 정보를 조사하는 기법
*/

/*
typeid
가상함수가 없는 객체 : 컴파일 시간에 타입조사
가상함수가 있는 객체 : 실행시간에 타입을 조사(가상함수 테이블 정보 참고)
*/
#endif

#if 0
#include <iostream>
#include <typeinfo>

class Animal
{
    //가상함수를 추가해주었다.
public:
    virtual ~Animal() {}
};

class Dog : public Animal
{
};

void foo(Animal *p)
{
    //가상함수가 있는 객체 : 실행시간에 타입을 조사(가상함수 테이블 정보 참고)
    const std::type_info &t1 = typeid(*p);
    std::cout << t1.name() << std::endl;
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
#include <typeinfo>

class Animal
{
public:
    virtual ~Animal() {}
};

class Dog : public Animal
{
};

void foo(Animal *p)
{
    const std::type_info &t1 = typeid(*p);
    const std::type_info &t2 = typeid(Dog);
    //std::typeinfo로 동일 타입을 조사하는 방법

    //1.
    if (t1 == t2)
    {
    }
    //"==" 연산자가 재정의된격
    //if(&t1 == &t2)와 같이 사용하는건 C++표준문서에 보장되지 않음

    //2. c++11부터
    if (t1.hash_code() == t2.hash_code())
    {
    }

    //3. c++11부터
    if (std::type_index(t1) == std::type_index(t2))
    {
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
//실전에서는
#include <iostream>
#include <typeinfo>

class Animal
{
public:
    virtual ~Animal() {}
};

class Dog : public Animal
{
};

void foo(Animal *p)
{
    if (typeid(*p) == typeid(Dog))
    {
        std::cout << "p == Dog" << std::endl;
    }
}

int main()
{
    Animal a;
    foo(&a);
    Dog d;
    foo(&d);
}