// !Author: Rohan Doshi
// ?Problem statement Group A - 1
/*
Implement a class Complex which represents the Complex Number data type. Implement the 
following 
1. Constructor (including a default constructor which creates the complex number 0+0i). 
2. Overload operator+ to add two complex numbers. 
3. Overload operator* to multiply two complex numbers. 
4. Overload operators << and >> to print and read Complex Numbers. 
*/

#include <iostream>
using namespace std;

class Complex //declaration of a class
{
    float real, imaginary;

public:
    Complex(float realParameter = 0, float imaginaryParameter = 0)
    {
        real = realParameter;
        imaginary = imaginaryParameter;
    }

    Complex operator+(Complex obj) // overloading of + operator
    {
        Complex temp;
        temp.real = real + obj.real;
        temp.imaginary = imaginary + obj.imaginary;
        return temp;
    }
    Complex operator-(Complex obj) // overloading of - operator
    {
        Complex temp;
        temp.real = real - obj.real;
        temp.imaginary = imaginary - obj.imaginary;
        return temp;
    }
    Complex operator*(Complex obj); // overloading of * operator

    void print()
    {
        cout << real << "+" << imaginary << "i" << endl;
    }

    friend ostream &operator<<(ostream &output, Complex obj) // overload extraction operator using friend function
    {
        return output << obj.real << " + " << obj.imaginary << "i" << endl; // permission of displaying is given only to cout so we use a reference to cout
    }

    friend istream &operator>>(istream &input, Complex &obj) // overload insertion operator using friend function
    {

        for (;;) // validation loop for a numerical input 
        {
            cout << "Enter Complex no (real & imaginary): ";
            if (input >> obj.real >> obj.imaginary)
            {
                return input;
                break;
            }
            else
            {
                cout << "Invalid Complex Number\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }
    }
};

Complex Complex::operator*(Complex obj) //definition of overloaded * operator
{
    Complex temp;
    temp.real = real * obj.real - imaginary * obj.imaginary;
    temp.imaginary = real * obj.imaginary + obj.real * imaginary;
    return temp;
}

int main()
{
    Complex c1, c2;
    cin >> c1 >> c2;
    int usersChoice = {0};
    while (usersChoice != -1)
    {
        cout << "*****************" << endl;
        cout << "Chose a operation to perform" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "-1. Exit" << endl;
        cin >> usersChoice;

        switch (usersChoice)
        {
        case 1:
        {
            cout << "Addition is " << c1 + c2 << endl;
            break;
        }
        case 2:
        {
            cout << "Subtraction is " << c1 - c2 << endl;
            break;
        }
        case 3:
        {
            cout << "Multiplication is " << c1 * c2 << endl;
            break;
        }
        case -1:
        {
            cout << "Exit" << endl;
            usersChoice = -1;
            break;
        }
        }
    }
    return 0;
}