#if 0
int main()
{
    Person p1("KIM", 2);
    Person p2 = p1; //객체의 복사
}

1.얕은 복사(Shallow Copy)
    메모리 내용 자체를 복사하지 않고 주소만 복사하는 현상
    소멸자에서 메모리를 삭제하는 경우 문제 발생

2.객체를 복사하는 기술(얕은 복사 해결책)
    깊은 복사(Deep Copy)
    참조 계수(Reference Counting)
    복사 금지(Delete Copy Constructor)
    소유권 이전(move)-"C++11 move 생성자"
#endif