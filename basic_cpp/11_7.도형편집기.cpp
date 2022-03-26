#include <iostream>
#include <vector>

class Rect
{
public:
    void Draw()
    {
        std::cout << "Rect Draw" << std::endl;
    }
};

class Circle
{
public:
    void Draw()
    {
        std::cout << "Circle Draw" << std::endl;
    }
};

int main()
{
    //따로 보관하면 뭐가 먼저 만들어졌는지 알기 힘들다.
    std::vector<Rect *> v1;
    std::vector<Circle *> v2;
}
//#######################################################################

#include <iostream>
#include <vector>
class Shape
{
};

class Rect : public Shape
{
public:
    void Draw()
    {
        std::cout << "Rect Draw" << std::endl;
    }
};

class Circle : public Shape
{
public:
    void Draw()
    {
        std::cout << "Circle Draw" << std::endl;
    }
};

int main()
{
    std::vector<Shape *> v;

    while (1)
    {
        int n;
        std::cin >> n;
        if (n == 1)
            v.push_back(new Rect);
        if (n == 2)
            v.push_back(new Circle);
        if (n == 9)
        {
            for (int i = 0; i < v.size(); i++)
            {
                v[i]->Draw();
                //error
                //파생클래스가 있는 고유한 멤버에 접근할 수 없다.
            }
        }
    }
}
//#######################################################################
//모든 도형의 공통의 특징(Draw)는 반드시 기반 클래스(Shape)에도 있어야 한다.
#include <iostream>
#include <vector>
class Shape
{
public:
    void Draw() //추가
    {
        std::cout << "Shape Draw" << std::endl;
    }
};

class Rect : public Shape
{
public:
    void Draw()
    {
        std::cout << "Rect Draw" << std::endl;
    }
};

class Circle : public Shape
{
public:
    void Draw()
    {
        std::cout << "Circle Draw" << std::endl;
    }
};

int main()
{
    std::vector<Shape *> v;

    while (1)
    {
        int n;
        std::cin >> n;
        if (n == 1)
            v.push_back(new Rect);
        if (n == 2)
            v.push_back(new Circle);
        if (n == 9)
        {
            for (int i = 0; i < v.size(); i++)
            {
                v[i]->Draw();
            }
        }
        //그런데 이렇게하면 Shape만 그린다
        //v자체는 shape니깐
    }
}
//#######################################################################

//기반 클래스의 함수 중 파생 클래스가 재정의하게 되는 모든 함수는 가상함수가 되어야한다.
#include <iostream>
#include <vector>
class Shape
{
public:
    virtual void Draw() //추가
    {
        std::cout << "Shape Draw" << std::endl;
    }
};

class Rect : public Shape
{
public:
    virtual void Draw() override //추가
    {
        std::cout << "Rect Draw" << std::endl;
    }
};

class Circle : public Shape
{
public:
    virtual void Draw() override //추가
    {
        std::cout << "Circle Draw" << std::endl;
    }
};

int main()
{
    std::vector<Shape *> v;

    while (1)
    {
        int n;
        std::cin >> n;
        if (n == 1)
            v.push_back(new Rect);
        if (n == 2)
            v.push_back(new Circle);
        if (n == 9)
        {
            for (int i = 0; i < v.size(); i++)
            {
                v[i]->Draw();
            }
        }
    }
}
//#######################################################################

#include <iostream>
#include <vector>
class Shape
{
public:
    virtual void Draw()
    {
        std::cout << "Shape Draw" << std::endl;
    }
};

class Rect : public Shape
{
public:
    virtual void Draw() override
    {
        std::cout << "Rect Draw" << std::endl;
    }
};

class Circle : public Shape
{
public:
    virtual void Draw() override
    {
        std::cout << "Circle Draw" << std::endl;
    }
};

class Triangle : public Shape //2.이게 미래에 추가되어도 밑의 코드는 수정할 필요가 없다.
{
public:
    virtual void Draw() override
    {
        std::cout << "Triangle Draw" << std::endl;
    }
};

int main()
{
    std::vector<Shape *> v;

    while (1)
    {
        int n;
        std::cin >> n;
        //4. 밑의 4줄은 OCP를 만족못한다.
        //추후 공부
        if (n == 1)
            v.push_back(new Rect);
        if (n == 2)
            v.push_back(new Circle);
        if (n == 9)
        {
            for (int i = 0; i < v.size(); i++)
            {
                v[i]->Draw();
                /*
                1.
                -다형성(polymorphism)
                동일한 코드표현(함수 호출)이 상황에 따라 다르게 동작하는 것

                3.
                -OCP(Open Close Principle)
                기능 확장에는 열려있고(open)
                코드 수정에는 닫혀 있어야(close)
                한다는 이론(principle)
                다형성은 OCP를 만족할 수 있는 좋은 코드이다.
                */
            }
        }
    }
}