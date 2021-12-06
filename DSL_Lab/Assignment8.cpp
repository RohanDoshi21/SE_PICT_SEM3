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
#include <iomanip>
using namespace std;

class Node
{
private:
    Node *next;
    bool isBooked;
    int start_time;
    int end_time;
    int min_duration;
    int max_duration;

public:
    Node(bool isBooked = false, int start_time = 0, int end_time = 0, int min_duration = 0, int max_duration = 60)
    {
        this->isBooked = isBooked;
        this->start_time = start_time;
        this->end_time = end_time;
        this->min_duration = min_duration;
        this->max_duration = max_duration;
        next = nullptr;
    };
    friend class DaySchedule;
};

class DaySchedule
{
private:
    Node *head;
    Node *tail;
    Node *sorted;         //used for insertion sort
    static int noOfSlots; // used for sorting

public:
    DaySchedule()
    {
        head = nullptr;
        tail = nullptr;
        sorted = nullptr;
    }

    void MakeSlot(int startTime = 0)
    {
        Node *temp = new Node();
        noOfSlots++;
        if (startTime == 0)
        {
            cout << "Enter start time ";
            cin >> startTime;
        }
        temp->start_time = startTime;
        cout << "Enter end time ";
        cin >> temp->end_time;
        cout << "Max duration ";
        cin >> temp->max_duration;
        cout << "Min duration: ";
        cin >> temp->min_duration;

        if (head == nullptr) // if list is empty
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

    void DisplaySlots()
    {
        if (head != nullptr)
        {
            Node *temp = head;
            cout << "****BookedSlots****" << endl;
            cout << left << setw(15) << "Start Time" << left << setw(15) << "End Time" << left << setw(15) << "Max Duration" << left << setw(15) << "Min Duration" << endl;
            while (temp != nullptr)
            {
                cout << left << setw(15) << temp->start_time << left << setw(15) << temp->end_time << left << setw(15) << temp->max_duration << left << setw(15) << temp->min_duration << endl;
                temp = temp->next;
            }
        }
        else // if list is empty
        {
            cout << "No slots booked till now" << endl;
        }
    }

    void BookAppointment()
    {
        cout << "Enter the start time(hr) ";
        int startTime;
        cin >> startTime;
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->start_time <= startTime && temp->end_time > startTime) // check if start time lies in between existing start and end times
            {
                cout << "Slot is aldready booked please try again!" << endl;
                return;
            }
            temp = temp->next;
        }
        MakeSlot(startTime);
    }

    void CancelAppointment()
    {
        cout << "Enter the start time(hr) to cancel the appointment ";
        int startTime;
        cin >> startTime;
        Node *temp = head;
        Node *temp_ptr = head; // using 2 pointer for deletion
        while (temp != nullptr)
        {
            if (temp->start_time == startTime) // if slot is found
            {
                cout << "Slot found! \tPress Y to cancel the appointment ";
                char input;
                cin >> input;
                if (input == 'Y' || input == 'y') // confirmation to cancel the slot
                {
                    if (head->next == nullptr) // deletion if list has only one node
                    {
                        head = nullptr;
                    }
                    else if (temp = head) // deletion to delete the element at head
                    {
                        head = temp->next;
                    }
                    else
                    {
                        temp_ptr->next = temp->next;
                    }
                    delete temp;
                    noOfSlots--;
                    return;
                }
                else
                {
                    cout << "Did not cancel the appointment" << endl;
                    return;
                }
            }
            temp_ptr = temp;
            temp = temp->next;
        }
        cout << "Did not find slot" << endl;
    }

    void SortStartTime()
    {
        for (int i = 0; i < noOfSlots - 1; i++)
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                if (temp->start_time > temp->next->start_time)
                {
                    int val = temp->start_time;
                    temp->start_time = temp->next->start_time;
                    temp->next->start_time = val;

                    val = temp->end_time;
                    temp->end_time = temp->next->end_time;
                    temp->next->end_time = val;

                    val = temp->min_duration;
                    temp->min_duration = temp->next->min_duration;
                    temp->next->min_duration = val;

                    val = temp->max_duration;
                    temp->max_duration = temp->next->max_duration;
                    temp->next->max_duration = val;
                }
                temp = temp->next;
            }
        }
    }

    void insert(Node *temp)
    {
        if (sorted == nullptr || sorted->start_time >= temp->start_time) // insertion before the head (here head is sorted)
        {
            temp->next = sorted;
            sorted = temp;
        }
        else
        {
            Node *current = sorted;
            while (current->next != nullptr && current->next->start_time < temp->start_time)
            {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
        }
    }

    void insertionSort()
    {
        Node *current = head;

        while (current != nullptr)
        {
            Node *next = current->next;
            insert(current);
            current = next;
        }
        head = sorted;
    }
};

int DaySchedule::noOfSlots = 0; // initialization of static variable

int main()
{
    DaySchedule today;
    bool repeat = true;
    while (repeat)
    {

        cout << "\n *** Menu ***";
        cout << "\n 1. Book an Appointment";
        cout << "\n 2. Display Slots";
        cout << "\n 3. Sort based on start time";
        cout << "\n 4. Cancel an Appointment";
        cout << "\n 5. Sort pointer manipulation";
        cout << "\n 6. Exit";

        cout << "\n\n Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            today.BookAppointment();
            break;

        case 2:
            today.DisplaySlots();
            break;

        case 3:
            today.SortStartTime();
            break;

        case 4:
            today.CancelAppointment();
            break;

        case 5:
            today.insertionSort();
            break;

        case 6:
            repeat = false;
            break;

        default:
            cout << "\n\t Wrong choice!!!";
        }
    }
    return 0;
}