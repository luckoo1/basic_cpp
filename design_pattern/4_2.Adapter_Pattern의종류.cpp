#if 0
#include <iostream>
#include <vector>
#include "4_1.TextView.h"
using namespace std;

class Shape
{
public:
    virtual void Draw() { cout << "Shape Draw" << endl; }
};

class Text : public TextView, public Shape //1.TextView의 인터페이스를 도형편집기에 맞도록 수정
{
public:
    Text(string s) : TextView(s)
    {
    }
    virtual void Draw() //2.Show()라는 이름을 도형편집기에 맞고 Draw()로 바꿨다고 생각
    {
        TextView::Show();
    }
};

int main()
{
    TextView tv("World"); //3.이미 존재하던 객체

    vector<Shape *> v;

    v.push_back(&tv);
    /*
    4.
    error발생한다
    TextView tv("World");
    즉 tv객체는 Shape의 파생클래스가 아니기 때문이다.
    */

    v.push_back(new Text("hello"));

    for (auto p : v)
    {
        p->Draw();
    }
}

/*
5.
Adapter의 종류에는
class Adapter(클래스 어답터)
objet Adapter(객체 어답터)가 있다.

위의 코드는 클래스 어답터다.

즉 TextView의 "클래스의" 인터페이스를 도형편집기에 맞도록 수정한 것이다.

v.push_back(&tv);를 사용하고 싶으면 객체어답터가 필요하다.
*/
#endif

#if 0
//객체 어답터를 만들어보자.
#include <iostream>
#include <vector>
#include "4_1.TextView.h"
using namespace std;

class Shape
{
public:
    virtual void Draw() { cout << "Shape Draw" << endl; }
};

class Text : public TextView, public Shape
{
public:
    Text(string s) : TextView(s)
    {
    }
    virtual void Draw()
    {
        TextView::Show();
    }
};

//2.objet Adapter(객체 어답터)
class ObjectAdater : public Shape
{
    TextView *pView; //포인터가 핵심

public:
    /*
    3.
    외부에 있는 TextView를 받아서
    Draw()를 부르면 거기있는 Show()를 호출하는 구조다.
    */
    ObjectAdater(TextView *p) : pView(p)
    {
    }
    virtual void Draw()
    {
        pView->Show();
    }
};

int main()
{
    vector<Shape *> v;
    TextView tv("World");

    //v.push_back(&tv); //error

    v.push_back(new ObjectAdater(&tv));
    /*
    4.
    기존에 존재하던 객체 tv가 있는데 이건 Shape에 들어가지 않는다.
    Shape에 들어갈수 있도록 중간에 Adapter("ObjectAdater")를 놓아줄게
    그럼 저 Adapter는 객체의 인터페이스를 바꾼다.
    */

    v.push_back(new Text("hello"));

    for (auto p : v)
    {
        p->Draw();
    }
}

/*
objet Adapter(객체 어답터)
객체의 인터페이스를 변경한다
구성(Composition,포함)을 사용하는 경우가 많다.
기존 객체를 포인터 또는 참조로 포함
*/
#endif

#include <iostream>
#include <vector>
#include "4_1.TextView.h"
using namespace std;

class Shape
{
public:
    virtual void Draw() { cout << "Shape Draw" << endl; }
};

/*
class Text : public TextView, public Shape
{
public:
    Text(string s) : TextView(s)
    {
    }
    virtual void Draw()
    {
        TextView::Show();
    }
};
*/

//새로운 방법
class Text : public Shape
{
    TextView tv;

public:
    Text(string s) : tv(s)
    {
    }
    virtual void Draw()
    {
        tv.Show();
    }
};
/*
기존방법은 TextView을 전부 물려받을 수 있다
새로운 방법은 내가 지정해준것만 사용할 수 있다.
*/

class ObjectAdater : public Shape
{
    TextView *pView;

public:
    ObjectAdater(TextView *p) : pView(p)
    {
    }
    virtual void Draw()
    {
        pView->Show();
    }
};

int main()
{
    vector<Shape *> v;
    TextView tv("World");

    v.push_back(new ObjectAdater(&tv));

    v.push_back(new Text("hello"));

    for (auto p : v)
    {
        p->Draw();
    }
}