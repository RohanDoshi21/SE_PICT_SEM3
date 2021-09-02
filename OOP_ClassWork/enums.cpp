#include <iostream>
using namespace std;

int main() {
    enum color {red, green, blue, alpha};
    color c = alpha;
    cout << c << endl;
    return 0;
}