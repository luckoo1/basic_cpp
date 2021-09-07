#if 0
class Point
{
    int x, y;

public:
    Point() //1
    {
        x = 0;
        y = 0;
    }
    Point(int a, int b) //2
    {
        x = a;
        y = b;
    }
};

int main()
{
    Point p1;       //1호출
    Point p2(1, 2); //2호출
}

/*
클래스 이름과 동일하다
리턴 타입을 표기하지 않는다
인자는 있어도 되고 없어도 된다
2개 이상 만들 수 있다.
*/
#endif

#if 0
class Point
{
    int x, y;

public:
    /*
    Point()
    {
        x = 0;
        y = 0;
    }
    */

    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

int main()
{
    Point p1; //여기서 error
    Point p2(1, 2);
}
#endif

#if 0
class Point
{
    int x, y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }
    /*
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    */
};

int main()
{
    Point p1;
    Point p2(1, 2);//여기서 error
}
#endif

#if 0
class Point
{
    int x, y;

public:
    /*
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    */
};

int main()
{
    Point p1;
    Point p2(1, 2); //여기서만 error가 뜬다
}
/*
객체를 생성하면 자동으로 생성자가 호출된다.
생성자가 없으면 객체를 만들 수 없다.
사용자가 생성자를 하나도 안 만들면 컴파일러가 인자없는 생성자를 하나 만든다.
=>디폴트 생성자(default)
*/
#endif

#if 0
#include <cstdlib>
class Point
{
    int x, y;

public:
    Point() //1
    {
        x = 0;
        y = 0;
    }
    Point(int a, int b) //2
    {
        x = a;
        y = b;
    }
};

int main()
{
    Point p1;                    //1호출
    Point p2(1, 2);              //2호출
    Point p3{1, 2};              //2호출
    Point p4[3];                 //1번생성자가 3회 호출
    Point p5[3] = {Point(1, 1)}; //2번 1회,1번 2회 호출
    Point *p6;                   //생상자 호출 안됨

    p6 = static_cast<Point *>(malloc(sizeof(Point))); //생성자 호출 안됨

    p6 = new Point;       //생성자 호출
    p6 = new Point(1, 2); //생성자 호출

    delete p6;
}
#endif

#if 0
#include <iostream>

class Point
{
    int x, y;

public:
    Point()
    {
        std::cout << "Point()" << std::endl;
    }
};

class Rect
{
    Point p1;
    Point p2;

public:
    Rect()
    {
        std::cout << "Rect()" << std::endl;
    }
};

int main()
{
    Rect r;
    /*
    Point() <-p1
    Point() <-p2
    Rect()
    순서대로 호출된다.
    */
}
/*
객체를 구성하는 요소의 생성자가 먼저 호출되고
객체 자신의 생성자가 호출된다
*/
#endif
#include <iostream>

class Point
{
    int x, y;

public:
    //1.
    Point() = default; //C++11부터 나온 문법이다.
    //default 생성자를 만들어준다.
    //C++중급에 가면 Point() { }와 차이를 배울수 있다.

    //2.
    Point() = delete;
    //defalt 생성자를 삭제하라는 문법도 있다.

    Point(int a, int b)
    {
        std::cout << "Point()" << std::endl;
    }
};

int main()
{
    Point p;
}