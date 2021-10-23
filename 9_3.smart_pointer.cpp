#include <iostream>

class Car
{
public:
    void Go() { std::cout << "Go" << std::endl; }
    ~Car() { std::cout << "~Car" << std::endl; }
};

class SPtr
{
    Car *ptr;

public:
    SPtr(Car *p = 0) : ptr(p) {}
    //2.Car Pointer에 SPtr 생성자가 있다.
    Car *operator->() { return ptr; }
};

int main()
{
    //1.
    //SPtr의 객체가 Car의 포인터처럼 사용
    SPtr p = new Car; //Sptr p(new Car)이런 모양
    p->Go();
    //4.
    //"(p.operator->())Go()"의 모양이다
    //그런데 C++에서는 ->연산자를 특수하게 처리해서
    //(p.operator->())->Go() 모양인것 처럼 처리해준다.
    //즉 ->가 한번 더있는거 처럼 해석해준다.
    //(p.operator->())->Go()를 다시보면
    //"p.operator->()"호출하면
    //(1000번지)->Go()된다
    //1000번지는 car이었으니 car에서 Go()가 호출된다.
}

/*
3.그림필기
SPtr p = new Car; 설명
p객체가 있다
이 p객체 내부에 "Car *ptr;"이라는 포인터가 있다.
p객체 내부에 멤버데이터로 포인터(ptr)가 있는격이다.

new car했으니깐 heap에 Car이 만들어졌을거구
그럼 생성자에서 *p에 Car이가고 멤버데이터 ptr이 car을 가리키는 격이다
SPtr(Car *p = 0) : ptr(p) {}

즉 p는 객체지만 내부적으로 포인터멤버가 있으니 객체를 가리킬 수 있다.
*/

/*
5.
Car* p = new Car;처럼 쓰면
저기의 p는 객체가 아니다.
블럭 벗어나면 아무일도 안생긴다

SPtr p = new Car;을 쓰면 블럭벗어나면 소멸자 호출이 가능해진다.
*/

#include <iostream>

class Car
{
public:
    void Go() { std::cout << "Go" << std::endl; }
    ~Car() { std::cout << "~Car" << std::endl; }
};

class SPtr
{
    Car *ptr;

public:
    SPtr(Car *p = 0) : ptr(p) {}
    ~SPtr() { delete ptr; } //내가 만약에 이런 코드를 소멸자를 통해 넣어주면
    //사용자가 new를 했지만 사용자가 delete하지 않아도 자동으로 된다.
    Car *operator->() { return ptr; }
};

int main()
{
    SPtr p = new Car;
    p->Go();
}

#include <iostream>

class Car
{
public:
    void Go() { std::cout << "Go" << std::endl; }
    ~Car() { std::cout << "~Car" << std::endl; }
};

class SPtr
{
    Car *ptr;

public:
    SPtr(Car *p = 0) : ptr(p) {}
    ~SPtr() { delete ptr; }
    Car *operator->() { return ptr; }
    //3.아래코드 추가함
    //Car operator*() { return *ptr; }
    //그런에 이렇게 하면 임시객체가 오니깐
    Car &operator*() { return *ptr; }
};

int main()
{
    SPtr p = new Car;
    p->Go();
    //1.
    //아래의 코드를 사용해서 포인터처럼 쓰고싶다.
    (*p).Go(); //p.operator*();모양이니깐 이거 더 만들어야지
}

/*
스마트 포인터
다른 타입의 포인터 역할을 하는 객체

구현원리
->연산좌와 *연산자를 재정의해서 포인터 처럼 보이게한다
*연산자를 재정의 할 떄는 반드시 참조를 리턴해야한다.

장점
객체이므로 생성자/복사생성자/대입연산자/소멸자 등을 통해서 생성/복사/대입/소멸의 과정을 제어할 수 있다.
소멸자에서 자원을 삭제(new만쓰고 delete가 필요가 없어짐)
*/