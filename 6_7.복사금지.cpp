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
    Person(const Person &) = delete;
};

int main()
{
    Person p1("KIM", 2);
    Person p2 = p1;
    //사람은 복사를 못하게 하자
    //이 순간 컴파일 error를 만들자
}

/*
복사생성자를 삭제(delete)한다
오직 하나만 존재하는 객체(singleton) 만들때
C++11 표준의 unique_ptr
mutex등의 동기화 객체등
*/