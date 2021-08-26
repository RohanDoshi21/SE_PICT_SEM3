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

class Complex
{
    float real, imaginary;

public:
    Complex(float realParameter = 0, float imaginaryParameter = 0)
    {
        real = realParameter;
        imaginary = imaginaryParameter;
    }

    Complex operator+(Complex obj)
    {
        Complex temp;
        temp.real = real + obj.real;
        temp.imaginary = imaginary + obj.imaginary;
        return temp;
    }
    Complex operator-(Complex obj)
    {
        Complex temp;
        temp.real = real - obj.real;
        temp.imaginary = imaginary - obj.imaginary;
        return temp;
    }
    Complex operator*(Complex obj)
    {
        Complex temp;
        temp.real = real * obj.real - imaginary * obj.imaginary;
        temp.imaginary = real * obj.imaginary + obj.real * imaginary;
        return temp;
    }

    // // TODO: learn how to divide complex numbers again 😞
    // Complex operator/(Complex obj)
    // {
    //     Complex temp;
    //     temp.real = real * obj.real - imaginary * obj.imaginary;
    //     temp.imaginary = real * obj.imaginary + obj.real * imaginary;
    //     return temp;
    // }

    void print()
    {
        cout << real << "+" << imaginary << "i" << endl;
    }

    // Completed TODO : implement overloading of >> & << operator using ostream and istream

    friend ostream& operator<<(ostream &output, Complex obj)
    {
        return output << obj.real << " + " << obj.imaginary << "i" << endl;
    }

    friend istream& operator >> (istream &input, Complex &obj)
    {
        cout << "Enter Complex no (real & imaginary): ";
        return input >> obj.real >> obj.imaginary;
    }
    
};

int main()
{
    Complex c1, c2(10, 13), c3;
    cin >> c1 >> c2;
    // c1.print();
    cout << "Complex no is " << c1;
    // c2.print();
    cout<< "Complex no is " << c2;
    c3 = c1 + c2;
    cout << "Addition " << c3;
    cout << "Substraction " << c1 - c2;
    cout << "Multiplaction " << c1*c2;
    return 0;
}