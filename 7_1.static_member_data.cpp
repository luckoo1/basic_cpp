#if 0
/*차가 생성될때마다 cnt를 추가하고 싶다.
그런데 객체당 변수가 하나씩 만들어진다
그렇다고 전역변수로
int cnt = 0;으로 하면 누구나 접근이 가능해져서 위험하다.
*/
#include <iostream>

class Car
{
    int speed;
    int cnt = 0;

public:
    Car() { ++cnt; }
    ~Car() { --cnt; }
};

int main()
{
    Car c1, c2;
}

/*멤버변수
객체당 하나씩 만들어 진다.
*/
#endif

#if 0
#include <iostream>

class Car
{
    int speed;

public:
    //static멤버 데이터 선언
    static int cnt; //static 멤버 데이터
    //객체들이 공유한다.
    Car() { ++cnt; }
    ~Car() { --cnt; }
};

//static 멤버 데이터 정의
int Car::cnt = 0;

int main()
{
    Car c1, c2;
    std::cout << c1.cnt << std::endl;
}

/*
1. static 멤버 변수 모양
클래스 안에 선언하고 -> static 키워드 사용
클래스 외부에 정의한다 -> static 키워드 사용 안함

2. static 멤버 변수
모든 객체가 공유한다
접근 지정자를 사용해서 보호가 가능하다.
*/
#endif

#if 0
#include <iostream>

class Car
{
    int speed;

public:
    //static멤버 데이터 선언
    static int cnt;
    Car() { ++cnt; }
    ~Car() { --cnt; }
};

//static 멤버 데이터 정의
int Car::cnt = 0;

int main()
{
    /*
    1.
    사실 "static 멤버 데이터 정의"가 결국엔 전역변수
    객체를 안만들어도 메모리에 존재한다.

    2.
    6분 그림필기
    객체를 만들때, static 멤버는 객체의 메모리에 포함되지 않는다.
    sizeof(객체) : static 멤버를 제외한 객체의 크기가 나온다.

    3.
    결국 전역변수처럼 생각하면되는데
    장점이 private와 public을 사용할 수 있다.

    4.
    또다른장점
    "클래스이름:변수이름"으로 사용하므로 각 클래스별로 동일 이름을 사용할 수 있다.
    Car::cnt,Bike::cnt
    */

    Car c1, c2;
    int n = sizeof(c1);
    std::cout << n << std::endl; //4가 나온다.
}
#endif
#if 0
#include <iostream>

class Car
{
    int speed;
public:
    //static멤버 데이터 선언
    static int cnt;
    Car() { ++cnt; }
    ~Car() { --cnt; }
};

//static 멤버 데이터 정의
int Car::cnt = 0;

int main()
{
    Car c1, c2;
    std::cout << Car::cnt << std::endl;
    std::cout << c1.cnt << std::endl;
}

/*
static 멤버 변수의 접근방법 2가지
클래스 이름::멤버이름->권장
객체이름.멤버이름 -> static 멤버인지 일반 멤버인지 구별이 어려움
*/
#endif

#include <iostream>

class Car
{
    int speed;
    static int limitspeed;
    /*static으로 뭘 놓아야할지 어려운데
    위와같이 limitspeed는 모든 자동차가 공유해야하니깐 static으로 둠
    */
public:
    //static멤버 데이터 선언
    static int cnt;
    Car() { ++cnt; }
    ~Car() { --cnt; }
};

//static 멤버 데이터 정의
int Car::cnt = 0;

int main()
{
    Car c1, c2;
    std::cout << Car::cnt << std::endl;
    std::cout << c1.cnt << std::endl;
}
