#if 0
//일반함수와 멤버함수를 동시에 묶을 수 있는 도구를 만들어보자
#include <iostream>
using namespace std;

void foo() { cout << "foo" << endl; }

class Dialog
{
public:
    void Close() { cout << "Dialog Close" << endl; }
};

int main()
{
    void (*f1)() = &foo;                   //일반함수 포인터
    void (Dialog::*f2)() = &Dialog::Close; //멤버함수포인터
}

/*
"&foo"일반함수포인터를 래핑하는 class "FunctionAction"
"&Dialog::Close" 멤버함수포인터를 래핑하는 class "MemberAction"

class "FunctionAction"에 멤버를 "&foo"일반함수포인터로
class "MemberAction"에 멤버를 "&Dialog::Close" 멤버함수포인터로 가지게 있게 하자

저 두개의 class를 묶고 싶으면 공통의 기반클래스를 가지면 된다.
IAction이라는 기반클래스를 가지게 했다.

이 IAction에서 "execute() =0;"순수가상함수를 만들면
"FunctionAction"과 "MemberAction"에서 "execute()"를 재정의해서 사용해주자
*/
#endif

#if 0
#include <iostream>
using namespace std;

void foo() { cout << "foo" << endl; }

class Dialog
{
public:
    void Close() { cout << "Dialog Close" << endl; }
};

struct IAction
{
    virtual void Execute() = 0;
    virtual ~IAction() {}
};

class FunctionAction : public IAction //함수포인터를 가지고 있다가 실행해주는 역할
{
    typedef void (*FP)(); //void return형식이고 받는 인자가 없는 함수 포인터 FP선언
    FP handler;           //함수포인터 별칭을 변수를 선언해서 멤버로 사용했다.

public:
    FunctionAction(FP f) : handler(f) {} 
    //FunctionAction(FP f)는 void return형식이고 받는 인자가 없는 함수를 받는다.
    //그리고 그 함수의 주소를 handler에 넣는다.

    virtual void Execute()
    {
        handler();
    }
};

int main()
{
    IAction *p = new FunctionAction(&foo);
    //foo의 주소를 handler(함수 포인터 별칭 fp)에 넣었다.
    //그럼 handler()에 foo의 주소가 들어가게 되므로 handler가 foo처럼 작동한다
    //자세한건 typedef 함수포인터 사용법을 익혀봐라
    p->Execute(); //이순간 foo함수를 실행한다.
}
#endif

#if 0
#include <iostream>
using namespace std;
//이제 멤버함수관련된것도 해보자
void foo() { cout << "foo" << endl; }

class Dialog
{
public:
    void Close() { cout << "Dialog Close" << endl; }
};

struct IAction
{
    virtual void Execute() = 0;
    virtual ~IAction() {}
};

class FunctionAction : public IAction
{
    typedef void (*FP)();
    FP handler;

public:
    FunctionAction(FP f) : handler(f) {}
    virtual void Execute()
    {
        handler();
    }
};

//멤버함수는 모든 class를 다 담아야해서 template를 사용해야한다.
template <typename T>
class MemberAction : public IAction
{
    typedef void (T::*FP)(); //멤버함수 포인터 별칭선언

    FP handler;
    T *target; //멤버함수를 호출하려면 객체도 있어야하니깐 객체 선언

public:
    MemberAction(FP f, T *obj) : handler(f), target(obj) {}
    //MemberAction(FP f, T *obj) 멤버함수랑 객체를 인자로 받음
    virtual void Execute()
    {
        (target->*handler)(); //해당객체에 맞는 포인터호출하기 위한 것
    }
};

int main()
{
    Dialog dlg;

    IAction *p1 = new FunctionAction(&foo); //일반함수
    IAction *p2 = new MemberAction<Dialog>(&Dialog::Close, &dlg);
    //멤버함수와 객체를 넘김

    p1->Execute(); //foo실행
    p2->Execute(); //Dialog::Close()실행
}

//IAction*라는 동일한 타입에 담았다
#endif

#if 0

template <typename T>
void square(T a)
{
    return a * a;
}

square<int>(3);
square(3); //int를 안적어줘도 3을보고 컴파일러가 int를 추정할수 있다.
//함수템플릿은 타입을 명시적으로 지정하지 않아도 컴파일러가 함수 인자를 통해서 타입을 추론 할 수 있다.

list<int> s(10,3);
//위와같은 class 템플릿은 <int>생략이 불가능(C++17부터는 생략이 가능했다)
//클래스 템플릿은 타입을 반드시 명시적으로 전달해야 한다.

#endif

#if 0
#include <iostream>
using namespace std;

void foo() { cout << "foo" << endl; }

class Dialog
{
public:
    void Close() { cout << "Dialog Close" << endl; }
};

struct IAction
{
    virtual void Execute() = 0;
    virtual ~IAction() {}
};

class FunctionAction : public IAction
{
    typedef void (*FP)();
    FP handler;

public:
    FunctionAction(FP f) : handler(f) {}
    virtual void Execute()
    {
        handler();
    }
};

template <typename T>
class MemberAction : public IAction
{
    typedef void (T::*FP)();

    FP handler;
    T *target;

public:
    MemberAction(FP f, T *obj) : handler(f), target(obj) {}
    virtual void Execute()
    {
        (target->*handler)();
    }
};
//2.함수템플릿
template <typename T>
MemberAction<T> *action(void (T::*f)(), T *obj) //인자로 void형식의 인자를 안받는 멤버함수와 객체를 받음
{
    return new MemberAction(f, obj);
}

int main()
{
    Dialog dlg;

    IAction *p1 = new FunctionAction(&foo);
    /*
    IAction *p2 = new MemberAction<Dialog>(&Dialog::Close, &dlg);

    1.이건 class template라서 <Dialog>생략이 불가능
    class template를 생성하는 함수 template를 만들면 편하다.
    */
    IAction *p2 = action(&Dialog::Close, &dlg);
    /*
    3.
    IAction *p2 = action<Dialog>(&Dialog::Close, &dlg);
    함수 템플릿이라서 <Dialog>생략해도
    &Dialog::Close보고 추론이 가능해진다.
    */
    p1->Execute();
    p2->Execute();
}

/*
클래스 템플릿을 생성하는 함수 템플릿을 도움 함수로 만들면 편한다.
*/
#endif

#if 0
#include <iostream>
using namespace std;

void foo() { cout << "foo" << endl; }

class Dialog
{
public:
    void Close() { cout << "Dialog Close" << endl; }
};

struct IAction
{
    virtual void Execute() = 0;
    virtual ~IAction() {}
};

class FunctionAction : public IAction
{
    typedef void (*FP)();
    FP handler;

public:
    FunctionAction(FP f) : handler(f) {}
    virtual void Execute()
    {
        handler();
    }
};

template <typename T>
class MemberAction : public IAction
{
    typedef void (T::*FP)();

    FP handler;
    T *target;

public:
    MemberAction(FP f, T *obj) : handler(f), target(obj) {}
    virtual void Execute()
    {
        (target->*handler)();
    }
};

template <typename T>
MemberAction<T> *action(void (T::*f)(), T *obj)
{
    return new MemberAction<T>(f, obj);
}

//일반함수를 위한 함수를 추가해줌
FunctionAction *action(void (*f)())
{
    return new FunctionAction(f);
}

int main()
{
    Dialog dlg;

    IAction *p1 = action(&foo); //변경
    IAction *p2 = action(&Dialog::Close, &dlg);

    p1->Execute();
    p2->Execute();
}
#endif

/*
C++11에는 표준이 도입되었다.
function 템플릿
C++11부터 지원되는 일반화된 함수 포인터 역할을 하는 템플릿
*/
#include <iostream>
#include <functional>
using namespace std;

void foo() { cout << "foo" << endl; }
void goo(int a) { cout << "goo : " << a << endl; }

class Dialog
{
public:
    void Close() { cout << "Dialog Close" << endl; }
};

int main()
{
    function<void()> f; //return값이 void고 파라미터가 없는 함수를 <>안에 적음
    //void()은 함수타입임
    f = &foo;
    f();

    function<void(int)> g; //return값이 void고 파라미터가 int하나
    //void()은 함수타입임
    g = &goo;
    g(3);

    Dialog dlg;
    f = bind(&Dialog::Close, &dlg); //action(&Dialog::Close, &dlg)
    //bind로 객체도 같이 묶어서 보낸다
    f(); //dlg.Close()호출된다

    f = bind(&goo, 5); //인자도 bind로 보낼 수 있다
    f();
}

/*
일반함수,멤버함수,람다표현식,함수객체등을 모두 담을 수 있다
bind와 같이 사용하면 인자도 고정할 수 있다.
*/