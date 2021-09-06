#if 0
//4번째 과정
#include <iostream>


struct Stack
{
private: //1.외부에서 접근할수 없고 멤버함수 내에서만 접근하게 한다.
    int buf[10];
    int idx;


    void push(int n)
    {
        buf[idx++] = n;
    }


    int pop()
    {
        return buf[--idx];
    }
};


int main()
{
    Stack s1, s2;
    s1.idx = 0; //2.컴파일 에러
    s2.idx = 0;


    s1.push(10);
    s1.push(20);


    s2.push(30);
    s2.push(20);


    std::cout << s1.pop() << std::endl;
    std::cout << s2.pop() << std::endl;
}
#endif

#if 0
#include <iostream>


struct Stack
{
private:
    int buf[10];
    int idx;


public:         //3.public이라고 적으면 밖에서 접근할수 있다.
    void init() //1.init함수를 만들었다.
    {
        idx = 0;
    }
    void push(int n)
    {
        buf[idx++] = n;
    }


    int pop()
    {
        return buf[--idx];
    }
};


int main()
{
    Stack s1, s2;
    s1.init(); //init을 불렀는데 private안에 있어서 못 부른다.
    s2.init();


    s1.push(10);
    s1.push(20);


    s2.push(30);
    s2.push(20);


    std::cout << s1.pop() << std::endl;
    std::cout << s2.pop() << std::endl;
}


/*
정리
접근 지정자
private : 멤버 함수에서만 접근 할 수 있다.
public : 멤버 함수가 아닌 함수에서도 접근 가능하다.


정보은닉(information hiding)
멤버 데이터를 외부에서 직접 접근할 수 없게 하고, 멤버 함수를 통해서만 접근 가능하게 한다.
외부에 잘못된 사용으로부터 객체가 불안해지는 것은 막는다.
Stack을 사용하는 사람은 push()/pop() 함수만 알면되지 Stack 내부 데이터를 몰라도 된다.
//29분 그림필기


struct vs class
struct : 접근 지정자 생략시 디폴트가 public
class : 접근 지정자 생략시 디폴트가 private
(//private:)
일반 사용자가 될수 있으면 멤버데이터를 못 건드리게 하는걸 좋아한다.
*/
#endif

#if 0
//5번째 단계
#include <iostream>


class Stack
{
private:
    int buf[10];
    int idx;


public:
    void init()
    {
        idx = 0;
    }
    void push(int n)
    {
        buf[idx++] = n;
    }


    int pop()
    {
        return buf[--idx];
    }
};


int main()
{
    Stack s1, s2;
    s1.init(); //1.stack쓰고 싶으면 반드시 init()함수를 호출해야한다.
    s2.init();


    s1.push(10);
    s1.push(20);


    s2.push(30);
    s2.push(20);


    std::cout << s1.pop() << std::endl;
    std::cout << s2.pop() << std::endl;
}
#endif
#if 0
#include <iostream>
class Stack
{
private:
    int buf[10];
    int idx;


public:
    Stack() //생성자 : 객체를 만들면 이것부터 실행한다. 객체의 초기화를 위해 사용
    {
        idx = 0;
    }


    void push(int n)
    {
        buf[idx++] = n;
    }


    int pop()
    {
        return buf[--idx];
    }
};


int main()
{
    Stack s1, s2;


    s1.push(10);
    s1.push(20);


    s2.push(30);
    s2.push(20);


    std::cout << s1.pop() << std::endl;
    std::cout << s2.pop() << std::endl;
}


/*
생성자
클래스으름과 동일한 이름을 가지는 함수
객체를 만들면 자동으로 생성자가 호출된다.
리턴 타입을 표기하지 않는다.
인자가 있어도 되고 없어도 된다.
*/
#endif

#if 0
//6번째 단계
//1.아래의 stack의 문제점은 buf의 사이즈가 10으로 고정되어 있다.
#include <iostream>
class Stack
{
private:
    int *buf; //2.수정
    int idx;


public:
    Stack(int sz = 10) //3.사용자가 사이즈를 안주면 10의 크기
    {
        buf = new int[sz]; //4.사이즈 동적할당
        idx = 0;
    }


    void push(int n)
    {
        buf[idx++] = n;
    }


    int pop()
    {
        return buf[--idx];
    }
};


int main()
{
    Stack s1(20); //5.sz가 20이 된다
    Stack s2;     //sz가 10이 된다.


    s1.push(10);
    s1.push(20);
    s2.push(30);
    s2.push(20);
    std::cout << s1.pop() << std::endl;
    std::cout << s2.pop() << std::endl;
}

#endif
/*
new buf int[sz];를 썼으니깐 
언젠가는 메모리를 파괴해야 한다
*/

#if 0

#include <iostream>
class Stack
{
private:
    int *buf;
    int idx;


public:
    Stack(int sz = 10)
    {
        buf = new int[sz];
        idx = 0;
    }


    ~Stack() //소멸자 : 객체가 파괴될때 자동으로 호출된다.
    {
        delete[] buf;
    }


    void push(int n)
    {
        buf[idx++] = n;
    }


    int pop()
    {
        return buf[--idx];
    }
};


int main()
{
    Stack s1(20);
    Stack s2;


    s1.push(10);
    s1.push(20);
    s2.push(30);
    s2.push(20);
    std::cout << s1.pop() << std::endl;
    std::cout << s2.pop() << std::endl;
}

/*
소멸자
"~클래스 이름()"의 모양의 함수
객체가 파괴될때 호출된다
객체가 자원(메모리)를 할당할 경우 소멸자에서 해지한다
리턴 타입을 표기하지 않고 인자도 가질 수 없다.
*/
#endif