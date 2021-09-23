#include <string.h>
#include <cstring>
#include <ctime>
#include <sstream>
#include <iostream>

using namespace std;

class Student
{
private:
    string *name, *date_of_birth, *blood_group, *address, *telephone_number, *driving_license_num, *std;
    int *roll_no;
    char *div;
    static int stud_number;

public:
    Student(){   //Default Constructor
        name = new string;
        date_of_birth = new string;
        blood_group = new string;
        address = new string;
        telephone_number = new string;
        driving_license_num = new string;
        std = new string;
        roll_no = new int;
        div = new char;
        stud_number++;
    }; 
    
    //Parameterized Constructor
    Student(string *name, string *date_of_birth, string *blood_group, string *address, string *telephone_number, string *driving_license_num, int *roll_no, string *std, char *div)
    {  this->name = name;
	this->roll_no = roll_no;
	this->std = std;
	this->div = div;
	this->date_of_birth = date_of_birth;
	this->blood_group = blood_group;
	this->address = address;
	this->telephone_number = telephone_number;
	this->driving_license_num = driving_license_num;
    };

    //Copy Constructor
    Student(Student &S){
	this->name = new string;
    *name = *S.name;
	this->roll_no = new int;
    *roll_no = *S.roll_no;
	this->std = new string; 
    *std = *S.std;
	this->div = new char;
    *div = *S.div;
	this->date_of_birth = new string;
    *date_of_birth = *S.date_of_birth;
	this->blood_group = new string;
    *blood_group = *S.blood_group;
	this->address = new string;
    *address = *S.address;
	this->telephone_number = new string;
    *telephone_number = *S.telephone_number;
	this->driving_license_num = new string;
    *driving_license_num = *S.driving_license_num;
    stud_number++;
}

    void getDetails();  //get all the details function which is defined below

    void setDetails();  //set the details from the user 

    void clearDetails();

    friend void update(const Student &obj);  //A friend function for updation 

    static int no_of_students(){            //Gives the number of students
        return stud_number;
    }

    ~Student(){         //Destructor
        delete name;
        delete address;
        delete roll_no;
        delete blood_group;
        delete std;
        delete telephone_number;
        delete driving_license_num;
        delete div;
        delete date_of_birth;
    }; 
};


void update(const Student &obj) // friend function declaration for update method
{
    cout << "********" << endl;
    string temp;
    int tempint;
    cout << "Update Name (previous name:" << *obj.name << ") for previous press enter" << endl;
    cin.ignore();
    getline(cin, temp);
    if (!temp.empty())
    {
        *obj.name = temp;
    }

    cout << "Update Roll no (previous roll no:" << *obj.roll_no << ") for previous press -1" << endl;
    cin >> tempint;
    if (tempint != -1)
    {
        *obj.roll_no = tempint;
    }

    cout << "Update class (previous std:" << *obj.std << ") for previous press -1" << endl;
    cin.ignore();
    cin >> temp;
    if (temp != "-1")
    {
        *obj.std = temp;
    }

    cout << "Update Division (previous division:" << *obj.div << ") for previous press -1" << endl;
    cin >> tempint;
    if (tempint != -1)
    {
        *obj.div = tempint;
    }

    cout << "Update TelephoneNo (previous telephone number:" << *obj.telephone_number << ") for previous press -1" << endl;
    cin >> temp;
    if (temp != "-1")
    {
        *obj.telephone_number = temp;
    }

    cout << "Update DLNo (previous driving license No:" << *obj.driving_license_num << ") for previous press -1" << endl;
    cin.ignore();
    cin >> temp;
    if (temp != "-1")
    {
        *obj.driving_license_num = temp;
    }

    cout << "Update BloodGroup (previous blood Group:" << *obj.blood_group << ") for previous press -1" << endl;
    cin.ignore();
    cin >> temp;
    if (temp != "-1")
    {
        *obj.blood_group = temp;
    }

    cout << "Update ContactAddress (previous Address:" << *obj.address << ") for previous press -1" << endl;
    cin.ignore();
    getline(cin, temp);
    if (temp != "-1")
    {
        *obj.address = temp;
    }

    cout << "Update Birthday (previous date of birth:" << *obj.date_of_birth << ") for previous press -1" << endl;
    cin >> temp;
    if (temp != "-1")
    {
        *obj.date_of_birth = temp;
    }
    cout << "********" << endl;
}


inline void Student::getDetails(){
    cout<<"====================================\n";
    cout<<"Name : "<<*name<<"\n";
    cout<<"date_of_birth : "<<*date_of_birth<<"\n";
    cout<<"Blood Grp : "<<*blood_group<<"\n";
    cout<<"Telephone Numer : "<<*telephone_number<<"\n";
    cout <<"Driving_license_num: "<<*driving_license_num <<"\n";
    cout<<"Standard : "<<*std<<"\n";
    cout<<"Division : "<<*div<<"\n";
    cout<<"====================================\n";
}

inline void Student::clearDetails(){
    delete name;
    delete address;
    delete roll_no;
    delete blood_group;
    delete std;
    delete telephone_number;
    delete driving_license_num;
    delete div;
    delete date_of_birth;
}

int Student::stud_number=0;



inline void Student::setDetails(){
    cout<<"Enter the name of the student: ";
    cin>>*name;
    cout<<"Enter the address of the student: ";
	cin>>*address;
	
    while (true)        //Exception handling for blood group
    {
        cout<< "Enter the blood group of the student: ";
        cin>>*blood_group;
        if (*blood_group == "A+" || *blood_group == "A-" || *blood_group == "B+" || *blood_group == "B-" || *blood_group == "AB+" || *blood_group == "AB+" || *blood_group == "O+" || *blood_group == "O-")
        {
            break;
        }
        else
        {
            cout<<"Invalid blood group\n";
        }
        
    }

    // Code to find today's date
        time_t ttime = time(nullptr);
        tm *local_time = localtime(&ttime);
        int year = 1900 + local_time->tm_year;
        int month = 1 + local_time->tm_mon;
        int day = local_time->tm_mday;
        string todayDate = to_string(day) + '/' + to_string(month) + '/' + to_string(year);
        string temp;

        // exception handling for birthday
        while (true)
        {
            try
            {
                cout << "Enter your birthday (dd/mm/yyyy): ";
                cin >> temp;
                int dayInt;
                int monthInt;
                int yearInt;
                stringstream dayStream, monthStream, yearStream; // used to convert string into an int
                dayStream << temp.substr(0, 2);
                dayStream >> dayInt;
                monthStream << temp.substr(3, 2);
                monthStream >> monthInt;
                yearStream << temp.substr(6, 4);
                yearStream >> yearInt;
                if (temp[2] != '/' || temp[5] != '/')
                {
                    throw "Invalid birthdate format";
                }
                else if (yearInt > year)
                {
                    throw "You canont be born in the future!";
                }
                else if (yearInt == year && monthInt > month)
                {
                    throw "You canont be born in the future!";
                }
                else if (monthInt == month && dayInt > day && yearInt == year)
                {
                    throw "You canont be born in the future!";
                }
                *date_of_birth = temp;
                break;
            }
            catch (const char *msg)
            {
                cout << msg << endl;
            }
        }
    
    while (true)        //Exception handling for roll number
    {
        cout<<"Enter the roll_no: ";
        if (cin>>*roll_no)
        {
            break;
        }
        else
        {
            cout<<"Invalid Roll number\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        
    }
    

	cout<<"Enter the Class of the student: ";
	cin>>*std;

	cout<<"Enter the Division of the student: ";
	cin>>*div;

    int ask = 0;
    while (ask != 1)        // Exception handling for telephone number
    {
        cout<<"Enter the telephone number: ";
        string temp;
        cin>>temp;
        if (temp.length() != 10)
        {
            cout<<"Telephone number must be 10 digits long\n";
            ask--;
        }
        for (char i : temp)
                {
                    if (!isdigit(i))
                    {
                        cout<< "Telephone no must be a digit\n";
                        break;
                    }
                }
                *telephone_number = temp;
                ask++;
    }

	cout<<"Enter the driving license number: ";
	cin>>*driving_license_num;

    stud_number++;
    };


int main()
{   
    int total_students;
    cout<<"how many students are present\n";
    cin>>total_students;
    Student studentData[total_students];
    int choice{0};

    while (choice !=6)
    {   
        cout<< "****Menu*****\n";
        cout<< "1. Create Student profile\n2. View Student profile\n3. Duplicate Student profile\n4. Update Student profile\n5. Delete Student profile\n6. Exit\n";
        cin>>choice;
        switch (choice){
            case 1:
                int position1;
                cout<<"Position of student whose data you want\n";
                cin>>position1;
                studentData[position1].setDetails();
                break;
            case 2:
                int position2;
                cout<<"Position of student whose data you want\n";
                cin>>position2;
                if (position2 > Student::no_of_students() || position2 < 0)
                {
                    cout<<"no object found at this position";
                }
                studentData[position2].getDetails();
                break;
            case 3:
                int from_position, to_position;
                cout<<"The position from which you want to copy\n";
                cin>>from_position;
                cout<<"The position where you want to copy\n";
                cin>>to_position;
                studentData[to_position] = studentData[from_position];
                break;
            case 4:
                int position4;
                cout<<"Which position do you want to update";
                cin>>position4;
                update(studentData[position4]);
                break;
            case 5:
                int position_delete;
                cout<<"Which position you want to delete\n";
                cin>>position_delete;
                studentData[position_delete].clearDetails();
                break;
            case 6:
                cout<<"Thank you\nExit\n";
                break;
            default:
                cout<<"Invalid choice\n";
                break;
    }        
    }
      
    return 0;
}