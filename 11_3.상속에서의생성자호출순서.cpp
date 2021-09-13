#if 0
#include <iostream>
using namespace std;

class Base
{
    int data;

public:
    Base() { cout << "Base()" << endl; };
    Base(int a) { cout << "Base(int)" << endl; }
    ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base
{
public:
    Derived() { cout << "Derived()" << endl; };
    Derived(int a) { cout << "Derived(int)" << endl; }
    ~Derived() { cout << "~Derived()" << endl; }
};

int main()
{
    Derived d;
    /*
    Base()
    Derived()
    ~Derived()
    ~Base()
    */
}

/*
파생클래스 객체생성시 기반 클래스의 생성자/소멸자도 호출된다
*/
#endif

#if 0
#include <iostream>
using namespace std;

class Base
{
    int data;

public:
    Base() { cout << "Base()" << endl; };
    Base(int a) { cout << "Base(int)" << endl; }
    ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base
{
public:
    Derived() { cout << "Derived()" << endl; };
    Derived(int a) { cout << "Derived(int)" << endl; }
    ~Derived() { cout << "~Derived()" << endl; }
};

int main()
{
    Derived d(5);
    /*
    Base()
    Derived(int)
    ~Derived()
    ~Base() 
    */
    //Derived만 인자있는 생성자 호출하고 Base는 기본생성자 호출
}
#endif

#if 0
#include <iostream>
using namespace std;

class Base
{
    int data;

public:
    //Base() { cout << "Base()" << endl; };
    Base(int a) { cout << "Base(int)" << endl; }
    ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base
{
public:
    Derived() { cout << "Derived()" << endl; };
    Derived(int a) { cout << "Derived(int)" << endl; }
    ~Derived() { cout << "~Derived()" << endl; }
};

int main()
{
    Derived d(5);
    //기반생성자의 기본생성자를 없애면 컴파일 에러 발생
    //기반클래스에 디폴트 생성자가 없는 경우 기본적으로 파생 클래스의 객체를 생성할 수 없다
}
#endif

#if 0

#include <iostream>
using namespace std;

class Base
{
    int data;

public:
    Base() { cout << "Base()" << endl; };
    Base(int a) { cout << "Base(int)" << endl; }
    ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base
{
public:
    Derived() { cout << "Derived()" << endl; };
    //2.아래와 같이 수정한다
    Derived(int a) : Base(a)
    {
        cout << "Derived(int)" << endl;
    }
    ~Derived() { cout << "~Derived()" << endl; }
};

int main()
{
    Derived d(5);
    //1. 5를 Base에 있는 멤버데이터 int data;에 넣고 싶다
}
/*
3.실행시 아래와 같이 기반클래스도 인자있는 버전으로 생성자 호출
Base(int)
Derived(int)
~Derived()
~Base()
*/

/*
기반 클래스의 디폴트 생성자가 아닌 다른 생성자를 호출하는 방법
파생클래스의 초기화 리스트에서 기반 클래스의 생성자를 명시적으로 호출해준다
*/

/*
여기서 생각해봐야할 점이
class Derived : public Base위치에 적었는데 
왜 위에있던 Base()와 Base(int)중 뭐가 불릴지 어떻게 정하는거지??
*/
#endif

#if 0
#include <iostream>
using namespace std;

class Base
{
    int data;

public:
    Base() { cout << "Base()" << endl; };
    Base(int a) { cout << "Base(int)" << endl; }
    ~Base() { cout << "~Base()" << endl; }
};

//1. 아래와 같이 상속이 이루어지면
class Derived : public Base
{
public:
    //2. 아래와 같이 명시적으로 :Base()가 생긴다.
    Derived() : Base() { cout << "Derived()" << endl; };
    Derived(int a) : Base() { cout << "Derived(int)" << endl; }
    ~Derived()
    {
        cout << "~Derived()" << endl;
        ~Base(); //3.여기서 기반클래스의 소멸자를 불러주는 코드도 생성된다
        //위와 같이 적으면 컴파일에러인데 의미상으로만 보자
    }
};

int main()
{
    Derived d(5);
}
#endif

#if 0
#include <iostream>
using namespace std;

class Base
{
    int data;

public:
    Base() { cout << "Base()" << endl; };
    Base(int a) { cout << "Base(int)" << endl; }
    ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base
{
public:
    Derived() : Base() { cout << "Derived()" << endl; };
    Derived(int a) : Base() { cout << "Derived(int)" << endl; }
    ~Derived()
    {
        cout << "~Derived()" << endl;
        ~Base();
    }
};

int main()
{
    Derived d(5);
    /*
    1.
    Derived 생성하면 이 순간에는 class Derived로 간다
    저기서 Derived(int a)로 가서 초기화리스트에 Base()로 가는거다.

    2.
    그런데 내가 직접  Derived(int a) : Base(a)라고 써줬으니
    인자가 있는 기반 클래스 생성자로 가는거다.
    */
}
#endif

#if 0
//내가 만약 아래와 같이 코드를 짜면 error가 없어보이지 않아?
#include <iostream>
using namespace std;

class Base
{
    int data;

public:
    //Base() { cout << "Base()" << endl; };
    Base(int a) { cout << "Base(int)" << endl; }
    ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base
{
public:
    Derived() { cout << "Derived()" << endl; };
    Derived(int a) : Base(a) { cout << "Derived(int)" << endl; }
    ~Derived() { cout << "~Derived()" << endl; }
};

int main()
{
    Derived d(5);
}
//하지만 컴파일러가 Derived() : base()를 자동으로 만들어주니깐 error뜬다
#endif

#if 0

#include <iostream>
using namespace std;

class Base
{
    int data;

public:
    //Base() { cout << "Base()" << endl; };
    Base(int a) { cout << "Base(int)" << endl; }
    ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base
{
public:
    Derived() : Base(0) { cout << "Derived()" << endl; }; //0이라도 보내서 error가 안뜨게 만들었다
    Derived(int a) : Base(a) { cout << "Derived(int)" << endl; }
    ~Derived() { cout << "~Derived()" << endl; }
};

int main()
{
    Derived d(5);
}

/*
생성자 호출의 원리
파생 클래스의 생성자에서 기반 클래스의 디폴트 생성자를 호출하는 코드를 컴파일러가 제공해주는 것
*/
#endif

#if 0
class Animal
{
public:
    Animal() {}
};

class Dog : public Animal
{
public:
};

int main()
{
    Animal a; //OK
    Dog d;    //default생성자로 OK
}
#endif

#if 0
class Animal
{
private: //변경
    Animal() {}
};

class Dog : public Animal
{
public:
};

int main()
{
    //다음중 에러를 모두 골라보세요
    Animal a;
    Dog d;
}

//둘다 error다
//Animal도 생성자 못부르고 Dog의 기본생성자도 Animal생성자 불러야하는데 못 부른다
#endif

class Animal
{
protected: //변경
    Animal() {}
};

class Dog : public Animal
{
public:
};

int main()
{
    //다음중 에러를 모두 골라보세요
    Animal a;
    Dog d;
}

/*
Animal a;가 error
protected는 외부에서 부를 수 없으나 파생클래스의 멤버함수는 부를 수 있다
*/

/*
protected생성자
자신의 객체는 만들수 없지만 파생클래스의 객체는 생성할 수 있다
Animal은 추상적(Abstract)개념이므로 객체가 존재할 수 없다.
Dog는 구체적(Concrete)존재이므로 객체가 존재할 수 있다.
*/