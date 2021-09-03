// !Author: Rohan Doshi
// ?Problem statement Group A - 1

/*
Develop a program in C++ to create a database of student’s 
information system containing the following information: 
Name, Roll number, Class, Division, Date of Birth, Blood group, 
Contact address, Telephone number, Driving license no. and other. 
Construct the database with suitable member functions. 
Make use of constructor, default constructor, copy constructor, destructor, 
static member functions, friend class, this pointer, inline code and dynamic memory 
allocation operators-new and delete as well as exception handling.
*/

#include <iostream>
using namespace std;

class StudentDatabase
{
    unsigned int RollNo, Division;
    unsigned long TelephoneNo, DLNo;
    string Name, Class, BloodGroup, ContactAddress, Birthday;
    static int noOfObjects;

public:
    static int StudentID[100];
    StudentDatabase()
    {
        cout << "Enter Roll no: ";
        cin >> RollNo;
        cout << "Enter your division number: ";
        cin >> Division;
        cout << "Enter your Telephone number: ";
        cin >> TelephoneNo;
        cout << "Enter your Driving licence number: ";
        cin >> DLNo;
        cout << "Enter your Name: ";
        cin >> Name;
        cout << "Enter your Class: ";
        Class = "";
        BloodGroup = "";
        ContactAddress = "";
        Birthday = "";
        noOfObjects++;
    };
    StudentDatabase(StudentDatabase &obj)
    {
        RollNo = obj.RollNo;
        Division = obj.Division;
        TelephoneNo = obj.TelephoneNo;
        DLNo = obj.DLNo;
        Name = obj.Name;
        Class = obj.Class;
        BloodGroup = obj.BloodGroup;
        ContactAddress = obj.ContactAddress;
        Birthday = obj.Birthday;
        noOfObjects++;
    }
    ~StudentDatabase(){
        noOfObjects--;
    }
    

    static int ObjectCount(){
        return noOfObjects;
    }

};

int StudentDatabase::noOfObjects = 0;
int StudentDatabase::StudentID[100] = {-1};

int main()
{ 
    cout << "No of objects present at this time " << StudentDatabase::ObjectCount() << endl;
    return 0;
}