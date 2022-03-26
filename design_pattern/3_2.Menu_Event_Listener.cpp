#if 0
#include "3_2.Menu_Event.hpp"

class MenuItem : public BaseMenu
{
    int id;

public:
    MenuItem(string s, int n) : BaseMenu(s), id(n)
    {
    }
    virtual void command() //여기서 진짜 일을 해보자!
    {
        /*
        여기서 일을 지정하면 m1과 m2가 하는일이 같아진다
        만약 여기서 Add Student를 하기로 했다고 가정해보자
        그럼 m2가 불러왔을때 Remove Student하고 싶은데 무조건 Add Student를 해야한다.
        여기서 하는일은 계속 변경되어야한다.
        */
    }
    //메뉴를 선택할 때 하는 일은 메뉴 객체에 따라 다르다.

};

int main()
{
    MenuItem m1("Add Student", 11);
    MenuItem m2("Remove Student", 12);

    m1.command();
    m2.command();
}
#endif

#if 0
//방법 1 : 메뉴 선택시 하는 일을 가상 함수로 분리하는 경우
#include "3_2.Menu_Event.hpp"

class MenuItem : public BaseMenu
{
    int id;

public:
    MenuItem(string s, int n) : BaseMenu(s), id(n)
    {
    }
    virtual void command()
    {
        doCommand(); //변해야하는 것을 가상함수로
    }
    virtual void doCommand() {}
};

class AddStudentMenu : public MenuItem //추가
{
public:
    virtual void doCommand() { cout << "Add Student" << endl; }
};

class RemoveStudentMenu : public MenuItem //추가
{
public:
    virtual void doCommand() { cout << "Remove Student" << endl; }
};
int main()
{
    AddStudentMenu m1("Add Student", 11);
    RemoveStudentMenu m2("Remove Student", 12);

    m1.command();
    m2.command();
}
/*
위와같이하면 Error뜬다
이유는 MenuItem에 기본생성자가 없잖아
그럼
class AddStudentMenu : public MenuItem
class RemoveStudentMenu : public MenuItem
인자를 받아서 전달해줘야한다.
*/
#endif

#if 0
//방법 1 : 메뉴 선택시 하는 일을 가상 함수로 분리하는 경우
#include "3_2.Menu_Event.hpp"

class MenuItem : public BaseMenu
{
    int id;

public:
    MenuItem(string s, int n) : BaseMenu(s), id(n)
    {
    }
    virtual void command()
    {
        doCommand();
    }
    virtual void doCommand() {}
};

class AddStudentMenu : public MenuItem
{
public:
    using MenuItem::MenuItem; //생성자 상속
    virtual void doCommand() { cout << "Add Student" << endl; }
};

class RemoveStudentMenu : public MenuItem
{
public:
    using MenuItem::MenuItem; //생성자 상속
    virtual void doCommand() { cout << "Remove Student" << endl; }
};
int main()
{
    AddStudentMenu m1("Add Student", 11);
    RemoveStudentMenu m2("Remove Student", 12);

    m1.command();
    m2.command();
}
/*
생성자 상속(C++11)
기반클래스에 인자2개짜리 생성자가 있으니깐 그걸 상속해달라
그럼 
class AddStudentMenu : public MenuItem
class RemoveStudentMenu : public MenuItem
여기도에 인자 2개짜리 생성자가 생기는거다.
*/

/*
이방법의 문제점은 만약 메뉴가 50개면??
파생클래스가 50개가된다.
*/
#endif

#if 0
//방법2 변하는 것을 다른 클래스로!(전략패턴)
#include "3_2.Menu_Event.hpp"

//메뉴 메세지를 처리하면 아래 인테페이스를 정의해야한다.
struct IMenuListener
{
    virtual void doCommand() = 0;
    virtual ~IMenuListener() {}
};

class MenuItem : public BaseMenu
{
    int id;
    IMenuListener *pListener = 0;

public:
    void setListener(IMenuListener *p)
    {
        pListener = p;
    }

    MenuItem(string s, int n) : BaseMenu(s), id(n) {}
    virtual void command()
    {
        if (pListener != 0)
        {
            pListener->doCommand();
        }
    }
    /*
    메뉴선택시 하는 일을 다른 클래스에 위임한다
    JAVA, C#, 안드로이드 앱 등에서 사용되는 개념
    "Listener"라는 개념
    */
};

class Dialog : public IMenuListener
{
public:
    virtual void doCommand()
    {
        cout << "Dialog doCommand" << endl;
    }
};

int main()
{
    Dialog dlg;

    MenuItem m1("Add Student", 11);
    MenuItem m2("Remove Student", 12);

    m1.setListener(&dlg);
    m2.setListener(&dlg);

    m1.command();
    m2.command();
}

/*
위에코드를 보면 
m1(Add Student)
m2(Remove Student)가 각자 command()를 호출하는데 전부 다
void doCommand()를 호출한다.
결국 같은 작업을 하게 된거다
m1인지 m2인지 조사한 이후에 거기에 맞게 작업을 해야한다.
*/
#endif

#if 0
#include "3_2.Menu_Event_Listener.hpp"

struct IMenuListener
{
    virtual void doCommand(int id) = 0; //1. id값을 받자
    virtual ~IMenuListener() {}
};

class MenuItem : public BaseMenu
{
    int id;
    IMenuListener *pListener = 0;

public:
    void setListener(IMenuListener *p)
    {
        pListener = p;
    }

    MenuItem(string s, int n) : BaseMenu(s), id(n) {}
    virtual void command()
    {
        if (pListener != 0)
        {
            pListener->doCommand(id);
        }
    }
};

class Dialog : public IMenuListener
{
public:
    virtual void doCommand(int id)
    {
        switch (id)
        {
        case 11:
            cout << "11" << endl;
            break;
        case 12:
            cout << "12" << endl;
            break;
        }
    }
};

int main()
{
    Dialog dlg;

    MenuItem m1("Add Student", 11);
    MenuItem m2("Remove Student", 12);

    m1.setListener(&dlg);
    m2.setListener(&dlg);

    m1.command();
    m2.command();
}

/*
만약 Dialog안에 버튼이 30개 있다면 switch case문이 30개가 나올수 있는거다.
이방식을 싫어하는 사람은 switch case문이 커지는게 싫은거다
*/
#endif

#if 0
//방법3 메뉴에 객체가 아닌 함수를 연결하자
/*
    m1.setListener(&dlg);
    m2.setListener(&dlg);

    m1.command();
    m2.command();
    conmmand()로 event처리

    m1객체를 선택했을때 dlg에서 event를 처리하겠다라는 방식
    m2객체를 선택했을때 dlg에서 event를 처리하겠다라는 방식

    Menu를 선택했을때 함수가 호출되는건데 
    &dlg는 함수에 대한 정보는 전혀없고 객체이름만 넘긴다.
    메뉴를 선택했을때 함수를 부를거라면 함수의 정보를 줘야하는데 객체만 넘기는 이유는
    함수에 대한 정보는 IMenuListener라는 Interface안에 doCommand라는 함수이름이 정의되어 있으니깐
    객체만 연결해도 객체에 따라 불리는 함수가 다르다
    함수의 이름이 약속되어 있기 때문에 m1을 선택하든 m2를 선택하든 doCommand로 간다.

    이렇게 하지말고 메뉴에 객체가 아닌 함수를 연결해보자.
    그림필기
    메뉴를 선택했을때 함수를 직접연결해서
    메뉴 선택시에 해야할 작업을 함수안에서 사용자가 마음대로 만들수 있다.
    */
#include "3_2.Menu_Event_Listener.hpp"

class MenuItem : public BaseMenu
{
    int id;

    void (*handler)(); //함수포인터
    //일반함수는 보낼수 있으나 Dialog의 멤버함수는 보낼수가 없다.

public:
    void setHandler(void (*f)()) { handler = f; }

    MenuItem(string s, int n) : BaseMenu(s), id(n) {}

    virtual void command()
    {
        handler();
    }
};

int main()
{
    MenuItem m1("Add Student", 11);
    MenuItem m2("Remove Student", 12);

    m1.command();
    m2.command();
}
#endif

#if 0
#include "3_2.Menu_Event_Listener.hpp"

class MenuItem : public BaseMenu
{
    int id;

    void (Dialog::*handler)(); //Dialog의 멤버함수를 받기위해서 이렇게 사용
    Dialog *target;            //멤버함수를 사용하려면 객체가 있어야하니깐 이렇게 사용
    //Dialog멤버함수는 담을 수 있으나 다른 클래스의 멤버함수는 담을 수 없다.
    //C++에는 일반함수와 멤버함수의 주소를 동시에 담을 수 있는 함수 포인터가 없다.
public:
    void setHandler(void (*f)()) { handler = f; }

    MenuItem(string s, int n) : BaseMenu(s), id(n) {}

    virtual void command()
    {
        handler();
    }
};

int main()
{
    MenuItem m1("Add Student", 11);
    MenuItem m2("Remove Student", 12);

    m1.command();
    m2.command();
}
#endif