#include <iostream>
using namespace std;

class General_Info
{
private:
    string name;
    int age;
    string address;

public:
    void Accept1()
    {
        cout << "Enter name age and address\n";
        cin >> name >> age;
        getline(cin, address);
    }
    void Display1()
    {
        cout << "Name: " << name << "\t"
             << " age: " << age << "\t"
             << " Address: " << address << "\n";
    }
};

class Academic_Info
{
private:
    int marks;
    string grade;

public:
    void Accept2()
    {
        cout << "Enter marks and grade\n";
        cin >> marks >> grade;
    }

    void Display2()
    {
        cout << "marks: " << marks << "\t"
             << " grade: " << grade << "\n";
    }
};

class Employee_Info : public General_Info, public Academic_Info
{
private:
    int EmployeeID;
    int salary;

public:
    void Accept3()
    {
        cout << "Enter EmployeeID and salary\n";
        cin >> EmployeeID >> salary;
    }
    void Display3()
    {
        cout << "Employee ID: " << EmployeeID << "\t"
             << "Salary: " << salary << "\n";
    }
};

int main()
{
    Employee_Info obj;
    obj.Accept1();
    obj.Accept2();
    obj.Accept3();
    obj.Display1();
    obj.Display2();
    obj.Display3();
    return 0;
}