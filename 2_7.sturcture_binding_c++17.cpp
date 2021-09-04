//c++17문법
//구조체나 배열의 각 멤버에서 값을 꺼낼 때 사용
//타입은 반드시 auto사용해야한다.
#if 0

#include <iostream>

struct Point
{
    int x = 10;
    int y = 20;
};

int main()
{
    Point p;
    int a = p.x;
    int b = p.y;
    std::cout << a << " " << b << std::endl;
}
#endif

#if 0
#include <iostream>

struct Point
{
    int x = 10;
    int y = 20;
};

int main()
{
    Point p;
    auto [a, b] = p;
    //p가 가지고 있는 모든 멤버를 [ ]안으로 옮겨라

    std::cout << a << " " << b << std::endl;
}
#endif

#if 0
#include <iostream>

struct Point
{
    int x = 10;
    int y = 20;
};

int main()
{
    Point p;
    auto [a, b] = p;       //OK
    int[a, b] = p;         //error
    const auto [a, b] = p; //error

    std::cout << a << " " << b << std::endl;
}
#endif

#include <iostream>

struct Point
{
    int x = 10;
    int y = 20;
};

int main()
{
    int x[2] = {1, 2};
    auto [a, b] = x;
    //배열도 가능

    std::cout << a << " " << b << std::endl;
}