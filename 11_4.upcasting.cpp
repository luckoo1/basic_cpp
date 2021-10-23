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

//#######################################################################

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
//#######################################################################

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

//#######################################################################

class Animal
{
public:
    int age;
};

class Cat : public Animal
{
};

class Dog : public Animal
{
};

void HappyNewYear(Dog *p)
{
    ++(p->age);
}
//2.고양이버전도 만들었다.
//이런식이면 동물이 늘어날때마다 계속 만들어야한다
//그런데 생각해보면 나이먹는건 모든 동물의 특징아니야?
void HappyNewYear(Cat *p)
{
    ++(p->age);
}

int main()
{
    Dog dog;
    HappyNewYear(&dog);

    Cat cat;
    HappyNewYear(&cat); //1.고양이도 나이먹게 하고싶다
}
//#######################################################################

class Animal
{
public:
    int age;
};

class Cat : public Animal
{
};

class Dog : public Animal
{
};

/*기반클래스의 포인터로 모든 동물을 가리킬수있다.
p로는 파생클래스의 고유멤버에는 접근못하지만
나이는 기반클래스 안에 있던거다
*/
void HappyNewYear(Animal *p)
{
    ++(p->age);
}

int main()
{
    Dog dog;
    HappyNewYear(&dog);

    Cat cat;
    HappyNewYear(&cat);
}

/*
동종(동일한 기반 클래스를 사용하는 클래스)을 처리하는 함수를 만들 수 있다.
*/
//#######################################################################

#include <vector>

class Animal
{
public:
    int age;
};

class Cat : public Animal
{
};

class Dog : public Animal
{
};

int main()
{
    std::vector<Dog *> v1; //Dog만 보관
    std::vector<Cat *> v2; //Cat만 보관

    std::vector<Animal *> v3; //모든동물 보관
}

/*
Composite패턴

탐색기를 예로보자
파일과 폴더 클래스가 있어야한다
폴더안에 파일을 보관할수 있다.
폴더안에 폴더도 보관할수 있어야한다. 
즉,폴더는 파일뿐아니라 폴더도 보관해야한다.

폴더와 파일은 공통의 기반클래스를 가지고 있어야한다.

A와 B를 같이 보관하고 싶다면 공통의 기반 클래스를 만들어야한다.
*/

/*
그림필기 35분
파워포인트를 예로보자
사각형과 원이 있다
이런걸 그룹으로 묶을수 있다.

Shape라는 기반클래스 사각형과 원을 파생클래스로 설계하자
group은 Shape의 포인터를 저장하면된다.
vector<Shape*>

그런데 group과 shape도 공통의 기반클래스 component를 둘수 있다.
component로 group과 shape를 관리할 수 있다.
그럼 vector<Shape*> => vector<Component*>로 바꿔야한다.
*/