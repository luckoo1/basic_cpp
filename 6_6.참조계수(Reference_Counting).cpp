//Reference Counting
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

    ~Person() { delete[] name; }

    Person(const Person &p) : age(p.age)
    {
        name = new char[strlen(p.name) + 1];
        strcpy(name, p.name);
    }
};

int main()
{
    Person p1("KIM", 2);
    Person p2 = p1;
    Person p3 = p1;
    //그림필기 참조
    //만약 kim이라는 자원이 큰 자원이라면 메모리적으로 부담이 온다.
    //참조계수를 쓰자
}
#endif

#include <iostream>
#include <cstring>
//이것도 그림필기 참조
class Person
{
    char *name;
    int age;
    int *ref; //1. 참조계수 메모리의 주소

public:
    Person(const char *n, int a) : age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        ref = new int; //2. 참조계수 할당
        *ref = 1;
    }

    ~Person()
    {
        if (--(*ref) == 0) //5. 참조계수 검사
        {
            delete[] name;
            delete ref;
        }
    }

    Person(const Person &p) : name(p.name), age(p.age), ref(p.ref) //3. 모든 멤버 얕은 복사
    {
        ++(*ref); //4. 참조계수 증가
    }
};

int main()
{
    Person p1("KIM", 2);
    Person p2 = p1;
    Person p3 = p1;
}
