#include <iostream>
#define nL cout << "\n"
using namespace std;

class User
{
private:
    int age;
    long salary;
    string city;
    string car;

public:
    User(int age = 0, long salary = 0, string city = "", string car = "")
    {
        this->age = age;
        this->salary = salary;
        this->city = city;
        this->car = car;
    };
    void inputData()
    {
        try
        {
            cout << "Enter age ";
            cin >> age;
            if (age > 55 || age < 18)
            {
                throw age;
            }
            nL;
            cout << "Enter income ";
            cin >> salary;
            if (salary > 100000 || salary < 50000)
            {
                throw salary;
            }
            nL;
            cout << "Enter city ";
            cin >> city;
            if (city != "Pune" || city != "Mumbai" || city != "Banglore" || city != "Chennai")
            {
                throw city;
            }
            nL;
        }
        catch (int &a)
        {
            cout << "Value " << a << " not accepted";
            nL;
        }
        catch (long &a)
        {
            cout << "Value " << a << " not accepted";
            nL;
        }
        catch (string a)
        {
            cout << "Value " << a << " not accepted";
            nL;
        }
        try
        {
            cout << "Enter 4 wheeler ";
            cin >> car;
            if (car != "Honda")
            {
                throw car;
            }
        }
        catch (string a)
        {
            cout << "Value " << a << " not accepted";
            nL;
        }
    }
};

int main()
{
    User obj;
    obj.inputData();
    return 0;
}