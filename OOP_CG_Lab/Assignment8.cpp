// !Author: Rohan Doshi
// ?Problem statement Assignemt 8
/*
Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array.
*/

#include <iostream>
using namespace std;

template <class T>
class Sorting
{
public:
    static void selectionSort(T arr[], int size)
    {

        // int size = sizeof(arr) / sizeof(arr[0]);
        int i, j, imin;
        for (i = 0; i < size - 1; i++)
        {
            imin = i;
            for (j = i + 1; j < size; j++)
                if (arr[j] < arr[imin])
                    imin = j;

            // Kth smallest will be replaces with the ith position
            auto temp = arr[imin];
            arr[imin] = arr[i];
            arr[i] = temp;
        }
    }
};

template <typename T>
T inputValidation(string msg)
{
    T takeInput;
    while (true)
    {
        cout << msg;
        if (cin >> takeInput)
        {
            break;
        }
        else
        {
            cout << "Invalid\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return takeInput;
}

template <typename T>
void Display(T arr[], int size)
{
    cout << "Array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int sizeIntArr = 0;
    int sizeFloatArr = 0;
    sizeIntArr = inputValidation<int>("Enter the number of elements in the int array: ");
    int intarr[sizeIntArr];
    for (int i = 0; i < sizeIntArr; i++)
    {
        intarr[i] = inputValidation<int>("");
    }

    sizeFloatArr = inputValidation<int>("Enter the number of elements in the float array: ");
    float floatarr[sizeFloatArr];
    for (int i = 0; i < sizeFloatArr; i++)
    {
        floatarr[i] = inputValidation<float>("");
    }

    cout << "*************" << endl;

    cout << "INT Array " << endl;
    Display<int>(intarr, sizeIntArr);
    cout << "SORTED INT ARRAY" << endl;
    Sorting<int>::selectionSort(intarr, sizeIntArr);
    Display<int>(intarr, sizeIntArr);

    cout << "FLOAT Array " << endl;
    Display<float>(floatarr, sizeFloatArr);
    cout << "SORTED FLOAT ARRAY" << endl;
    Sorting<float>::selectionSort(floatarr, sizeFloatArr);
    Display<float>(floatarr, sizeFloatArr);

    return 0;
}