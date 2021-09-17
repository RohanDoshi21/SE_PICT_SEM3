#include <iostream>
using namespace std;

class Test
{
public:
    int x;
    float y;
    // Test(){
    //     x= 12;
    //     y= 14;
    //     cout << x << " " << y << endl;
    // }
    
    //! we cannot have more than one default constructor the below parameterised constructor acts as a default constructor
    
    Test(int a = 0, float b = 0)
    {
        x = a;
        y = b;
        cout << x << " " << y << endl;
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
    Test abc; // parameterised constructor acting as default constructor
    Test obj(3, 2);
    Test obj1(10, 15.5);
    cout << obj1 + obj; // call to overloaded plus operator
    // obj.print();
    // obj1.print();
    // cout << "hello" << endl;
    return 0;
}