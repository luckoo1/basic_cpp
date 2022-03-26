#include <iostream>
//아래의 상황을 가정해보자
//x 값을 foo함수로 넘기고 싶은데 절대로 x값을 바꾸면 안되는 상황이다
//?에 들어갈 값은?
void foo(? a)
{
}

int main()
{
    int x = 10;
    foo(x);
    std::cout << x << std::endl;
}
//#######################################################################
#include <iostream>

//call by value로 받으면 절대로 x는 안변한다.
//복사본이 하나 더 만들어져서 넘긴다.
void foo(int a)
{
}

int main()
{
    int x = 10;
    foo(x);
    std::cout << x << std::endl;
}
//#######################################################################
#include <iostream>

/*그런데 아래의 경우를 살펴보자
구조체가 있는데 용량이 매우크다

call by value의 특징은 복사본이 하나 더 만들어지는거다.
call by value로 인자를 넘기니깐 성능저하가 커진다.
*/
struct Data
{
    char data[1000];
};

void foo(Data a) //call by value
{
}

int main()
{
    Data x = 10;
    foo(x);
    std::cout << x << std::endl;
}
//#######################################################################
#include <iostream>
/*
call by reference하면
복사가 안되니깐 메모리적 측면에서는 좋다.
그런데 foo함수내에서 원본이 바뀔수도 있다.
*/
struct Data
{
    char data[1000];
};

void foo(Data &a) //call by reference
{
}

int main()
{
    Data x = 10;
    foo(x);
    std::cout << x << std::endl;
}
//#######################################################################
#include <iostream>
/*
const reference를 사용했다.
x가 복사본을 만든건 아니다.
*/
struct Data
{
    char data[1000];
};

void foo(const Data &a) //const reference
{
}

int main()
{
    Data x = 10;
    foo(x);
    std::cout << x << std::endl;
}
//#######################################################################

/*

정리
1.함수의 인자로 사용한 변수의 값을 변경되지 않게 하려면
call by value : 동일한 객체가 메모리에 한번 더 생성된다
const reference가 좋다.

2.객체의 복사본이 생성되지 않는다.
복사생성자와 소멸자의 호출을 막을수 있다.(추후공부)

3.
void goo(int n) {}
void goo(const int &n) {}
int와 같은 표준타입쓸때에는 메모리도 작다
call by value가 최적화 측면에서 훨씬 좋다.

primitive type : call by value(ex. int,char)
user define type : const reference(ex. 구조체)

*/
