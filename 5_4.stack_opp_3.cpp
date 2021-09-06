#if 0
//7번째 단계
//1. 선언과 구현을 불리해보자.
#include <iostream>
class Stack
{
private:
    int *buf;
    int idx;


public: //2. 클래스 안에는 멤버함수의 선언만
    Stack(int sz = 10);
    ~Stack();
    void push(int n);
    int pop();
};


//3.멤버함수의 구현은 클래스 외부에 놓자.
//대신 이게 멤버함수인지 일반함수인지 구별이 불가능하다.
/*
Stack(int sz = 10)
{
    buf = new int[sz];
    idx = 0;
}


~Stack()
{
    delete[] buf;
}


void push(int n)
{
    buf[idx++] = n;
}


int pop()
{
    return buf[--idx];
}
*/


//4.아래와 같이 적자.
Stack::Stack(int sz)   //5.문법 생각하자.
{                      // 선언부에만 표시하고 여기는 "int sz=10"이 아니라 int sz로 적어야한다
    buf = new int[sz]; //3_1참조
    idx = 0;
}


Stack::~Stack()
{
    delete[] buf;
}


void Stack::push(int n)
{
    buf[idx++] = n;
}


int Stack::pop()
{
    return buf[--idx];
}


int main()
{
    Stack s1(20);
    Stack s2;


    s1.push(10);
    s1.push(20);
    s2.push(30);
    s2.push(20);
    std::cout << s1.pop() << std::endl;
    std::cout << s2.pop() << std::endl;
}


/*
정리
선언과 구현의 분리
클래스 선언 안에는 함수의 선언만 포함
함수의 구현은 클래스 외부에 구현
*/
#endif

//Stack.h
#include <iostream>
class Stack
{
private:
    int *buf;
    int idx;

public:
    Stack(int sz = 10);
    ~Stack();
    void push(int n);
    int pop();
};

//Stack.cpp
Stack::Stack(int sz)
{
    buf = new int[sz];
    idx = 0;
}

Stack::~Stack()
{
    delete[] buf;
}

void Stack::push(int n)
{
    buf[idx++] = n;
}

int Stack::pop()
{
    return buf[--idx];
}

int main()
{
    Stack s1(20);
    Stack s2;

    s1.push(10);
    s1.push(20);
    s2.push(30);
    s2.push(20);
    std::cout << s1.pop() << std::endl;
    std::cout << s2.pop() << std::endl;
}

/*
선언파일과 구현 파일의 분리
클래스 선언부는 헤더파일로 만든다
클래스 구현부는 소스 파일(.cpp)로 만든다.
*/