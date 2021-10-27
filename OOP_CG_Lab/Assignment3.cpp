// !Author: Rohan Doshi
// ?Problem statement Group A - 1

/*
Imagine a publishing company which does marketing for book and audio cassette 
versions. Create a class publication that stores the title (a string) and price (type float) of 
a publication. 
From this class derive two classes: book, which adds a page count (type int), and tape, 
which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape classes, allows user to enter data 
and displays the data members. If an exception is caught, replace all the data member 
values with zero values.
*/

#include <iostream>
using namespace std;
#define nL "\n"

class Publication
{
protected: // protected as we are going to inherit these data members in class Book and class Tape
    string title;
    float price;

public:
    Publication(string title = "", float price = 0.0) : title(title), price(price){}; // this is parametrized constructor with default values
    ~Publication();
};

Publication::~Publication()
{
}

class Book : public Publication
{
private:
    int pageCount;

public:
    Book(string title = "", float price = 0.0, int pageCount = 0) : Publication{title, price}, pageCount{pageCount} {}; // this is parametrized constructor with default values which calls constructor of class Publication setting required values
    ~Book();

    void getDetails() // Getter for showing the details of all the data members
    {
        cout << "\n***Showing parameters for Book***" << nL;
        cout << "Book Title: " << this->title << nL;
        cout << "Page Count: " << this->pageCount << nL;
        cout << "Price: " << this->price << nL;
    }

    void setDetails() // setter for setting all the details of all the data members
    {
        try
        {
            cout << "Enter Title: ";
            getline(cin, title);
            if (title.length() == 0) // if length of title is null it is not valid
            {
                throw 0;
            }
        }
        catch (...) // catch statement for all exceptions
        {
            cout << "Failed to set title initializing all paramters to 0" << nL;
            title = "";
            price = 0.0;
            pageCount = 0;
            return;
        }

        try
        {
            cout << "Enter Page count: ";
            if (cin >> pageCount)
            {
            }
            else // exception handling for input
                throw 0;
        }
        catch (...) // catch all the exceptions
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Setting page count failed setting all values to 0" << nL;
            title = "";
            price = 0.0;
            pageCount = 0;
            return;
        }

        try
        {
            cout << "Enter Price: " << nL;
            if (cin >> pageCount)
            {
            }
            else // exception handling for input
                throw 0;
        }
        catch (...) // catch all the exceptions
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Setting price failed setting all values to 0" << nL;
            title = "";
            price = 0.0;
            pageCount = 0;
            return;
        }
    }
};

Book::~Book()
{
}

class Tape : public Publication
{
private:
    float playingTime;

public:
    Tape(string title = "", float price = 0.0, float playingTime = 0.0) : Publication{title, price}, playingTime(playingTime){};
    ~Tape();

    void getDetails()
    {
        cout << "\n***Showing parameters for Tape***" << nL;
        cout << "Cassette Title: " << this->title << nL;
        cout << "Playing Time: " << this->playingTime << nL;
        cout << "Price: " << this->price << nL << nL;
    }

    void setDetails()
    {
        try
        {
            cout << "Enter Title: ";
            cin >> title;
            if (title.length() == 0) // exception handling for input
            {
                throw;
            }
        }
        catch (...) // catch all the exceptions
        {
            cout << "Failed to set title initializing all paramters to 0" << nL;
            title = "";
            price = 0.0;
            playingTime = 0;
            return;
        }

        try
        {
            cout << "Enter Playing Time: ";
            if (cin >> playingTime)
            {
            }
            else // exception handling for input
                throw 0;
        }
        catch (...) // catch all the exceptions
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Setting playing time failed setting all values to 0" << nL;
            title = "";
            price = 0.0;
            playingTime = 0;
            return;
        }

        try
        {
            cout << "Enter Price: " << nL;
            if (cin >> playingTime)
            {
            }
            else // exception handling for input
                throw 0;
        }
        catch (...) // catch all the exceptions
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Setting price failed setting all values to 0" << nL;
            title = "";
            price = 0.0;
            playingTime = 0;
            return;
        }
    }
};

Tape::~Tape()
{
}

int main()
{
    Book b1("Percy Jackson", 345.00, 488);
    b1.getDetails();

    Book b2;
    b2.setDetails();
    b2.getDetails();

    Tape t1;
    t1.setDetails();
    t1.getDetails();
    return 0;
}