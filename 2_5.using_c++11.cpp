#if 0
typedef int DWORD;
typedef void (*F)(int); //함수 포인터

int main()
{
    DWORD n;
    F f;
}
#endif

using DWORD = int;
using F = void (*)(int); //reture값이 void고 파라미터가 int인 함수 포인터

//template 별명만들고 싶을떄 사용

int main()
{
    DWORD n;
    F f;
}

//정리1
//typedef : 타입에 대해서 별칭(alias)를 만들 때 사용
//using : 타입뿐 아니라 template의 별칭(alias)도 만들수 있다.
