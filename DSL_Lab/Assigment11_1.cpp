//! Author: Rohan Doshi
//? Problem statement Group E - 29

/*
Queues are frequently used in computer programming, and a typical example is the 
creation of a job queue by an operating system. If the operating system does not use 
priorities, then the jobs are processed in the order they enter the system. Write C++ 
program for simulating job queue. Write functions to add job and delete job from queue. 
*/

#include <iostream>
using namespace std;

const int max_priority = 3;
class Node
{
private:
    string job_title;
    Node *next;
    int priority;

public:
    explicit Node(string job_title = "", int priority = 0, Node *next = nullptr) : job_title(job_title), next(next), priority(priority){};
    friend class Queue;
};

class Queue
{
    Node *front;

public:
    Queue() : front(nullptr){};

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(string job_title, int priority)
    {
        Node *temp = new Node(job_title, priority);
        if (isEmpty())
            front = temp; // condition for empty queue
        else
        {
            Node *pos = front;
            if (pos->next == nullptr) // 1st position
            {
                if (pos->priority > temp->priority)
                {
                    temp->next = pos;
                    front = temp;
                }
                else
                {
                    pos->next = temp;
                }
            }
            else
            {
                while (pos->next != nullptr)
                {
                    if (pos->next->priority > temp->priority)
                    {
                        temp->next = pos->next;
                        pos->next = temp;
                        return;
                    }
                    pos = pos->next;
                }
                pos->next = temp;
            }
        }
    }

    void dequeue()
    {
        if (!isEmpty())
        {
            Node *temp = front;
            front = front->next;
            cout << "Job removed: " << temp->job_title << endl;
            delete temp;
        }
        else
        {
            cout << "No element present in the Queue" << endl;
        }
    }

    void display()
    {
        if (!isEmpty())
        {
            Node *temp = front;
            while (temp != nullptr)
            {
                cout << "Job Title: " << temp->job_title << endl;
                temp = temp->next;
            }
        }
        else
        {
            cout << "No element present in the Queue" << endl;
        }
    }
};

int main()
{
    Queue os;
    bool repeat = true;
    while (repeat)
    {

        cout << "\n *** Menu ***";
        cout << "\n 1. Enqueue";
        cout << "\n 2. Dequeue";
        cout << "\n 3. Display";
        cout << "\n 4. Exit";
        cout << "\n\n Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string job_title = "";
            cout << "Enter Job Title ";
            cin.ignore();
            getline(cin, job_title);
            cout << "Enter Priority (1-" << max_priority << ") : ";
            int priority = 0;
            cin >> priority;
            while (priority <= 0 && priority > max_priority)
            {
                cout << "Enter only between (1-" << max_priority << ") : ";
                cin >> priority;
            }
            os.enqueue(job_title, priority - 1);
            break;
        }

        case 2:
        {
            os.dequeue();
            break;
        }

        case 3:
        {
            os.display();
            break;
        }

        case 4:
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