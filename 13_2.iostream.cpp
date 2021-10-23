#include <iostream>

int main()
{
    int n = 0;

    std::cin >> n;
    //정수를 입력하지 않고 'a'를 입력했다고 가정해보자
    //이건 입력의 실패인데 입력에 성공했는지 실패했는지 조사해야한다.

    //cin로 iostream의 객체다
    //cin의 멤버함수를 사용해보자

    std::cout << n << std::endl;
}
//#######################################################################

#include <iostream>

int main()
{
    int n = 0;

    while (1)
    {
        std::cin >> n;

        if (std::cin.fail())
        {
            std::cout << "실패" << std::endl;
            continue;
        }
        break;
    }

    std::cout << n << std::endl;
}
//이거 실행하고 'a'입력해보았다
//계속 실패라고 메세지가 무한으로 뜬다

/*
그림필기
*/
//#######################################################################

#include <iostream>

int main()
{
    int n = 0;

    while (1)
    {
        std::cin >> n;

        if (std::cin.fail())
        {
            std::cout << "실패" << std::endl;
            std::cin.ignore(); //입력버퍼를 지운다
            continue;
        }
        break;
    }
    std::cout << n << std::endl;
}

/*
이거 실행하고 'a'입력해보았다
또!!! 계속 실패라고 메세지가 무한으로 뜬다

cin도 객체다
cin은 멤버데이터도 있다.
입력을 받다가 실패하면 cin이 가지고있는 멤버데이터중에서 실패를 나타내는 멤버데이터가 있는데 이미 실패로 표시되어 있다.
그걸 다시 reset하지 않는 이상 계속 실패로 남아있다.
*/
//#######################################################################

#include <iostream>

int main()
{
    int n = 0;

    while (1)
    {
        std::cin >> n;

        if (std::cin.fail())
        {
            std::cout << "실패" << std::endl;
            std::cin.clear();  //cin의 상태를 나타내는 상태비트를 reset
            std::cin.ignore(); //입력버퍼를 지운다
            continue;
        }
        break;
    }
    std::cout << n << std::endl;
}

/*
'a'입력하면 성공적으로 실패를 한번 출력한다
그런데... 'abcdf'입력하면 실패를 5번 출력한다.
std::cin.ignore();하면 디폴트로 std::cin.ignore(1);처럼 되는데
그러면 한자리만 비운다
*/
//#######################################################################

#include <iostream>

int main()
{
    int n = 0;

    while (1)
    {
        std::cin >> n;

        if (std::cin.fail())
        {
            std::cout << "실패" << std::endl;
            std::cin.clear();           //cin의 상태를 나타내는 상태비트를 reset
            std::cin.ignore(256, '\n'); //입력버퍼를 지운다
            //'\n'을 만날때까지 최대 256자리 지운다
            continue;
        }
        break;
    }
    std::cout << n << std::endl;
}

/*
std::cin
std::istream타입의 객체(basic_istream<char>)
"operator>>"뿐 아니라 다양한 멤버함수가 존재
ignore,clear
*/
//#######################################################################

#include <iostream>
#include <string>

int main()
{
    std::string s;

    std::cin >> s;
    //'aaa bbb'이렇게 입력하면 한단어만 입력되는지 문자열전체가 입력되는지 생각해보자
    //단어입력(scanf와 같다)

    std::cout << s << std::endl; //aaa뜬다
}
//#######################################################################

#include <iostream>
#include <string>

int main()
{
    std::string s;

    std::getline(std::cin, s); //'aaa bbb'입력하면

    std::cout << s << std::endl; //'aaa bbb'뜬다

    //getline은 "한문장" 입력이다.
}

/*
문자열입력
std::cin >> s;

문자열 입력
std::getline(std::cin, s);
*/