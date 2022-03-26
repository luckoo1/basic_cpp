int main()
{
    int n1 = 3;

    ++n1;

    int n2; //쓰레기 값을 가지게 된다
    //그런데 만약에 int가 객체였다면 생성자를 통해서 저 순간에 0으로 초기화도 가능하겠네?
}
//#######################################################################

#include <iostream>

//Interger class를 추가했다.
class Integer
{
    int value;

public:
    Integer(int n = 0) : value(n) {} //생성자 만들어줌
    void print() const
    {
        std::cout << value << std::endl;
    }
};

int main()
{
    Integer n1 = 3;

    /*
    ++n1;을 쓰고 싶다.
    n1.operator++()을 만들어야지

    Integer n2 = ++n1;
    증가하고 나서 자기랑 똑같은 타입으로 받는격이잖아.
    */

    n1.print();
}
//#######################################################################

#include <iostream>

//Interger class를 추가했다.
class Integer
{
    int value;

public:
    Integer(int n = 0) : value(n) {}
    void print() const
    {
        std::cout << value << std::endl;
    }
    //1.이런식으로 operator++()를 만들었다.
    Integer operator++()
    {
    }
};

int main()
{
    Integer n1 = 3;

    Integer n2 = ++n1; //n1.operator++()

    n1.print();
}
//#######################################################################

#include <iostream>

class Integer
{
    int value;

public:
    Integer(int n = 0) : value(n) {}
    void print() const
    {
        std::cout << value << std::endl;
    }
    //1.이런식으로 operator++()를 만들었는데
    Integer operator++()
    {
    }
    //3.후위형을 위한 것이 추가됨
    Integer operator++(int)
    {
    }
};

int main()
{
    Integer n1 = 3;
    /*
    2.
    ++n1;
    n1++;
    두가지 유형이 있고 하는 일도 다르다.
    */
    Integer n2 = ++n1; //n1.operator++()
    Integer n3 = n1++; //n1.operator++(int)
    //후위형일땐 parameter로 int받기로 약속했다.
    //전위형과 구별하기 위해서 int를 넣었을뿐
    //사용되는게 아니라 단지 전위형과 구별을 위해넣었다
    n1.print();
}
//#######################################################################

#include <iostream>

class Integer
{
    int value;

public:
    Integer(int n = 0) : value(n) {}
    void print() const
    {
        std::cout << value << std::endl;
    }
    //전위형
    Integer operator++()
    {
    }
    //후위형
    Integer operator++(int)
    {
    }
};

int main()
{
    Integer n1 = 3;

    Integer n2 = ++n1; //n1.operator++()
    Integer n3 = n1++; //n1.operator++(int)

    n1.print();
}
/*
전위형과 후위형을 구별해야한다
후위형은 인자로 int를 가진다(사용하지 않지만 전위형과 구별하기 위해서)
*/
//#######################################################################

//일단 전위형부터 구현해보겠다.
#include <iostream>

class Integer
{
    int value;

public:
    Integer(int n = 0) : value(n) {}
    void print() const
    {
        std::cout << value << std::endl;
    }
    //1. 전위형구현
    Integer operator++()
    {
        ++value;
        return *this;
    }
};

int main()
{
    Integer n1 = 3;

    ++n1;

    n1.print(); //2.실행시 4나옴
}
//#######################################################################

#include <iostream>

class Integer
{
    int value;

public:
    Integer(int n = 0) : value(n) {}
    void print() const
    {
        std::cout << value << std::endl;
    }

    Integer operator++()
    {
        ++value;
        return *this;
    }
};

int main()
{
    int n = 3;
    ++++n;                       //1.이게 가능하다
    std::cout << n << std::endl; //5가 나온다

    Integer n1 = 3;
    ++++n1;

    n1.print(); //2. 4가 나오네?
}

/*
3.
++++n1은 ++(++n1)격이다
(n1.operator++()).operator++()
이걸 살펴보자
n1.operator++()하면 "Integer operator++()"함수로부터 임시객체가 return된다.
그럼 "(n1.operator++()).operator++()"에서 뒤에있는 "operator++()"은 임시객체에서 ++한거다
임시객체는 5가 되었다.
n1은 4로 남아있다.
n1은 operator++()을 한번밖에 못 부른격이다.
*/
//#######################################################################

#include <iostream>

class Integer
{
    int value;

public:
    Integer(int n = 0) : value(n) {}
    void print() const
    {
        std::cout << value << std::endl;
    }

    Integer &operator++() //참조로 바꾸자
    {
        ++value;
        return *this;
    }
};

int main()
{
    int n = 3;
    ++++n;
    std::cout << n << std::endl;

    Integer n1 = 3;
    ++++n1;

    n1.print(); //5가 나온다
}

/*
전위형은 자신을 참조로 리턴한다.
*/
//#######################################################################

#include <iostream>
//이제 후위형을 만들어보자
class Integer
{
    int value;

public:
    Integer(int n = 0) : value(n) {}
    void print() const
    {
        std::cout << value << std::endl;
    }
    //전위형
    Integer &operator++()
    {
        ++value;
        return *this;
    }
    //후위형
    Integer operator++(int)
    {
        //후위형은 자기가 증가되는건 맞지만 return은 자기자신으로 와야한다.
        Integer temp = *this;
        ++value;     //자기는 증가하고
        return temp; //return값을 자기 사진값으로 증가하고
        //지역변수는 참조리턴이 불가능하니깐 후위형은 어쩔수 없이 값 리턴을 해야한다.
    }
};

int main()
{
    Integer n1 = 3;
    Integer n2 = n1++;

    n1.print(); //4출력
    n2.print(); //3출력
}
//#######################################################################

#include <iostream>

class Integer
{
    int value;

public:
    Integer(int n = 0) : value(n) {}
    void print() const
    {
        std::cout << value << std::endl;
    }
    //2. 그럼 전위형과 후위형 두군데에서 ++value를 바꿔야한다.
    //    정책이 변할때 수정이 많은건 좋지않다.

    //전위형
    Integer &operator++()
    {
        ++value;
        return *this;
    }
    //후위형
    Integer operator++(int)
    {
        Integer temp = *this;
        ++value;
        return temp;
    }
};

int main()
{
    //1. Interger를 만드는데 얘는 홀수만 되게 하겠다고 해보자
    //   그럼++하면 2씩증가해야한다.
    Integer n1 = 3;
    Integer n2 = n1++;

    n1.print(); //4출력
    n2.print(); //3출력
}
//#######################################################################

#include <iostream>

class Integer
{
    int value;

public:
    Integer(int n = 0) : value(n) {}
    void print() const
    {
        std::cout << value << std::endl;
    }

    //전위형
    Integer &operator++()
    {
        ++value;
        return *this;
    }
    //후위형
    Integer operator++(int)
    {
        Integer temp = *this;
        //++value;
        ++(*this);
        //내 자신을 다시 전위형증가한다.
        //전위형 "Integer &operator++()"로 간다
        //그럼 수정이 필요하면 전위형의 ++value에서 수정을 한다.
        return temp;
    }
};

int main()
{
    Integer n1 = 3;
    Integer n2 = n1++;

    n1.print();
    n2.print();
}
//#######################################################################

/*
후위형의 구현은 전위형을 구현을 사용한다.
*/

//전위형과 후위형중에 속도는 전위형이 분명하게 빠르다
for (int i = 0; i < 10; i++)
{
}
//사실 아래와 같이 쓰는게 빠르다.ㅋㅋㅋ
for (int i = 0; i < 10; ++i)
{
}
//요즘 for문 for (int i = 0; i < 10; i++)써도
//컴파일러가들이 똑똑해서 for (int i = 0; i < 10; ++i)바꾼다