#if 0
#include <stdio.h>


void init()
{
    printf("Audio init\n");
}

void init()
{
    printf("Video init\n");
}

void init()
{
    printf("System init\n");
}

int main()
{

}

//수많은 개발자가 개발하면서 함수가 충돌할수도 있다.
#endif

#if 0
#include <stdio.h>

namespace Audio
{
    void init()
    {
        printf("Audio init\n");
    }
}

namespace Video
{
    void init()
    {
        printf("Video init\n");
    }
}

//global namespace(전역공간) : namespace에 포함되어 있지 않은 공간
void init()
{
    printf("System init\n");
}

int main()
{
    init(); //global namespace
    Audio::init();
    Video::init();
}

//namespace의 장점
//프로그램의 기능별로 연관된 코드를 묶어서 관리할 수 있다.
//함수 또는 변수 등의 이름 충돌을 막을 수 있다.
#endif

#if 0
#include <stdio.h>

namespace Audio
{
    void init() { printf("Audio init"); }
    void reset() { printf("Audio reset"); }
}

int main()
{
    Audio::init();     //완전한 이름을 사용한 접근
    using Audio::init; //using 선언
                       //init함수만큼은 Auido를 쓰지않고 접근하게 해달라
    init();            //OK
    reset();           //Error
}
#endif

#if 0
#include <stdio.h>

namespace Audio
{
    void init() { printf("Audio init"); }
    void reset() { printf("Audio reset"); }
}

int main()
{
    using namespace Audio; //using 지시어
                           //Audio안에 있는 모든 것을 "Audio::"없이 사용
    init();
    reset();
}
#endif

#if 0
#include <stdio.h>

namespace Audio
{
    void init() { printf("Audio init"); }
    void reset() { printf("Audio reset"); }
}
using namespace Audio; //여기 사용해서 여기 밑에 오는 건 모두 "Audio::"생략 가능

int main()
{
    init();
    reset();
}
#endif

#include <stdio.h>

namespace Audio
{
    void init() { printf("Audio init"); }
    void reset() { printf("Audio reset"); }
}
using namespace Audio; //여기 사용해서 여기 밑에 오는 건 모두 "Audio::"생략 가능

void init() { printf("global init\n"); } //이렇게 사용이 또 되면

int main()
{
    init();   //error뜬다.
    ::init(); //"::"은 전역공간을 의미한다.
              //error안뜬다.
    reset();
}

// namespace안에 있는 요소를 접근하는 3가지 방법
// 1.qualified name(완전한 이름)을 사용한 접근
// 2.using declaration(선언)을 사용한 방법
// 3.using directive(지시어)를 사용한 방법

//선언과 지시어는 함수 안에 만들거나 밖에 만들 수 있다.
//선언과 지시어를 사용시 전역 공간에 동일 이름의 함수가 있으면 다시 이름 충돌이 발생한다
//※ global namespace에 접근하려면 ::을 사용한다.

//완전한 이름을 쓰는게 가장 안전한 코딩이다.

//아직 다루지 않은 namespace
//1.중첩된(nested) namespace
//2.unnamed namespace
//3.namespace와 다중파일
//4.인자 기반 탐색 (Argument Dependant Lookup)
//5.namespace 활용한 테크닉