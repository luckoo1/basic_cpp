#if 0
#include <iostream>

void inc1(int n) { ++n; }
void inc2(int *p) { ++(*p); }
void inc3(int &r) { ++r; }

int main()
{
    int a = 10;
    int b = 10;
    int c = 10;

    inc1(a);
    inc2();
    inc3();
    //전부다 11이 나오게 해보고 싶다.
    //일단 괄호에 뭐 넣어야할까??
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
}
#endif

#if 0
#include <iostream>

void inc1(int n) { ++n; }
void inc2(int *p) { ++(*p); }
void inc3(int &r) { ++r; }

int main()
{
    int a = 10;
    int b = 10;
    int c = 10;

    inc1(a);
    inc2(&b); //포인터 변수로 받으니깐 b의 주소를 보낸다.
    inc3(c);  //참조로 받았으니 그냥 변수로 보내자

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
}
#endif

#if 0
#include <iostream>

void inc1(int n) { ++n; }
void inc2(int *p) { ++(*p); }
void inc3(int &r) { ++r; }

int main()
{
    int a = 10;
    int b = 10;
    int c = 10;

    inc1(a); //n변수안에서 ++될뿐이다.
             //call by value

    inc2(&b); //가리키는 주소에서 ++이 된다.
              //call by pointer

    inc3(c); //가리키는 곳에서 ++된다
             //call by reference

    //그림참조
    std::cout << a << std::endl; //10
    std::cout << b << std::endl; //11
    std::cout << c << std::endl; //11
}
#endif
#include <iostream>

int main()
{
    int n = 0;
    scanf("%d", &n);
    //scanf는 변수에 값을 담아야해서 주소를 보냈다.
    //scanf는 인자로 포인터

    std::cin >> n;
    //cin은 주소안썼음
    //cin은 참조로 전달 받음
}