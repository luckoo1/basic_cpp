#if 0
#include <iostream>

struct Point
{
    int x;
    int y;
};
//인자로 받을때
void f1(Point p) {}  //복사본이 생성된다.
void f2(Point &r) {} //복사본이 아님

int main()
{
    goo();
}
#endif

#if 0
//리턴도 마찬가지이다.
#include <iostream>

struct Point
{
    int x;
    int y;
};

Point pt;
Point goo() { return pt; }

int main()
{
    goo();
    /*그림참조
    goo()자리에 pt가 온게 아니라
    리턴용 임시객체가 오는거다.
    */
    goo().x = 20; //error
    //g++ error : "using temporary as lvalue"
    //MS 컴파일러 error : "왼쪽 피연산자는 l-value여야 합니다".
    //임시객체는 왼쪽에 올 수 없다.
    std::cout << pt.x << std::endl; //error
}
#endif

#if 0
#include <iostream>

struct Point
{
    int x;
    int y;
};

Point pt;
Point& goo() { return pt; }
//return 값을 참조로 만들어서 리턴해 버린다.
//참조로 만들어서 리턴하니 복사본을 만들지 않는다.

int main()
{
    goo().x = 20;
    //참조로 리턴을 받았다.
    //복사본이 아닌 진짜 pt다.
    //참조리턴인경우 에러 아님
    std::cout << pt.x << std::endl; //20
}
#endif

/*
정리
함수리턴
1.return by value : 복사본(임시 객체)를 리턴한다
임시객체는 등호의 왼쪽에 올 수 없다(lvalue가 될수 없다)
2.return by reference : 복사본을 만들지 않는다.
3.지역변수는 참조로 리턴하면 절대 안된다.
*/

//3번 설명
#include <iostream>

struct Point
{
    int x;
    int y;
};

Point pt;

Point &goo()
{
    Point p;
    //1
    //이건 지역 객체다
    //{}을 지나면 파괴 된다.
    return p;

    //2.
    //참조 리턴하면
    //4.
    //block을 지나면 파괴니깐
    //이렇게 쓰면 안된다.
}

int main()
{
    goo().x = 20;
    //3.여기서 참조리턴된게 살아 있어야하는데
    std::cout << pt.x << std::endl;
}

//5.C++에서 지역변수로 참조를 리턴하지말라고 했지 참조로 리턴하면 어떻게 되는지는 적지않았다
//undefined다
//컴파일러마다 다르다.