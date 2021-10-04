#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define pb push_back
#define mk make_pair
#define vi vector<int>
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9

void Rohan();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        Rohan();
        cout << endl;
    }

    return 0;
}

void Rohan()
{
    int size = 5;
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
}