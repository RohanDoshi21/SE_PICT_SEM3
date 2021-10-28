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
#include <list>
#include <iterator>
#include <iomanip>
using namespace std;
#define nL "\n"

class Publication
{
protected: // protected as we are going to inherit these data members in class Book and class Tape
    float price;

public:
    string title; // making it public so that it can be searched

public:
    Publication(string title = "", float price = 0.0) : title(title), price(price){}; // this is parametrized constructor with default values
    float getPrice() { return price; }
};

class Book : public Publication
{
private:
    int pageCount;

public:
    Book(string title = "", float price = 0.0, int pageCount = 0) : Publication{title, price}, pageCount{pageCount} {}; // this is parametrized constructor with default values which calls constructor of class Publication setting required values
    ~Book();

    int getPageCount() { return pageCount; }

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
            cin.ignore(1000, '\n');
            getline(cin, title);
            if (title.length() == 0) // if length of title is null it is not valid
            {
                throw 0;
            }
            else
            {
                for (auto i : title)
                {
                    if (isdigit(i))
                    {
                        throw 0;
                        break;
                    }
                }
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
            cout << "Enter Price: ";
            if (cin >> price)
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
    Tape(string title = "", float price = 0.0, float playingTime = 0.0) : Publication{title, price}, playingTime(playingTime){}; // this is parametrized constructor with default values which calls constructor of class Publication setting required values
    ~Tape();
    float getTime() const { return playingTime; }
    void getDetails() // Getter for showing the details of all the data members
    {
        cout << "\n***Showing parameters for Tape***" << nL;
        cout << "Cassette Title: " << this->title << nL;
        cout << "Playing Time: " << this->playingTime << nL;
        cout << "Price: " << this->price << nL << nL;
    }

    void setDetails() // setter for setting all the details of all the data members
    {
        try
        {
            cout << "Enter Title: ";
            cin.ignore(1000, '\n');
            getline(cin, title);
            if (title.length() == 0) // if length of title is null it is not valid
            {
                throw 0;
            }
            else
            {
                for (auto i : title)
                {
                    if (isdigit(i))
                    {
                        throw 0;
                        break;
                    }
                }
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
            cout << "Enter Price: ";
            if (cin >> price)
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

    list<Book> bookList;
    list<Tape> tapeList;
    int usersChoice = {0};
    while (usersChoice != -1)
    {
        cout << "\n********MENU*********" << endl;
        cout << "1. Create data for new Book" << nL;
        cout << "2. Create data for new Tape" << nL;
        cout << "3. Display all books" << nL;
        cout << "4. Display all Tapes" << nL;
        cout << "5. Search Book" << nL;
        cout << "6. Search Tape" << nL;
        cout << "7. Delete data" << nL;
        cout << "8. Display All Data" << nL;
        cout << "-1. Exit" << nL;
        cout << "Chose a operation to perform ";
        cin >> usersChoice;

        switch (usersChoice)
        {
        case 1:
        {
            cout << "Creating new record for a Book" << nL;
            Book newBook;
            newBook.setDetails();
            bookList.push_back(newBook);
            // cin.ignore(1000, '\n');
            break;
        }
        case 2:
        {
            cout << "Creating new record for a Tape" << nL;
            Tape newTape;
            newTape.setDetails();
            tapeList.push_back(newTape);
            // cin.ignore(1000, '\n');
            break;
        }
        case 3:
        {
            if (bookList.size() == 0)
            {
                cout << "No record exist!" << nL;
            }
            else
            {
                list<Book>::iterator it;
                for (it = bookList.begin(); it != bookList.end(); ++it)
                {
                    it->getDetails();
                    cout << nL;
                }
            }
            break;
        }
        case 4:
        {
            if (tapeList.size() == 0)
            {
                cout << "No record exist!" << nL;
            }
            else
            {
                list<Tape>::iterator it;
                for (it = tapeList.begin(); it != tapeList.end(); ++it)
                {
                    it->getDetails();
                    cout << nL;
                }
            }
            break;
        }
        case 5:
        {
            cout << "Enter the name of the book to be searched ";
            string name;
            cin.ignore(1000, '\n');
            getline(cin, name);
            list<Book>::iterator it;
            bool isFound = false;
            for (it = bookList.begin(); it != bookList.end(); ++it)
            {
                if (name == it->title)
                {
                    cout << "Book Found! " << nL;
                    it->getDetails();
                    isFound = true;
                    cout << nL;
                }
            }
            if (!isFound)
            {
                cout << "Book not found" << nL;
            }
            break;
        }
        case 6:
        {
            cout << "Enter the name of the Tape to be searched ";
            string name;
            cin.ignore(1000, '\n');
            getline(cin, name);
            list<Tape>::iterator it;
            bool isFound = false;
            for (it = tapeList.begin(); it != tapeList.end(); ++it)
            {
                if (name == it->title)
                {
                    cout << "Tape Found! " << nL;
                    it->getDetails();
                    isFound = true;
                    cout << nL;
                }
            }
            if (!isFound)
            {
                cout << "Tape not found" << nL;
            }
            break;
        }
        case 7:
        {
            int choice;
            cout << "Which data do you want to delete? 1.Book 2.Tape 3.Cancel ";
            cin >> choice;

            if (choice == 1)
            {
                cout << "Enter name of book to delete ";
                string name;
                cin.ignore(1000, '\n');
                getline(cin, name);
                bool isFound = false;
                list<Book>::iterator it;
                for (it = bookList.begin(); it != bookList.end(); ++it)
                {
                    if (name == it->title)
                    {
                        isFound = true;
                        bookList.erase(it);
                        cout << "Deleted book record" << nL;
                        break;
                    }
                }
                if (!isFound)
                {
                    cout << "Book not found" << nL;
                }
            }
            else if (choice == 2)
            {
                cout << "Enter name of Tape to delete ";
                string name;
                cin.ignore(1000, '\n');
                getline(cin, name);
                bool isFound = false;
                list<Tape>::iterator it;
                for (it = tapeList.begin(); it != tapeList.end(); ++it)
                {
                    if (name == it->title)
                    {
                        isFound = true;
                        tapeList.erase(it);
                        cout << "Deleted Tape record" << nL;
                        break;
                    }
                }
                if (!isFound)
                {
                    cout << "Tape not found" << nL;
                }
            }
            break;
        }
        case 8:
        {
            if (bookList.size() == 0)
            {
                cout << "No record exist for Books!" << nL;
            }
            else
            {
                cout << "Displaying data for books" << nL << nL;
                cout << "Title " << setw(12) << "Price " << setw(12) << "Page Count" << setw(12) << nL;
                list<Book>::iterator it;
                for (it = bookList.begin(); it != bookList.end(); ++it)
                {
                    cout << it->title << setw(12) << it->getPrice() << setw(12) << it->getPageCount() << setw(12) << nL;
                }
            }
            cout << nL << nL;
            if (tapeList.size() == 0)
            {
                cout << "No record exist for Tapes!" << nL;
            }
            else
            {
                cout << "Displaying data for Tapes" << nL << nL;
                cout << "Title " << setw(12) << "Price " << setw(12) << "Play Time" << setw(12) << nL;
                list<Tape>::iterator it;
                for (it = tapeList.begin(); it != tapeList.end(); ++it)
                {
                    cout << it->title << setw(12) << it->getPrice() << setw(12) << it->getTime() << setw(12) << nL;
                }
            }
            break;
        }
        case -1:
        {
            cout << "Exit" << endl;
            usersChoice = -1;
            break;
        }
        }
    }
    return 0;
}