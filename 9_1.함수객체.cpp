#if 0
#include <iostream>

struct Plus
{
    int operator()(int a, int b)
    {
        return a + b;
    }
};

int main()
{
    Plus p;          //이건 Plus 구조체의 객체다
    int n = p(1, 2); //이건 마치 함수처럼 보이네?!
    //객체를 함수처럼 사용한 것 : 함수객체

    std::cout << n << std::endl; //3이 호출된다

    /*
    a가 사용자 타입이면
    a+b;하면
    a.operaotor+(b)
    a-b;하면
    a.operaotor-(b)

    a();하면
    a.operator()()
    앞에 괄호는 연산자 이름을 위한거라 뒤에 괄호가 하나 더 붙음
    괄호 연산자를 찾아서 호출해달라는 말이다.

    a(1,2);하면
    a.operator()(1,2);
    operator()를 호출하면서 인자로 (1,2)를 보낸다
    */
}

/*
함수객체(function object)
()연산자를 재정의해서 함수처럼 사용 가능한 객체
"function object"또는 "functor"라고도 부른다.

함수객체의 장점
특정 상황(다른 함수의 인자로 전달될 때)에서는 일반함수보다 빠르다(인라인 치환)
상태를 가지는 함수(멤버 데이터가 있고,멤버 함수를 활용 가능)
*/
#endif
#if 0
#include <iostream>

int add(int a, int b)
{
    return a + b;
}
//일반함수로 add만들면 이 안에는 동작밖에 할수 없다

//struct는 다르다.
struct Plus
{
    int base;                    //여기서 add만들어서 멤버데이터도 추가함
    Plus(int n = 0) : base(n) {} //생성자도 만들수 있음
    int operator()(int a, int b)
    {
        return base + a + b; //여기에다가 base도 추가 가능
    }
};

int main()
{
    Plus p;
    int n = p(1, 2);

    std::cout << n << std::endl;
}
#endif

#if 0
#include <iostream>

int add(int a, int b)
{
    static int base = 10; //이런식으로 적어도 되는거 아니냐?
    //그런데 위에것은 값을 바꿀수 없다.
    return a + b;
}

struct Plus
{
    int base;
    Plus(int n = 0) : base(n) {}
    void resetBase(int n) { base = n; } //여기서는 이런식으로 값을 바꿀 수 있다.
    int operator()(int a, int b)
    {
        return base + a + b;
    }
};

int main()
{
    Plus p;
    int n = p(1, 2);

    std::cout << n << std::endl;
}
#endif

#if 0
#include <iostream>
//아래와 같이 template를 사용하면 더 좋다
template <typename T>
struct Plus
{
    T operator()(T a, T b)
    {
        return a + b;
    }
};

int main()
{
    Plus<int> p;
    int n = p(1, 2);
}
#endif

#include <iostream>
#include <functional> //C++표준에는 이미 plus함수를 가지고 있다.

int main()
{
    std::plus<int> p;
    int n = p(1, 2);
}

/*
C++표준 함수 객체
<functional>헤더
plus,minus,module,less,greater등
www.cppreference 사이트 참고
*/