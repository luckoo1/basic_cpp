#if 0
/*
모든함수를 객체로 하고싶다!
그런데 C/C++ main은 일반함수로 해야한다.

특정분야의 프로그램은 전체적인 흐름이 항상 유사하다

main함수에 전체적인 흐름을 담아서 라이브러리 내부에 감추자
*/

#include <iostream>
using namespace std;

class CWinApp; //1. 클래스 전방 선언
//"CWinApp *g_app"를 사용해야하는데
//class CWinApp는 뒤에서 구현되었으니 전방선언해준거다.

CWinApp *g_app = 0;

class CWinApp
{
public:
    CWinApp() { g_app = this; }
    virtual bool InitInstance() { return false; }
    virtual int ExitInstance() { return false; }
    virtual int Run() { return 0; }
};

int main()
{
    /*
    전체적인 흐름을 잡아둠
    g_app->InitInstance();가 true면
    g_app->Run();하고
    아니면 ExitInstance();한다
    */
    if (g_app->InitInstance() == true)
    {
        g_app->Run();
    }
    g_app->ExitInstance();
}

//----------------------------------------
/*
아래부터 라이브러리 사용자의 코드
1.CWinApp의 파생클래스를 만들어야한다.
2.사용자 클래스를 전역객체 생성
*/

class MyApp : public CWinApp
{
public:
    virtual bool InitInstance()
    {
        cout << "Initialization" << endl;
        return true;
    }
};

MyApp theApp;

/*
1.
전역변수 생성자가 main함수보다 먼저 실행된다
기반클래스 생성자(CWinApp)가 호출된다.

CWinApp() { g_app = this; }호출되면서
g_app에 자기의 주소를 보관했다.
즉 theApp의 주소를 라이브러리 내부에서 알고 있다.

2.
main함수가 호출된다.
if (g_app->InitInstance() == true)
    {
        g_app->Run();
    }
이렇게 되는데
g_app가 theApp의 주소를 담고 있으니깐
class MyApp : public CWinApp
{
public:
    virtual bool InitInstance()
    {
        cout << "Initialization" << endl;
        return true;
    }
};
호출된다.

그럼 true를 return한다

true를 리턴했으므로
if (g_app->InitInstance() == true)
{
    g_app->Run();
}
Run을 실행
*/
#endif

#include <iostream>
using namespace std;

class CWinApp;
CWinApp *g_app = 0;

class CWinApp
{
public:
    CWinApp() { g_app = this; }
    virtual bool InitInstance() { return false; }
    virtual int ExitInstance() { return false; }
    virtual int Run() { return 0; }
};

int main()
{
    if (g_app->InitInstance() == true)
    {
        g_app->Run();
    }
    g_app->ExitInstance();
}
//----------------------------------------
//아래부터 라이브러리 사용자의 코드

class MyApp : public CWinApp
{
public:
    virtual bool InitInstance()
    {
        cout << "Initialization" << endl;
        return true;
    }

    virtual int ExitInstance() //2.여기를 추가함
    {
        cout << "Something to do" << endl;
        cout << "Finish" << endl;
        return 0;
    }
};

MyApp theApp;

/*
1.
만약 사용자가 프로그램이 종료되기직전에 할일이 있다고 생각을하면
virtual int ExitInstance()를 재정의하면 된다.
*/

/*
3.
그럼 이 라이브러리 사용자는
CWinApp의 파생클래스를 만들고
virtual bool InitInstance() 재정의하고 초기화 할거 해라
virtual int ExitInstance()에서 하고싶은 작업을 해라
그리고 MyApp theApp;와 같은 전역객체를 만들어라고 설명을 듣게된다.
그러면 라이브러리 사용자는 main함수가 없게 되네
라이브러리 안에 갇혀있으니깐!
*/

/*
4.
application의 전체적인 흐름을 라이브러리가 가지고있는것들을
application framework라고 부른다.
framework 내부구조를 잘 알고 framework에 끼워 맞추듯이 코딩하는거다.
*/

/*
5.
원래는 아래와 같이 사용해서 template method의 전형적인 모양으로 사용하고 싶은데
main이 멤버함수로 올수 없으니 밖으로 빼는거다.

class CWinApp;
CWinApp *g_app = 0;

class CWinApp
{
public:
    CWinApp() { g_app = this; }
    virtual bool InitInstance() { return false; }
    virtual int ExitInstance() { return false; }
    virtual int Run() { return 0; }

    if (g_app->InitInstance() == true)
    {
        g_app->Run();
    }
    g_app->ExitInstance();
};
*/

/*
6.
main함수에 전체적인 흐름을 담아서 라이브러리 내부에 감추자
template method기반의
Application Framework
ex)MFC,QT,WxWidget,IOS,Android등
*/