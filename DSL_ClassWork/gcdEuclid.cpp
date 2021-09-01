#include <iostream>
using namespace std;

int EuclidGcd(int m, int n){
    while (n%m!=0){
        int r = n%m;
        n = m;
        m = r;
    }
    return m;
}

int main() {
    cout << EuclidGcd(44, 66);
    return 0;
}