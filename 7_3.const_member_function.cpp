
#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a, int b) : x(a), y(b) {}

    void set(int a, int b)
    {
        x = a;
        y = b;
    }
    //상수멤버함수
    //상수멤버함수 안에 있는 것을 모두 상수취급한다.
    void print() const
    {
        x = 10;    //error
        set(1, 2); //error
        //set함수 호출시 x와 y값을 바꾼다.
        //멤버데이터를 변경하는 어떠한 형태의 코드도 올 수 없다.
        std::cout << x << ", " << y << std::endl;
    }
};

int main()
{
}
/*
상수멤버함수 특징
상수 멤버함수안에서는 모든 멤버를 상수 취급
멤버의 값을 변경할 수 없다. 읽는것은 문제없음
상수 멤버 함수안에서는 상수 멤버 함수만 호출이 가능
*/

//#######################################################################

//상수함수의 필요성에 대해서 살펴보자!

#include <iostream>

class Point
{
public:
    int x, y; //설명을 위해 public에 두었다.
    Point(int a, int b) : x(a), y(b) {}

    void set(int a, int b)
    {
        x = a;
        y = b;
    }

    void print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

int main()
{
    /*
    Point p(1, 2);
    p.x = 10;
    p.set(10, 20);
    p.print();
    위와 같이 하는건 상관없다
    */

    const Point p(1, 2);
    p.x = 10;      //error
    p.set(10, 20); //error
    //set 호출시 값이 변경되는게 발생하니깐
    p.print();
    //값이 변경되는 코드는 없는데...? error날까?

    /*
    이걸 생각해보자
    보통 선언부와 구현부를 나눈다.
    void print();  //선언부

    void Point::print()  //구현부
    {
        std::cout << x << ", " << y << std::endl;
    }

    그럼 해당코드에서 구현부는 다른파일에 있다.
    컴파일러는 void print();만 볼텐데
    이안에 코드가 변경되는게 있는지 없는지 구현부만 보고는 알 수 없다.
    */

    //그래서 p.print();는 무조건 error
}
//#######################################################################

#include <iostream>

class Point
{
public:
    int x, y; //설명을 위해 public에 두었다.
    Point(int a, int b) : x(a), y(b) {}

    void set(int a, int b)
    {
        x = a;
        y = b;
    }
    //2.컴파일러에게 나는 내부적으로 값을 안바꾸는 함수니깐
    //혹시 상수객체 오더라도 나를 부를수 있게 해줘 표시를 해주자
    void print() const //const 붙임
    {
        std::cout << x << ", " << y << std::endl;
    }
};

int main()
{
    const Point p(1, 2);
    p.print();
    //1. 아무리 고정된 점이라도 화면출력정도는 하고싶은데...

    /*
    3.
    void print() const; //선언부

    void Point::print() const//구현부
    {
        std::cout << x << ", " << y << std::endl;
    }
    */
}

/*
상수멤버함수의 필요성

상수객체는 상수멤버함수만 호출가능

상수객체는 많이 사용된다. 항상 상수 객체를 고려해야한다.
객체의 상태를 변경하지 않은 모든 멤버함수는 상수 함수가 되어야한다.

getter는 대부분 상수 멤버 함수가 되어야한다.
*/
//#######################################################################

#include <iostream>
class Point
{
    int x, y;

public:
    Point(int a, int b) : x(a), y(b) {}
    void print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

/*
3.
아래와 같이 쓰면 call by value니깐 성능저하 발생
void foo(Point p)
{
}
성능저하를 막기위해 아래와 같이 const 참조를 사용하자
*/
void foo(const Point &p)
{
    p.print(); //4.error뜬다.
    //print()함수에서 변경이 발생할수도 있잖아!
}

int main()
{
    Point p(1, 2);
    p.print(); //1.ok

    foo(p); //2.이걸 추가했다.
}
//#######################################################################

#include <iostream>
class Point
{
    int x, y;

public:
    Point(int a, int b) : x(a), y(b) {}
    void print() const //이걸 붙여서 해결했다.
    {
        std::cout << x << ", " << y << std::endl;
    }
};

void foo(const Point &p)
{
    p.print();
}

int main()
{
    Point p(1, 2);
    p.print();

    foo(p);
}

//객체 상태를 변경하지 않는 모든 함수는 const를 붙여야 한다. ex) getter함수
//#######################################################################

//1. print()함수가 몇번 불리는지 궁금해서 아래와 같은 작업을했다.
#include <iostream>
class Point
{
    int x, y;
    int cnt = 0;

public:
    Point(int a, int b) : x(a), y(b) {}
    void print() const
    {
        ++cnt; //2.그런데 이게 상수함수 안에 있음
               //값을 바꿀수 없다
        std::cout << x << ", " << y << std::endl;
    }
};

int main()
{
    Point p(1, 2);
    p.print();
}
//#######################################################################
//1. print()함수가 몇번 불리는지 궁금해서 아래와 같은 작업을했다.
#include <iostream>
class Point
{
    int x, y;
    mutable int cnt = 0; //mutable을 사용

public:
    Point(int a, int b) : x(a), y(b) {}
    void print() const
    {
        ++cnt;
        std::cout << x << ", " << y << std::endl;
    }
};

int main()
{
    Point p(1, 2);
    p.print();
}

/*
mutable
상수 멤버 함수 안에서 값을 변경하고 싶을 때 사용
논리적으로 상수 멤버 함수가 되야 하지만 다양한 이유로 멤버의 값을 변경하고 싶을 때 사용
*/
//#######################################################################

/*
상수 멤버 함수 주의사항
상수 멤버 함수안에서는 모든 멤버가 상수 취급
동일 이름의 상수 멤버 함수와 비상수멤버함수를 동시에 제공할 수 있다.
멤버 함수를 선언과 구현으로 분리할 때 선언과 구현 모두에 const 붙여야한다.
*/
#include <iostream>

class Test
{
    int data = 0;

public:
    int *getPointer() const { return &data; }
    /*
    위의 코드는 error발생
    상수 멤버함수 안에서는 모든 멤버다 상수
    &data는 const int가 된다.
    */
    void foo() { std::cout << "1" << std::endl; };
};

int main()
{
}

//#######################################################################

#include <iostream>

class Test
{
    int data = 0;

public:
    const int *getPointer() const { return &data; }
    //const int return 타입으로 만들었다.

    void foo() { std::cout << "1" << std::endl; };
};

int main()
{
}
//#######################################################################
#include <iostream>
class Test
{
    int data = 0;

public:
    const int *getPointer() const { return &data; }

    void foo() { std::cout << "1" << std::endl; };       //1
    void foo() const { std::cout << "2" << std::endl; }; //2
};

int main()
{
    Test t1;
    t1.foo(); //1호출,없으면 2호출
    //1를 주석으로 막으면 2가 호출된다.

    const Test t2;
    t2.foo(); //2호출
    //2를 주석으로 막으면 error
    //상수객체라서 알아서 상수멤버함수 호출한다.
}
//#######################################################################

#include <iostream>
class Test
{
    int data = 0;

public:
    const int *getPointer() const { return &data; }

    void foo() { std::cout << "1" << std::endl; };
    void foo() const { std::cout << "2" << std::endl; };

    void goo() const;
};
//선언부에 const를 붙여야하나 말아야 하나..
void Test::goo()
{
}

/*
생각해보자
foo를보면 상수와 비상수로 나누어져 있다.
분명히 둘은 다른함수였다.
그래서 
void goo() const;
void Test::goo(){}
이건 다른함수로 취급된다.
const 붙여라
*/
int main()
{
    Test t1;
    t1.foo();

    const Test t2;
    t2.foo();
}
//#######################################################################

#include <iostream>
class Test
{
    int data = 0;

public:
    const int *getPointer() const { return &data; }

    void foo() { std::cout << "1" << std::endl; };
    void foo() const { std::cout << "2" << std::endl; };

    void goo() const;
};

void Test::goo() const
{
}

int main()
{
    Test t1;
    t1.foo();

    const Test t2;
    t2.foo();
}

//상수함수의 필요성을 느끼자!!