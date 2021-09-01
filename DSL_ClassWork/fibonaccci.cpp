// #include <iostream>
// using namespace std;
// long long arr[15] = {-1};

// long long fibonacci(long long n)
// {
//     if (arr[n] == -1)
//     {
//         if (n <= 1)
//         {
//             arr[n] = n;
//         }
//         else
//         {
//             arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
//         }
//     }
//     return arr[n];
// }
// int main()
// {
//     cout << "fibonacci: " << fibonacci(12);
//     return 0;
// }

// #include <iostream>
// using namespace std;
// #define ll long long
// ll result[31] = {-1};
// ll fibonacci(ll n){
//     if(result[n] == -1){
//         if(n<=1)
//             result[n] = n;
//         else
//             result[n] = fibonacci(n-1) + fibonacci(n-2);
//     }
//     return result[n];
// }
// int main() {
//     int n;
//     cin >> n;
//     cout << fibonacci(n);
//     return 0;
// }

#include <iostream>
using namespace std;
#define ll long long
#define nil -1
#define max 100

ll fib[max];
void initialize(){
    for (size_t i = 0; i < max; i++)
    {
        fib[i] = nil;
    }
    
}
ll fibonacci(ll n){
    if (fib[n] == nil){
    if (n<=1) fib[n] = n;
    else fib[n]= fibonacci(n-1) + fibonacci(n-2);
    }
    return fib[n];
}

int main() {
    initialize();
    ll n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}