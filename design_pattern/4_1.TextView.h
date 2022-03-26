#include <iostream>
#include <string>

class TextView
{
    std::string data;
    std::string font;
    int width;

public:
    TextView(std::string s, std::string fo = "Godic", int w = 24) : data(s), font(fo), width(w)
    {
    }

    void Show() { std::cout << data << std::endl; }
};

//아래와 같이 사용할 수 있다.

//TextView tv("hello");
//tv.Show();