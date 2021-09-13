#if 0
#include <iostream>
#include <string>
//공통적인 요소가 있어서 불편하다
class Student
{
    int age;
    std::string name;
    int id;
};

class Professor
{
    int age;
    std::string name;
    int major;
};

//공통적인 요소가 있다.
int main()
{
}
#endif

#include <iostream>
#include <string>
//1.공통적인 요소를 Person에 넣었다.
//Base(기반) class, Supper class
class Person
{
    int age;
    std::string name;
};
//2.아래의 문법으로 상속했다
//person의 멤버를 student가 물려받겠다는 뜻
//Derived(파생) class, Sub class
class Student : public Person
{
    int id;
};

class Professor : public Person
{
    int major;
};

int main()
{
}

/*
상속 문법 사용하기
student와 professor의 공통의 특징을 모아서 person 클래스를 설계한다
student와 professor 클래스를 만들 때 person로 부터 상속 받는다

대부분 객체지향 언어에 존재하는 개념
C++ : class Student : public Person
Java : class Student extends Person
C# : class Student : Person

상속의 장점
코드중복을 막을 수 있다
상속을 통해서 기존 클래스에 새로운 특징을 추가할 수 있다.
다형성(polymorphism)을 활용한 객체 지향 디자인

상속을 
*/