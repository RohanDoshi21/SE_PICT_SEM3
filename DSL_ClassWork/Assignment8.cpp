//! Author: Rohan Doshi
//? Problem statement Group C - 21

/*
Write C++ program for storing appointment schedule for day. Appointments are booked
randomly using linked list. Set start and end time and min and max duration for visit slot.
Write functions for
A) Display free slots 
B) Book appointment 
C) Sort list based on time
D) Cancel appointment ( check validity, time bounds, availability)
E) Sort list based on time using pointer manipulation
*/

#include <iostream>
using namespace std;

class Node
{
private:
    Node *next;
    bool isBooked;
    // int duration;
    int start_hr;
    int min_durations;
    int max_durations;

public:
    Node(bool isBooked = false, int start_hr = 0, int min_durations = 0, int max_durations = 60)
    {
        this->isBooked = isBooked;
        // this->duration = duration;
        this->start_hr = start_hr;
        this->min_durations = min_durations;
        this->max_durations = max_durations;
        next = nullptr;
    };
    void MakeFree()
    {
        isBooked = false;
        min_durations = 0;
        max_durations = 60;
    }
    friend class DaySchedule;
};

class DaySchedule
{
private:
    Node *head;
    Node *tail;
    int start_hr;
    int end_hr;
    static int noOfSlots;

public:
    DaySchedule()
    {
        head = nullptr;
        tail = nullptr;
        cout << "Enter start hr of the day ";
        cin >> this->start_hr;
        cout << "Enter end hr for the day ";
        cin >> this->end_hr;
        for (int i = start_hr; i < end_hr; i++)
        {
            newSlot(i);
            noOfSlots++;
        }
    }
    void newSlot(int start_hr, int min_durations = 0, int max_durations = 60)
    {
        Node *temp = new Node();
        temp->start_hr = start_hr;
        // temp->min_durations = min_durations;
        // temp->max_durations = max_durations;
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void displaySlots()
    {
        Node *temp_ptr = head;
        while (temp_ptr != nullptr)
        {
            if (temp_ptr->isBooked)
            {
                cout << "Slot " << temp_ptr->start_hr << " to " << temp_ptr->start_hr + 1 << " is booked. "
                     << "Minimum time: " << temp_ptr->min_durations << endl;
            }
            else
            {
                cout << "Slot " << temp_ptr->start_hr << " to " << temp_ptr->start_hr + 1 << " is free" << endl;
            }
            temp_ptr = temp_ptr->next;
        }
    }
    void cancelAppointment()
    {
        int start_hr;
        cout << "Enter the slot to cancel" << endl;
        cin >> start_hr;
        if (checkFree(start_hr))
        {
            cout << "Slot is free! You cant cancel it if slot is not booked!" << endl;
        }
        else
        {
            Node *temp_ptr = head;
            while (temp_ptr->start_hr != start_hr)
            {
                temp_ptr = temp_ptr->next;
            }
            temp_ptr->MakeFree();
            cout << "Appointment cancel successful";
        }
    }
    bool checkFree(int start_hr)
    {
        bool isFree = true;
        Node *temp_ptr = head;
        while (temp_ptr != nullptr || !isFree)
        {
            if (temp_ptr->start_hr == start_hr && temp_ptr->isBooked == true)
            {
                isFree = false;
                break;
            }
            temp_ptr = temp_ptr->next;
        }
        return isFree;
    }
    void bookAppointment()
    {
        int start_hr;
        cout << "Enter start time ";
        cin >> start_hr;
        while (start_hr < this->start_hr && start_hr >= this->end_hr)
        {
            cout << "Enter slot between proper time " << endl;
            cin >> start_hr;
        }

        if (checkFree(start_hr))
        {
            Node *temp_ptr = head;
            while (temp_ptr->start_hr == start_hr)
            {
                temp_ptr = temp_ptr->next;
            }
            cout << "Slot available! " << endl;
            cout << "Enter min duration " << endl;
            cin >> temp_ptr->min_durations;
            cout << "Enter max duration " << endl;
            cin >> temp_ptr->max_durations;
            temp_ptr->isBooked = true;
        }
        else
        {
            cout << "Slot is Booked! " << endl;
        }
    }

    void Sort(int size)
    {
        Node *current = head;
        Node *currentCopy = head;
        Node *next_ptr = nullptr;
        while (current != nullptr)
        {
            auto temp_pos = current->next;
            next_ptr = current->next;
            while (next_ptr != nullptr)
            {
                if (next_ptr->min_durations > current->min_durations)
                {
                    auto temp = next_ptr->next;
                    if (head == current)
                    {
                        head = next_ptr;
                    }
                    next_ptr->next = current->next;
                    current->next = temp;
                }
                
            }
        }
    }

    ~DaySchedule()
    {
        Node *temp_ptr = head;
        while (head != nullptr)
        {
            head = head->next;
            delete temp_ptr;
            temp_ptr = head;
        }
    }
};

int DaySchedule::noOfSlots = 0;

int main()
{
    DaySchedule today;
    today.displaySlots();
    today.bookAppointment();
    today.bookAppointment();
    today.displaySlots();
    today.cancelAppointment();
}