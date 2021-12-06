// !Author: Rohan Doshi
// ?Problem statement Assignemt 8
/*
Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array.
*/

#include <iostream>
using namespace std;

template <typename T, int size>
class Object
{
    T array[size];
    template <class T1>
    friend void selectionSort(T1 &obj);

public:
    Object()
    {
        cout << "Enter the inputs of the array" << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> array[i];
        }
    };
    void Display()
    {
        cout << "Array is: ";
        for (auto i : array)
            cout << i << " ";
        cout << endl;
    };
};

template <class T>
void selectionSort(T &obj)
{

    int size = sizeof(obj.array) / sizeof(obj.array[0]);
    int i, j, imin;
    for (i = 0; i < size - 1; i++)
    {
        imin = i;
        for (j = i + 1; j < size; j++)
            if (obj.array[j] < obj.array[imin])
                imin = j;

        auto temp = obj.array[imin];
        obj.array[imin] = obj.array[i];
        obj.array[i] = temp;
    }
}

int main()
{
    // const int size = 0;
    cout << "Enter the numebr of elements in the int array";
    int abc;
    cin >> abc;
    const int size = abc;
    Object<int, size> intObj;
    Object<float, 5> floatObj;

    return 0;
}