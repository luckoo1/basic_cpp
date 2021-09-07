#if 0
#include <iostream>

class Point
{
    int x;
    int y;

public:
    Point() : x(0), y(0) //1.초기화 리스트(initialzier list)
    {
        // x = 0;
        // y = 0;
        //3. 여기는 대입이다.
    }
};

int main()
{
    Point p;

    //2.
    //초기화
    int n = 0;

    //대입
    int n2;
    n2 = 0;
    //초기화는 만들때 넣는거 대입은 만들고 나서 넣는것
}

/*
4.
int형은 초기화나 대입이나 큰 차이가 없다.

객체(사용자 정의 타입)의 관점으로 보면
초기화는 생성자로 초기화를 한다.
대입은 생성자 호출후 대입 연산자를 호출한다.(성능저하)
*/
#endif

#if 0
int main()
{
    const int c1 = 10;
    //밑에 2줄은 error
    const int c2;
    c2 = 10;

    //초기화는 가능하나 대입은 불가능하다
}
#endif

#if 0
#include <iostream>

class Point
{
    int x;
    int y;
    const int c; //1.이거 추가했다.

public:
    Point() : x(0), y(0)
    {
        c = 10; //대입이니깐 당연히 error
    }
};

int main()
{
    Point p;
}
#endif

#if 0
#include <iostream>

class Point
{
    int x;
    int y;
    const int c;

public:
    Point() : x(0), y(0), c(10) //여기에 이렇게 적으면 초기화라서 된다.
    {
    }
};

int main()
{
    Point p;
}
//초기화리스트를 사용하는 것이 좋다.
#endif

#if 0
#include <iostream>

class Point
{
public: //설명을 위해
    int x;
    int y;

public:
    Point() : y(0), x(y)
    {
        /*
        2.
        int x;
        int y;
        이런식으로 선언해서
        위에 구문은 코딩상으로는 y부터 실행되는거처럼 보이지만
        실제로는 x부터 실행된다.

        즉 멤버데이터가 놓여있는 순서가 중요하다.
        */
    }
};

int main()
{
    Point p;
    //1.
    std::cout << p.x << std::endl; //쓰레기 값
    std::cout << p.y << std::endl; //0
}

#endif
#if 0
#include <iostream>

class Point
{
public:
    int x;
    int y;

public:
    //선언부
    Point(int a = 0, int b = 0);
};

//구현부
Point::Point(int a, int b) : x(a), y(b)
{
}

int main()
{
    Point p;

    std::cout << p.x << std::endl;
    std::cout << p.y << std::endl;
}

/*
초기화 리스트 정리
생성자의 () 뒤에 :을 표기하고 멤버를 초기화 하는 것
대입이 아니라 초기화다
멤버가 놓인 순서대로 초기화 된다.
*/
#endif

#if 0
#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a, int b) : x(a), y(b)
    {
    }
};

class Rect
{
    const int c;

public:
    Rect() : c(0)
    {
    }
};

int main()
{
}
#endif

#if 0
#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a, int b) : x(a), y(b)
    {
    }
};

class Rect
{
    //1.추가
    Point p1;
    Point p2;
    const int c;

public:
    Rect() : c(0)
    {
    }
};

int main()
{
    Rect c;
    /*
    2.
    Rect의 객체를 만들어서
    Point p1;
    Point p2;
    호출했는데
    Point class에는 기본 생성자가 없네
    error발생
    */
}
#endif

#if 0
#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a, int b) : x(a), y(b)
    {
    }
};

class Rect
{
    Point p1;
    Point p2;
    const int c;
    int &r; //이것도 추가

public:
    Rect() : p1(0, 0), p2(0, 0), c(0), r(n) //이렇게 적어야 한다.
    //n은 초기화할수 있는 뭔가로 받아야한다.
    {
    }
};

int main()
{
    Rect c;
}

/*초기화 리스트가 반드시 필요한 경우
객체가 상수멤버나 참조 멤버를 가진 경우 초기화 리스트로 초기화 되어야한다
디폴트 생성가 없는 경우 객체를 멤버로 가진 경우도 초기화 리스트를 사용해서 초기화 해야한다.
*/

#endif
