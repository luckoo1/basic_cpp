#include <iostream>

class Point
{
    int x = 0;
    int y = 0;

public:
    void set(int a, int b)
    {
        x = a;
        y = b;
    }
};

int main()
{
    Point p1;
    Point p2;

    p1.set(10, 20);
}

/*그림필기 37
멤버데이터는 객체의 수만큼 메모리에 놓이게 된다.
함수는 하나뿐이다.
그럼 함수에 있는 x,y는 어느 객체에서 온지 어떻게 알 수 있을까..?
*/
//#######################################################################

#include <iostream>

class Point
{
    int x = 0;
    int y = 0;

public:
    void set(int a, int b)
    {
        x = a;
        y = b;
    }
};

int main()
{
    Point p1;
    Point p2;

    p1.set(10, 20);
    /*
    사실 컴파일러는 아래와 같이 사용한다.
    set(&p1, 10, 20);
    엄밀하게는 &p1은 레지스터를 통해 넘어간다(추후 공부)
    */
}

/*
함수의 의미상도 아래와 같다.
void set(Point* const this,int a, int b)
{
    this->x = a;
    this->y = b;
}
*/

/*
정리
멤버함수 호출의 원리
멤버 함수는 호출시 객체의 주소가 추가로 전달된다.
this
객체의 주소를 나타내는 상수 포인터,멤버 함수 안에서 사용할 수 있다.
*/
//#######################################################################

//위의 과정을 증명하겠다.
#include <iostream>

class Point
{
    int x = 0;
    int y = 0;

public:
    void set(int a, int b)
    {
        std::cout << "this : " << this << std::endl;
        x = a;
        y = b;
    }
};

int main()
{
    Point p1;
    Point p2;
    std::cout << &p1 << std::endl;
    p1.set(10, 20);
    std::cout << &p2 << std::endl;
    p2.set(10, 20);
}

/*
아래와 같이 출력되었다.
0x61ff08
this : 0x61ff08
0x61ff00
this : 0x61ff00
*/
//#######################################################################

//this를 활용해보자
#include <iostream>

class Point
{
    int x = 0;
    int y = 0;

public:
    //void set(int x, int y)안에 x는
    //멤버의 x냐 함수의 인자의 x냐?
    //아래의 경우는 함수인자의 x가 선택된다.
    void set(int x, int y)
    {
        x = x;
        y = y;
    }
};

int main()
{
    Point p;
    p.set(10, 20);
}
//#######################################################################

#include <iostream>

class Point
{
    int x = 0;
    int y = 0;

public:
    //멤버데이터의 x,y에 접근하고 싶다.
    //아래와 같이 써주면 된다.
    void set(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int main()
{
    Point p;
    p.set(10, 20);
}

/*
멤버의 이름과 지역변수(함수인자)이름이 동일 할 때
지역 변수가 우선시 된다
this를 사용하면 멤버변수에 접근할 수 있다.
충돌이 나지 않더라도 명확히 적으면 좋자나!
*/
//#######################################################################

//this활용하는 또다른 예제를 보자
class Test
{
    int data;

public:
    Test *foo() { return this; }
    //1. return값이 this
};

int main()
{
    Test t;
    //2.return 값이 this라서 함수호출을 연속으로 할 수 있다.
    t.foo()->foo()->foo();
}
//#######################################################################

class Test
{
    int data;

public:
    //1.this가 가리키는 값으로 리턴
    Test goo() { return *this; }
    //3.근데 위와 같이 적으면 *this는 정말 자기 자신일까???
    //  임시객체 리턴이다.
    //  임시객체가 계속 만들어지는거다.
};

int main()
{
    Test t;
    //2.return이 자기 자신의 값으로 왔으니 연속으로 호출 가능
    t.goo().goo().goo();
}
//#######################################################################
class Test
{
    int data;

public:
    //이러한 방식으로 참조리턴해야한다.
    //이거 좀 생각해보자..
    //4_5참조
    Test &goo() { return *this; }
};

int main()
{
    Test t;

    t.goo().goo().goo();
}

/*
std::cout<<"A"<<"B"<<"C";
cout의 원리가 this를 return하는거다.
*/

/*
this를 리턴하는 함수
멤버 함수 호출을 연속적으로 사용할 수 있다.
자신(*this)을 리턴시 반드시 참조로 리턴해야한다.
*/
//#######################################################################

//this활용시 주의사항
#include <iostream>
class Test
{
    int data;

public:
    static void foo()
    {
        std::cout << this << std::endl; //2.error
    }
};

int main()
{
    Test::foo();
    //1.static 멤버함수는 객체없이 부를수 있다.
    //  그런데 객체가 없으니 전달할 객체가 없네
}

//정리1 : static 멤버 함수 안에서는 this 사용이 불가능하다.
//#######################################################################

#include <iostream>
class Test
{
    int data;

public:
    static void foo()
    {
        data = 0;
        /*그럼 이건 this->data=0;
        이러한 형태라고 배웠는데...
        사전에
        static멤버 함수 안에서는 일반 멤버 data에 접근이 불가능
        공부했다.
        this->data=0으로 컴파일러가 바꾸고 싶었지만
        this가 없어서 못한거다.
        그래서 static멤버 함수 안에서는 일반 멤버 data에 접근이 불가능
        */
    }
};

int main()
{
    Test::foo();
}

//static 멤버 함수 안에서는 this 사용이 불가능하기 때문에 멤버 데이터도 접근을 할 수 없다.