
#include <iostream>
#include <stack> //C++ 표준에 있다.

int main()
{
    std::stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    int n = s.pop(); //error
    //pop은 제거만하고 리턴이 안됨
    s.pop();

    int n1 = s.top(); //30
    //리턴만하고 제거가 안됨
}

/*
STL
C++ 표준 라이브러리
다양한 자료구조와 알고리즘 함수를 제공한다.

stack
내부 버퍼 크기는 자동으로 관리된다(STL과정 참조)
템플릿으로 되어 있다.

제거용 함수와 리턴용 함수가 분리되어 있다.
pop : 제거만 하고 리턴하지 않는다
top : 리턴만 하고 제거되지 않는다.
*/
