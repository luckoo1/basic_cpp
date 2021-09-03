#include <iostream>
#include <iomanip>

//iomanipulator 함수
//dec,hex : 변수 값을 10진수, 16진수 등으로 출력
//setw : 문자열 출력시 개수 지정

int main()
{
    int n = 10;
    std::cout << n << std::endl;             //10진수 출력
    std::cout << std::hex << n << std::endl; //16진수 출력
    std::cout << n << std::endl;             //16진수 출력
    std::cout << std::dec << n << std::endl; //10진수 출력

    std::cout << "hello" << std::endl;
    std::cout << std::setw(10) << "hello" << std::endl;                                   //hello출력시 10자리로 출력해달라.
                                                                                          // #include <iomanip> 포함해야한다.
    std::cout << std::setw(10) << std::setfill('#') << "hello" << std::endl;              //빈칸에 '#'로 채워달라
    std::cout << std::setw(10) << std::setfill('#') << std::left << "hello" << std::endl; //문자를 왼쪽으로 넣고 나머지를 '#'로 채운다.
    std::cout << std::left << std::setw(10) << std::setfill('#') << "hello" << std::endl; //문자를 왼쪽으로 넣고 나머지를 '#'로 채운다.
    std::cout << std::setw(10) << std::left << std::setfill('#') << "hello" << std::endl; //문자를 왼쪽으로 넣고 나머지를 '#'로 채운다.
}