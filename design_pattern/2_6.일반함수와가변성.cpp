#if 0
#include <iostream>
#include <algorithm>
using namespace std;

void Sort(int *x, int sz)
{
    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            if (x[i] > x[j]) //Sort의 정책을 바꾸려면 라이브러리 내부코드를 바꿔야한다.
            {
                swap(x[i], x[j]);
            }
        }
    }
}

int main()
{
    int x[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    Sort(x, 10);
    for (auto n : x)
    {
        cout << n << ", ";
    }
}
/*
멤버함수에서 변하는것은 가상함수로 분리하거나 다른클래스로 분리했다

멤버가 아닌 일반함수에서 변하는 것은?
변해야 하는 것(정책)을 함수인자화
*/
#endif

#if 0
#include <iostream>
#include <algorithm>
using namespace std;

void Sort(int *x, int sz, bool (*cmp)(int, int)) //1.함수포인터 추가
{
    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            if (cmp(x[i], x[j])) //여기에서 함수포인터를 받음
            {
                swap(x[i], x[j]);
            }
        }
    }
}

//2.정책추가
bool cmp1(int a, int b) { return a < b; }
bool cmp2(int a, int b) { return a > b; }

int main()
{
    int x[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    Sort(x, 10, &cmp1); //3.정책을 넣어서 보냄
    for (auto n : x)
    {
        cout << n << ", ";
    }
}
//이미 C언어 표준에 qsort()가 있다.
#endif

#if 0
#include <iostream>
#include <algorithm>
using namespace std;

void Sort(int *x, int sz, bool (*cmp)(int, int)) //2.여기는 유지해도 된다.
{
    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            if (cmp(x[i], x[j]))
            {
                swap(x[i], x[j]);
            }
        }
    }
}

int main()
{
    int x[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    Sort(x, 10, [](int a, int b)
         { return a < b; }); //1.람다표현식
    for (auto n : x)
    {
        cout << n << ", ";
    }
}
//3.람다표현식을 사용하면 " if (cmp(x[i], x[j]))" 인라인 치환이 안된다(C++중급해서 배움)
#endif

#include <iostream>
#include <algorithm>
using namespace std;

//람다 표현식을 template를 사용해서 받아주면 inline치환이 된다.
//성능향상 가능
template <typename T>
void Sort(int *x, int sz, T cmp)
{
    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            if (cmp(x[i], x[j]))
            {
                swap(x[i], x[j]);
            }
        }
    }
}

int main()
{
    int x[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    Sort(x, 10, [](int a, int b)
         { return a < b; });
    for (auto n : x)
    {
        cout << n << ", ";
    }
}

/*
함수인자로 정책을 담은 코드를 전달하는 방법
-함수포인터
-함수객체,람다표현식을 전달하고 템플릿으로 받는다

-함수 포인터
장점 : 코드 메모리가 증가하지 않는다
단점 : 인라인 치환이 안됨
-함수객체,람다표현식
장점 : 인라인 치환
단점 : 코드메모리가 증가(cmp T가 여러가지 타입으로 보내지면 만들어야할 기계어코드도 많아지니깐)
*/