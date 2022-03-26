#include <iostream>

class Point
{
    int x, y;
    int *buf;

public:
    Point()
    {
        std::cout << "Point()" << std::endl;
        buf = new int[10];
    }
    ~Point()
    {
        std::cout << "~Point()" << std::endl;
        delete[] buf;
        //소멸자가 필요한 이유
        //자원해지를 위해서 만든다.
        //자바는 delete할 필요가 없어서 소멸자가 없다.
    }
};

int main()
{
    Point p;
}

/*
소멸자 정리
"~클래스이름()"
리턴 타입을 표기하지 않는다.
인자를 가질 수 없다.
한개만 만들 수 있다.

객체가 파괴될때 소멸자가 호출된다
객체가 자원을 할당한 경우 소멸자에서 자원을 해지한다
사용자가 소멸자를 만들지 않으면 컴파일러가 만들어 준다.
*/