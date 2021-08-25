// this is a program to demonstrate working of public and private members of a class 

#include <iostream>
using namespace std;

class A
{
    int x, y, a[5];
    float a1, b1;

public:
    void setValues()
    {
        cout << "Enter values (int) ";
        cin >> x >> y;
        cout << "Enter values (float) ";
        cin >> a1 >> b1;
        cout << "Enter 5 elements of an array";
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter " << i + 1 << " element ";
            cin >> a[i];
        }
    }
    void getValues()
    {
        cout << "Values of interger are " << x << " & " << y << "\n";
        cout << "Values of float are " << a1 << " & " << b1 << "\n";
        cout << "Array elements are \n";
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << " element:" << a[i] << "\n";
        }
    }
};

int main()
{
    A a1;
    B = 12;
    a1.setValues();
    a1.getValues();
    return 0;
}