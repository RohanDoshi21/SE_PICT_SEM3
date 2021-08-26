// !Author: Rohan Doshi
// ? Problem statement
/*
Create an structure Account that the bank might use to represent 
customer bank accounts. Include the data members Name, Account 
number and Account balance. Provide three member functions in a 
class, member function Credit() should add an amount to current 
balance and member function Debit() should withdraw the money 
from the account and ensures that the debit amount does not exceed 
the account's balance. If it does, the balance should left unchanged 
and the function should print a message indicating " Debit Amount 
Exceeded Account Balance ". Member function getBalance() should 
display the current balance with customers information . Create a 
Program that display information of five Customers. 
*/

#include <iostream>
using namespace std;

class Account
{
    string Name;
    int AccountNumber;
    float AccountBalance;

public:
    Account(string NameParameter, int AccountNumberParameter)
    {
        Name = NameParameter;
        AccountNumber = AccountNumberParameter;
        AccountBalance = 0;
    }
    float credit(float amount)
    {
        AccountBalance += amount;
        return AccountBalance;
    }
    float debit(float amount)
    {
        if (AccountBalance - amount < 0)
        {
            cout << "Debit Amount Exceeded Account Balance\n";
            return -1;
        }
        else
        {
            AccountBalance -= amount;
            return AccountBalance;
        }
    }
    float getBalance()
    {
        return AccountBalance;
    }
};

int main()
{
    Account a1("Rohan", 1), a2("Rohit", 2), a3("Muks", 3), a4("sid", 4), a5("Raj", 5);
    a1.credit(500);
    cout << a1.getBalance() << "\n";
    a1.debit(800);
    a1.debit(300);
    cout << a1.getBalance() << "\n";
    return 0;
}