#if 0
#include <iostream>
#include <algorithm>
#include <list>
 using namespace std;

 int main()
 {
     list<int> s = {1, 2, 3, 4};

     auto p1 = s.begin();
     auto p2 = s.end();

     //p1부터 p2까지 [](int a)로 보내라
    //[](int a)에 함수써야하는데 람다표현식사용했음
    for_each(p1, p2, [](int a)
              { cout << a << endl; });
     //1 2 3 4가 정상적으로 나온다.

     //이번에는 반대로 출력해보고 싶어졌다
    for_each(p2, p1, [](int a)
              { cout << a << endl; });
     /*
     p2는 4다음이다
    p2->p1으로 갈때 ++로 간다
    거꾸로 출력하려면 --로 가야한다.

     그런데 우리는 ++하면 p2->p1으로 가게 하겠다
    즉 거꾸로 이동하게 하겠다.
     */
 }
#endif

#if 0
#include <iostream>
#include <algorithm>
#include <list>
 using namespace std;

 int main()
 {
     list<int> s = {1, 2, 3, 4};

     auto p1 = s.begin();
     auto p2 = s.end();

     /*
     reverse_iterator <?> p3(p2); // p3가 --p2로 초기화된다.
     reverse_iterator<?> p4(p1); // p4가 --p1로 초기화된다.

     ?자리 뭐 들어갈지 생각해봐라
    */

     reverse_iterator<list<int>::iterator> p3(p2); //p3가 --p2로 초기화된다.
     reverse_iterator<list<int>::iterator> p4(p1); //p4가 --p1로 초기화된다.

     for_each(p3, p4, [](int a)
              { cout << a << endl; });

     cout << *p3 << endl; //4
     ++p3;                //전후진을 거꾸로 해주는 adapter가 된다.
     cout << *p3 << endl; //3;
 }
 /*
 reverse_iterator는 객체 adapter다
p1이라는 반복자와 p2라는 반복자를 미리 선언했다.
     auto p1 = s.begin();
     auto p2 = s.end();
이러한 반복자들을 거꾸로 동작할 수 있게 해주는 거다.
 */
#endif

#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
    list<int> s = {1, 2, 3, 4};

    auto p1 = s.begin();
    auto p2 = s.end();

    //아래의 방법도 있다.
    auto p3 = make_reverse_iterator(p2);
    auto p4 = make_reverse_iterator(p1);

    for_each(p3, p4, [](int a)
             { cout << a << endl; });

    cout << *p3 << endl;
    ++p3;
    cout << *p3 << endl;
}

/*
 Iterator Adapter

 reverse_iterator
기존 반복자의 동작을 거꾸로 동작하게 하는 어답터
 다양한 알고리즘을 역순으로 적용할수 있다.
 */