#if 0
#include <iostream>

class Car
{
public:
    void Go() { std::cout << "Go" << std::endl; }
    ~Car() { std::cout << "~Car" << std::endl; }
};
//1.아래 SPtr의 문제는 Car의 포인터 역할만 한다
class SPtr
{
    Car *ptr;

public:
    SPtr(Car *p = 0) : ptr(p) {}
    ~SPtr() { delete ptr; }

    Car *operator->() { return ptr; }
    Car &operator*() { return *ptr; }
};

int main()
{
}
#endif
#if 0
#include <iostream>

class Car
{
public:
    void Go() { std::cout << "Go" << std::endl; }
    ~Car() { std::cout << "~Car" << std::endl; }
};
//1.임의의 타입에 대한 스마트 포인터를 만들었다.
template <typename T>
class SPtr
{
    T *ptr;

public:
    SPtr(T *p = 0) : ptr(p) {}
    ~SPtr() { delete ptr; }

    T *operator->() { return ptr; }
    T &operator*() { return *ptr; }
};

int main()
{
    SPtr<int> p1 = new int;
    *p1 = 10;
    std::cout << *p1 << std::endl;
}
#endif

#if 0
#include <iostream>

class Car
{
public:
    void Go() { std::cout << "Go" << std::endl; }
    ~Car() { std::cout << "~Car" << std::endl; }
};
//1.임의의 타입에 대한 스마트 포인터를 만들었다.
template <typename T>
class SPtr
{
    T *ptr;

public:
    SPtr(T *p = 0) : ptr(p) {}
    ~SPtr() { delete ptr; }

    T *operator->() { return ptr; }
    T &operator*() { return *ptr; }
};

int main()
{
    SPtr<int> p1 = new int;
    SPtr<int> p2 = p1; //runtime error
    /*
    컴파일 타입에러가 아닌 런타임 에러가 나온다.
    그림필기
    얇은 복사의 문제점이 나온다.
    그림 깊은 복사로 해결해볼까??
    그럼 car을 또 만들게 되는데...
    스마트 포인터의 철학은 자원을 별개로 쓰는게 아니라
    하나의 자원을 같이 공유하는거다.
    참조계수를 사용하자!
    */
    *p1 = 10;
    std::cout << *p1 << std::endl;
}

/*
템플릿으로 만들어야한다
얕은 복사 현상을 해결해야한다(참조 계수 방식을 주로 사용)
*/
#endif

#include <iostream>
#include <memory> //스마트 포인터 사용가능

class Car
{
public:
    void Go() { std::cout << "Go" << std::endl; }
    ~Car() { std::cout << "~Car" << std::endl; }
};

int main()
{
    //std::shared_ptr<Car> p = new Car; //error
    std::shared_ptr<Car> p(new Car); //이런 방식으로 사용해야한다.
    //p를 포인터처럼 사용할 수 있다.
    p->Go();
}

/*
shard_ptr
C++표준의 스마트 포인터
<memory>헤더
참조 계수 기반으로 구현되어 있다

사용시 주의사항
std::shared_ptr<Car> p = new Car; //NG
std::shared_ptr<Car> p(new Car);  //OK
explicit 생성자 때문에 그런데 중급과정(Conversion)에서 배울 수 있다.
*/