#if 0
//알고리즘의 정책변경
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional> //5.STL함수

//3.
bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    std::vector<int> v = {5, 3, 1, 7, 9, 2, 4, 6};

    //1.오름차순 정렬
    std::sort(v.begin(), v.end());
    //내림차순으로 해보고 싶은데...?

    /*
    2.일반함수 사용
    세번째 인자로 두개의 요소를 비교할 수 있는 함수 전달
    */
    std::sort(v.begin(), v.end(), cmp);

    for (auto &n : v)
    {
        std::cout << n << ", ";
    }

    /*
    4.함수객체를 넘기자
    STL에 함수객체가 있음
    */

    std::greater<int> g;
    /*
    #include <functional>사용해야한다.
    greater는 내부적으로 ">연산"을 한다
    inline치환 가능
    */
    std::sort(v.begin(), v.end(), g);

    for (auto &n : v)
    {
        std::cout << n << ", ";
    }

    /*
    5.Lambda Expression - C++11
    "[]"는 람다가 시작됨을 알리는 람다 "introducer"
    가독성의 장점
    inline치환 가능
    제일 권장됨
    */

    std::sort(v.begin(), v.end(), [](int a, int b)
              { return a > b; });

    for (auto &n : v)
    {
        std::cout << n << ", ";
    }
}

/*
알고리즘이 사용하는 정책을 변경하는 방법
일반함수 사용
함수객체사용 <functional>
람다 표현식 사용(C++11)
*/
#endif

#if 0
#include <iostream>
#include <set>
#include <functional>

int main()
{
    std::set<int> s; //균형잡힌 tree
    //tree는 크면 오른쪽 작으면 왼쪽으로 보내서 sort한다

    s.insert(10);
    s.insert(30);
    s.insert(20);

    for (auto &n : s)
    {
        std::cout << n << ", "; //알아서 정렬되어 있다.
    }
}
#endif

#include <iostream>
#include <set>
#include <functional>

int main()
{
    std::set<int, std::greater<int>> s;
    //tree는 크면 왼쪾 작으면 오른쪽으로 보내서 sort한다

    s.insert(10);
    s.insert(30);
    s.insert(20);

    for (auto &n : s)
    {
        std::cout << n << ", ";
    }
}
