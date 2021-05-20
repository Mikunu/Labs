#include <iostream>
#include <windows.h>

class Stack
{
private:
    int val;
public:
    Stack(int n);
    ~Stack();
};

Stack::Stack(int n)
{
    val = n;
    std::cout << val;
}

Stack::~Stack()
{
    std::cout << "Память освобождена";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Stack* stack;
    stack = new Stack(5);
    std::cout << '\n';
    delete stack;
}
