#include <iostream>
#include <time.h>

using namespace std;

int main() {
    int arr[100][10];
    cout << "Hello";
    clock_t start = clock();
    for(int i =0; i<100; i++){
        for (int j =0; i<10; j++){
            arr[i][j] = 0;
        }
    }
    cout << "Hi";
    cout.precision(10);
    cout << fixed <<  float(clock() - start)/CLOCKS_PER_SEC  << endl;
    return 0;
}
