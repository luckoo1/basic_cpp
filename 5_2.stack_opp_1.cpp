//stack을 만들면서 객체지향의 기본 개념을 이해하자
//1번째 단계
#include <iostream>

int buf[10];
int idx = 0;

void push(int n)
{
    buf[idx++] = n;
}

int pop()
{
    return buf[--idx];
}

int main()
{
    push(10);
    push(20);
    push(30);

    std::cout << pop() << std::endl;
}
/*
전역변수를 사용해서 버퍼와 indxe관리
문제점 : stack이 2개 이상 필요하면 어떻게 해야 할까?
buf를 2개 놓을까??
push에서 pop을할때 버퍼의 포인터와 인덱스의 포인터도 받아야한다.
까다롭다.
*/
//#######################################################################

//2번째 단계
/*
1 .핵심개념
필요한 타입을 먼저 설계하자
complex가 필요하면 int 타입 2개를 사용하지 말고 complex 타입을 만들자
구조체 사용해서 "stack"이라는 타입을 만들자
*/

#include <iostream>

struct Stack
{
    int buf[10];
    int idx;
};

void push(Stack *s, int n)
{
    s->buf[(s->idx)++] = n;
}

int pop(Stack *s)
{
    return s->buf[--(s->idx)];
}

int main()
{
    Stack s1, s2; //2. stack 2개 필요하면 이렇게 사용하면 되겠네
    s1.idx = 0;
    s2.idx = 0;

    //3.어느 stack에 넣을지 지정해줬다.
    push(&s1, 10);
    push(&s1, 20);
    push(&s1, 30);

    push(&s2, 30);
    push(&s2, 20);
    push(&s2, 10);

    std::cout << pop(&s1) << std::endl;
    std::cout << pop(&s2) << std::endl;
}
//위의 코드가 C언어로 구현한 모양이다.

/*
push 함수의 모양
stack타입이 없다면 : void push(int *buf,int *idx,int n)
stack타입이 있다면 : void push(Stack * s,int n)

문제점
Stack의 상태를 나타내는 데이터와 Stack의 상태를 조작하는 함수가 분리되어 있다.
push(),pop() 함수가 1번째 인자로 Stack을 받아야한다.
상태를 나타내는 데이터와 상태를 조작하는 함수를 묶으면 어떻까??
c++에서 가능해짐
*/
//#######################################################################
//3번째 단계
#include <iostream>

struct Stack
{
    int buf[10]; //멤버 데이터
    int idx;

    void push(int n) //멤버 함수
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
    Stack s1, s2;
    s1.idx = 0;
    s2.idx = 0;

    s1.push(10);
    s1.push(20);

    s2.push(30);
    s2.push(20);

    /*
    s1.push(40); //객체중심
    push(&s1, 40); //함수중심

    그런데 s1.push(40)도 컴파일러가 내부적인 원리로
    push(&s1,40);으로 바꾼다.
    */
    std::cout << s1.pop() << std::endl;
    std::cout << s2.pop() << std::endl;
}

/*
상태를 나타내는 데이터와 상태를 조작하는 함수를 묶는다.
C++구조체는 함수를 포함 할 수 있다.

멤버함수에서는 멤버 데이터를 접근할 수 있다.

push 함수의 모양
stack타입이 없다면 : void push(int *buf,int *idx, int n)
stack타입이 있다면 : void push(Stack * s, int n)
멤버함수로 만들면 : void push(int n)
(push함수의 모양이 간단해졌다.)
*/

/*
문제점
사용자가 idx에 잘못도니 값을 넣으면 어떻게 될까?
ex)s1.idx = -1;   <=이렇게 쓰면 문제가 생기잖아.
잘못 사용하기 어렵게 만들 수 있을까??
*/