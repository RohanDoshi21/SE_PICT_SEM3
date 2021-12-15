// !Author: Rohan Doshi
// ?Problem statement Assignemt 11
/*
Write C++ program using STL for sorting and searching user defined 
records such as personal records (Name, DOB, Telephone number etc) using vector container. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <sstream>
using namespace std;

string inputValidationBirthdate() // input validation for a future birthdate and incorrect format
{
    string temp;
    string birthdate;
    // Code to find today's date
    time_t ttime = time(nullptr);
    tm *local_time = localtime(&ttime);
    int year = 1900 + local_time->tm_year;
    int month = 1 + local_time->tm_mon;
    int day = local_time->tm_mday;
    string todayDate = to_string(day) + '/' + to_string(month) + '/' + to_string(year);

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
            if (temp[2] != '/' || temp[5] != '/') //checking format
            {
                throw "Invalid birthdate format";
            }
            else if (yearInt > year || yearInt < 1900) //checking year
            {
                throw "Invalid";
            }
            else if ((yearInt == year && monthInt > month) || monthInt > 12 || monthInt < 1) //checking month
            {
                throw "Invalid";
            }
            else if ((monthInt == month && dayInt > day && yearInt == year) || dayInt > 31) //checking day
            {
                throw "Invalid";
            }
            birthdate = temp;
            return birthdate;
        }
        catch (const char *msg) // if validatoin failed display msg
        {
            cout << msg << endl;
        }
    }
}

template <typename T>
T inputValidation(string msg)
{
    T takeInput;
    while (true)
    {
        cout << msg;
        if (cin >> takeInput)
        {
            break;
        }
        else // if validatoin failed display msg
        {
            cout << "Invalid\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return takeInput;
}

string inputValidationTelephoneNo()
{
    while (true)
    {
        cout << "Enter Telephone number: ";
        try
        {
            string temp;
            cin >> temp;
            if (temp.length() != 10) //check for only 10 digits
            {
                throw "Telephone number must be 10 characters long\n";
            }
            for (char i : temp) //check for a character
            {
                if (!isdigit(i))
                {
                    throw "Telephone no must be a digit\n";
                    break;
                }
            }
            return temp;
        }
        catch (const char *msg) // if failed catch the error msg
        {
            cout << msg;
        }
    }
}

class PersonalRecord
{
public:
    string name;
    string birthdate;
    string telephoneNo;

    static bool compareByName(const PersonalRecord &a, const PersonalRecord &b) //3rd parameter for sorting by Name
    {
        return a.name < b.name;
    }
    static bool compareByTelephoneNo(const PersonalRecord &a, const PersonalRecord &b) //3rd parameter for sorting by telephone no
    {
        return a.telephoneNo < b.telephoneNo;
    }

    static bool compareByDOB(const PersonalRecord &a, const PersonalRecord &b) //3rd parameter for sorting by date of birth
    {

        if (a.birthdate.substr(6, 4) == b.birthdate.substr(6, 4))
        {

            if (a.birthdate.substr(3, 2) == b.birthdate.substr(3, 2))
            {
                if (a.birthdate.substr(0, 2) < b.birthdate.substr(0, 2))
                {
                    return a.birthdate.substr(0, 2) < b.birthdate.substr(0, 2);
                }
                else
                {
                    return true;
                }
            }
            else
                return a.birthdate.substr(3, 2) < b.birthdate.substr(3, 2);
        }
        else
        {
            return a.birthdate.substr(6, 4) < b.birthdate.substr(6, 4);
        }
    }

    void create()
    {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        birthdate = inputValidationBirthdate();
        telephoneNo = inputValidationTelephoneNo();
    }
    void update()
    {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        birthdate = inputValidationBirthdate();
        telephoneNo = inputValidationTelephoneNo();
    }
    void Display()
    {
        cout << "Name: " << name << endl;
        cout << "Birthdate: " << birthdate << endl;
        cout << "Telephone No: " << telephoneNo << endl;
    }
};

void Search(vector<PersonalRecord> &Records)
{
    int usersChoice2 = 0;
    cout << "\n\n********Search*********" << endl;
    cout << "1. Name" << endl;
    cout << "2. DOB" << endl;
    cout << "3. Telephone No" << endl;
    cout << "-1. Cancel" << endl;
    usersChoice2 = inputValidation<int>("Chose a operation to perform ");

    switch (usersChoice2)
    {
    case 1:
    {
        string name;
        cin.ignore();
        cout << "Enter Name ";
        getline(cin, name);
        auto it = Records.begin();
        while (it != Records.end()) // iterating to the last vector
        {
            if ((it->name == name)) // if name maches show data
            {
                cout << "Record Found" << endl;
                it->Display();
                return;
            }
            it++;
        }
        if (Records.end()->name == name) // If name is at the last position
        {
            cout << "Record Found" << endl;
            Records.end()->Display();
        }
        else // If name is not found
        {
            cout << "No record is found" << endl;
        }
        break;
    }
    case 2: // same as for name but checking for date of birth
    {
        string name;
        cin.ignore();
        cout << "Enter DOB (dd/mm/yyyy) ";
        getline(cin, name);
        auto it = Records.begin();
        while (it != Records.end())
        {
            if ((it->birthdate == name))
            {
                cout << "Record Found" << endl;
                it->Display();
                return;
            }
            it++;
        }
        if (Records.end()->birthdate == name)
        {
            cout << "Record Found" << endl;
            Records.end()->Display();
        }
        else
        {
            cout << "No record is found" << endl;
        }
        break;
    }
    case 3: // same as for name but searchin for date of birth
    {
        string name;
        cin.ignore();
        cout << "Enter TelephoneNo ";
        getline(cin, name);
        auto it = Records.begin();
        while (it != Records.end())
        {
            if ((it->telephoneNo == name))
            {
                cout << "Record Found" << endl;
                it->Display();
                return;
            }
            it++;
        }
        if (Records.end()->name == name)
        {
            cout << "Record Found" << endl;
            Records.end()->Display();
        }
        else
        {
            cout << "No record is found" << endl;
        }
        break;
    }

    default:
        cout << "CANELLING" << endl;
        break;
    }
    return;
}

int main()
{
    vector<PersonalRecord> Records;
    int usersChoice = {0};
    while (usersChoice != -1)
    {
        cout << "\n\n********MENU*********" << endl;
        cout << "1. Create Record" << endl;
        cout << "2. Read Data Record" << endl;
        cout << "3. Update Record" << endl;
        cout << "4. Delete Record" << endl;
        cout << "5. Search" << endl;
        cout << "6. Sort" << endl;
        cout << "7. Display All" << endl;
        cout << "-1. Exit" << endl;
        usersChoice = inputValidation<int>("Chose a operation to perform ");

        switch (usersChoice)
        {
        case 1: //create record
        {
            PersonalRecord temp;
            temp.create();
            Records.push_back(temp);
            break;
        }
        case 2: //read record
        {
            int position = inputValidation<int>("Enter position to read data for the object ");
            if (Records.size() < position)
            {
                cout << "No object found at this position " << endl;
                break;
            }
            else
            {
                Records[position - 1].Display();
            }
            break;
        }
        case 3: //update record
        {
            int position = inputValidation<int>("Enter position to update data for the object ");
            if (Records.size() < position)
            {
                cout << "No object found at this position " << endl;
                break;
            }
            else
            {
                Records[position - 1].update();
            }
            break;
        }
        case 4: //delete record
        {
            int position = inputValidation<int>("Enter position to delete data for the object ");
            if (Records.size() < position)
            {
                cout << "No object found at this position " << endl;
                break;
            }
            else
            {
                Records.erase(Records.begin() + position - 1);
            }
            break;
        }
        case 5: //Search the records
        {
            Search(Records);
            break;
        }
        case 6: //sorting the data
        {
            int code = 0;
            cout << "\n\n********Sort*********" << endl;
            cout << "1. Name" << endl;
            cout << "2. DOB" << endl;
            cout << "3. Telephone No" << endl;
            cout << "-1. Cancel" << endl;
            code = inputValidation<int>("Chose a operation to perform ");
            switch (code)
            {
            case 1:
                cout << "\n\nSorting by Name..\n";
                sort(Records.begin(), Records.end(), PersonalRecord::compareByName);
                break;
            case 2:
                cout << "\n\nSorting by DOB..\n";
                sort(Records.begin(), Records.end(), PersonalRecord::compareByDOB);
                break;
            case 3:
                cout << "\n\nSorting by TelephoneNo..\n";
                sort(Records.begin(), Records.end(), PersonalRecord::compareByTelephoneNo);
                break;
            default:
                cout << "Invalid sorting option.\n";
                break;
            }
            break;
        }
        case 7: //displaying all the data
        {
            int i = 1;
            cout << endl;
            for (auto it = Records.begin(); it != Records.end(); it++, i++)
            {
                cout << "Position "
                     << i << endl;
                it->Display();
                cout << endl;
            }
            break;
        }
        case -1: //Exit
        {
            cout << "Exit" << endl;
            usersChoice = -1;
            break;
        }
        default:
        {
            cout << "Enter valid Choice";
            break;
        }
        }
    }
    return 0;
}