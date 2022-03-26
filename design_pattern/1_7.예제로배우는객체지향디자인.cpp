#if 0
#include <iostream>
#include <vector>
using namespace std;

class Rect
{
public:
    void Draw() { cout << "Draw Rect" << endl; }
};

class Circle
{
public:
    void Draw() { cout << "Draw Circle" << endl; }
};

int main()
{
    vector<Rect *> v1;
    vector<Circle *> v2;
    //Rect와 Circle을 따로 보관했다
    //누가 먼저 그려졌는지 순서를 알 수 없다
}
#endif

#if 0
/*
모든 도형의 공통의 기반 클래스가 있다면 
모든 도형을 하나의 컨테이너에 담아서 관리 할 수 있다.
기반 클래스 Shape 추가
*/

#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
};

class Rect : public Shape
{
public:
    void Draw() { cout << "Draw Rect" << endl; }
};

class Circle : public Shape
{
public:
    void Draw() { cout << "Draw Circle" << endl; }
};

int main()
{
    vector<Shape *> v; //upcasting을 활용해서 Rect와 Circle을 보관할 수 있다.

    while (1)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 1)
        {
            v.push_back(new Rect);
        }
        else if (cmd == 2)
        {
            v.push_back(new Circle);
        }
        else if (cmd == 9)
        {
            for (auto p : v)
            {
                p->Draw();
            }
        }
    }
}
/*
이렇게 하면 Error다
p자체는 Shape의 Pointer인데 Shape에는 Draw()가 없잖아.
*/
#endif

#if 0
/*
모든 도형의 공통의 특징은 반드시 기반 클래스에도 있어야한다
Draw함수는 Shape에도 있어야한다.
*/
#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
    void Draw() { cout << "Draw Shape" << endl; }
    //Shape Class에 Draw추가
};

class Rect : public Shape
{
public:
    void Draw() { cout << "Draw Rect" << endl; }
};

class Circle : public Shape
{
public:
    void Draw() { cout << "Draw Circle" << endl; }
};

int main()
{
    vector<Shape *> v;

    while (1)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 1)
        {
            v.push_back(new Rect);
        }
        else if (cmd == 2)
        {
            v.push_back(new Circle);
        }
        else if (cmd == 9)
        {
            for (auto p : v)
            {
                p->Draw();
            }
        }
    }
}
/*
문제점 발생
p->Draw()가 Shape class만 간다
*/
#endif

#if 0
//파생클래스에 재정의하게 되는 함수는 반드시 가상함수로 만들어야한다.
#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
    virtual void Draw() { cout << "Draw Shape" << endl; };
};

class Rect : public Shape
{
public:
    virtual void Draw() override { cout << "Draw Rect" << endl; }
};

class Circle : public Shape
{
public:
    virtual void Draw() override { cout << "Draw Circle" << endl; }
};

int main()
{
    vector<Shape *> v;

    while (1)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 1)
        {
            v.push_back(new Rect);
        }
        else if (cmd == 2)
        {
            v.push_back(new Circle);
        }
        else if (cmd == 9)
        {
            for (auto p : v)
            {
                p->Draw();
            }
        }
    }
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
    virtual void Draw() { cout << "Draw Shape" << endl; }
};

class Rect : public Shape
{
public:
    virtual void Draw() override { cout << "Draw Rect" << endl; }
};

class Circle : public Shape
{
public:
    virtual void Draw() override { cout << "Draw Circle" << endl; }
};

class Triangle : public Shape //추가함
{
public:
    virtual void Draw() override { cout << "Draw Triangle" << endl; }
};

int main()
{
    vector<Shape *> v;

    while (1)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 1)
        {
            v.push_back(new Rect);
        }
        else if (cmd == 2)
        {
            v.push_back(new Circle);
        }
        else if (cmd == 9)
        {
            for (auto p : v)
            {
                p->Draw();
            }
        }
    }
}

/*
1.다형성(Polymorphism)
동일한 함수(메서드)호출이 상황(객체)에 따라 다르게 동작하는 것

p->Draw();

2.개방폐쇄법칙(OCP,Open Close Priciple)
기능 확장에 열려있고(Open),코드 수정에는 닫혀있어야(Close),한다는 이론(Priciple)
다형성은 OCP를 만족하는 좋은 코딩 스타일

Triangle class가 추가되어도 기존코드를 수정하지 않아도 된다
*/
#endif
