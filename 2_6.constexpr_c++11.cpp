#if 0

int main()
{
    int n = 0;
    n = 10;

    const int c = 10;
    c = 20; //error

    constexpr int c2 = 10;
    c2 = 20; //error

    const int c3 = n;     //ok
    constexpr int c4 = n; //error
}

//정리1
//c++에서 상수를 만드는 방법
//const : 초기값으로 literal뿐 아니라 변수도 사용가능
//constexpr : 컴파일 시간 상수 초기값으로 컴파일 시간에 결정된 값만 사용해야 한다.
#endif

#include <iostream>

int main()
{
    const int c = 10;
    //밑에 코드는 error
    //int *p = &c;
    //상수의 주소를 비상수 포인터로 가리키는 건 불가능
    //그림설명
    //int 포인터가 가리키는 곳은 1000번지인데 따라가면 int가 있으니 난 바꿀수 있을거라 생각하는데 그게 안된다.

    int *p = (int *)&c; //OK 강제로 캐스팅

    *p = 20;

    std::cout << c << std::endl;  //10
    std::cout << *p << std::endl; //20
}

/*
const int c = 10; <=컴파일 시간에 컴파일러가 c가 10인걸 안다.
컴파일 시간 상수이다.
컴파일러는 c는 10이네
c를 읽어오는 코드가 있으면 메모리에서 가져오는게 아니라 컴파일 할때
std::cout << c << std::endl;을
std::cout << 10 << std::endl; 방식으로 바꿔버린다.
그런데 int *p = (int *)&c;
c를 강제로 캐스팅해서 바꾸었으니 역참조해서 꺼내면
20이 되는거다.

컴파일 시간 상수는 컴파일러에 의해서 매크로처럼 처리된다.
*/

#include <iostream>
int main()
{
    int n = 10;
    const int c = n;

    int *p = (int *)&c;

    *p = 20;

    std::cout << c << std::endl;  //20
    std::cout << *p << std::endl; //20
}
/*
n은 변수다
const int c = n;
컴파일 시간에 값을 모르겠다.
실행시간 상수다
실행할때는 값은 바꿀수 없지만 초기값이 뭔지는 컴파일할때 모른다.
std::cout << c << std::endl;와 같이 c를 접근하는 코드가 있으면
실제로 메모리에 가서 읽어온다.
*/

/*
컴파일 시간 상수와 실행 시간 상수를 같은 키워드를 써서 관리해서 복잡해진다고 판단되었다.
컴파일 시간 상수만을 다룰수 있는 키워드가 필요하다 => constexpr
*/

/*
정리
상수의 종류는
runtime constant
complie-time constant
constexpr은 compile-time 상수로만 초기화 가능하다.
*/

int main()
{
    int ar1[3]; //OK

    int s1 = 3;  //OK
    int ar2[s1]; //??
                 //
}

/*
배열의 크기
c89문법 : 컴파일 시간 상수만 가능
c99문법 : 변수도 가능하다 (VC++지원 안함)
*/

int main()
{
    const int s2 = 3;
    int ar3[s2]; //OK
    //컴파일 시간에 s2가 3이라는 사실을 아니깐 가능하다.
}

int main()
{
    int s1 = 3;

    const int s3 = s1;
    int ar3[s3]; //error
    //컴파일 시간에 s3가 뭘로 초기화 되는지 알 수 없다.
}

////////////////////////////////
void foo(const int s)
{
    int x[s]; //error
}

/*
foo호출시 foo(3)과 같이 호출할수도 있지만
foo(n)과 같이 호출 할수도 있다.
컴파일 시간에 s를 알 수 없다.
런타임 상수가 된다.
int x[s];부분이 없으면 컴파일 된다.
*/

int main()
{
    int n = 10;

    const int c1 = 10; //ok
    const int c2 = n;  //ok
    //c1은 배열의 크기로 들어갈 수 있으나 c2는 배열의 크기로 들어갈 수 없다.
    //c1은 템플릿의 인자로 갈 수 있지만 c2는 템플릿의 인자로 갈 수 없다.

    constexpr int c1 = 10; //ok(컴파일 최적화에도 좋다)
    constexpr int c2 = n;  //error
}

//결론 : 컴파일 상수를 만들때는 constexpr쓰자.