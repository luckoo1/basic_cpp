#include <iostream>
#include <fstream>

//그림필기 참조

int main()
{
    //ostream cout이 basic_ostream<>로 사용되는데
    //typedef basic_ostream<char> ostream;되어 있어서 ostream처럼 사용했다.
    std::cout << "hello";
}

/*
basic_ifstream과 basic_ofstream이 파일 입출력을 위한 스트림 클래스
basic_ifstream => ifstream
basic_ofstream => ofstream
와 같은 방식으로 tyfedef되어 있다.

파일입출력
<fstream>
ifstream : 입력파일을 위한 스트림
ofstream : 출력파일을 위한 스트림
*/
//#######################################################################

#include <iostream>
#include <fstream>

int main()
{
    std::ofstream f("a.txt");
    //ofstream의 객체 f를 만들었다.
    //a.txt파일의 출력을 위한 객체

    f << "hello"; //a.txt에 출력

    //a.txt파일이 생기고 hello가 찍혀있다.
}
//#######################################################################

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string s;

    std::ifstream fin("13_3.파일입출력.cpp");
    //ifstream의 객체 fin을 만들어서 "13_3.파일입출력.cpp"넣었다.

    fin >> s;
    //fin으로부터 s가 입력을 받음
    //파일로부터 입력을 받는데 "13_3.파일입출력.cpp"의 첫번째 단어가 입력됨

    std::cout << s << std::endl;
}
//#######################################################################

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string s;

    std::ifstream fin("13_3.파일입출력.cpp");
    //ifstream의 객체 fin을 만들어서 "13_3.파일입출력.cpp"넣었다.

    std::getline(fin, s);
    //한줄이 입력됨

    std::cout << s << std::endl;
}
//#######################################################################

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    std::string s;

    std::ifstream fin("13_3.파일입출력.cpp");
    //ifstream의 객체 fin을 만들어서 "13_3.파일입출력.cpp"넣었다.

    std::vector<std::string> v; //문자열을 보관하는 vector

    while (std::getline(fin, s)) //getline은 EOL만나면 false를 return한다
    {
        //파일의 한줄씩 꺼내는데 파일의 끝(EOL)에 도착할때까지 루프를 돈다.
        v.push_back(s);
    }

    for (auto &n : v)
    {
        std::cout << n << std::endl;
    }
    //파일의 모든내용을 화면에 출력
}
//#######################################################################

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    std::string s;

    std::ifstream fin("13_3.파일입출력.cpp");

    std::vector<std::string> v;

    while (std::getline(fin, s))
    {
        v.push_back(s);
    }

    std::reverse(v.begin(), v.end()); //파일 뒤집기도 가능

    for (auto &n : v)
    {
        std::cout << n << std::endl;
    }
}
//#######################################################################

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    std::string s;

    std::ifstream fin("13_3.파일입출력.cpp");

    std::vector<std::string> v;

    while (std::getline(fin, s))
    {
        v.push_back(s);
    }

    std::reverse(v[0].begin(), v[0].end()); //첫번째줄만 좌우로 뒤집어짐

    for (auto &n : v)
    {
        std::cout << n << std::endl;
    }
}
//#######################################################################

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    std::string s;

    std::ifstream fin("13_3.파일입출력.cpp");

    std::vector<std::string> v;

    while (std::getline(fin, s))
    {
        v.push_back(s);
    }

    for (int i = 0; i < v.size(); i++)
    {
        std::reverse(v[i].begin(), v[i].end());
    }

    for (auto &n : v)
    {
        std::cout << n << std::endl;
    }
}