#include <iostream>
using namespace std;
class A
{
    int a;

public:
    void accept()
    {
        cout << "Enter A ";
        cin >> a;
    }

    void Display()
    {
        cout << "A is " << a << "\n";
    }
};

class B : public A
{
    int b;

public:
    void accept()
    {
        cout << "Enter B ";
        cin >> b;
    }

    void Display()
    {
        cout << "B is " << b << "\n";
    }
};

class C : public B
{
    int c;

public:
    void accept()
    {
        cout << "Enter C ";
        cin >> c;
    }

    void Display()
    {
        cout << "C is " << c << "\n";
    }
};

int main()
{
    C obj;
    obj.accept();
    obj.Display();
    obj.B::accept();
    obj.B::Display();
    obj.A::accept();
    obj.A::Display();
    return 0;
}