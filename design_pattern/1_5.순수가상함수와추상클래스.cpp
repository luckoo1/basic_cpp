#if 0
class Shape
{
public:
    virtual void Draw() = 0;
};

int main()
{
    Shape s;  //error 객체를 만들 수 없다
    Shape *p; //포인터 변수를 만들 수 있다.
}

/*
순수가상함수(pure virtual function)
함수 선언뒤에 "=0"을 표기한 가상함수
함수의 구현부가 없다

추상클래스(abstract class)
순수 가상 함수를 한개 이상 가지고 있는 클래스

추상클래스의 특징
객체를 생성할 수 없다
포인터 변수는 만들 수 있다.
*/
#endif

#if 0
class Shape
{
public:
    virtual void Draw() = 0;
};
//기반클래스인 shape로부터 순수가상함수를 물려받고 있음
class Rect : public Shape
{
public:
};

int main()
{
    Rect r; //error
}
#endif

#if 0
class Shape
{
public:
    virtual void Draw() = 0;
};

class Rect : public Shape
{
public:
    virtual void Draw() {} //구현부를 제공하면 추상 아님
};

int main()
{
    Rect r; //OK
}

/*
순수가상함수의 구현부를 제공하지 않은 경우 파생클래스도 추상클래스다

Shape 추상클래스의 의도
앞으로 파생클래스는 반드시 Draw를 구현해라
파생클래스에게 특정 함수를 반드시 구현하라고 지시하는 것
*/
#endif