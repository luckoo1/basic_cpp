#if 0
#include <iostream>
#include <list>
using namespace std;

//stack을 만들려는데 linked list를 한쪽 방향으로만 쓸려고 한다.
//list의 함수이름을 stack처럼 보이도록 변경해보자
template <typename T>
class Stack : public list<T>
{
public:
    void push(const T &a)
    {
        list<T>::push_back(a);
    }
    void pop()
    {
        list<T>::pop_back();
    }
    T &top()
    {
        return list<T>::back();
    }
};

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);

    s.push_front(20);
    //스택은 이렇게 사용하면 안되는데 지금 코드에서는 이게 사용이 가능하다.

    cout << s.top() << endl;
}
#endif

#if 0
#include <iostream>
#include <list>
using namespace std;
//private 상속을 받아 외부에서 못쓰게 만들었다.
//상속을 사용한 어답터
template <typename T>
class Stack : private list<T> //private로 바꾸었다.
{
public:
    void push(const T &a)
    {
        list<T>::push_back(a);
    }
    void pop()
    {
        list<T>::pop_back();
    }
    T &top()
    {
        return list<T>::back();
    }
};

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);

    s.push_front(20); //error발생

    cout << s.top() << endl;
}
#endif

#if 0
#include <iostream>
#include <list>
using namespace std;

//상속이 아닌 포함으로 만들었다.
//포함을 사용한 어답터
template <typename T>
class Stack
{
    list<T> st;

public:
    void push(const T &a)
    {
        st.push_back(a);
    }
    void pop()
    {
        st.pop_back();
    }
    T &top()
    {
        return st.back();
    }
};

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);

    s.push_front(20); //error발생
    //stack안에 push_front자체가 없다.

    cout << s.top() << endl;
}

//상속을 사용한 어답터와 포함을 사용한 어답터의 차이를 알자.
#endif

#if 0
#include <iostream>
#include <list>
#include <vector>
using namespace std;

template <typename T, typename C>//template추가
class Stack
{
    C<T> st;

public:
    void push(const T &a)
    {
        st.push_back(a);
    }
    void pop()
    {
        st.pop_back();
    }
    T &top()
    {
        return st.back();
    }
};

int main()
{
    Stack<int, list<int>> s;   //list기반의 stack(연속되지 않은 메모리)
    Stack<int, vector<int>> s; //vector기반의 stack(연속된 메모리)
    s.push(10);
    s.push(20);

    //s.push_front(20); //error발생
    //stack안에 push_front자체가 없다.

    cout << s.top() << endl;
}
#endif

#if 0
#include <iostream>
#include <list>
#include <vector>
#include <deque>

using namespace std;
//사용자가 C 부분에 아무것도 안주면 default로 deque가 들어간다.
template <typename T, typename C = deque<T>> //template추가
class Stack
{
    C<T> st;

public:
    void push(const T &a)
    {
        st.push_back(a);
    }
    void pop()
    {
        st.pop_back();
    }
    T &top()
    {
        return st.back();
    }
};

int main()
{
    Stack<int, list<int>> s;   //list기반의 stack(연속되지 않은 메모리)
    Stack<int, vector<int>> s; //vector기반의 stack(연속된 메모리)
    Stack<int> s;              //default인 deque기반의 stack
    s.push(10);
    s.push(20);

    cout << s.top() << endl;
}
/*
이건 객체 어답터일까 class 어답터일까?
C<T> st;와 같이 썼다 클래스 어답터다
C*<T> st;와 같이 쓰지않음
*/
#endif

#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);

    cout << s.top() << endl;
}
/*
stl에서 stack을 stack adapter라고 부른다.
전부 다 inline최어 있다.
실제호출이 아니라 기계어 코드로 치환되어 있다.
*/