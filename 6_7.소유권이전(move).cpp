#if 0
#include <iostream>
#include <cstring>

class Person
{
    char *name;
    int age;

public:
    Person(const char *n, int a) : age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    ~Person()
    {
        delete[] name;
    }
    //얕은 복사
    Person(Person &p) : age(p.age), name(p.name)
    {
    }
};

int main()
{
    Person p1("KIM", 2);
    Person p2 = p1;
}
#endif

#include <iostream>
#include <cstring>

class Person
{
    char *name;
    int age;

public:
    Person(const char *n, int a) : age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    ~Person()
    {
        delete[] name;
    }

    Person(Person &p) : age(p.age), name(p.name) //2. const를 없앴다.
    {
        p.name = 0;
        //1. 원래 객체가 가진 name을 0으로 바꿈
    }
    //3. p1이 파괴될때는 0번지가 delete된다.
    //C++에서는 0번지를 지우는건 아무문제 없다고 한다.
};

int main()
{
    Person p1("KIM", 2);
    Person p2 = p1;
    //4. p1은 내가 가진 자원을 p2에게 준격이 된다.
}
//소유권 이전의 복사생성자
//const가 사라진다.
//그림필기

/*
소유권 이전(move 개념)
객체가 사용하던 자원을 전달하는 개념
버퍼 복사 등의 일부 알고리즘에서 사용되면 성능향상을 볼수 잇다
C++11의 move 생성자 개념-"C++ Intermediate"과정 참고
*/