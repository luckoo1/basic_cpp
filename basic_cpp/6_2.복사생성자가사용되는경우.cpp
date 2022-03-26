//복사생성자가 사용되는 경우에 대해 알아보자.
#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a = 0, int b = 0) : x(a), y(b) //생성자
    {
        std::cout << "Point()" << std::endl;
    }

    Point(const Point &p) : x(p.x), y(p.y) //복사생성자
    {
        std::cout << "Point(Point&)" << std::endl;
    }
};

int main()
{
    Point p1(1, 2); //생성자
    Point p2(p1);   //복사생성자
    Point p3{p1};   //복사생성자
    Point P4 = p1;  //복사생성자 "Point p4(p1)"
}
/*
1. 객체가 자신의 타입으로 초기화 될 때
Point p2(p1)
Point P2{p1}
Point p2 = p1
*/
//#######################################################################

#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a = 0, int b = 0) : x(a), y(b) //생성자
    {
        std::cout << "Point()" << std::endl;
    }

    Point(const Point &p) : x(p.x), y(p.y) //복사생성자
    {
        std::cout << "Point(Point&)" << std::endl;
    }
};

void foo(Point pt)
{
}

int main()
{
    Point p;
    foo(p);
    /*
    call by value
    "Point pt = p"와 같은 형식이다.
    foo()함수로 넘어가는 순간에 복사생성자가 불린다.
    */
}
/*
2. 함수 인자로 객체를 값으로 받을 때(call by value)
const&를 사용하면 복사생성자/소멸자의 호출을 막을 수 있다.
void foo(const Point& p);
위와 같이 사용하면 복사생성자와 소멸자의 호출을 막으니깐 성능이 향상되는거다.
*/
//#######################################################################

#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a = 0, int b = 0) : x(a), y(b) //생성자
    {
        std::cout << "Point()" << std::endl;
    }

    Point(const Point &p) : x(p.x), y(p.y) //복사생성자
    {
        std::cout << "Point(Point&)" << std::endl;
    }
};

void foo(const Point &pt) //이렇게 바꿈!
{
}

int main()
{
    Point p;
    foo(p);
}
//이 코드 빌드하면 생성자만 부른다.
//#######################################################################

#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a = 0, int b = 0) : x(a), y(b) //생성자
    {
        std::cout << "Point()" << std::endl;
    }

    Point(const Point &p) : x(p.x), y(p.y) //복사생성자
    {
        std::cout << "Point(Point&)" << std::endl;
    }
};

Point foo()
{
    Point pt(1, 2); //생성자 호출
    return pt;      //복사생성자 호출
    /*
    여기 pt객체는 지역객체라서 블록을 벗어날때 파괴될텐데
    return pt;를 했네
    return pt;의 순간 리턴용 임시객체생성
    임시객체를 리턴한다.
    */
}

int main()
{
    foo(); //여기에 리턴용 임시객체가 놓이게 된다.
    //foo();가 있는 줄을 마치고 다음줄로 내려가면 임시객체가 파괴된다.
    //그림필기
    //리턴용 임시객체를 만들때 복사생성자를 사용한다.
}

/*copy ellipse
MS 컴파일은 복사생성자가 불리는데
g++로 컴파일했는데 복사생성자가 안불린다.
이유는 요즘 컴파일러들이 복사생성자 최적화를 했다.
최적화를 풀려면
g++ "파일명".cpp -fno-elide-constructors
g++ 6_2.복사생성자가사용되는경우.cpp -fno-elide-constructors
이렇게 하면 불린다.
*/

/*
3. 함수가 객체를 값으로 리턴할 때-리턴용 임시객체 생성
RVO/NRVO
g++ 사용시 -fno-elide-constructors옵션
*/