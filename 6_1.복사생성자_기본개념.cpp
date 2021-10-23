#include <iostream>

class Point
{
    int x, y;

public:
    Point() : x(0), y(0) {}             //1
    Point(int a, int b) : x(a), y(b) {} //2
};

int main()
{
    Point p1;       //1
    Point p2(1, 2); //2
    Point p3(1);    //error
    Point p4(p2);   //ok
    //Point(Point)가 불린다는 건데......
    //나는 위와같은 함수를 만든적이 없다.
    //즉 컴파일러가 만들었다는 말이다.
    //어떻게 생겼을까?
}
//#######################################################################

#include <iostream>

class Point
{
    int x, y;

public:
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}

    //복사생성자가 아래와 같은 모양으로 만들어졌다.
    Point(const Point &p) : x(p.x), y(p.y)
    {
    }
};

int main()
{
    Point p1;       //1
    Point p2(1, 2); //2
    Point p4(p2);   //ok
}
/*
복사생성자
객체가 자신과 동일한 타입으로 초기화 될 때 사용된다.
사용자가 만들지 않으면 컴파일러가 제공=>디폴트 복사 생성자(default copy constructor)
컴파일러가 제공하는 복사 생성자는 모든 멤버를 복사해준다(bitwise copy)
필요한 경우 사용자가 직접 만들어도 된다.

복사생성자의 정확한 모양
Point(const Point &p) : x(p.x), y(p.y)
*/
}
//#######################################################################

#include <iostream>

class Point
{
public:
    int x, y; //설명을 위해 public

    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}

    //복사생성자를 사용자가 거꾸로 복사되게 만들어 보았다.
    Point(const Point &p) : x(p.y), y(p.x)
    {
    }
};

int main()
{
    Point p1(2, 1);
    Point p2(p1);
    std::cout << p2.x << std::endl;
    std::cout << p2.y << std::endl;
}
//2와 1순서대로 출력됨
//#######################################################################