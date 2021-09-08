#include <iostream>
using namespace std;

int main() {
    string *s1 = new string;
    string s2;
    cin >> s2;
    *s1 = s2;
    cout << s2;
    cout << *s1 << endl;
    delete s1;
    return 0;
}