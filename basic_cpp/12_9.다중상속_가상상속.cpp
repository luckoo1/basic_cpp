#include <iostream>

struct A
{
    int a;
};

struct B
{
    int b;
};
/*
기반클래스를 2개적을수 있다
다중상속
A와 B를 물려받음
*/
struct C : public A, public B
{
    int c;
};

int main()
{
    C c;
    c.a = 10;
}
//#######################################################################

#include <iostream>
//문제점
//A와 B에 똑같은 이름의 멤버가 있다면 error
struct A
{
    int a;
};

struct B
{
    int a;
};

struct C : public A, public B
{
    int c;
};

int main()
{
    C c;
    c.a = 10;    //error
    c.A::a = 10; //OK
    c.B::a = 10; //OK
}
//#######################################################################

//다중상속의 문제점 : 다이아몬드 상속

//그림필기(1:00)
struct X
{
    int x;
};

struct A : public X
{
    int a;
};

struct B : public X
{
    int c;
};

struct C : public A, public B
{
    int c;
};

int main()
{
    C c;
    c.x = 10;    //여기의 x는 a쪽의 x인가 b쪽의 x인가 알수가 없다
    c.A::x = 10; //Ok
    c.B::x = 10; //OK
    //OK이긴하나...똑같은 멤버를 2개받음
}
//#######################################################################

struct X
{
    int x;
};
//가상상속
//x가 한번 상속됨을 보장해준다.
//public 앞에 적어도 된다.
//다이아몬드 상속의 가능성이 생기면 가상상속을 적자
struct A : public virtual X
{
    int a;
};
//가상상속
struct B : public virtual X
{
    int c;
};

struct C : public A, public B
{
    int c;
};

int main()
{
    C c;
    c.x = 10; //OK
}
