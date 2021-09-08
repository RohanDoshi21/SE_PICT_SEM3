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
    unsigned int *RollNo, *Division;
    unsigned long *TelephoneNo, *DLNo;
    string *Name, *Class, *BloodGroup, *ContactAddress, *Birthday;
    static int noOfObjects;

public:
    StudentDatabase() // default constructor
    {
        RollNo = new unsigned int;
        Division = new unsigned int;
        TelephoneNo = new unsigned long;
        DLNo = new unsigned long;
        Name = new string;
        Class = new string;
        BloodGroup = new string;
        ContactAddress = new string;
        Birthday = new string;
        noOfObjects++;
    }

    void create() // Create operation database
    {
        cout << "Enter your Name: ";
        cin >> *Name;
        cout << "Enter Roll no: ";
        cin >> *RollNo;
        cout << "Enter your division number: ";
        cin >> *Division;
        cout << "Enter your Telephone number: ";
        cin >> *TelephoneNo;
        cout << "Enter your Driving licence number: ";
        cin >> *DLNo;
        cout << "Enter your Class: ";
        cin >> *Class;
        cout << "Enter your blood group: ";
        cin >> *BloodGroup;
        cout << "Enter your Contact address: ";
        cin >> *ContactAddress;
        cout << "Enter your birthday: ";
        cin >> *Birthday;
    }

    void read(); // read operation database

    void update(); // update operation database

    void deleteDB(); // delete operation database



    StudentDatabase(StudentDatabase &obj) //Copy Constructor
    {
        this->RollNo = obj.RollNo;
        this->Division = obj.Division;
        this->TelephoneNo = obj.TelephoneNo;
        this->DLNo = obj.DLNo;
        this->Name = obj.Name;
        this->Class = obj.Class;
        this->BloodGroup = obj.BloodGroup;
        this->ContactAddress = obj.ContactAddress;
        this->Birthday = obj.Birthday;
        noOfObjects++;
    }

    ~StudentDatabase() //destructor
    {
        delete RollNo, Division, TelephoneNo, DLNo, Name, Class, BloodGroup, ContactAddress, Birthday;
        noOfObjects--;
    }

    static int ObjectCount()
    {
        return noOfObjects;
    }
};

void StudentDatabase::read()
{
    cout << "Name is " << *Name << endl;
    cout << "Roll no is " << *RollNo << endl;
    cout << "Division is " << *Division << endl;
    cout << "Telephone no is " << *TelephoneNo << endl;
    cout << "DLNo is " << *DLNo << endl;
    cout << "Class is " << *Class << endl;
    cout << "Blood group is " << *BloodGroup << endl;
    cout << "Contact address is " << *ContactAddress << endl;
    cout << "Birthday is " << *Birthday << endl;
}

int StudentDatabase::noOfObjects = 0;

int main()
{
    cout << "No of objects present at this time " << StudentDatabase::ObjectCount() << endl;
    return 0;
}