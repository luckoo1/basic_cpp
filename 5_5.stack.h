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
