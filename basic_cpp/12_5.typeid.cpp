#include <iostream>
#include <typeinfo>

int main()
{
    int n1 = 10;
    auto n2 = n1;

    const std::type_info &t1 = typeid(n2);
    //함수가 아닌 연산자라서 "std::typeid"안 붙여도 된다
    //type_info의 복사생성자가 사용할수 없게 되어있어서 참조로만 받아야한다.
    //t1은 type_info의 객체

    std::cout << t1.name() << std::endl; //i로 나온다

    const std::type_info &t2 = typeid(int);
    const std::type_info &t3 = typeid(3 + 4.5);

    std::cout << t2.name() << std::endl; //i
    std::cout << t3.name() << std::endl; //d
}

/*
typeid
타입에 대한 정보를 얻을때 사용하는 연산자
<typeinfo>헤더 파일을 포함해야한다
typeid(타입)
typeid(객체)
typeid(expression)
typeid의 결과로 const std::type_info& 가 반환된다.
*/

/*
std::type_info
타입의 정보를 담고 있는 클래스
사용자가 직접 객체를 생성할 수는 없고 typeid()연산자를 통해서는 얻을 수 있다.
멤버함수인 name()을 통해서 타입의 이름을 얻을수 있다
실행결과는 컴파일러마다 표현 방법이 다르다
g++로 생성된 실행파일의 경우 "a.exe | c++ filt-t"로 실행하면 완전한 타입의 이름을 볼 수 있다.
"std:type_info t;"와 같이 사용하면 error
*/