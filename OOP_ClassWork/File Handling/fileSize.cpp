#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("mydata.txt");
    fin.seekg(0, ios::end);
    auto size =fin.tellg();
    cout << "Size " << size << endl;
    fin.close();
    return 0;
}