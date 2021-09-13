#if 0
#include <iostream>
#include <vector>
#include <list>
#include <algorithm> //find 사용하기 위한 헤더

int main()
 {
     std::list<int> s = {1, 2, 3, 4, 5, 6, 7, 8};
     std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
     /*
     s.find(3);
     v.find(3);
     find는 같은 알고리즘을 각 컨테이너마다 멤버함수로 다 만들어야하네
    그렇게 하지말고 일반함수로 두자
    */

     //return으로 3을 가리키는 반복자가 나온다
    //3을 가리키는 포인터모양의 객체가 나온다
    //std::list<int>::iterator 대신 auto쓰자
    auto p1 = std::find(s.begin(),  s.end(), 3);
     auto p2 = std::find(v.begin(),  v.end(), 3);

     std::cout << *p1 << std::endl;
     std::cout << *p2 << std::endl;
 }

 /*
 STL 알고리즘의 특징
 멤버함수가 아닌 일반함수
<algorithm>
대부분 함수 인자와 반환 타입으로 반복자를 사용
 자료구조에 독립적이다(list와 vector에서 검색가능)
 */
#endif
#if 0
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

 int main()
 {
     std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

     /*
     [first,last) 선형 검색한다.
     즉 end()는 검색대상에 포함하지 않는다.
     어차피 end()는 접근못한다고 공부했었음
    */
     auto p = std::find(v.begin(),  v.end(), 9999);
     //검색에 실패하면 end()의 파라미터를 리턴한다

    if(p==v.end())
     {
         cout<<"검색실패"<<std::endl;
     }

     auto p1 = std::begin(v);
     auto ret = std::find(p1,p1+2,3);
     //p1+2는 검색대상이 되지않아 3을 찾지 못한다.
     if(ret ==std::end(v))
     {
         std::cout<<"실패"<<std::endl
     }
     //검색을 실패한곳 바로 뒤부터 다시 찾아봄
    std::find(ret,std::end(v),3);

 }

 /*
 find 알고리즘
[first,last) 선형 검색한다.
last는 검색의 대상이 아니다
 검색실패시 0이 아닌 last를 반환한다
*/
#endif

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    std::reverse(v.begin(), v.end()); //뒤집었음
    std::sort(v.begin(), v.end());    //정렬
    for (auto &n : v)
    {
        std::cout << n << ", ";
    }
}
//www.cppreference.com에서 다양한 알고리즘 함수 예제 참고가능