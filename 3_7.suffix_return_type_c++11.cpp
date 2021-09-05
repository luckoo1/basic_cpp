#if 0
int square(int a) 
    return a * a;
}

int main()
{
    square(3);
}
#endif

#if 0
//후위 반환 타입
//return type을 뒤에 적었다.(int)
auto square(int a) -> int
{
    return a * a;
}

int main()
{
    square(3);
}
#endif

/*
정리
1.C++11에 추가된 문법
2.리턴 타입을 함수()뒤에 적는 표기법
3.suffix return 또는 trailing return 이라고 한다
4.원래의 리턴 값 위치(함수 이름 앞)에는 auto라고 적는다.
*/

//왜 이게 필요할까???????
//람다표현식과 template에 많이 쓰인다.

#if 0
//이렇게 만들면 int만 덧셈이 된다.
int Add(int a, int b)
{
    return a + b;
}

int main()
{
    Add(1, 2);
}
#endif

#if 0
//아래와 같이 사용해서 문제가 없었다.
template <typename T>
T Add(T a, T b)
{
    return a + b;
}

int main()
{
    Add(1, 2);
}
#endif

#if 0
//아래와 같이 쓰이면....?
//error가 뜬다.
//같은 type보내달라했는데 다른 type보냈으니깐..
template <typename T>
T Add(T a, T b)
{
    return a + b;
}

int main()
{
    Add(1, 2.2);
}
#endif

#if 0

//type을 2개 받는다.
//근데 return type는 어떻게 할거냐...?
//T Add(T a, U b)리턴타입이 무조건 int
//U Add(T a, U b)리턴타입이 무조건 double되는데..
//?? Add(T a, U b) ??에 뭐써야하나..
template <typename T, typename U>
T Add(T a, U b)
{
    return a + b;
}

int main()
{
    Add(1, 2.2);
}
#endif

#if 0
//그래서 아래와 같은 아이디어를 생각했다.
//error가 발생한다.
//'a' was not declared in this scope
//'b' was not declared in this scope
//이런 에러가 발생
//decltype(a + b)에 있는 변수 a,b의 선언은
//Add(T a,U b)단계에서 진행된다.
//즉 변수 선언전에 사용한격이 된다.
/*
a = 20;
int a =10;
a=20
과 같이 사용하는 격이다.
a를 밑에서 선언했는데 위에서 a쓰는 격
*/
//decltype(a + b)시점에서는 a,b가 선언이 안된격

template <typename T, typename U>
decltype(a + b) Add(T a, U b)
{
    return a + b;
}

int main()
{
    Add(1, 2.2);
}
#endif

//아래와 같이 사용하면 Add(T a, U b)한뒤에
//decltype(a + b)썼으니 문제가 없다.
template <typename T, typename U>
auto Add(T a, U b) -> decltype(a + b)
{
    return a + b;
}

int main()
{
    Add(1, 2.2);
}