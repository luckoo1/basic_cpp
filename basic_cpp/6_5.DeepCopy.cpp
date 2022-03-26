//얕은복사를 해결하는 방법은 총 4가지이다

#include <iostream>
#include <cstring>
//그림필기참조
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
    //복사 생성자
    Person(const Person &p) : age(p.age) //1.포인터가 아닌 멤버는 그냥 복사
    {
        name = new char[strlen(p.name) + 1]; //2.메모리 할당
        strcpy(name, p.name);                //3.메모리 내용을 복사
    }
    /*
    1.포인터가 아닌 멤버는 그냥 복사
    2.메모리 할당
    3.메모리 내용을 복사
    */
    //p2을 지울때는 자기 버퍼를 지우니깐 3000번지 파괴됨
    //p1을 지울대는 자기 버퍼를 지우니깐 2000번지 파괴됨
};

int main()
{
    Person p1("KIM", 2);
    Person p2 = p1; //복사생성자가 불린다.
}
/*
깊은복사(Deep Copy)
주소가 아닌 메모리 내용 자체를 복사하는 것
*/