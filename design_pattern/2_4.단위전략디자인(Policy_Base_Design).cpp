#if 0
#include <iostream>
using namespace std;

template <typename T>
class List
{
public:
    void push_front(const T &a)
    {
        //3.사용자의 편의를 위해 여기서 Lock과 Unlock을 하면 편하지 않을까
        Lock();
        //.....
        Unlock();
    }
};

List<int> s; //1.전역변수로 만들면 멀티스레드에 안전하지 않다.

int main()
{
    //2.안전을 위해서 여기서 Lock
    s.push_front(10);
    //여기서 Unlock하면 될텐데
}
/*
4.그런데 만약 사용자가 Lock과 Unlock이 필요없다고 하면 성능의 저하가 발생
동기화 하는 코드(Lock과 Unlock)을 void push_front()안에 넣을래 뺄래?
사용자가 선택하게 하는게 Best아닐까?
*/

/*
List에서 변하는 것과 변하지 않는 것
list의 전방 삽입 알고리즘은 변하지 않지만 동기화 정책은 교체 가능하다
void push_front(const T &a)
{
    Lock();
    //.....
    Unlock();
}
Lock과 Unlock은 교체 가능하지만 "//....."부분은 변하지 않는다.

변하는 것을 분리하는 방법 2가지 사전에 공부함
변하는 것을 가상함수로
변하지는 것을 다른 클래스로

생각해보자!
동기화 정책은 다른클래스에도 필요하지 않을까???
동기화 정책을 전략 패턴으로 구현하자
*/

#endif

#if 0
#include <iostream>
using namespace std;

struct ISync //1.전략의 Interface
{
    virtual void Lock() = 0;
    virtual void UnLock() = 0;
    virtual ~ISync() {}
};

template <typename T>
class List
{
    ISync *pSync = 0; //2

public:
    void setSync(ISync *p) { pSync = p; } //3

    void push_front(const T &a) //4.동기화내용 추가
    {
        if (pSync != 0) //5.pSync에 내용이 있으면 동기화 진행
        {
            pSync->Lock();
        }
        //.....
        if (pSync != 0)
        {
            pSync->UnsLock();
        }
    }
};

class MutexLock : public ISync //6
{
    virtual void Lock() {}
    virtual void UnLock() {}
};

List<int> s;

int main()
{
    MutexLock m;
    s.setSync(&m);
    //7.이렇게 하면 이제 s는 동기화를 한다
    s.push_front(10);
}

/*
8.
struct ISync 
{
    virtual void Lock() = 0;
    virtual void UnLock() = 0;
    virtual ~ISync() {}
};
가상함수는 Inline치환이 되지 않아 성능저하가 있다.
*/
#endif

#if 0
#include <iostream>
using namespace std;

template <typename T, typename ThreadModel> //2.template인자 추가
class List
{
    ThreadModel tm; //3.동기화 정책을 담은 class다

public:
    void push_front(const T &a)
    {
        tm.Lock();
        //......
        tm.UnLock();
    }
};
//1.인터페이스 삭제하고 수정했다.
class MutexLock
{
public:
    inline void Lock() { cout << "Mutex lock" << endl; }
    inline void UnLock() { cout << "Mutex Unlock" << endl; }
};

class NoLock
{
public:
    inline void Lock() {}
    inline void UnLock() {}
};

//4.아래와 같이 정책을 같이 보낸다.
List<int, MutexLock> s1;
List<int, NoLock> s2; //동기화 안하는 int담은 List

/*
5.
inline을 할때 치환한다
그런데
class NoLock
{
    inline void Lock() {}
    inline void UnLock() {}
};
이 부분에서는 Lock()과 UnLock()부분에서 아무것도 안하니깐 

void push_front(const T &a)
{
    tm.Lock();
    tm.Unlock();
}
최적화 하면서     
tm.Lock();
tm.Unlock();
부분을 지운다.
*/

int main()
{
    s1.push_front(10);
    //s2.push_front(10);
}
#endif

#include <iostream>
using namespace std;

template <typename T, typename ThreadModel = NoLock> //1.디폴트를 주었다.
class List
{
    ThreadModel tm;

public:
    void push_front(const T &a)
    {
        tm.Lock();
        //......
        tm.UnLock();
    }
};

class MutexLock
{
public:
    inline void Lock() { cout << "Mutex lock" << endl; }
    inline void UnLock() { cout << "Mutex Unlock" << endl; }
};

class NoLock
{
public:
    inline void Lock() {}
    inline void UnLock() {}
};

List<int, MutexLock> s1;
List<int, NoLock> s2;
List<int> s3; //디폴트인 Nolock으로 실행된다.

int main()
{
    s1.push_front(10);
}

/*
단위전략디자인(Policy_Base_Design)
template 인자를 사용해서 정책 클래스를 교체하는 기술
C++기반 라이브러리에서 많이 볼수 있는 디자인 기술
"Modern C++ Design"서적 참고
*/

/*
전략패턴과 단위전략디자인의 비교

-속도
전략패턴은 가상함수기반이라 느리다.
단위전략디자인은 인라인 치환이 가능해서 빠르다

-유연성
전략패턴은 실행시간에 교체가 가능하다(예제에서는 setSync를 통해서 정책을 바꾸는거)
단위전략디자인은 컴파일 시간 정책교체해야한다.(List<int, MutexLock> s1;)
실행시간에 교체 할 수 없다.

단위전략디자인의 단점
전략패턴은 "class MutexLock : public ISync"을 보면
ISync에서 Lock()과 UnLock()이 있으니깐 그걸보고 코드가 구현가능하다
하지만 단위전략디자인은 상속된게 없으니 무슨 함수를 넣어야할지 알 수가 없어서 문서화해야한다.
*/