//#######################################################################
#include <iostream>

int foo()
{
    return -1;
}

int main()
{
    int ret = foo();

    if (ret == -1)
    {
        std::cout << "fail" << std::endl;
    }

    //위에 코드와 같은 역할이다.
    if (int ret = foo(); ret == -1) //ret이 -1이면
    {
        std::cout << "fail" << std::endl;
    }
}
//#######################################################################

#include <iostream>

int foo()
{
    return -1;
}

int main()
{
    switch (int ret = foo(); ret)
    {
    case -1:
        std::cout << "-1" << std::endl;
        break;
    }
}

/*
if문과 switch문에 초기화 구문을 포함할 수 있다.
if(init:조건문), switch(init;조건문)형태로 사용
*/
