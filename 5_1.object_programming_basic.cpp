#if 0
//복소수 2개를 더하는 함수를 만들고 싶다.
? Add(int xr, int xi, int yr, int yi)
{
}
//실수부와 허수부를 나눠야해서 2개의 리턴값이 필요하다.
//?부분에 뭐써야하냐...
int main()
{
    int ar = 1, ai = 1;
    int br = 2, bi = 2;
    Add(ar, ai, br, bi);
}
#endif

#if 0
//여러 방법이 있겠지만 이 방법을 써보자
void Add(int xr, int xi, int yr, int yi, //in parameter
         int *sr, int *si)               //out parameter
{
}


int main()
{
    int ar = 1, ai = 1;
    int br = 2, bi = 2;
    int sr, si;
    Add(ar, ai, br, bi, &sr, &si);
}


//읽기 좋지않고... 복잡하고...불편해보이고..
//6분가량 그림 필기


/*
프로그램에서 필요한 타입을 먼저 설계한다
c언어의 구조체를 사용하면 새로운 타입을 만들 수 있다.
*/
#endif

#if 0
//구조체 만들어서 복소수라는 type를 만들어보자!!


struct Complex
{
    int re;
    int im;
};


Complex Add(Complex c1, Complex c2)
{
    Complex temp;
    temp.re = c1.re + c2.re;
    temp.im = c1.im + c1.re;
    return temp;
}


int main()
{
    Complex c1 = {1, 2};
    Complex c2 = {2, 2};


    Complex t = Add(c1, c2);
}
#endif

#if 0
struct Complex
{
    int re;
    int im;
};


//성능향상을 위해서 const참조를 썼다.
Complex Add(const Complex &c1, const Complex &c2)
{
    Complex temp;
    temp.re = c1.re + c2.re;
    temp.im = c1.im + c1.re;
    return temp;
}


int main()
{
    Complex c1 = {1, 2};
    Complex c2 = {2, 2};


    Complex t = Add(c1, c2);
}


//구조체를 써서 새로운 type를 만들어서 가독성을 높혔다.
//C의 구조체의 단점은 data만 포함할 수 있다.
#endif

#if 0
struct Complex
{
    int re;
    int im;
    //성능향상을 위해서 const참조를 썼다.
    Complex Add(const Complex &c1, const Complex &c2)
    {
        Complex temp;
        temp.re = c1.re + c2.re;
        temp.im = c1.im + c1.re;
        return temp;
    }
};
//이런식으로 구조체에 함수를 넣을수 없다.


int main()
{
    Complex c1 = {1, 2};
    Complex c2 = {2, 2};


    Complex t = Add(c1, c2);
}
//C++의 구조체는 데이터 뿐 아니라 함수도 포함할 수 있다.
#endif
