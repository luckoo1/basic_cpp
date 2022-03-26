//그림필기
#if 0

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BaseMenu
{
    string title;

public:
    BaseMenu(string s) : title(s)
    {
    }
    string getTitle() const
    {
        return title;
    }
    virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
    int id;

public:
    MenuItem(int n) : id(n)
    {
    }
    virtual void command()
    {
        cout << getTitle() << endl;
        getchar();
    }
};
int main()
{
    MenuItem m(11);
}

/*
에러발생
파생클래스 만들때는 기반클래스에서 기본생성자가 필요하다
MenuItem(int n) : id(n)에서
컴파일러단계에서
MenuItem(int n) : BaseMenu(), id(n)
자동으로 생성된다.
*/
#endif

#if 0
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BaseMenu
{
    string title;

public:
    BaseMenu(string s) : title(s)
    {
    }
    string getTitle() const
    {
        return title;
    }
    virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
    int id;

public:
    MenuItem(string s, int n) : BaseMenu(s), id(n) //BaseMenu(s) 명시해줬다.
    {
    }
    virtual void command()
    {
        cout << getTitle() << endl;
        getchar();
    }
};
int main()
{
    MenuItem m("sound", 11);
}

//BaseMenu()으로 생기는걸 BaseMenu(s)를 명목적으로 적어 주었다.
//"11_3.상속에서의생성자호출순서.cpp"참조해라
#endif

#if 0
//이제 popupmenu만들어보자

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BaseMenu
{
    string title;

public:
    BaseMenu(string s) : title(s)
    {
    }

    string getTitle() const
    {
        return title;
    }

    virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
    int id;

public:
    MenuItem(string s, int n) : BaseMenu(s), id(n)
    {
    }

    virtual void command()
    {
        cout << getTitle() << endl;
        getchar();
    }
};

//3. 1번과 2번에 BaseMenu 포인터를 썼다는걸 인지하자
class PopupMenu : public BaseMenu
{
    vector<BaseMenu *> v; //1.BaseMenu넣게했다.

public:
    PopupMenu(string s) : BaseMenu(s) {}

    void addMenu(BaseMenu *p) //2
    {
        v.push_back(p);
    }

    virtual void command()
    {
        while (1)
        {
            system("cls");

            int sz = v.size();

            //4.메뉴출력
            for (int i = 0; i < sz; i++)
            {
                cout << i + 1 << ". " << v[i]->getTitle() << endl;
            }
            cout << sz + 1 << ". Go to top menu" << endl; //상위메뉴로

            //5.메뉴선택
            int cmd;
            cout << "Select menu >>";
            cin >> cmd;

            //7
            if (cmd < 1 || cmd > sz + 1) //잘못된입력
                continue;
            if (cmd == sz + 1) //상위메뉴를 선택하면 break
                break;

            //6.선택된 메뉴 실행
            v[cmd - 1]->command();
            //여기서 선택되는게  MenuItem인지 PopupMenu인지 판단해봐야한다
            //위와같이 적으면 알아서 조사해준다.
            //여기가 핵심이다.
        }
    }
};

int main()
{
}
#endif

#if 0
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BaseMenu
{
    string title;

public:
    BaseMenu(string s) : title(s) {}

    string getTitle() const { return title; }

    virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
    int id;

public:
    MenuItem(string s, int n) : BaseMenu(s), id(n) {}

    virtual void command()
    {
        cout << getTitle() << endl;
        getchar();
    }
};

class PopupMenu : public BaseMenu
{
    vector<BaseMenu *> v;

public:
    PopupMenu(string s) : BaseMenu(s) {}

    void addMenu(BaseMenu *p) { v.push_back(p); }

    virtual void command()
    {
        while (1)
        {
            system("cls");

            int sz = v.size();

            for (int i = 0; i < sz; i++)
            {
                cout << i + 1 << ". " << v[i]->getTitle() << endl;
            }

            cout << sz + 1 << ". Go to Upper menu" << endl;

            int cmd;
            cout << "Select menu >>";
            cin >> cmd;

            if (cmd < 1 || cmd > sz + 1)
                continue;
            if (cmd == sz + 1)
                break;
            v[cmd - 1]->command();
        }
    }
};

int main()
{
    PopupMenu *menubar = new PopupMenu("MenuBar");

    PopupMenu *pm1 = new PopupMenu("Display");
    PopupMenu *pm2 = new PopupMenu("Sound");
    MenuItem *m1 = new MenuItem("Information", 11);

    menubar->addMenu(pm1);
    menubar->addMenu(pm2);
    menubar->addMenu(m1);
    //그림필기2

    pm1->addMenu(new MenuItem("Resolution", 21)); //해상도
    pm1->addMenu(new MenuItem("Contrast", 22));   //명암

    pm2->addMenu(new MenuItem("Volume", 31)); //음량
    //그림필기3

    //시작하려면
    menubar->command();
    //menubar를 누른것과 같다.
}

/*
구조에 대한 부분은 재귀함수 즉,  stack구조를 생각하자
*/

/*
Composite Patter
객체들을 트리 구조로 구성하여 부분과 전체를 나타내는 계층구조로 만들 수 있다.
개별객체와 복합객체를 구별하지 않고 동일한 방법으로 다룰 수 있다.
*/
#endif

#if 0
//하위 메뉴를 얻는 getSubMenu()추가해보자
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BaseMenu
{
    string title;

public:
    BaseMenu(string s) : title(s) {}

    string getTitle() const { return title; }

    virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
    int id;

public:
    MenuItem(string s, int n) : BaseMenu(s), id(n) {}

    virtual void command()
    {
        cout << getTitle() << endl;
        getchar();
    }
};

class PopupMenu : public BaseMenu
{
    vector<BaseMenu *> v;

public:
    PopupMenu(string s) : BaseMenu(s) {}

    void addMenu(BaseMenu *p) { v.push_back(p); }

    virtual void command()
    {
        while (1)
        {
            system("cls");

            int sz = v.size();

            for (int i = 0; i < sz; i++)
            {
                cout << i + 1 << ". " << v[i]->getTitle() << endl;
            }

            cout << sz + 1 << ". Go to Upper menu" << endl;

            int cmd;
            cout << "Select menu >>";
            cin >> cmd;

            if (cmd < 1 || cmd > sz + 1)
                continue;
            if (cmd == sz + 1)
                break;
            v[cmd - 1]->command();
        }
    }
    /*
    2.
    ?부분에 뭐가 들어가야할까
    ? getSubMenu(int idx)
    {
        return v[idx];
    }
    */
    BaseMenu *getSubMenu(int idx)
    {
        return v[idx];
    }
};

int main()
{
    PopupMenu *menubar = new PopupMenu("MenuBar");

    PopupMenu *pm1 = new PopupMenu("Display");
    PopupMenu *pm2 = new PopupMenu("Sound");
    MenuItem *m1 = new MenuItem("Information", 11);

    menubar->addMenu(pm1);
    menubar->addMenu(pm2);
    menubar->addMenu(m1);

    pm1->addMenu(new MenuItem("Resolution", 21)); //해상도
    pm1->addMenu(new MenuItem("Contrast", 22));   //명암

    pm2->addMenu(new MenuItem("Volume", 31)); //음량

    menubar->getSubMenu(1);
    /*
    1.
    menubar안에는 Display,Sound,Information가 들어있는데
    getSubMenu(1)을 통해서 Sound를 호출해보자
    */

    menubar->command();
}
#endif

#if 0
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BaseMenu
{
    string title;

public:
    BaseMenu(string s) : title(s) {}

    string getTitle() const { return title; }
    virtual BaseMenu *getSubMenu(int idx) //2. 추가했다
    {
        return 0; //실패 return
    }
    /*
    그런데 문제는 이 getSubMenu 함수는 PopupMenu에만 필요하지
    MenuItem에서는 필요없다.

    그래서
    virtual BaseMenu *getSubMenu(int idx) = 0;으로 하지 않았다.
    실패를 return하게 했다.
    */

    virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
    int id;

public:
    MenuItem(string s, int n) : BaseMenu(s), id(n) {}

    virtual void command()
    {
        cout << getTitle() << endl;
        getchar();
    }
};

class PopupMenu : public BaseMenu
{
    vector<BaseMenu *> v;

public:
    PopupMenu(string s) : BaseMenu(s) {}

    void addMenu(BaseMenu *p) { v.push_back(p); }

    virtual void command()
    {
        while (1)
        {
            system("cls");

            int sz = v.size();

            for (int i = 0; i < sz; i++)
            {
                cout << i + 1 << ". " << v[i]->getTitle() << endl;
            }

            cout << sz + 1 << ". Go to Upper menu" << endl;

            int cmd;
            cout << "Select menu >>";
            cin >> cmd;

            if (cmd < 1 || cmd > sz + 1)
                continue;
            if (cmd == sz + 1)
                break;
            v[cmd - 1]->command();
        }
    }

    BaseMenu *getSubMenu(int idx)
    {
        return v[idx];
    }
};

int main()
{
    PopupMenu *menubar = new PopupMenu("MenuBar");

    PopupMenu *pm1 = new PopupMenu("Display");
    PopupMenu *pm2 = new PopupMenu("Sound");
    MenuItem *m1 = new MenuItem("Information", 11);

    menubar->addMenu(pm1);
    menubar->addMenu(pm2);
    menubar->addMenu(m1);

    pm1->addMenu(new MenuItem("Resolution", 21)); //해상도
    pm1->addMenu(new MenuItem("Contrast", 22));   //명암

    pm2->addMenu(new MenuItem("Volume", 31)); //음량

    BaseMenu *p = menubar->getSubMenu(1)->getSubMenu(0);
    /*
    1.
    menubar->getSubMenu(1);을 통해서 소리설정에 들어왔는데
    menubar->getSubMenu(1)->getSubMenu(0);을 통해서
    소리설정 안에있는 음량조절을 불러보자
    이건 error뜬다

    menubar->getSubMenu(1)에서
    BaseMenu *getSubMenu(int idx)
        {
            return v[idx];
        }
    를 통해서 BaseMenu타입으로 리턴을 받았는데
    BaseMenu타입에는 getSubMenu가 없으니깐 error

    결국 getSubMenu()를 파생클래스에만 넣을 것인가? 기반클래스에도 넣을 것인가?

    기반클래스에 추가를 했다.
    */

    menubar->command();
}
#endif

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BaseMenu
{
    string title;

public:
    BaseMenu(string s) : title(s) {}

    string getTitle() const { return title; }

    virtual BaseMenu *getSubMenu(int idx) { return 0; } //실패 return

    void addMenu(BaseMenu *p) //2.그래서 여기도 추가했다.
    {
        throw "unsupported function.."; //실패 던지기
    }

    virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
    int id;

public:
    MenuItem(string s, int n) : BaseMenu(s), id(n) {}

    virtual void command()
    {
        cout << getTitle() << endl;
        getchar();
    }
};

class PopupMenu : public BaseMenu
{
    vector<BaseMenu *> v;

public:
    PopupMenu(string s) : BaseMenu(s) {}

    void addMenu(BaseMenu *p) { v.push_back(p); }

    virtual void command()
    {
        while (1)
        {
            system("cls");

            int sz = v.size();

            for (int i = 0; i < sz; i++)
            {
                cout << i + 1 << ". " << v[i]->getTitle() << endl;
            }

            cout << sz + 1 << ". Go to Upper menu" << endl;

            int cmd;
            cout << "Select menu >>";
            cin >> cmd;

            if (cmd < 1 || cmd > sz + 1)
                continue;
            if (cmd == sz + 1)
                break;
            v[cmd - 1]->command();
        }
    }

    BaseMenu *getSubMenu(int idx)
    {
        return v[idx];
    }
};

int main()
{
    PopupMenu *menubar = new PopupMenu("MenuBar");

    PopupMenu *pm1 = new PopupMenu("Display");
    PopupMenu *pm2 = new PopupMenu("Sound");
    MenuItem *m1 = new MenuItem("Information", 11);

    menubar->addMenu(pm1);
    menubar->addMenu(pm2);
    menubar->addMenu(m1);

    pm1->addMenu(new MenuItem("Resolution", 21)); //해상도
    pm1->addMenu(new MenuItem("Contrast", 22));   //명암

    pm2->addMenu(new MenuItem("Volume", 31)); //음량

    BaseMenu *p = menubar->getSubMenu(1)->getSubMenu(0);

    menubar->getSubMenu(1)->addMenu(new MenuItem("AA", 100));
    /*
    1.
    error뜬다
    이유는  menubar->getSubMenu(1)에서 나온 type가 BaseManu이기 때문이다.
    BaseManu안에 addMenu가 없다.
    
    어기서도 기반클래스에 추가를 했다.
    */
    menubar->command();
}

/*
3.
기반클래스에서
virtual BaseMenu *getSubMenu(int idx) ///실패 return
    { 
        return 0; 
    }

void addMenu(BaseMenu *p)
    {
        throw "unsupported function.."; //실패 던지기
    }

이 두개의 함수는 PopupMenu에만 있어도 되지만 기반에 넣었다
이유는 개별객체와 복합객체를 구별을 두지 않고 사용하기위해서다.
*/

//그림필기4(Diagram)