//대입 초기화
//생성자의 블록 안에서 초기화
class Point
{
    int x;
    int y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }
};

int main()
{
}
//초기화 리스트
//초기화
class Point
{
    int x;
    int y;

public:
    Point() : x(0), y(0)
    {
    }
};

int main()
{
}

//C++11부터 가능
//멤버 변수 선언시 초기화
//JAVA가 먼저 이렇게해서 따라함
class Point
{
    int x = 0;
    int y = 0;

public:
    Point()
    {
    }
};

int main()
{
}