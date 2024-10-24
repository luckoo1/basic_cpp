#include <iostream>

class Animal
{
public:
    void Cry()
    {
        std::cout << "Animal Cry" << std::endl;
    }
};

class Dog : public Animal
{
public:
    //기반클래스의 함수를 가져옴
    //함수 오버라이드(override)
    void Cry()
    {
        std::cout << "Dog Cry" << std::endl;
    }
};

int main()
{
    Animal a;
    a.Cry(); //Animal Cry

    Dog d;
    d.Cry(); //Dog Cry

    Animal *p = &d;
    p->Cry();
    //객체가 dog니깐 dog를 부르는게 맞는 행동이다
    //C++에서는 Animal Java는 Dog를 부른다.
}