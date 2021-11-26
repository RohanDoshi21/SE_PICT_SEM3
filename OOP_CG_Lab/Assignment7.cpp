// !Author: Rohan Doshi
// ?Problem statement Assignemt 7
/*
Write a C++ program that creates an output file, writes information to it, closes the file, open
it again as an input file and read the information from the file.
*/

#include <iostream>
#include <fstream>
using namespace std;
string exitCondition = "^C";
void readFile()
{
    ifstream file;
    file.open("Assignment7.txt");

    if (!file)
    {
        cout << "Error opening the file" << endl;
        return;
    }
    string line;
    while (!file.eof())
    {
        getline(file, line);
        cout << line << endl;
    }
    file.close();
}

void writeData()
{
    ofstream file;
    file.open("Assignment7.txt");
    string line;

    cout << "Keep on writing data to the files! To exit press " << exitCondition << endl;
    bool append = true;
    cin.ignore();
    while (append)
    {
        getline(cin, line);
        if (exitCondition.compare(0, 2, line) == 0)
        {
            cout << "Breaking" << '\n';
            append = false;
            break;
        }
        file << line << endl;
    }
    file.close();
}

void appendData()
{
    ofstream file;
    file.open("Assignment7.txt", ios::app);
    string line;

    cout << "Keep on writing data to the files! To exit press " << exitCondition << endl;
    bool append = true;
    cin.ignore();
    while (append)
    {
        getline(cin, line);
        if (exitCondition.compare(0, 2, line) == 0)
        {
            cout << "Breaking" << '\n';
            append = false;
            break;
        }
        file << line << endl;
    }
    file.close();
}
int main()
{
    char continueProgram = true;
    while (continueProgram)
    {
        cout << "Menu" << endl;
        cout << "1. Write Data" << endl;
        cout << "2. Append Data" << endl;
        cout << "3. Read Data" << endl;
        cout << "4. exit" << endl;
        cout << "Choose operations u want to perform? ";
        int choice = 0;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            writeData();
            break;
        }
        case 2:
        {
            appendData();
            break;
        }

        case 3:
        {
            readFile();
            break;
        }
        case 4:
        {
            continueProgram = false;
            break;
        }
        default:
        {
            cout << "INVALID CHOICE" << endl;
            break;
        }
        }
    }
    return 0;
}