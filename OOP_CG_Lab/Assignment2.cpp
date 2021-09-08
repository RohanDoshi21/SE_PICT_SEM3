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
    unsigned long long *TelephoneNo;
    string *DLNo;
    string *Name, *Class, *BloodGroup, *ContactAddress, *Birthday;
    static int noOfObjects;

public:
    StudentDatabase() // default constructor
    {
        RollNo = new unsigned int;
        Division = new unsigned int;
        TelephoneNo = new unsigned long long;
        DLNo = new string;
        Name = new string;
        Class = new string;
        BloodGroup = new string;
        ContactAddress = new string;
        Birthday = new string;
        noOfObjects++;
        create();
    }

    void create() // Create operation database
    {
        string temp;
        cout << "Enter your Name: ";
        getline(cin, temp);
        *Name = temp;
        cout << "Enter Roll no: ";
        cin >> *RollNo;
        cout << "Enter your Class: ";
        cin >> temp;
        *Class = temp;
        cout << "Enter your division: ";
        cin >> *Division;
        cout << "Enter your Telephone number: ";
        cin >> *TelephoneNo;
        cout << "Enter your Driving licence number: ";
        cin >> *DLNo;
        cout << "Enter your blood group: ";
        cin >> temp;
        *BloodGroup = temp;
        cout << "Enter your Contact address: ";
        string temp2;
        cin.ignore();
        getline(cin, temp2);
        *ContactAddress = temp2;
        cout << "Enter your birthday: ";
        cin >> temp;
        *Birthday = temp;
    }

    void read(); // read operation database

    void update(); // update operation database

    void deleteDB(); // delete operation database

    StudentDatabase(StudentDatabase &obj) //Copy Constructor
    {
        this->RollNo = new unsigned int;
        *RollNo = *obj.RollNo;
        this->Division = new unsigned int;
        *Division = *obj.Division;
        this->TelephoneNo = new unsigned long long;
        *TelephoneNo = *obj.TelephoneNo;
        this->DLNo = new string;
        *DLNo = *obj.DLNo;
        this->Name = new string;
        *Name = *obj.Name;
        this->Class = new string;
        *Class = *obj.Class;
        this->BloodGroup = new string;
        *BloodGroup = *obj.BloodGroup;
        this->ContactAddress = new string;
        *ContactAddress = *obj.ContactAddress;
        this->Birthday = new string;
        *Birthday = *obj.Birthday;
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
    cout << "********************" << endl;
    cout << "Name is " << *Name << endl;
    cout << "Roll no is " << *RollNo << endl;
    cout << "Class is " << *Class << endl;
    cout << "Division is " << *Division << endl;
    cout << "Telephone no is " << *TelephoneNo << endl;
    cout << "DLNo is " << *DLNo << endl;
    cout << "Blood group is " << *BloodGroup << endl;
    cout << "Contact address is " << *ContactAddress << endl;
    cout << "Birthday is " << *Birthday << endl;
    cout << "********************" << endl;
}

int StudentDatabase::noOfObjects = 0;

void StudentDatabase::update()
{
    cout << "********************" << endl;
    string temp;
    int tempint;
    cout << "Update Name (previous name:" << *this->Name << ") for previous press enter" << endl;
    cin.ignore();
    getline(cin, temp);
    if (temp != "")
    {
        *Name = temp;
    }

    cout << "Update Roll no (previous roll no:" << *this->RollNo << ") for previous press -1" << endl;
    cin >> tempint;
    if (tempint != -1)
    {
        *RollNo = tempint;
    }

    cout << "Update class (previous class:" << *this->Class << ") for previous press -1" << endl;
    cin.ignore();
    cin >> temp;
    if (temp != "-1")
    {
        *Class = temp;
    }

    cout << "Update Division (previous division:" << *this->Division << ") for previous press -1" << endl;
    cin >> tempint;
    if (tempint != -1){
        *Division = tempint;
    }

    cout << "Update TelephoneNo (previous telephoneNo:" << *this->TelephoneNo << ") for previous press -1" << endl;
    cin >> tempint;
    if (tempint != -1){
        *TelephoneNo = tempint;
    }

    cout << "Update DLNo (previous dlNo:" << *this->DLNo << ") for previous press -1" << endl;
    cin.ignore();
    cin >> temp;
    if (temp != "-1"){
        *DLNo = temp;
    }

    cout << "Update BloodGroup (previous bloodGroup:" << *this->BloodGroup <<") for previous press -1" << endl;
    cin.ignore();
    cin >> temp;
    if (temp != "-1"){
        *BloodGroup = temp;
    }

    cout << "Update ContactAddress (previous contactAddress:" << *this->ContactAddress << ") for previous press -1" << endl;
    cin.ignore();
    getline(cin, temp);
    if (temp != "-1")
    {
        *ContactAddress = temp;
    }

    cout << "Update Birthday (previous birthday:" << *this->Birthday << ") for previous press -1" << endl;
    cin >> temp;
    if (temp != "-1"){
        *Birthday = temp;
    }
    cout << "********************" << endl;
}

void StudentDatabase::deleteDB()
{
    delete RollNo, Division, TelephoneNo, DLNo, Name, Class, BloodGroup, ContactAddress, Birthday;
    noOfObjects--;
    cout << "Data for this user is now empty" << endl;
}

int main()
{
    StudentDatabase s1;
    s1.read();
    cout << "No of objects present at this time " << StudentDatabase::ObjectCount() << endl;
    StudentDatabase s2 = s1;
    s2.read();
    cout << "No of objects present at this time " << StudentDatabase::ObjectCount() << endl;
    // s2.deleteDB();
    // cout << "No of objects present at this time " << StudentDatabase::ObjectCount() << endl;
    s1.update();
    s1.read();
    s2.read();
    return 0;
}