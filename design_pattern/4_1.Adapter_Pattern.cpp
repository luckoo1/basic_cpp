#if 0
//1.기존에 사용하던건데 문자열을 추가하고 싶어졌다
#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
    virtual void Draw() { cout << "Shape Draw" << endl; }
};

class Text : public Shape //2.여기를 추가함
{
};

/*
3.
"4_1.TextView.h"를 봐보자
도형편집기에서 "class TextView"를 사용하고싶어졌다

그런데 문제점이 발생한ㄷ다.
도형편집기에서 "class TextView"를 사용하려면 Shape로 부터 파생되어야한다.
Draw()함수에서 그림(글자)를 출력해야하는데 "class TextView"에서는 Show()를 사용하고 있다.
*/
class Rect : public Shape
{
public:
    virtual void Draw() { cout << "Rect Draw" << endl; }
};

class Circle : public Shape
{
public:
    virtual void Draw() { cout << "Circle Draw" << endl; }
};

int main()
{
    vector<Shape *> v;
    v.push_back(new Rect);
    v.push_back(new Circle);

    for (auto p : v)
    {
        p->Draw();
    }
}
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
1.
TextView도 추가해서 다중 상속을 받는다.
TextView를 도형편집기(현재코드)에서 사용하기 위해 
인터페이스 변경(함수이름변경)

TextView가 가진 모든 특징을 도형편집기(현재코드)에서 사용할 수 있도록
인터페이스만 수정한것
*/
class Text : public TextView, public Shape
{
public:
    Text(string s) : TextView(s)
    {
    }
    virtual void Draw()
    {
        TextView::Show(); //Show()라는 이름을 도형편집기에 맞고 Draw()로 바꿨다고 생각
    }
};
/*
3.
110v를 220v에서 사용하려고 Adapter사용하는 걸 생각

Adapter pattern
하나의 클래스(또는 객체)의 인터페이스를 클라이언트가 사용하고자 하는 다른 인터페이스로 변환한다
호환성때문에 사용할 수 없었던 클래스들을 연결해서 사용할 수 있다.
*/

class Rect : public Shape
{
public:
    virtual void Draw() { cout << "Rect Draw" << endl; }
};

class Circle : public Shape
{
public:
    virtual void Draw() { cout << "Circle Draw" << endl; }
};

int main()
{
    vector<Shape *> v;
    v.push_back(new Rect);
    v.push_back(new Circle);

    v.push_back(new Text("hello")); //2.추가

    for (auto p : v)
    {
        p->Draw();
    }
}