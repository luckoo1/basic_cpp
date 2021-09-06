#include <iostream>
#include "5_5.stack.h" //이건 c에서도 적었다.

int main()
{
    Stack s1(20);
    s1.push(30);
    std::cout << s1.pop() << std::endl;
}