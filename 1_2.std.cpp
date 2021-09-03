#if 0
//에러가 발생
#include <algorithm>

int main()
{
    int n = min(1, 2);
}
#endif

#if 0
#include <algorithm>

int main()
{
    int n = std::min(1, 2);
}
#endif

#if 0
//1. 이렇게 사용하거나
#include <algorithm>
using std::min;
int main()
{
    int n = min(1, 2);
}
#endif

#if 0
//2.std namespace 전체를 열었다.
//★C++의 모든 표준 라이브러리는 std 이름 공간안에 있다.
#include <algorithm>
using namespace std;
int main()
{
    int n = min(1, 2);
    int n2 = max(1, 2);
}
#endif

#if 0
#include <algorithm>
using namespace std;
//count가 모호한 기호라고 에러가 뜬다.
//std라는 namespace안에
//std::count()함수가 있다.
//컴파일러가 c++표준의 count인지 전역변수 count인지 컴파일러가 헷갈려하는 거다.
int count = 0;
int main()
{
    int n = min(1, 2);
    int n2 = max(1, 2);
    count = 20; //error가 뜬다.
}
#endif

#include <algorithm>
int count = 0;
int main()
{
    int n = std::min(1, 2);
    count = 20;
}
//문제없이 사용된다.

//★
//C++ 표준 라이브러리를 사용하는 3가지 방법
// 1.qualified name(완전한 이름)을 사용한 접근 => std::min(1,2)
// 2.using declaration(선언)을 사용한 방법 => using std::min
// 3.using directive(지시어)를 사용한 방법 => using namespace std;

//using namespace std;를 사용할 경우 이름 충돌에 주의해야한다.
//완전한 이름을 사용하는 것이 좋다.

//★
//표준라이브러리 헤더 파일 모양
//c언어 : 파일이름뒤에 .h를 붙인다. => <stdio.h>
//c++언어 : 파일이름뒤에 .h가 붙어 있지 않다. =><algorithm>
//사용자가 헤더를 만들 때는 .h를 붙이는것이 관례이다. =>myheader.h