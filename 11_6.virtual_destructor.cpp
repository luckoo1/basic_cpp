#if 0
#include <iostream>

class Base
{
public:
    Base() { std::cout << "Base자원할당" << std::endl; }
    ~Base() { std::cout << "Base자원해지" << std::endl; }
};

class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Derived 자원할당" << std::endl;
    }
    ~Derived()
    {
        std::cout << "Derived 자원해지" << std::endl;
    }
};

int main()
{
    Derived *p = new Derived;
    delete p;
    //위의 두줄은 문제없이 할당하고 해지한다.

    Base *p = new Derived;
    delete p;
    //위의 두줄은 할당만하고 해지를 하지 않는다.
    //new Derived할때 Derived생성자 불린다.
    //delete p하려는데 P를 보고 Base의 소멸자를 호출한다.
}
#endif

#include <iostream>

class Base
{
public:
    Base() { std::cout << "Base" << std::endl; }
    //2. 소멸자를 가상으로 해야한다.
    virtual ~Base() { std::cout << "~Base" << std::endl; }
};

class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Derived" << std::endl;
    }
    //3.기반이 가상이니 파생도 자동으로 가상이라고 virtual안붙여도 되기는 한데 가독성을 위해 적어주자
    virtual ~Derived()
    {
        std::cout << "~Derived" << std::endl;
    }
};

int main()
{
    Base *p = new Derived;
    delete p;
    //1. 지울때 메모리를 조사해서 객체를 보고 호출해야한다.
    //이순간 p의 타입(base)를 보고 Base를 조사를 한다.
    //Base로 갔더니 가상이네
    //그럼 포인터 타입보고 호출하는게 아니라 메모리를 실제로 조사해볼게!
}

/*
기반 클래스의 소멸자는 반드시 가상소멸자이어야한다
*/