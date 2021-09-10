#if 0
void setAlarm(int hour, int min, int sec)
{
}
int main()
{
    setAlarm(3, 4, 5);
    setAlarm(3, 0, 0);
    //정각에 알람주고 싶은데 0들을 쳐주기가 귀찮다
}
#endif

#if 0
void setAlarm(int hour, int min = 0, int sec = 0)
{
}
int main()
{
    setAlarm(3, 4, 5);
    setAlarm(3);
    //나머지 값이 2개가 저절로 0이된다.
    setAlarm(3, 2);
    //hour는 3 min은 2가 되고 sec는 저절로 0이 된다.
}
#endif
//주의해야할점 2가지가 있다.
#if 0
void setAlarm1(int hour, int min = 0, int sec)
{
    //이렇게 하면 error다
    //젤 오른쪽부터 default 설정 해야한다.
}
void setAlarm2(int hour = 0, int min, int sec = 0)
{
    //이렇게 하면 error다
    //젤 오른쪽부터 차례대로 default 설정 해야한다.
}
int main()
{
    setAlarm1(3, 4);
}
#endif

#if 0
void setAlarm(int hour, int min = 0, int sec = 0); //선언부 선언

int main()
{
    setAlarm(3, 2);
}
//선언부에서 default값 설정했는데
//또 바꾸려한다는 error를 발생시킨다.
//기본인수재정의 에러
void setAlarm(int hour, int min = 0, int sec = 0)
{
}
#endif

#if 0
//아래와 같이 하면 문제가 없다
//하지만 문제가 발생할 수 있다.
void setAlarm(int hour, int min, int sec);
int main()
{
    setAlarm(3, 2, 4);
}

void setAlarm(int hour, int min = 0, int sec = 0)
{
}
#endif

#if 0
void setAlarm(int hour, int min, int sec);

int main()
{
    setAlarm(3, 2);
    //함수를 호출할때 선언부를 보고 호출한다.
    //인자를 2개밖에 안줬네??
    //컴파일 에러 발생
}

void setAlarm(int hour, int min = 0, int sec = 0)
{
}
#endif
//default parameter는 선언부에 선언해줘야한다.
void setAlarm(int hour, int min = 0, int sec = 0);

int main()
{
    setAlarm(3, 2);
}
//아래와 같이 주석으로 가독성을 고려해줌
void setAlarm(int hour, int min /*=0*/, int sec /*=0*/)
{
}

/*
결론
함수의 마지막 파라미터부터 차례대로 지정해야한다.
함수를 선언과 구현으로 분리할 경우 함수 선언에만 디폴트 값을 표시해야한다.
*/
