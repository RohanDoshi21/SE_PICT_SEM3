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
        // ? Time Complexity:
        // Best O(n)
        // Avg O(n^2)
        // Worst O(n^2)
        // Space O(1) so inplace sorting ie does not require extra memory
        // Stable sort: does not change the relative order of elements with equal keys.
        // less no of swaps as compared to bubble sort
        // Suitable for linked lists
        // K-passes not useful
        // Adaptive algorithm - Timecomplexity changes if input is sorted

        // int size = sizeof(arr) / sizeof(arr[0]);
        int i, j, imin; // imin is the kth
        for (i = 0; i < size - 1; i++)
        {
            imin = i;
            for (j = i + 1; j < size; j++)
                if (arr[j] < arr[imin])
                    imin = j;

            // Kth smallest will be replaces with the ith position

            //swap the kth and ith position
            auto temp = arr[imin];
            arr[imin] = arr[i];
            arr[i] = temp;
        }
    }
};

template <typename T>
T inputValidation(string msg) // input validation function for failing cases
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
void Display(T arr[], int size) // template function to print the arrays
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
    int sizeIntArr = 0; // this is the size of array
    int sizeFloatArr = 0;
    sizeIntArr = inputValidation<int>("Enter the number of elements in the int array: ");
    int intarr[sizeIntArr];
    for (int i = 0; i < sizeIntArr; i++) // taking input for int array
    {
        intarr[i] = inputValidation<int>("");
    }

    sizeFloatArr = inputValidation<int>("Enter the number of elements in the float array: ");
    float floatarr[sizeFloatArr];
    for (int i = 0; i < sizeFloatArr; i++) //taking input for float array
    {
        floatarr[i] = inputValidation<float>("");
    }

    cout << "*************" << endl;

    cout << "INT Array " << endl;
    Display<int>(intarr, sizeIntArr); // displaying int array
    cout << "SORTED INT ARRAY" << endl;
    Sorting<int>::selectionSort(intarr, sizeIntArr); // performing selection sort on int array
    Display<int>(intarr, sizeIntArr);

    cout << "FLOAT Array " << endl;
    Display<float>(floatarr, sizeFloatArr); // displaying float array
    cout << "SORTED FLOAT ARRAY" << endl;
    Sorting<float>::selectionSort(floatarr, sizeFloatArr); //performing selection sort on float array
    Display<float>(floatarr, sizeFloatArr);

    return 0;
}