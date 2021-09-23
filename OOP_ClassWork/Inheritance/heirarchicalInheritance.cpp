#include <iostream>
using namespace std;

class Person
{
public:
    int age;
    string name;
};

class Student : public Person
{
public:
    int marks;
};

class Employee : public Person
{
public:
    int salary;
};

int main()
{
    Student s1;
    Employee p1;
    cout << "Enter Name, age and marks for a student\n";
    cin >> s1.name >> s1.age >> s1.marks;
    cout << "Enter Name, age, salary for employee\n";
    cin >> p1.name >> p1.age >> p1.salary;
    cout << "Student Details\n";
    cout << "Name " << s1.name << endl
         << "Age " << s1.age << "Mark " << s1.marks << endl;
    cout << "Employee Details\n";
    cout << "Name " << p1.name << endl
         << "Age " << p1.age << "Salary " << p1.salary << endl;
    return 0;
}