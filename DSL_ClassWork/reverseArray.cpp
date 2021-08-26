// !Author: Rohan Doshi

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 6, 8, 9, 12, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    size--;
    int *p = &arr[size];
    
    for (size_t i = 0; i <= size; i++)
    {
        cout << *p << endl;
        p--;
    }
    return 0;
}