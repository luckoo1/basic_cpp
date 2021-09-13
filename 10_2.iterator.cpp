#if 0
#include <iostream>
#include <vector>
#include <list>

int main()
{
    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8};

    int *px = x;
    ++px;
    *px;
    //1.요소에 접근할때 이런식으로 접근을 했었다.
    std::list<int> s = {1, 2, 3, 4, 5, 6, 7, 8};

    /*
    2.
    리스트는 연속되지 않은데
    그럼에도 불구하고 ++을 연산자 재정의를 해서
    처음꺼 꺼내서 ++로 뒤로 이동할 수 있다.
    */
    std::list<int>::iterator p1 = s.begin();
    //이게 좀 복잡하네..
    //std안에있는 list<int>안에 iterator쓰자는 말
    auto p2 = s.begin();
    //auto라고 편하게 적자

    ++p1;
    ++p2;

    int n1 = *p1;
    int n2 = *p2;

    std::cout << n1 << std::endl;
    std::cout << n2 << std::endl;
}
/*
반복자(iterator)
컨테이너의 요소를 가리키는 포인터와 유사한 객체
++,*연산자등을 재정의해서 포인터와 유사하게 동작하도록 만든 것
list<int>::iterator가 정확한 타입
멤버함수 begin()을 통해서 꺼낼 수 있다.
*/
#endif

#if 0
#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::list<int> s = {1, 2, 3, 4, 5, 6, 7, 8};

    //std::list<int>::iterator p = s.begin();
    //아래와같이 사용하자
    auto p1 = s.begin();

    auto p2 = s.end(); //마지막 다음 요소
    *p2 = 10;          //runtime error
    //마지막 다음에는 메모리를 할당한적이 없다.

    //end를 아래와 같이 사용할 수 있다
    while (p1 != s.end())
    {
        int n = *p1;
        ++p1;
    }
}

/*
반복자(iterator)주의 사항
end로 꺼내는 반복자는 마지막 요소가 아닌 마지막 다음 요소를 가리킨다.
*/
#endif

#if 0
#include <iostream>
#include <vector>
#include <list>

int main()
{
    int s[] = {1, 2, 3, 4, 5, 6, 7, 8};
    /*
    s를 vector도 아닌, list도 아닌 배열로 사용했다고 가정해보자
    그럼 s는 객체가 아니므로 멤버함수가 없다
    아래의 코드는 사용이 불가능하다.
    */
    /*
    auto p1 = s.begin();
    auto p2 = s.end();
    *p2 = 10;

    while (p1 != p2)
    {
        int n = *p1;
        ++p1;
    }
    */

    /*
    아래와 같이 사용하자
    std안에 begin()과 end()일반함수가 있다.
    일반함수 만들때 인자로 STL컨테이너 받는버전만들고
    진짜배열 받는버전도 만들어서 진짜배열받는 버전에는 pointer리턴하면 되잖아
    */
    /*
    auto로 받았으니깐 진짜배열이면 int*로 하면됨
    int*면 ++가능!
    아래코드 컴파일 문제없다
    */
    auto p1 = std::begin(s);
    auto p2 = std::end(s);

    while (p1 != p2)
    {
        int n = *p1;
        ++p1;
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <list>
//위의 코드에서 s를 list로 바꾸어도 문제가 없다
int main()
{
    std::list<int> s = {1, 2, 3, 4, 5, 6, 7, 8};

    auto p1 = std::begin(s);
    auto p2 = std::end(s);

    while (p1 != p2)
    {
        int n = *p1;
        ++p1;
    }
}

/*
반복자 꺼내기
멤버함수 begin/end사용
일반함수 begin/end사용-C++11부터
*/
#endif
#if 0
#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    /*
    1.[]연산을 사용한 컨테이너 접근
    vector,deque은 사용가능
    list는 []연산자 사용이 불가
    */
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }
    //2. range for
    for (auto &n : v) //"auto&"를 썼다.
    {
        std::cout << n << std::endl;
    }

    //3.반복자 사용
    auto p1 = std::begin(v);
    while (p1 != std::end(v))
    {
        std::cout << *p1 << std::endl;
        ++p1;
    }
}
#endif

#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::list<int> s = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    auto p1 = std::begin(s);
    auto p2 = std::end(v);

    ++p1;
    ++p2;

    int n1 = *p1;
    int n2 = *p2;
}

/*
반복자의 장점 : 자료구조에 상관없이 동일한 방법으로 접근이 가능
GOF's 디자인패턴 중 "Iterator"패턴
*/