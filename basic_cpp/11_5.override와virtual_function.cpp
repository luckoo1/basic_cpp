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
//#######################################################################

#include <iostream>

class Animal
{
public:
    virtual void Cry() //1.가상함수
    {
        std::cout << "Animal Cry" << std::endl;
    }
};

class Dog : public Animal
{
public:
    virtual void Cry() //2.가상함수
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
    //3.가상함수 만들어줘서 객체를 보고 결정해서 Dog Cry호출한다
}

/*
function overrride
기반클래스의 함수를 파생 클래스에서 재정의 할 수 있다.
 
기반 클래스의 포인터로 파생 클래스 객체를 가리킬때(Animal *p = &dog;)
p->Cry() : C++에서는 Animal::Cry()
           Jave에서는 Dog::Cry()

virtual function
멤버함수 호출시, 포인터 타입이 아닌 실제 객체에 따라 함수를 호출
실행 시간에 포인터가 가리키는 메모리를 조사한 후 호출하는 것
*/
//#######################################################################

#include <iostream>

class Animal
{
public:
    virtual void Cry()
    {
        std::cout << "Animal Cry" << std::endl;
    }
};

class Dog : public Animal
{
public:
    virtual void Cry() //2.재정의하는 단계에서는 virtual를 안붙여도 되나 가독성이 떨어지니 붙이자
    {
        std::cout << "Dog Cry" << std::endl;
    }
};

int main()
{
    Dog d;

    Animal *p = &d;
    p->Cry();
    //1. Cry()가 가상함수라면 Dog의 Cry()호출
}

//가상함수 재정의시에는 virtual키워드는 붙여도 되고 붙이지 않아도 된다.
//#######################################################################

#include <iostream>

class Animal
{
public:
    virtual void Cry()
    {
        std::cout << "Animal Cry" << std::endl;
    }
};

class Dog : public Animal
{
public:
    //모르고 오타를 냈다 내의도는 가상함수 재정의인데 컴파일러는 멤버함수가 추가된걸로 인식한다.
    virtual void Cryaaa()
    {
        std::cout << "Dog Cry" << std::endl;
    }
};

int main()
{
    Dog d;

    Animal *p = &d;
    p->Cry();
}
//#######################################################################

#include <iostream>

class Animal
{
public:
    virtual void Cry()
    {
        std::cout << "Animal Cry" << std::endl;
    }
};

class Dog : public Animal
{
public:
    /*
    뒤에 override붙여줘서 컴파일 error뜨게 함
    override를 적어줌으로서 기반클래스 재정의함을 알려주는것
    C++11부터 나옴
    */
    virtual void Cryaaa() override
    {
        std::cout << "Dog Cry" << std::endl;
    }
};

int main()
{
    Dog d;

    Animal *p = &d;
    p->Cry();
}
//가상함수 재정의시 실수를 막기위해서 override 키워드를 사용한다(C++11)

#include <iostream>

class Animal
{
public:
    virtual void Cry()
    {
        std::cout << "Animal Cry" << std::endl;
    }
};

class Dog : public Animal
{
public:
    virtual void Cry() override;
};

//구현부에는 virtual와 override를 뺀다.
void Dog::Cry()
{
    std::cout << "Dog Cry" << std::endl;
}

int main()
{
    Dog d;

    Animal *p = &d;
    p->Cry();
}

//가상함수를 선언과 구현으로 분리할떄는 선언부에만 virtual와 override을 표기하고 구현부에는 표기하면 안된다.