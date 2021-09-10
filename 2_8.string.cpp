#if 0
#include <iostream>
#include <string.h>

int main()
{
    char s1[] = "hello";
    char s2[10];

    s2 = s1; //error
    //strcpy(s2,s1)사용해야한다
    if (s1 == s2)
    {
    } //무조건 틀리게 나온다.
    //주소를 비교하게되니깐
    //strcmp(s2,s1)==0 사용해야한다.
}
#endif

#include <iostream>
#include <string>
//cstring은 c의 헤더에서 가져온거다

int main()
{
    std::string s1 = "hello";
    std::string s2;

    s2 = s1;

    if (s1 == s2)
    {
    }

    std::string s3 = s1 + s2;
    std::cout << s3 << std::endl;

    //#include <string>과 같은게 사용이 가능해진다.
}

/*
정리
C언어에서 문자열
char* 또는 char배열 사용
문자열 전용 함수를 사용해야한다. strcmp,strcpy

C++에서는 string타입을 사용하자
문자열 처리가 정수형 변수처럼 직관적으로 사용가능
C언어의 const char*로의 변환이 필요하면 .c_str()을 사용
*/