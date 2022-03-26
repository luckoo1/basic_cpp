#if 0
#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
    virtual void Draw()
    {
        cout << "Mutex lock" << endl; //2.동기화 도구 사용하는 코드
        cout << "Draw Shape" << endl; //1.이코드가 멀티쓰레드 환경에서 안전하지 않다고 가정해보자.
        cout << "mutex unlock" << endl;
    }
    virtual Shape *Clone() { return new Shape(*this); }
};
//3.Rect와 Circle도 동기화도구가 필요하다!
//코드의 중복이 보이네?
class Rect : public Shape
{
public:
    virtual void Draw() override { cout << "Draw Rect" << endl; }
    virtual Shape *Clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
    virtual void Draw() override { cout << "Draw Circle" << endl; }
    virtual Shape *Clone() { return new Circle(*this); }
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
        else if (cmd == 8)
        {
            cout << "index >>";
            int k;
            cin >> k;
            v.push_back(v[k]->Clone());
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
/*
변하지 않은 코드에서 변하는 부분은 분리되어야한다.
변하는 것은 가상함수로 분리한다.
*/
#if 0
#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
    virtual void DrawImp() //변하는 것을 가상함수로 뽑아낸다.
    {
        cout << "Draw Shape" << endl;
    }
    virtual void Draw()
    {
        cout << "Mutex lock" << endl;
        DrawImp();
        cout << "mutex unlock" << endl;
    }
    virtual Shape *Clone() { return new Shape(*this); }
};

class Rect : public Shape
{
public:
    virtual void DrawImp() override { cout << "Draw Rect" << endl; } //수정
    virtual Shape *Clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
    virtual void DrawImp() override { cout << "Draw Circle" << endl; } //수정
    virtual Shape *Clone() { return new Circle(*this); }
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
        else if (cmd == 8)
        {
            cout << "index >>";
            int k;
            cin >> k;
            v.push_back(v[k]->Clone());
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

#include <iostream>
#include <vector>
using namespace std;

class Shape
{
    //변하는건 뽑아내서 파생클래스가 재정의 할 수 있게했는데
    //외부에서 재정의 못하게 protected에 넣었다.
protected:
    virtual void DrawImp()
    {
        cout << "Draw Shape" << endl;
    }
    //파생클래스에서는 절대로 Draw()를 재정의하면 안된다.
    //final 키워드를 붙임(C++11)
public:
    virtual void Draw() final
    {
        cout << "Mutex lock" << endl;
        DrawImp();
        cout << "mutex unlock" << endl;
    }
    virtual Shape *Clone() { return new Shape(*this); }
};

class Rect : public Shape
{
public:
    virtual void DrawImp() override { cout << "Draw Rect" << endl; }
    virtual Shape *Clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
    virtual void DrawImp() override { cout << "Draw Circle" << endl; }
    virtual Shape *Clone() { return new Circle(*this); }
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
        else if (cmd == 8)
        {
            cout << "index >>";
            int k;
            cin >> k;
            v.push_back(v[k]->Clone());
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
Template method
모든 도형에 공통적인 변하지 않은 전체적인 흐름을 기반 클래스에서 제공하고(public,final)
각 도형별로 변해야 하는 부분을 가상함수(private 또는 protected)로 제공해서 파생클래스가 재정의 할 수 있게 한다.

    virtual void Draw() final
    {
        cout << "Mutex lock" << endl;
        DrawImp();
        cout << "mutex unlock" << endl;
    }
    virtual Shape *Clone() { return new Shape(*this); }

위의 코드에 모든도형의 공통의 특징을 담게했다.
보통 final과 public으로 만든다.
*/

/*
정리

모든 도형을 타입으로 설계한다(Rect,Circle)

모든 도형의 공통의 기반 클래스가 있다면 모든 도형을 하나의 컨테이너에 담아서 관리 할 수 있다(Shape class)

모든 도형의 공통의 특징이 있다면 반드시 기반 클래스에도 있어야한다.(Draw함수)

파생클래스에 재정의하게 되는 함수는 반드시 가상함수로 만들어야 한다.(virtual)

변하지 않은 코드(Draw)에서 변하는 부분(DrawImp)은 분리 되어야한다
-변하는 것을 가상함수로(template method)
*/

/*
virtual void DrawImp() = 0; { cout << "Draw Shape" << endl; }
 virtual Shape *Clone() = 0; { return new Circle(*this); }
와 같이 써도 좋다.
 */

/*
그런데 위의 코드에도 문제가 있다
Triangle이 추가되면
    else if (cmd == 3)
        {
            v.push_back(new Triangle);
        }
이 부분이 추가되어야한다

객체의 생성과정을 OCP를 만족하게 할 수 없을까?
*/
