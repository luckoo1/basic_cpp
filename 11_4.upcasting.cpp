#if 0
#include <string>

class Animal
{
public:
    int age;
    std::string name;
};

class Dog : public Animal
{
public:
    int color;
    int getColor() const
    {
        return color;
    }
};

int main()
{
    Dog dog;
    //크기가 같을거니깐 dog의 주소를 int point에 넣겠다
    //에러뜬다
    //그런데 아무리 크기가 같아도 서로다른 타입에 주소를 담을 수 없다.

    int *p = &dog;
}

#endif

#if 0
#include <string>

class Animal
{
public:
    int age;
    std::string name;
};

class Dog : public Animal
{
public:
    int color;
    int getColor() const
    {
        return color;
    }
};

int main()
{
    Dog dog;

    Animal *p = &dog;
    /*
    dog와 Animal은 서로다른 타입이다.
    그럼에도 불구하고 담을 수 있다.
    기반클래스가 파생클래스를 가리킬 수 있다.
    이것을 upcasting이라고 한다
    그림필기참고
    포인터의 의미가 나를 따라가면 Animal이 있다 인데 Animal이 있네!!?
    */
    Animal &r = dog;
    //참조도 가능하다
}
#endif

#include <string>

class Animal
{
public:
    int age;
    std::string name;
};

class Dog : public Animal
{
public:
    int color;
    int getColor() const
    {
        return color;
    }
};

int main()
{
    Dog dog;

    Animal *p = &dog;
    //Animal의 멤버가 public에 있으면 접근이 가능
    p->age = 20;
    p->name = "AA";

    //dog안에 color가 있는데도 error
    //컴파일러는 p가 가리키는 곳에 animal이 있다고 생각하는데 animal에는 color가 없다
    p->color = 1;  //error
    p->getcolor(); //error

    //아래와 같이 해야 가능하다.
    static_cast<Dog *>(p)->color = 10;
}

/*
기반 클래스의 포인터로 파생 클래스를 가리킬 수는 있지만 파생 클래스의 고유한 멤버에 접근할 수는 없다.
파생클래스의 고유 멤버에 접근하려면 기반클래스 포인터를 파생클래스의 포인터 타입으로 캐스팅해야한다.

*/