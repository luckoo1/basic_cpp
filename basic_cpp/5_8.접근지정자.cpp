struct Bike
{
    int gear;
};

int main()
{
    Bike b;
    b.gear = -10; //현실에서는 기어가 마이너스값이 될 수 없다.
}
//#######################################################################

struct Bike
{
private: //1.private를 사용해서 사용자가 직접 접근 못하게 만들었다.
    int gear;

public: //2.사용자가 이 멤버함수에 접근할 수 있도록 public에 두자.
    void changeGear(int n)
    {
        //4.잘못 보내는걸 확인하자
        if (n < 0)
        {
        }

        gear = n;
    }
};

int main()
{
    Bike b;
    b.changeGear(-10); //3.잘못 보낼수도 있잖아
}

/*
5.
멤버 데이터를 외부에서 직접 변경하면 잘못된 값을 가지게 될 수 있다.
함수를 통해서만 변경할수 있게 하는 것이 좋다.
멤버함수의 경우 인자의 유효성 여부를 조사할 수 있다.

6.접근지정자
private : 멤버 함수에서만 접근 할 수 있다.
publice : 멤버 함수가 아닌 함수에서도 접근할 수 있다.

자바와 C#은 아래와 같이 코드를 짠다.
struct Bike
{
    private int gear;
};

7.struct vs class
struct : 접근 지정자 생략시 디폴트가 public
class : 접근 지정자 생략시 디폴트가 private
*/