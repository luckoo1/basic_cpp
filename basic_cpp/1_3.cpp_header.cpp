//#######################################################################

void foo()
{
}

namespace Audio
{
    void init()
    {
    }
}

int main()
{
    Audio::init(); //1.Ok
    foo();         //2.Ok
    Audio::foo();  //foo를 전역변수이지 Audio안에 없으니깐 에러발생
}

//#######################################################################
void foo()
{
}

namespace Audio
{
    using ::foo; //전역 공간에 있는 foo를 Audio namespace로 가져오겠다.
    void init()
    {
    }
}

int main()
{
    Audio::init();
    foo();
    Audio::foo(); //문제없이 사용된다.
}

//#######################################################################
#include <stdio.h>

int main()
{
    printf("hello\n");
    std::printf("hello\n"); //error
}

#include <cstdio>
//c시절에 사용하던 std io header를 포함하겠다.

int main()
{
    printf("hello\n");
    std::printf("hello\n");
}

// ★
// C++은 모든 표준 라이브러리는 std이름공간 안에 있다.
// C표준 함수도 결국 C++표준의 일부이므로 std 이름 공간에 넣고 싶었다.

// <stdio.h>와 <cstdio> 파일의 차이점
// <stdio.h> : printf가 전역 공간에 있다.
// <cstdio> : printf(),std::printf()모두 사용이 가능하다.

// cstdio의 원리
// #include <stdio.h>
// //printf가 전역에 있음
// namespace std
// {
//     using ::printf;
// }

// 전역공간에 있는 printf를 std안에서도 쓰게 만들었다.
// stdio.h안에 모든 함수를 using으로 가지고 들어왔다.

// ★
// c++에서 c언어 헤더 사용하는 방법
// 기존의 c언어 헤더파일을 모두 계속 사용할 수 있다
// c언어 헤더에서 '.h'를 제고하고 앞에 'c'를 붙여서 사용한다.
// <string.h>=><cstring>
// <stdlib.h>=><cstdlib>
// <math.h>=><cmath>