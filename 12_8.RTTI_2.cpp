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
public:
    int color;
};

void foo(Animal *p)
{
    /*
    모든동물의 공통의 작업공간
    p가 dog라면 색상을 변경하고 싶다
    p가 dog인지 아닌지 조사하는게 좋은코드인가?
    여긴 공통의 작업만해야지
    p가 dog라면 색상을 변경하는 코드를 추가하는건 좋지 못한 코드이다.
    */
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
public:
    int color;
};

void foo(Animal *p)
{
}
//차라리 아래의 코드를 추가하는게 낫다
void foo(Dog *p)
{
    //여기에 dog일때 작업내용 추가해서 적어준다
    //그럼 작업이 끝나면 Animal의 작업을 하라고 foo로 보내준다
    foo(static_cast<Animal *>(p));
}

//철학
//기존코드 수정보다는 새로운 코드를 추가하는게 더 안전하지 않을까?
//RTTI를 쓰지말자는 주장도 있다.
int main()
{
    Animal a;
    foo(&a);
    Dog d;
    foo(&d);
}
#endif