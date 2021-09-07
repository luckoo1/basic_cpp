#if 0
struct Bike
{
private:
    int gear;

public:
    void changeGear(int n)
    {
        gear = n;
    }
};

void fixBike()
{
    Bike b;
    b.gear = 0; //1. gear가 private니깐 멤버가 아닌 함수에서 접근이 불가능하다.
}
//2.멤버함수가 아닌 fixBike()같은 곳에서 private data에 접근하고 싶은 경우가 발생할 수 있다.

int main()
{
}
#endif

struct Bike
{
private:
    int gear;

public:
    int getGear() { return gear; } //4.이렇게 써서 private에 접근하면 되는거 아냐?
    //이렇게하면 모든 함수가 멤버 데이터에 접근이 가능하다.
    //우리 코드에서는 약속된 함수(fixBike())만 멤버 데이터에 접근할 수 있다.

    void changeGear(int n)
    {
        gear = n;
    }
    //1. friend 함수
    //   fixBike()는 멤버 함수가 아니지만 함수내에서 private data에 접근이 가능
    friend void fixBike();

    friend class AAA; //5."AAA" class의 모든 멤버함수 안에서 private data에 접근 가능
};

//2.Bike::fixBike(){ }
//  멤버함수는 구현부에서 이런 모양으로 적었었다.

//3.왜 멤버함수로 하지 않는가??
//   멤버함수로 만들 수 없는 경우가 있다.(연산자 재정의 참조)
void fixBike()
{
    Bike b;
    b.gear = 0;
}

int main()
{
}

/*
5.
getter()/setter() 함수를 제공하는 경우 : 모든 함수가 멤버 데이터에 접근이 가능
friend함수 : 약속된 함수만 멤버 데이터에 접근이 가능
*/