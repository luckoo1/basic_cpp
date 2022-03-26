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
        /*
        Copy & Paste기능 추가하기
        k번째 도형의 복사본을 v에 추가한다.
        K번째 도형을 어떻게 알수있나??
        */
        else if (cmd == 8)
        {
            cout << "index >>";
            int k;
            cin >> k;
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
    int type; //type멤버 추가
    virtual void Draw() { cout << "Draw Shape" << endl; }
};

class Rect : public Shape
{
public:
    Rect() { type = 1; } //초기화
    virtual void Draw() override { cout << "Draw Rect" << endl; }
};

class Circle : public Shape
{
public:
    Circle() { type = 2; } //초기화
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
        else if (cmd == 8)
        {
            cout << "index >>";
            int k;
            cin >> k;
            switch (v[k]->type) //무슨 모양인지 확인하기 위한 작업 추가
            {
            case 1:
                /* Rect에서 하고싶은 작업 */
                break;
            case 2:
                /* circle에서 하고싶은 작업 */
                break;
            }
            /*
            문제점 : 나중에 Triangle이 추가되면 기존코드에 추가내용이 생긴다
            */
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
public:
    virtual void Draw() { cout << "Draw Shape" << endl; }
    //복사본을 만드는 가상함수
    //Shape의 생성자의 인자로 자기 자신을 보냄
    virtual Shape *Clone() { return new Shape(*this); }
};

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
            v.push_back(v[k]->Clone()); //다형성
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
가상함수를 사용한 방법
새로운 도형이 추가되어도 기존 코드가 수정되지 않는다.
OCP를 만족

어떤객체의 복사본을 만들어야될 필요가 있다면
Clone이라는 가상함수를 만드는게 좋다.

"Prototype"이라고 불리는 디자인 패턴
*/