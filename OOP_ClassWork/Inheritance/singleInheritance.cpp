//! Author: Rohan Doshi

#include <iostream>
using namespace std;

class Mathematics
{
protected:
    int a, b;

public:
    Mathematics()
    {
        cout << "Enter values of a and b : ";
        cin >> a >> b;
    }
};

class Addition : public Mathematics
{
public:
    int add()
    {
        return a + b;
    }
};

int main()
{
    Addition numbers;
    cout << numbers.add();
    return 0;
}