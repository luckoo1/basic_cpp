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
    String s1 = "hello"; //1.초기화가 되어야한다.

    std::cout << s1 << std::endl; //2.cout과 연동이 되어야한다(화면출력)

    String s2 = s1; //3.복사연산자

    String s3 = "world";

    s2 = s3; //4.대입연산자
}
#endif

#if 0
#include <iostream>
#include <cstring> //string.h의 C++ 버전
//초기화부터 살펴보자
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
        //그림필기 참조
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
#endif

#if 0
//cout과 연동해보자(화면 출력)
//operator<<만들기
#include <iostream>
#include <cstring>

class String
{
    char *buff;
    int size;

public:
    String(const char *s)
    {
        size = strlen(s);
        buff = new char[size + 1];
        strcpy(buff, s);
    }

    ~String()
    {
        delete[] buff;
    }

    friend std::ostream &operator<<(std::ostream &os, const String &s); //2.private에 접근하기 위해서 friend사용
};

//1.ostream namespace안에 있는 operator<<()를 재정의 했다
std::ostream &operator<<(std::ostream &os, const String &s)
{
    os << s.buff;
    return os;
}

int main()
{
    String s1 = "hello";

    std::cout << s1 << std::endl;
}
#endif

#if 0
#include <iostream>
#include <cstring>
//복사기능을 만들어보자
class String
{
    char *buff;
    int size;

public:
    String(const char *s)
    {
        size = strlen(s);
        buff = new char[size + 1];
        strcpy(buff, s);
    }

    ~String()
    {
        delete[] buff;
    }
    //3.깊은복사로 복사생성자 구현
    String(const String &s) : size(s.size)
    {
        buff = new char[size + 1];
        strcpy(buff, s.buff);
    }

    friend std::ostream &operator<<(std::ostream &os, const String &s);
};

std::ostream &operator<<(std::ostream &os, const String &s)
{
    os << s.buff;
    return os;
}

int main()
{
    String s1 = "hello";

    std::cout << s1 << std::endl;

    String s2 = s1;
    std::cout << s2 << std::endl;
    /*
    1.
    복사생성자는 컴파일러가 만들어줘서 복사는 되지만 runtime error발생
    얕은복사 문제 해결해야한다.->deep copy로 해결해보자
    1:00그림필기 추가
    */
}
#endif

#if 0
#include <iostream>
#include <cstring>
//대입연산자를 만들어보자
class String
{
    char *buff;
    int size;

public:
    String(const char *s)
    {
        size = strlen(s);
        buff = new char[size + 1];
        strcpy(buff, s);
    }

    ~String()
    {
        delete[] buff;
    }
    String(const String &s) : size(s.size)
    {
        buff = new char[size + 1];
        strcpy(buff, s.buff);
    }
    /*
    2.
    대입연산자를 만들어줬는데, 기존 buff를 지우고 기존 buff에 새로운 buff를 넣어서 복사해줬다.
    */
    String &operator=(const String &s)
    {
        size = s.size;
        delete[] buff;
        buff = new char[size + 1];
        strcpy(buff, s.buff);
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const String &s);
};

std::ostream &operator<<(std::ostream &os, const String &s)
{
    os << s.buff;
    return os;
}

int main()
{
    String s1 = "apple";
    String s2 = "banana";

    s1 = s2;
    std::cout << s1 << std::endl;
    /*
    1.대입연산자는 컴파일러가 제공해줘서 문제는 없다.
    그림필기 1:04
    메모리 해지가 안되는 현상이 발생한다.
    */
}
#endif

#include <iostream>
#include <cstring>
//대입연산자를 만들어보자
class String
{
    char *buff;
    int size;

public:
    String(const char *s)
    {
        size = strlen(s);
        buff = new char[size + 1];
        strcpy(buff, s);
    }

    ~String()
    {
        delete[] buff;
    }
    String(const String &s) : size(s.size)
    {
        buff = new char[size + 1];
        strcpy(buff, s.buff);
    }

    String &operator=(const String &s)
    {
        if (&s == this) //2.자신과의 대입을 조사
        {
            return *this;
        }
        size = s.size;

        delete[] buff;
        buff = new char[size + 1];

        strcpy(buff, s.buff);

        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const String &s);
};

std::ostream &operator<<(std::ostream &os, const String &s)
{
    os << s.buff;
    return os;
}

int main()
{
    String s1 = "apple";
    String s2 = "banana";

    s1 = s1;
    /*
    1.
    사용자가 이렇게 썼다고 가정해보자
    그런데 buff를 지웠네...?
    문자열이 파괴되고 없다
    */
    std::cout << s1 << std::endl;
}
