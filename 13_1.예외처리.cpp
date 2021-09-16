#if 0
//c방식 실패처리
int foo()
{
    if (실패)
    {
        return -1;
    }
    return 0;
}

int main()
{
    int ret = foo();
    //....
}
/*
c방식 에러처리
리턴값 받아보는데 약속된 -1이 나오면 error처리
return값이 0이 와야하는데 수행결과 -1이와서 혼란을 야기할수도 있다.

if (실패)
{
    return -1;
}
여기서 심각한 오류가 발생했는데, foo를 호출하는 사람은 
//...부분에서 에러체크를 반드시 해야하는건 아니다
에러체크 안했다고 문제될건 없고 밑쪽으로 계속 갈수 있다
c방식 에러처리는 사용자가 반드시 확인할 필요가 없다.
*/
/*
리턴값을 사용한 에러 처리방식
리턴값과 에러값을 구분하기 어려운 경우가 있다
함수 사용자가 반드시 에러를 확이할 필요가 없다.
*/
#endif

#if 0
int foo()
{
    if (1) //항상실패하게 만들었다.
    {
        throw 1;
    }
    return 0;
}

int main()
{
    foo(); //여기서 실패발생
}
//그럼 위의 예제는 무조건 실패한다
#endif

#if 0
#include <iostream>

int foo()
{
    if (1) //항상실패하게 만들었다.
    {
        throw 1;
    }
    return 0;
}

int main()
{
    try
    {
        foo();
    }
    catch (int n) //예외를 throw한걸 잡았다
    {
        std::cout << "예외 발생" << std::endl;
    }
    std::cout << "계속 실행" << std::endl;

    /*
    컴파일하면
    예외발생
    계속실행
    이렇게 뜬다.

    즉 예외발생하면 catch구문에서 확인하고 처리를 할수 있게되고
    뒤에 계속 이어나갈수 있는거다
    */
}
#endif

#if 0
#include <iostream>

int foo()
{
    if (1) //항상실패하게 만들었다.
    {
        throw 1;
    }
    return 0;
}

int main()
{
    try
    {
        foo();
    }
    catch (int n)
    {
        std::cout << "123" << std::endl;
    }
    catch (...) //어떠한 type를 던져도 여기서 잡힌다.
    //주의할게 오버로딩이 되는게 아니라 위에서 부터 찾아간다
    //즉 이걸 "catch (int n){}"보다 위에 두면
    //"catch (...)"에서 무조건 걸리게된다.
    //이 부부분을 위에 두면 안된다.
    {
        std::cout << "543" << std::endl;
    }
    std::cout << "fadsfads" << std::endl;
}

/*
예외(exception)기본
throw,try,catch
throw를 사용해서 예외를 던진다
throw된 예외는 반드시 잡아서 처리해얗나다
처리되지 않은경우 abort()함수를 수행하고 종료된다
try~catch 구문을 사용해서 예외를 잡는다
*/

/*
catch(...)
모든 종류의 예외를 잡을 수 있다.
catch를 여러개 만들때는 반드시 마지막에 놓여야 한다.
*/
#endif

#if 0
/*
단순히 1을 던지는거보다
MemoryException class를 만들어서
class안에 정보를 담을수있다.
*/
class MemoryException
{
};

int foo()
{
    if (1)
    {
        throw MemoryException();
    }
    return 0;
}

int main()
{
    try
    {
        foo();
    }
    catch (MemoryException &e)
    {
    }
}
#endif

#if 0
#include <iostream>
#include <exception> //추가

class MemoryException : public std::exception //상속받음
{
public:
    virtual const char *what() const noexcept //exception안에는 what이라는 가상함수가 있다.
    {
        return "메모리 예외";
    }
};

int foo()
{
    if (1)
    {
        throw MemoryException();
    }
    return 0;
}

int main()
{
    try
    {
        foo();
    }
    catch (MemoryException &e)
    {
        std::cout << e.what() << std::endl; //예외이유를 알수있다.
    }
}

/*
std::exception
C++표준 예외의 최상위 클래스
what() 가상함수를 제공한다

c++표준의 어떤함수를 부르면 실패했을때 예외가 나올수 있다.
그 c++표준에는 미리 만들어진 예외도 있다.

C++표준의 예외 클래스
std::bad_alloc
std::range_error
std::out_of_range
*/
#endif

#if 0
#include <iostream>

int main()
{
    int *p = new int[100]; //메모리할당 실패시 예외발생
}
#endif

#if 0
#include <iostream>

int main()
{
    try
    {
        int *p = new int[100];
    }
    catch (std::bad_alloc &e)
    {
        std::cout << e.what() << std::endl; //메모리할당 실패시 예외발생
    }
}
#endif

#if 0
#include <iostream>

//1. foo함수가 실행되다가 int형태의 예외가 나올수 있다.
void foo() throw(int)
{
}
int main()
{
}

//2.예외는 없다
void foo() throw()
{
}
int main()
{
}

//3.예외가 있을수도 있다.
void foo()
{
}
int main()
{
}
#endif

#if 0
//C++11부터 예외의 종류를 알려주는건 중요하지 않은데 예외의 유무를 알려주는건 중요한거같다고 판단함
//1.
void foo() noexcept(false)//예외가 있다.
{
}
int main()
{
}
//2.
void foo() noexcept(true) //예외가 없다.
{
}
int main()
{
}
//3.
void foo() noexcept //예외가 없다.
{
}
int main()
{
}
//4.
void foo()  //예외가 있다.
{
}
int main()
{
}

//사실 1,4번만 많이 쓴다
#endif

void goo() noexcept(true) //예외가 없다
{
}
void foo() //예외가 있다.
{
}
int main()
{
    bool b = noexcept(foo());
    //foo()가 예외가 있나 없나 조사하는 것
    //foo()뒤에 4번형태로 적었으니 true로 나올것이다.
    bool b = noexcept(goo());
    //false로 나올것이다.
}

//컴파일러가 예외가 없으면 최적화를 더 잘하니깐
//예외가 없는 상황이면 웬만하면 적어주자