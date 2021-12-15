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

string tolower(string s1) // function to make the entire string to lower case
{
    for (int i = 0; i < s1.length(); i++)
    {
        s1[i] = tolower(s1[i]);
    }
    return s1;
}

class States
{
private:
    map<string, int> population; //map for storing state, population as pairs

public:
    States()
    {
        // hard coding the population of some states present in India
        population.insert(mp("Uttar Pradesh", 199812341));
        population.insert(mp("Maharashtra", 112374333));
        population.insert(mp("Bihar", 104099452));
        population.insert(mp("West Bengal", 91276115));
        population.insert(mp("Madhya Pradesh", 72626809));
        population.insert(mp("Tamil Nadu", 72147030));
    }
    void find() //searching for the key values
    {
        string stateName;
        cout << "Enter state Name: ";
        cin.ignore();
        getline(cin, stateName);
        // auto iter = population.find(stateName);
        // if (iter != population.end())
        //     cout << stateName << " 's population is " << iter->second;
        // else
        //     cout << "Key is not present in Map"
        //          << "\n";
        bool found = false;
        for (auto iter = population.begin(); iter != population.end(); iter++)
        {
            auto string1 = iter->first;
            string1 = tolower(string1);     //make lower
            stateName = tolower(stateName); // make lower
            int position = 0;
            int index_str;
            // find function return string::npos if substring is not found
            // if it finds it will return the 1st position
            while ((index_str = string1.find(stateName, position)) != string::npos)
            {
                cout << iter->first << " 's population is " << iter->second << endl;
                found = true;
                position = index_str + 1;
            }
        }
        if (!found)
        {
            cout << "No key found" << endl;
        }
    }
    void display()
    {
        for (auto x : population)
            cout << setw(15) << x.first << ":\t" << x.second << endl;
        cout << endl;
    }
    void insert(string state, int pop)
    {
        for (auto iter = population.begin(); iter != population.end(); iter++)
        {
            if (iter->first == state)
            {
                cout << "State Aldready Present in the Map" << endl;
                return;
            }
        }
        population.insert(mp(state, pop)); // inserting new value in the map
    }
    void update(string state, int pop)
    {
        for (auto iter = population.begin(); iter != population.end(); iter++)
        {
            if (iter->first == state)
            {
                population[state] = pop; //updating the state name
                return;
            }
        }
        cout << "State not present in the Map" << endl;
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
        cout << "\n 3. Add in Map";
        cout << "\n 4. Update Map";
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
        case 3:
        {
            cout << "Enter the state Name ";
            string stateName;
            cin >> stateName;
            cout << "Enter Population ";
            int pop;
            cin >> pop;
            populationMap.insert(stateName, pop);
            break;
        }
        case 4:
        {
            cout << "Enter the state Name ";
            string stateName;
            cin >> stateName;
            cout << "Enter Population ";
            int pop;
            cin >> pop;
            populationMap.update(stateName, pop);
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
