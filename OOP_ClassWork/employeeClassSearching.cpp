#include <iostream>
#include <fstream>
#define nL "\n"
using namespace std;

class Employee
{
private:
    int salary;
    string name;

public:
    void inputData()
    {
        cout << "Enter Name ";
        cin >> name;
        cout << "Enter Salary";
        cin >> salary;
    };
    void displayData()
    {
        cout << "Name: " << name << nL;
        cout << "Salary: " << salary << nL;
    };
};

int main()
{
    fstream file;
    file.open("employee.txt", ios::in | ios::out);
    cout << "Enter data for 3 new Employees" << nL;
    Employee arr[3];
    for (auto i : arr)
    {
        i.inputData();
        file.write((char *)&i, sizeof(i));
    }
    file.seekg(0);
    cout << "Data Displayed" << nL;
    for (auto i : arr)
    {
        file.read((char *)&i, sizeof(i));
    }
    file.close();
    return 0;
}