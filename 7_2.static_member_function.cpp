#if 0
/*cnt를 사용자가 접근못하게 private에 두었다.
std::cout << Car::cnt << std::endl;
std::cout << c1.cnt << std::endl;
error가 발생하지
그럼 어떻게 cnt를 조회해볼수 있을까??
*/
#include <iostream>

class Car
{
    int speed;
    static int cnt;

public:
    Car()
    {
        ++cnt;
    }
    ~Car()
    {
        --cnt;
    }
};

int Car::cnt = 0;

int main()
{
    Car c1, c2;
    std::cout << Car::cnt << std::endl;
    std::cout << c1.cnt << std::endl;
}
#endif

#if 0
#include <iostream>

class Car
{
    int speed;
    static int cnt;

public:
    Car() { ++cnt; }
    ~Car() { --cnt; }
    int getCount() { return cnt; }//추가
};

int Car::cnt = 0;

int main()
{
    Car c1, c2;
    std::cout << c1.getCount() << std::endl;
    //위와같이 사용했다.
}

#endif
#if 0
#include <iostream>

class Car
{
    int speed;
    static int cnt;

public:
    Car() { ++cnt; }
    ~Car() { --cnt; }
    int getCount() { return cnt; }
};

int Car::cnt = 0;

int main()
{
    std::cout << Car::getCount() << std::endl;
    //그런데 자동차가 없을때 0인걸 알고 싶은데 그게 안된다..
}
#endif
#if 0

#include <iostream>

class Car
{
    int speed;
    static int cnt;

public:
    Car() { ++cnt; }
    ~Car() { --cnt; }
    static int getCount() { return cnt; } //static 멤버함수 만들었다.
};

int Car::cnt = 0;

int main()
{
    std::cout << Car::getCount() << std::endl; //자동차가 안만들어 졌는데 호출가능
    Car c1;
    std::cout << c1.getCount() << std::endl;
}

/*
static 멤버함수
객체없이 호출 가능한 멤버함수
클래스이름::함수이름()으로 호출가능
객체이름.함수이름()으로도 사용가능
일반멤버함수 : 호출하려면 반드시 객체가 필요
*/
#endif

#if 0
#include <iostream>

class Test
{
    int data1;
    static int data2;

public:
    //1,2,3,4번중에 뭐가 error일까
    void f1()
    {
        data1 = 0; //1
        data2 = 0; //2
    }

    static void f2()
    {
        data1 = 0; //3
        data2 = 0; //4
    }
};

int Test::data2 = 0;

int main()
{
    Test::f2();
}
#endif

#if 0
#include <iostream>

class Test
{
    int data1;
    static int data2;

public:
    //1,2,3,4번중에 뭐가 error일까
    void f1() //객체만들어야 호출 가능
    {
        data1 = 0; //1
        data2 = 0; //2
    }

    static void f2() //객체없이 호출가능
    {
        data1 = 0; //3
        data2 = 0; //4
    }
};

int Test::data2 = 0;

int main()
{
    Test::f2();
    /*
    static 멤버 함수라서 객체없이 호출 가능
    그런데 data1은 static data가 아니라서
    객체없이 존재할수 없다
    3번에서 error
    
    data2는 "int Test::data2 = 0;"
    여기서 정의되었으니 문제없다.
    */
}
#endif
#include <iostream>

class Test
{
    int data1;
    static int data2;

public:
    void f1()
    {
        data1 = 0;
        data2 = 0;
    }

    static void f2()
    {
        //data1 = 0;
        data2 = 0;
    }

    static void f3(); //선언
};

int Test::data2 = 0;
void Test::f3() //여기 앞에다가 static붙여야할까? =>안붙여도 된다.
{
}
int main()
{
    Test::f2();
}

/*
static멤버 함수 안에서는 일반 멤버 data에 접근이 불가능
static멤버 함수 안에서는 static 멤버 데이터에는 접근이 가능
static멤버 함수를 선언과 구현을 분리할때는 선언에만 static 표기
*/

/*
static함수는 객체없이 부를 수 있으니 일반함수랑 같은거잖아!
static data는 객체없이 메모리에 있으니 결국 전역변수랑 비슷하네!

결국 c의 입장에서 보면 전역변수와 일반함수네
단지 static자를 붙여서 private와 public을 사용해서 보다 효율적으로 작업할 수 있게 했다.
*/