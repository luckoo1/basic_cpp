#if 0
#include <iostream>
using namespace std;

class Car
{
public:
    Car() {}

protected:
    ~Car() { cout << "~Car" << endl; }
};

int main()
{
    Car c; //error
    /*
    {}을 벗어나면 객체를 파괴하기 위해 소멸자를 호출해야하는데
    protected에 있어서 소멸자 호출이 불가능
    스택에 객체를 만들 수 없다.
    */
}
#endif

#if 0
#include <iostream>
using namespace std;

class Car
{
public:
    Car() {}

protected:
    ~Car() { cout << "~Car" << endl; }
};

int main()
{
    Car *p = new Car; //대신 heap에는 만들수 있다.
    delete p;         //error
    //delete할때 protected라 호출이 불가능하다
}
#endif

#include <iostream>
using namespace std;

class Car
{
public:
    Car() {}

    void Destroy()
    {
        delete this;
    }

protected:
    ~Car() { cout << "~Car" << endl; }
};

int main()
{
    Car *p = new Car;
    p->Destroy(); //가능
}

/*
protected 소멸자
객체를 스택에 만들 수 없게 할 때 주로 사용하는 기법
객체를 힙에만 만들수 있게한다.
참조 계수 기반의 객체 수명 관리 기법에서 주로 사용된다.
*/