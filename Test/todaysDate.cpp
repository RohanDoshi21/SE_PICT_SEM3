#include <iostream>
#include <ctime>
#include <sstream>
using namespace std;

int main()
{
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    int year = 1900 + local_time->tm_year;
    int month = 1 + local_time->tm_mon;
    string monthStr;
    if (month<10){
         monthStr = '0' + to_string(month);
    }
    else {
         monthStr = to_string(month);
    }
    int day = local_time->tm_mday;
    string todaysdate = to_string(day) + '/' + monthStr + '/' + to_string(year);
    cout << todaysdate << endl;
    string temp;
    try
    {
        cout << "Enter your birthday (dd/mm/yyyy): ";
        cin >> temp;
        int day1;
        int month1;
        int year1;
        stringstream day2, month2, year2;
        day2 << temp.substr(0,2);
        day2 >> day1;
        month2 << temp.substr(3,2);
        month2 >> month1;
        year2 << temp.substr(6,4);
        year2 >> year1;
        if (temp[2] != '/' || temp[5] != '/')
        {
            throw "Invalid birthdate";
        }
        else if (year1 > year) {
            throw "Invalid birthdate";
        }
        else if (year1 == year && month1 > month) { 
            throw "Invalid birthdate";
        }
        else if (month1 == month && day1 >= day && year1 == year) { 
            throw "Invalid birthdate";
        }
        cout << temp << endl;
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }
    return 0;
}