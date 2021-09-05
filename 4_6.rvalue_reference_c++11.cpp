int main()
{
    int v1 = 0;
    int v2 = 0;

    v2 = 10; //ok
    10 = v1; //error
    v2 = v1; //ok

    /*
    정리
    1.lvalue vs rvalue
    rvalue : 등호(=)의 오른쪽에만 올 수 있는 것(10)
    lvalue : 등호(=)의 왼쪽과 오른쪽 모두 올 수 있는 것(v1)
    */

    /////////////////////////////////////////////////////////////
    //4.
    //c++11나오고 rvalue reference가 생기면서
    //lvalue referenc라고 부르기로 했다.

    //1.
    int &r1 = v1; //ok
    int &r2 = 10; //error
    //참조변수에서
    //10같은 rvalue를 적는 것이 안된다.
    //참조할때 값이 고정된거 해야해서 그런가...?

    //2.
    const int &r3 = v1; //ok
    const int &r4 = 10; //ok
    //const 붙이면 lvalue도 rvalue도 가리킬 수 있다.

    /*C++창시자의 인터뷰
    int &r2 = 10;
    10은 못바꾸는거 아니냐 
    10을 바꾸겟다고 int& 로 가리키는건 잘못된거다
    const int &r4는 상수로 했으니깐
    못바꾸겠다고 약속한거 아니냐
    이건 되게했다.
    */

    //3.
    //rvalue reference
    //rvalue만 가리키게 했다.
    int &&r5 = v1; //lvalue가리킬때 에러뜬다.
    int &&r6 = 10;
}

/*
정리
1. lvalue reference는 lvalue만 가리킬 수 있다.
2. const lvalue reference는 lvalue와 rvalue모두 가리킬 수 있다.
3. rvalue reference : rvalue만 가리킬 수 있다 (C++11)
*/

/*
move semantics와 perfect forwarding에서 rvalue의 필요성에대해 느낄수 있다(추후 공부)
*/