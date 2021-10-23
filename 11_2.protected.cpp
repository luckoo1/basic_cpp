class Base
{
private:
    int a;

public:
    int c;
};

class Derived : public Base
{
public:
};

int main()
{
    Base b;
    b.a = 10; //private에 접근하는건 불가능
    b.c = 10;
}
//#######################################################################

class Base
{
private:
    int a;

public:
    int c;
};

class Derived : public Base
{
public:
    void foo()
    {
        a = 10; //private에 접근하는것 마찬가지로 불가능
        //물려는 받으나 접근이 불가능
        c = 10; //OK
    }
};
//#######################################################################

class Base
{
private:
    int a;

protected: //파생클래스에서는 접근가능,외부에서 접근 불가능
    int b;

public:
    int c;
};

class Derived : public Base
{
public:
    void foo()
    {
        a = 10; //error
        b = 10; //OK
        c = 10; //OK
    }
};

int main()
{
    Base b;
    b.a = 10; //error;
    b.b = 10; //error
    b.c = 10; //OK
}

/*
private:
멤버함수와 friend함수만 접근가능

protected:
멤버함수와 friend함수
파생클래스의 멤버함수, 파생클래스의 friend함수에서 접근가능

public:
모든함수에서 접근 가능
*/
//#######################################################################

#include <iostream>
#include <string>

class Person
{
    int age;
    std::string name;
};

class Student : public Person
{
    int id;

public:
    void print() const
    {
        //private는 접근이 불가능
        std::cout << name << std::endl; //error
        std::cout << age << std::endl;  //error
        std::cout << id << std::endl;   //OK
    }
};

int main()
{
}
//#######################################################################

//방법 1
#include <iostream>
#include <string>

class Person
{
    int age;
    std::string name;

public:
    int getAge() const //함수를 만들어줌
    {
        return age;
    }
};

class Student : public Person
{
    int id;

public:
};

int main()
{
}
//#######################################################################

//방법 2
#include <iostream>
#include <string>

class Person
{
protected:
    int age; //protected추가
    std::string name;
};

class Student : public Person
{
    int id;

public:
};

int main()
{
}
//#######################################################################

//기반클래스에 protected로할지
//private로 두고 get함수로 접근하게 할지 잘 생각해보자