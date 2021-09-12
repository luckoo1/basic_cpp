#if 0
int main()
{
    char s1[10] = "hello";
    char s2[10];
    s2 = s1; //error
    //c에서는 strcpy
}
#endif

#if 0
#include <iostream>
#include <string>

int main()
{
    std::string s1 = "hello";
    std::string s2;

    s2 = s1; //가능
}
//string을 만들어보자(고급기법 제외 간단한 형태로!)
#endif

#if 0
#include <iostream>

int main()
{
    String s1 = "hello";

    std::cout << s1 << std::endl; //1.cout과 연동이 되어야한다.

    String s2 = s1; //2.복사연산자

    String s3 = "world";

    s2 = s3; //3.대입연산자
}
#endif

#include <iostream>
#include <cstring> //string.h의 C++ 버전

class String
{
    char *buff;
    int size;

public:
    //2.인자로 char 포인터 받음
    String(const char *s)
    {
        size = strlen(s);
        buff = new char[size + 1]; //null 고려
        strcpy(buff, s);           //buff를 할당해서 문자열을 보관한다
    }

    ~String()
    {
        delete[] buff;
    }
};

int main()
{
    String s1 = "hello";
    /*
    1.이렇게 적는건 이 코드는
    String s1("hello")와 같다
    */
}