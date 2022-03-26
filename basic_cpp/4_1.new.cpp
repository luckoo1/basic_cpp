
#include <iostream>
#include <cstdlib>

int main()
{
    int cnt = 0;

    std::cout << "the number of student ?";
    std::cin >> cnt;
    //학생수 만큼의 메모리 할당이 필요

    int jumsu[cnt]; //g++은 가능
                    //vc++ error;
}
//#######################################################################

#include <iostream>
#include <cstdlib>

int main()
{
    int cnt = 0;

    std::cout << "학생수 ?";
    std::cin >> cnt;

    //동적 메모리 할당했다.
    int *jumsu = (int *)malloc(sizeof(int) * cnt);
    free(jumsu);
}
/*
정리
동적메모리 할당이 필요한 이유
1.실행 시간에 결정된 크기 만큼의 메모리를 할당하고 싶을때
2.자동으로 메모리를 해지하지 말고, 사용자가 원하는 때에 메모리를 해지하고 싶을때
3.c언어에서는 malloc을 사용했다.
4.malloc 사용시 주소를 원하는 타입으로 캐스팅 해야 한다.
*/
//#######################################################################

#include <iostream>
#include <cstdlib>

int main()
{
    //C언어 style
    int *p1 = (int *)malloc(sizeof(int) * 10);
    free(p1);

    //C++ style
    int *p2 = new int; //int 한개 할당. 4바이트
    delete p2;

    int *p3 = new int[10]; //int 10개 할당. 40바이트
    delete[] p3;           //배열버전 delete로 해지

    //undefined(미정의 동작)
    //C++표준문서에서는 이렇게 사용하지 마라고 했다.
    //delete p3;
    //어떤 오류가 뜨는지 알수 없다.
    //컴파일러마다 다르다.
}

/*정리
new로 할당하고 delete로 해지한다
원하는 타입으로 주소를 리턴하므로 캐스팅이 필요없다.
배열로 할당한 경우 delete[]로 해지한다
malloc은 생성자를 호출하지 않지만 new는 생성자를 호출한다(추후 공부)
*/