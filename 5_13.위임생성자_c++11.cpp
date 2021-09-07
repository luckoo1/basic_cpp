#if 0
class Point
{
    int x, y;

public:
    Point()
    {
        Point(0, 0); //생성자를 호출하는게 아니라
                     //임시객체를 생성하는것
    }
    Point(int a, int b) : x(a), y(b)
    {
    }
};

int main()
{
    Point p;
    std::cout << p.x << std::endl; //쓰레기값 나온다.
}
#endif

#include <iostream>

class Point
{
public: //출력을 위해서
    int x, y;

public:
    //예전에는 하나의 생성자에서 다른 생성자를 부를수 있는 방법이 없었다.
    //C++11부터 아래와 같이 적으면 다른생성자를 부를 수 있게 되었다.
    Point() : Point(0, 0) //위임생성자
    {
    }
    Point(int a, int b) : x(a), y(b)
    {
    }
};

int main()
{
    Point p;
    std::cout << p.x << std::endl; //0
}

/*
delegate constructor
하나의 생성자에서 다른 생성자를 호출하는 문법
초기화 리스트 구문에서 다른 생성자를 호출한다
C++11부터 지원됨
*/