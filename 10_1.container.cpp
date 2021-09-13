#include <iostream>
#include <vector>
#include <list>
/*
1.배열은 크기를 중간에 바꿀 수 없다.
연속된 메모리다
2.STL vector는 크기를 바꿀 수 있다.
연속된 메모리다
3.list는 연속되지 않은 메모리다.
*/

/*
멤버함수이름이 대부분 동일하다
대부분 코드를 수정하지 않고 컨테이너를 교체할 수 있다
요소삽입 : push_front,push_back,insert
요소제거 : pop_front,pop_back,erase
요소접근 : front,back
※ vector는 앞에 삽입할 수 없다.(push_front가 없다)

pop_back()은 제거만하고 리턴하지 않는다.
back()은 리턴만하고 제거하지 않는다.
*/
int main()
{
    int x[10]; //크기고정

    std::vector<int> v(10);
    v.resize(5); //크기변경

    std::list<int> s = {1, 2, 3};

    s.push_back(10);
    s.push_back(20);
    s.push_back(30);
    s.push_back(40);
    s.pop_back();

    /*
    std::list<int> s;를
    std::vector<int> s;로 바꾸면 링크드리스트로 쓰던걸 vector로 사용할 수 있게된다.
    */
}
