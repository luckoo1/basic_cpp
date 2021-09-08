#if 0
#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a = 0, int b = 0)
    {
        std::cout << "Point()" << std::endl;
    }
    Point(const Point &p)
    {
        std::cout << "Point(Point&)" << std::endl;
    }
    ~Point()
    {
        std::cout << "~Point()" << std::endl;
    }
};

int main()
{
    Point p1(1, 1);                  //1.생성자 호출
    std::cout << "AAA" << std::endl; //2."AAA"
                                     //3.소멸자 호출
    /*
    출력
    Point()
    AAA
    ~Point()
    */
}
#endif

#if 0

#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a = 0, int b = 0)
    {
        std::cout << "Point()" << std::endl;
    }
    Point(const Point &p)
    {
        std::cout << "Point(Point&)" << std::endl;
    }
    ~Point()
    {
        std::cout << "~Point()" << std::endl;
    }
};

int main()
{
    Point(1, 1);
    /*
    1.c++에서 "클래스이름()"의 문법이 있다.
    이렇게 하면 임시객체를 만든다.
    이 임시객체의 수명은 Point(1,1);
    즉 단일 문장에서만 사용되고, 문장의 끝에 오면 파괴된다.
    */
    std::cout << "AAA" << std::endl;
    /*
    출력
    Point()
    ~Point()
    AAA
    */
}

/*
임시객체
"클래스이름()"로 만드는 객체
사용자가 직접 만들거나 컴파일러에 의해 임시객체를 만드는 코드가 생성됨
단일 문장에서만 사용된다.문장의 끝에서 파괴된다.
"C++ Intermediate"과정 참고
*/
#endif
#if 0
//전역객체의 관점에서 보자.
#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a = 0, int b = 0)
    {
        std::cout << "Point()" << std::endl;
    }
    Point(const Point &p)
    {
        std::cout << "Point(Point&)" << std::endl;
    }
    ~Point()
    {
        std::cout << "~Point()" << std::endl;
    }
};

Point pt(1, 1); //1

Point foo()
{
    std::cout << "foo" << std::endl; //2
    return pt;                       //3 pt를 복사해서 리턴용 임시객체생성
}

int main()
{
    foo();
    //4 foo()함수 빠져 나가면 임시객체파괴
    std::cout << "end of main" << std::endl; //5
}
//6

/*
위의 코드의 순서
1.전역변수 생성자
2.foo
3.복사 생성자 - 임시객체
4.소멸자 - 임시객체
5.end of main
6.전역변수 소멸자
*/

/*
Point()
foo
Point(Point&)
~Point()
end of main
~Point()
*/
#endif

#if 0
#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a = 0, int b = 0)
    {
        std::cout << "Point()" << std::endl;
    }
    Point(const Point &p)
    {
        std::cout << "Point(Point&)" << std::endl;
    }
    ~Point()
    {
        std::cout << "~Point()" << std::endl;
    }
};

Point pt(1, 1); //1

Point &foo() //임시객체의 생성을 막기위해 참조형 리턴을 했다.
{
    std::cout << "foo" << std::endl; //2
    return pt;
}

int main()
{
    foo();
    std::cout << "end of main" << std::endl; //3
}
//4

/*
1.전역변수 생성자
2.foo
3.end of main
4.전역변수 소멸자
*/

/*
Point()
foo
end of main
~Point()
*/

/*
함수가 값 타입으로 리턴할때
리턴용 임시객체가 생성된다
리턴용 임시객체는 함수 호출이 이루어지는 문장이 종료될때 파괴된다

함수가 참조를 리턴하면 리턴용 임시 객체가 생성되지 않는다.
*/
#endif

#if 0
//지역객체의 관점에서 보자.
#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a = 0, int b = 0)
    {
        std::cout << "Point()" << std::endl;
    }
    Point(const Point &p)
    {
        std::cout << "Point(Point&)" << std::endl;
    }
    ~Point()
    {
        std::cout << "~Point()" << std::endl;
    }
};

Point foo()
{
    Point pt(1, 1);                  //1
    std::cout << "foo" << std::endl; //2
    return pt;                       //3
}
//4

int main()
{
    foo();
    //5
    std::cout << "end of main" << std::endl; //6
}

/*
1.지역객체 생성자
2.foo
3.복사 생성자 - 임시객체
4.지역변수 소멸자
5.소멸자 - 임시객체
6.end of main
*/

/*
g++컴파일(복사생성자 최적화)
Point()
foo
~Point()
end of main
*/

/*
g++ "6_3.RVO&NRVO.cpp" -fno-elide-constructors(복사생성자 최적화 막기)
Point()
foo
Point(Point&)
~Point()
~Point()
end of main
*/
#endif

#if 0
//1.임시객체 생성막을려고 참조리턴을 고려해보았다.
#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a = 0, int b = 0)
    {
        std::cout << "Point()" << std::endl;
    }
    Point(const Point &p)
    {
        std::cout << "Point(Point&)" << std::endl;
    }
    ~Point()
    {
        std::cout << "~Point()" << std::endl;
    }
};
//2. 그런데 지역변수는 블럭 벗어나면 파괴되는데....?
//   참조리턴이 안된다.
Point &foo()
{
    Point pt(1, 1);
    std::cout << "foo" << std::endl;
    return pt;
}

int main()
{
    foo();
    std::cout << "end of main" << std::endl;
}
#endif

//Point pt(1,1);
//return pt;가 따로 있어서 그런거같다
//만들면서 리턴하자.
//임시객체로 리턴하자는 거다.
#include <iostream>

class Point
{
    int x, y;

public:
    Point(int a = 0, int b = 0)
    {
        std::cout << "Point()" << std::endl;
    }
    Point(const Point &p)
    {
        std::cout << "Point(Point&)" << std::endl;
    }
    ~Point()
    {
        std::cout << "~Point()" << std::endl;
    }
};

Point foo()
{
    std::cout << "foo" << std::endl; //1
    return Point(1, 1);              //2 만들면서 임시객체로 리턴하자.
}

int main()
{
    foo();
    //3
    std::cout << "end of main" << std::endl;
}

/*
1.foo
2.임시객체 생성자
3.임시객체 소멸자
*/

/*
foo
Point()
~Point()
end of main
*/

/*
지역변수를 리턴할 때는 임시객체를 사용한 리턴이 효율적이다.
RVO : Return Value Optimization
NRVO : named RVO
요즘 컴파일러들이 똑똑해서
Point foo()
{
    Point pt(1, 1);
    std::cout << "foo" << std::endl;
    return pt;
}
위와 같은 코드를
Point foo()
{
    std::cout << "foo" << std::endl;
    return Point(1, 1); 
}
컴파일러에 의해서 알아서 바뀐다.
복사생성자 호출이 생략되는거다.
이름이 있는 객체라도 RVO를 쓸 수 있다고 해서 named RVO라고 부른다.

요즘은 그냥 위에 코드로도 쓰는데 용어가 많이 나온다.
용어정도는 알아줬으면 좋겠다는 취지로 공부함
*/

/*
최종정리
함수가 값 타입으로 리턴할때
리턴용 임시객체가 생성된다
리턴용 임시객체는 함수 호출이 이루어지는 문장이 종료될때 파괴된다

함수가 참조를 리턴하면 리턴용 임시 객체가 생성되지 않는다.

지역변수는 참조리턴이 안된다.

지역변수를 리턴할 때는 임시객체를 사용한 리턴이 효율적이다.
RVO : Return Value Optimization
NRVO : named RVO
*/