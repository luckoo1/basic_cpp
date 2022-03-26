#include "5_5.stack.h" //"Stack::" 사용하기 위해서 필요하다
//보통 c할때는 이거까진 안적었다.
Stack::Stack(int sz)
{
    buf = new int[sz];
    idx = 0;
}

Stack::~Stack()
{
    delete[] buf;
}

void Stack::push(int n)
{
    buf[idx++] = n;
}

int Stack::pop()
{
    return buf[--idx];
}
