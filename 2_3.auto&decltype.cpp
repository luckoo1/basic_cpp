#if 0
int main()
{
    int x[3] = {1, 2, 3};

    int n1 = x[0];
}
//이렇게 사용했다가
#endif
#if 0
int main()
{
    double x[3] = {1, 2, 3}; //이게 double로 바뀌면

    int n1 = x[0]; //여기서 문제가 생긴다.
    //한곳이 바뀌면서 여러곳을 바꿔야하는 경우가 올수가 있다.
}

#endif

int main()
{
    double x[3] = {1, 2, 3};

    auto n1 = x[0]; //auto사용
    //우변의 type로 좌변의 type을 결정
    //실행시간이 아닌 컴파일 시간에 결정한다.

    auto n2; //초기화 안하면 error

    decltype(n1) d1 = n1;
    //괄호안에 있는 것과 동일한 type로 만들어 달라
    //d1이 double로 결정된다.
    decltype(n1) d2; //auto하고 다르게 초기값이 없어도 된다.

    decltype(x[0]) d3; //error(추후 배울거다)
}

//★정리1
//우변의 수식의 결과를 가지고 좌변의 타입을 결정
//반드시 초기값이 필요
//컴파일 시간에 타입을 결장하므로 실행 시간의 성능 저하 없음

//decltype(n1) d2;
//()안에 있는 변수의 타입을 조사
//초기값이 없어도 된다.