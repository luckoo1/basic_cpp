//#######################################################################
int square(int a)
{
    return a * a;
}

double square(double a)
{
    return a * a;
}

int main()
{
    square(3);   //int니깐 알아서 int형으로 가고
    square(3.3); //double이니깐 알아서 double로 간다.
}

//타입만 빼고 똑같은데....
//중복이 생겨 불편하다는 생각이 들었다.

//#######################################################################

//함수를 만들어내는 틀

template <typename T>
T square(T a)
{
    return a * a;
}
//지금부터 나는 틀을 만들건데 그 틀은 type이 인자로 와야한다
//그 type를 T라고 부르겠다.

int main()
{
    //template의 인자는 <>안에 보낸다.
    //square라는 틀을 쓰는데 <>안에 버전이 필요하는걸 알 수 있다.
    square<int>(3);      //int square(int)함수 생성
    square<double>(3.3); //douvle square(double)함수 생성

    //기계어(assembly) 코드 내에는 square함수가 2개 있다.

    //아래와 같이 보내도 컴파일러가 알아서 type를 추론해준다.
    square(3);
    square(3.3);
}

/*정리
1.실제 함수가 아닌 함수를 만들어 내는 틀(template)
2.사용자가 템플릿을 사용하는 코드를 보고 컴파일러가 필요한 타입의 함수를 생성
3.템플릿 인자 표시는 typename또는 class로 한다.
template <class T>
T square(T a)
{
}
4.함수 뿐 아니라 구조체도 템플릿으로 만들 수 있다.
5.잘못 사용시 코드 메모리가 커질 수 있다(code bloat 현상)
*/

//#######################################################################

//아래와 같이 사용하면 p1.x가 double형이라서 곤란하다.
struct Point
{
    int x;
    int y;
};

int main()
{
    Point p1;
    p1.x = 3.3;
}

//#######################################################################

//아래와 같이 사용하면 p1.x가 int형이라서 곤란하다
//int가 속도가 더 빠를텐데 double을 써서 속도가 느려진다.
struct Point
{
    double x;
    double y;
};

int main()
{
    Point p1;
    p1.x = 3;
}

//#######################################################################

template <typename T>
struct Point
{
    T x;
    T y;
};

int main()
{
    //여기선 반드시 <>안에 type를 써줘야한다.
    Point<int> p1;
    p1.x = 3;
    p1.y = 4;

    Point<double> p2;
    p1.x = 3.4;
    p1.y = 7.1;
}
//위와 같이 사용하면
//결국 double과 int가 두개 만들어지니 코드 메모리는 커질 수 있다.