#include <iostream>
using namespace std;
#define size 10

int main()
{
    int arr[size];
    int *ptr = arr;
    cout << "Enter " << size << " elements \n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int find;
    cout << "Enter element to be found"
         << "\n";
    cin >> find;
    bool flag = false;
    for (int i = 0; i < size; i++)
    {
        if (*ptr == find)
        {
            cout << "Element present at index " << i << "\n";
            flag ^= 1; // best way to flip the value of a boolean!
            break;
        }
        ptr++;
    }
    if (!flag)
        cout << "No element found";

    return 0;
}