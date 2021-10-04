#include <iostream>
#define nL "\n"
using namespace std;
class A
{
    int a;

public:
    A(){
        cout << "Constructor of Class A is called" << nL;
    }
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
    B(){
        cout << "Constructor of Class B is called" << nL;
    }
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
    C(){
        cout << "Constructor of Class C is called" << nL;
    }
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