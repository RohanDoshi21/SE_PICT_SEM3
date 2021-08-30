// !Author: Rohan Doshi 21126
// ?Problem statement
/*
Write a menu driven program in C++ having a class with member functions for performing each of the arithmetic operations.
Accept input values from user and pass them as parameter to these functions and display the resultant output.
*/

#include <iostream>
using namespace std;

class ArithmeticOperation
{
    float x1, x2;

public:
    ArithmeticOperation()
    {
        x1 = x2 = 0;
    }
    void setOperators(float a, float b)
    {
        x1 = a;
        x2 = b;
    }
    float plus(float a, float b)
    {
        setOperators(a, b);
        return x1 + x2;
    }
    float minus(float a, float b)
    {
        setOperators(a, b);
        return x1 - x2;
    }
    float multiply(float a, float b)
    {
        setOperators(a, b);
        return x1 * x2;
    }
    float divide(float a, float b)
    {
        setOperators(a, b);
        return x1 / x2;
    }
};

int main()
{
    ArithmeticOperation operations;
    bool toContinue = true;
    while (toContinue)
    {
        cout << "************************\n";
        cout << "Menu enter the number to continue\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n";
        int condition;
        cin >> condition;
        switch (condition)
        {
        case 1:
        {
            cout << "Enter the 2 number: ";
            float op1, op2;
            cin >> op1 >> op2;
            cout << "Result is " << operations.plus(op1, op2) << "\n";
            break;
        }
        case 2:
        {
            cout << "Enter the 2 number: ";
            float op1, op2;
            cin >> op1 >> op2;
            cout << "Result is " << operations.minus(op1, op2) << "\n";
            break;
        }
        case 3:
        {
            cout << "Enter the 2 number: ";
            float op1, op2;
            cin >> op1 >> op2;
            cout << "Result is " << operations.multiply(op1, op2) << "\n";
            break;
        }
        case 4:
        {
            cout << "Enter the 2 number: ";
            float op1, op2;
            cin >> op1 >> op2;
            if(op2 == 0){
                cout << "Error: Divide by 0\n";
                break;
            }
            else{
                cout << "Result is " << operations.divide(op1, op2) << "\n";
            }
            break;
        }
        case 5:
        {
            cout << "Exit";
            toContinue = false;
            break;
        }
        default:
        {
            cout << "Invalid input\n";
        }
        }
    }

    return 0;
}