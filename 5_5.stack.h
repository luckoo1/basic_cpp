class Stack
{
private:
    int *buf;
    int idx;

public:
    Stack(int sz = 10);
    ~Stack();
    void push(int n);
    int pop();
};
//#######################################################################

/*
private안에 있는건 접근할수도 없다.
사용자입장에서는 함수만 중요하지 안에 뭐가있는지는 안중요하다.
pop이랑 push만 알면되지 내부적으로 data를 어떻게 쓸건지는 안중요하다.
*/

class Stack
{
public:
    Stack(int sz = 10);
    ~Stack();
    void push(int n);
    int pop();

private: //코딩관례상 data를 아래에 두는 경우가 많다.
    int *buf;
    int idx;
};
//일반사람들은 함수가 중요하니깐 함수를 위에 두는거지