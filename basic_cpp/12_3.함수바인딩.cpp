#include <iostream>

class Animal
{
public:
    void Cry() { std::cout << "Animal Cry" << std::endl; }
};

class Dog : public Animal
{
public:
    void Cry() { std::cout << "Dog Cry" << std::endl; }
};

int main()
{
    Animal a;
    Dog d;

    Animal *p = &d;
    p->Cry();
    //C++은 aniaml Jave는 Dog
    //왜그럴까????
}
//#######################################################################

//그림필기
#include <iostream>

class Animal
{
public:
    void Cry() { std::cout << "Animal Cry" << std::endl; }
};

class Dog : public Animal
{
public:
    void Cry() { std::cout << "Dog Cry" << std::endl; }
};

int main()
{
    Animal a;
    Dog d;

    Animal *p = &d;

    //1.사용자의 입력에 따라 p가 바뀔수 있다.
    //-------------------
    int n;
    std::cin >> n;
    if (n == 0)
    {
        p = &a;
    }
    //-------------------
    /*
    2.컴파일러가 컴파일 시간에 dog를 가리킬지 animal을 가리킬지 판단 불가능
    나는 실제 객체가 누군지 모르겠다
    대신 이 포인터의 타입이 animal이란건 알고있다
    무조건 animal로 부른다
    */
    p->Cry();
}

/*
static binding
컴파일러가 컴파일 시간에 함수 호출 결정
포인터 타입으로 함수 호출을 결정
빠르다. 하지만 비이성적이다
이른 바인딩(early binding)
C++의 non-virtual function
C++은 기본적으로 타입으로 결정하지만 virtual걸어두면 메모리 조사를 하게 할 수 있다

dynamic binding
실행시간에 함수 호출을 결정
p->Cry(); 이순간 어느 함수를 부를지를 컴파일할때 하지 않겠다
하지만 p가 가리키는 메모리를 조사하는 기계어코드를 만들어 놓겠다.
포인터가 가리키는 메모리를 조사후 결정
느리다. 하지만 이성적이다
늦은 바인딩(late binding)
JAVA, C++의 virtual function
메모리를 조사한다.
*/