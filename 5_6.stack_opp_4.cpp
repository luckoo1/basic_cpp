//8번째 단계
#if 0
//아래의 stack은 int만 저장할 수 있다.
#include <iostream>
class Stack
{
private:
    int *buf;
    int idx;

public:
    Stack(int sz = 10)
    {
        buf = new int[sz];
        idx = 0;
    }
    ~Stack()
    {
        delete[] buf;
    }
    void push(int n)
    {
        buf[idx++] = n;
    }
    int pop()
    {
        return buf[--idx];
    }
};

int main()
{
    Stack s1(20);
    s1.push(10);
    s2.push(30);
    std::cout << s1.pop() << std::endl;
    std::cout << s2.pop() << std::endl;
}
#endif

#if 0
//template를 사용하자
#include <iostream>
template <typename T>
class Stack
{
private:
    T *buf;
    int idx;

public:
    Stack(int sz = 10)
    {
        buf = new T[sz];
        idx = 0;
    }
    ~Stack()
    {
        delete[] buf;
    }
    void push(T n)
    {
        buf[idx++] = n;
    }
    T pop()
    {
        return buf[--idx];
    }
};

int main()
{
    //int version과 double version이 생긴다.
    Stack<int> s1(20);
    s1.push(3);

    Stack<double> s2(10);
    s1.push(4.5);

    std::cout << s1.pop() << std::endl;
    std::cout << s2.pop() << std::endl;
}
/*
결국 assembly 코드 안에는
double 버전 stack class와
int 버전 stack class
따로 따로 있다.
각 타입을 저장하는 stack 클래스를 별도로 코드를 생성하는 것
*/
#endif
//선언부와 구현부 분리해보자 일단 pop함수만 해보자

#include <iostream>
template <typename T>
class Stack
{
private:
    T *buf;
    int idx;

public:
    Stack(int sz = 10)
    {
        buf = new T[sz];
        idx = 0;
    }
    ~Stack() { delete[] buf; }
    void push(T n) { buf[idx++] = n; }
    T pop();
};

/*
아래와 같이 사용하면 저기의 T가 template라는 사실이 
세줄 위에 코드(클래스 안)에서만 유효하다.
T Stack::pop()
{
    return buf[--idx];
}
*/

//"template <typename T>"를 또 적어줘야하고
template <typename T>
T Stack<T>::pop() //Stack<T>를 적어야한다.
{
    return buf[--idx];
}

int main()
{
    //int version과 double version이 생긴다.
    Stack<int> s1(20);
    s1.push(3);

    Stack<double> s2(10);
    s1.push(4.5);

    std::cout << s1.pop() << std::endl;
    std::cout << s2.pop() << std::endl;
}

/*
클래스 템플릿에서 멤버함수 구현시
클래스 선언 안에 구현부를 넣어도 되고,
클래스 선언에는 멤버함수 선언만 넣고,멤버 함수 구현은 클래스 외부에 놓아도 된다.

이때!!!! 구현부를 별도의 소스로 분리하면 안된다.
함수 선언과 구현 모두 헤더 파일에 있어야 한다.
*/