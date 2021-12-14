// !Author: Rohan Doshi
// ?Problem statement Assignemt 12

/*
Write a program in C++ to use map associative container. 
The keys will be the names of states and the values will be the populations of the states.
When the program runs, the user is prompted to type the name of a state. 
The program then looks in the map, using the state name as an index and returns the population of the state
*/

#include <iostream>
#include <map>
#include <iomanip>
#define mp make_pair
using namespace std;

class States
{
private:
    map<string, int> population;

public:
    States()
    {
        population.insert(mp("Uttar Pradesh", 199812341));
        population.insert(mp("Maharashtra", 112374333));
        population.insert(mp("Bihar", 104099452));
        population.insert(mp("West Bengal", 91276115));
        population.insert(mp("Madhya Pradesh", 72626809));
        population.insert(mp("Tamil Nadu", 72147030));
    }
    void find()
    {
        string stateName;
        cout << "Enter state Name: ";
        cin.ignore();
        getline(cin, stateName);
        auto iter = population.find(stateName);
        if (iter != population.end())
            cout << stateName << " 's population is " << iter->second;
        else
            cout << "Key is not present in Map"
                 << "\n";
    }
    void display()
    {
        for (auto x : population)
            cout << setw(15) << x.first << ":\t" << x.second << endl;
        cout << endl;
    }
};

int main()
{
    States populationMap;
    bool repeat = true;
    while (repeat)
    {

        cout << "\n *** Menu ***";
        cout << "\n 1. Search State";
        cout << "\n 2. Display All";
        cout << "\n -1. Exit";
        cout << "\n\n Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            populationMap.find();
            break;
        }

        case 2:
        {
            populationMap.display();
            break;
        }
        case -1:
        {
            repeat = false;
            break;
        }

        default:
            cout << "\n\t Wrong choice!!!";
        }
    }
    return 0;
}
