#if 0
//추상클래스
class Shape
{
public:
    //이러한 모양으로 가상함수를 만들었다
    //순수가상함수
    virtual void Draw() = 0;
};

int main()
{
    Shape s;  //객체를 만들수 없다.
    Shape *p; //포인터는 만들수 있다.
}

/*
순수 가상함수(Pure Virtual Function)
함수 구현부가 없고 선언부가 "=0"으로 끝나는 가상함수

추상클래스(Abstract Class)
순수 가상 함수가 한개이상 있는 클래스
객체를 만들 수 없다
포인터 타입을 만들 수는 있다.
*/
#endif

#if 0
class Shape
{
public:
    virtual void Draw() = 0;
};

//Rect는 추상클래스일까 아닐까?
//순수가상함수를 물려받은거라 추상클래스다
class Rect : public Shape
{
public:
};

int main()
{
    Rect r;
    //현재 Rect도 추상클래스다
}

//추상클래스로부터 상속받은 클래스가 순수 가상함수의 구현부를 제공하지 않으면 역시 추상클래스다
//Rect를 사용하고 싶으면 Rect안에서 Draw()를 재정의해라
#endif

class Shape
{
public:
    virtual void Draw() = 0;
};
//구체 클래스(conceret class)
class Rect : public Shape
{
public:
    virtual void Draw() //이걸 추가해주니 문제없이 컴파일된다
    {
    }
};

int main()
{
    Rect r;
}
/*
추상클래스의 의도
파생 클래스에게 특정함수를 반드시 만들라고 지시하는 것
인터페이스
*/