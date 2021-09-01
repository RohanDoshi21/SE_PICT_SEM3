#include <iostream>
using namespace std;

class Test
{
public:
    int x;
    float y;
    Test()
    {
        x = 0;
        y = 0.0;
    }
    Test(int a, float b)
    {
        x = a;
        y = b;
    }
    // Test1(){

    // }
    int operator+(Test obj1); //decleration
    // return_type function_name(parameters);
    void print()
    {
        cout << x << " " << y << endl;
    }
};
// return_type class_name :: function_name(parameters){ //definition

// }
int Test::operator+(Test obj) //definition
{ 
    return x - obj.x;
}

int main()
{
    Test obj(3, 2);
    Test obj1(10, 15.5);
    cout << obj1 + obj; // call to overloaded plus operator
    // obj.print();
    // obj1.print();
    // cout << "hello" << endl;
    return 0;
}