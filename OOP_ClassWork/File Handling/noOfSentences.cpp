#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int count = 0;
    ifstream readFile;
    readFile.open("sentenceCount.txt");
    if (!readFile)
    {
        cout << "Error opening the file" << endl;
        return 1;
    }
    string data;
    while (!readFile.eof())
    {
        getline(readFile, data);
        for (auto i : data)
        {
            if (i == '.' || i == '?' || i == '!')
                count++;
        }
    }
    
    cout << "No of sentences are " << count << endl;
    readFile.close();
    return 0;
}