#if 0
#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    void print() const
    {
        std::cout << x << ", " << y << std::endl;
    }
};

int main()
{
    Point p1(1, 1);
    Point p2(2, 2);

    p1 + p2; //p1.operator+(p2)
    //만든적 없어서 error나온다
    p1 = p2; //p1.operator=(p2)
    //이것도 만든적 없는데 error가 왜 안나오지?

    p1.print();
    //실행도 2,2가 나와!!!
}
/*
대입연산자
operator=()
사용자가 제공하지 않으면 컴파일러가 제공한다
모든 멤버를 대입해준다.

아래거랑 헷갈리지 말자
Point p3 = p2;
위에거는 p3를 만들때 넣는거다
대입연산자가 아닌 복사생성자다

복사 생성자vs대입 연산자
복사생성자 : 객체를 만들면서 초기화할 때
대입연산자 : 객체를 만든 후에 대입할 때
*/
#endif

#if 0
#include <iostream>
//대입연산자 만들어보자
//아래와 같이 하면 정상 작동한다.
class Point
{
    int x, y;

public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    void print() const
    {
        std::cout << x << ", " << y << std::endl;
    }
    void operator=(const Point &p)
    {
        x = p.x;
        y = p.y;
        std::cout << "= logging" << std::endl;
    }
};

int main()
{
    Point p1(1, 2);
    Point p2(3, 4);

    p1 = p2; //p1.operator=(p2)

    p1.print();
}
#endif

#if 0
#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    void print() const
    {
        std::cout << x << ", " << y << std::endl;
    }
    //1.이거 return type생각해보자
    void operator=(const Point &p)
    {
        x = p.x;
        y = p.y;
        std::cout << "= logging" << std::endl;
    }
};

int main()
{
    Point p1(1, 2);
    Point p2(3, 4);

    p1 = p2;
    //2.내가 아래와 같이 만들수도 있잖아

    Point p3;

    p3 = (p1 = p2);
    //3.p2를 p1으로 옮긴다음에 다시 그 결과를 p3에 넣는 것
    //지금은 operator= return type가 void라서 error
    p1.print();
}
#endif
#if 0
#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    void print() const
    {
        std::cout << x << ", " << y << std::endl;
    }
    //1.아래와 같이 수정하자
    Point operator=(const Point &p)
    {
        x = p.x;
        y = p.y;
        std::cout << "= logging" << std::endl;
        return *this;
    }
};

int main()
{
    Point p1(1, 2);
    Point p2(3, 4);

    p1 = p2;

    Point p3;

    p3 = (p1 = p2);

    p1.print(); //3,4
    p3.print(); //3,4
}
#endif

#if 0
#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    void print() const
    {
        std::cout << x << ", " << y << std::endl;
    }
    Point operator=(const Point &p)
    {
        x = p.x;
        y = p.y;
        std::cout << "= logging" << std::endl;
        return *this;
    }
};

int main()
{
    Point p1(1, 2);
    Point p2(3, 4);

    Point p3;
    //1.아래와 같이 해보자
    (p3 = p1) = p2;
    /*
    p3에 p1을 넣으니 p3가 되고 거기 p2를 넣으니
    최종적으로 p3에는 p2가 들어가야하는데
    */

    p3.print(); //1,2가 나온다
}

/*
왜그럴까?
(p3=p1)햇을떄
저 자리에 오는건 임시객체다
임시객체에 p2를 넣는격이다
p3에는 결국 p1만 들어가는거다.
*/
#endif

#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    void print() const
    {
        std::cout << x << ", " << y << std::endl;
    }
    //참조리턴해야한다
    Point &operator=(const Point &p)
    {
        x = p.x;
        y = p.y;
        std::cout << "= logging" << std::endl;
        return *this;
    }
};

int main()
{
    Point p1(1, 2);
    Point p2(3, 4);

    Point p3;

    (p3 = p1) = p2;

    p3.print();
}

/*
대입연산자
자기 자신의 참조를 리턴해야한다.
*/