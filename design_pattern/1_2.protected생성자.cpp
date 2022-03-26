class Animal
{
protected:
    Animal() {}
};

class Dog : public Animal
{
public:
    Dog() {}
};

int main()
{
    Animal a; //error
    //외부에서 proteced에 접근할수 없다.

    Dog d; //OK
    /*여기서 Dog객체가 생성되면
    class Dog : public Animal
    {
    public:
        Dog() : Animal() {}
    };
    위에처럼 컴파일러가 코드를 수정한다.
    Dog의 {}을 실행하기전에 기반클래스의 생성자를 호출한다.
    */

    /*
    기반class의 protected의 이유
    Animal은 객체를 만들수 없지만 Dog는 만들 수 있다.
    자기 자신은 객체를 만들수 없지만 내 파생클래스는 객체를 만들게 하겠다.
    현실세계에서도 Animal은 추상적인 개념이잖아
    Dog는 현실세계에도 존재함
    */
}

/*
1.생성자의 정확한 호출 순서
Dog의 생성자가 먼저 호출
Dog의 생성자 안에서 기반클래스인 Animal의 생성자를 호출

2.생성자를 protected에 만드는 이유
자기 자신(Animal)을 만들 수는 없다
하지만 파생클래스(Dog)의 객체는 만들 수 있다.
동물은 추상적인 개념이기 때문에 객체가 존재할수 없지만 "강아지"는 현실세계에서 객체가 존재한다.
*/