#include <iostream>
#include <cstring>

class Person
{
    char name[8]; //이렇게 쓰면 이름의 크기가 고정되어 있어서 싫다.
    int age;

public:
    Person(const char *n, int a) : age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    ~Person() { delete[] name; }
};

int main()
{
    Person p1("KIM", 2);
}
//#######################################################################

#include <iostream>
#include <cstring>

class Person
{
    char *name; //이렇게 바꿈
    int age;

public:
    Person(const char *n, int a) : age(a)
    {
        name = new char[strlen(n) + 1]; //null문자 고려해줌
        strcpy(name, n);                //사용자가 전달한걸 name에다가 보관
    }
    ~Person() { delete[] name; }
};

int main()
{
    Person p1("KIM", 2);
}

/*
배열에 담을 경우 :문자열의 최대 개수가 컴파일 시간에 정해진다
동적메모리 할당 : 실행시간에 문자열의 개수를 정할 수 있다.
*/
//#######################################################################
#include <iostream>
#include <cstring>

class Person
{
    char *name; //이렇게 바꿈
    int age;

public:
    Person(const char *n, int a) : age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    ~Person() { delete[] name; }
};

int main()
{
    Person p1("KIM", 2);
    Person p2 = p1; //runtime error
    //컴파일은 되는데 실행하면 죽는다.
    //그림필기(얕은 복사)
    //위의 코드에서 복사생성자 호출한다.
    //블록이 벗어나는 순간 p2가 파괴된다.
    //그럼 kim을 지운다.

    //그럼 p1은 kim을 못쓰게된다.
    //게다가 kim을 한번 더 delete하려 한다.
    //해지된 메모리를 다시 해지하려 하는 것
}
/*
얕은 복사(Shallow Copy)
동적 할당된 메모리가 있을 때 메모리 자체를 복사하지 않고 메모리 주소만 복사하는 현상
클래스 안에 포인터 멤버가 있고 동적 메모리 할당된 코드를 사용한다면
반드시 사용자가 복사 생성자를 만들어서 얕은 복사 문제를 해결해야 한다.
*/

//얕은복사를 해결하는 방법은 총 4가지이다
