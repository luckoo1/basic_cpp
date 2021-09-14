#include <iostream>

class Animal
{
    //*vtptr
    int age;

public:
    virtual ~Animal() {}
    virtual void foo() {}
    virtual void goo() {}
};

class Dog : public Animal
{
    int color;

public:
    virtual void ~Dog() {}
    virtual void foo() override {}
};

int main()
{
    Animal a1, a2;
    Dog d1, d2;

    Animal *p = &d1;

    p->foo();
    /*
    그림필기 참조
    컴파일러는 p가 Animal*라는 사실만 안다
    Animal가보고
    foo가 가상함수인지 조사하고 가상함수가 아니면 그냥 호출
    여기서는 가상함수니깐
    p가 가리키는 주소를 따라가봐라 그럼 vtprt이 있을것이다.
    그런다음 두번째꺼를 꺼내서 호출해달라
    p->vtptr[2]();

    이러한 기계어 코드를 만든다
    */

    std::cout << sizeof(a1) << std::endl; //8(32비트 컴파일환경)
    std::cout << sizeof(d1) << std::endl; //16(패딩되었으면) 12(패딩안되었으면)
}