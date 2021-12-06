//! Author: Rohan Doshi
//? Problem statement Group C - 23

/*
Write C++ program for storing binary number using doubly linked lists. Write function
a) To compute 1‘s and 2‘s complement
b) Add two binary numbers
*/

#include <iostream>
#define nL "\n"
using namespace std;

class Node
{
private:
    int data;
    Node *prev;
    Node *next;

public:
    explicit Node(int data = 0)
    {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
    friend class Binary;
};

class Binary
{
    Node *head;
    Node *tail;

public:
    Binary()
    {
        head = nullptr;
        tail = nullptr;
    }
    ~Binary()
    {
        while (head != nullptr)
        {
            auto temp = head->next;
            delete head;
            head = temp;
        }
    }
    void input()
    {
        int bytes;
        cout << "Enter no of bits ";
        cin >> bytes;
        if (bytes > 0)
        {
            for (int i = 0; i < bytes; ++i)
            {
                int data;
                cin >> data;
                while (data != 0 && data != 1)
                {
                    cout << "Enter 0 or 1 only" << endl;
                    cin >> data;
                }
                insertAtHead(data);
            }
        }
    }

    void display()
    {
        auto temp = tail;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
    }
    void insertAtHead(int data)
    {
        if (head == nullptr)
        {
            Node *temp = new Node(data);
            head = temp;
            tail = temp;
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    void insertAtTail(int data)
    {
        if (head == nullptr)
        {
            Node *temp = new Node(data);
            head = temp;
            tail = temp;
        }
        else
        {
            Node *temp = new Node(data);
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    Binary onesComplement()
    {
        Binary obj;
        auto temp = head;
        while (temp != nullptr)
        {
            int data;
            temp->data == 1 ? data = 0 : data = 1;
            obj.insertAtTail(data);
            temp = temp->next;
        }
        return obj;
    }

    Binary twosComplement()
    {
        Binary obj;
        auto temp = head;
        int carry = 1;
        while (temp != nullptr)
        {
            int data;
            temp->data == 1 ? data = 0 : data = 1;
            if (carry == 1)
            {
                data += carry;
                if (data == 2)
                {
                    carry = 1;
                    data = 0;
                }
                else
                {
                    carry = 0;
                }
            }
            obj.insertAtTail(data);
            temp = temp->next;
        }
        if (carry == 1)
        {
            obj.insertAtTail(carry);
        }
        return obj;
    }

    Binary Add(const Binary &no2)
    {
        auto no1_ptr = head;
        auto no2_ptr = no2.head;
        Binary obj;
        int carry = 0;
        while (no1_ptr != nullptr || no2_ptr != nullptr)
        {

            int data = carry;
            carry = 0;
            if (no1_ptr != nullptr)
            {
                data += no1_ptr->data;
                no1_ptr = no1_ptr->next;
            }

            if (no2_ptr != nullptr)
            {
                data += no2_ptr->data;
                no2_ptr = no2_ptr->next;
            }

            if (data == 3)
            {
                carry = 1;
                data = 1;
            }
            if (data == 2)
            {
                carry = 1;
                data = 0;
            }
            obj.insertAtTail(data);
        }
        if (carry == 1)
        {
            obj.insertAtTail(carry);
        }
        return obj;
    }

    void inputDecimal(int data){
        while(data/2){
            int remainder = data%2;
            data /= 2;
            insertAtTail(remainder);
        }
        data != 0 ? insertAtTail(1) : insertAtTail(0);
    }
};

int main()
{
    Binary obj1, obj2;
    cout << "Enter the first Binary number " << endl;
    obj1.input();
    cout << nL;
    cout << "Enter the second binary number " << endl;
    obj2.input();
    int usersChoice = {0};
    while (usersChoice != -1)
    {
        cout << "********MENU*********" << endl;
        cout << "1. one's Complement" << endl;
        cout << "2. 2's Complement" << endl;
        cout << "3. Add" << endl;
        cout << "-1. Exit" << endl;
        cout << "Chose a operation to perform ";
        cin >> usersChoice;

        switch (usersChoice)
        {
        case 1:
        {
            cout << "*********************" << endl;
            cout << "1st number: ";
            obj1.display();
            cout << nL;
            cout << "1's complement: ";
            Binary temp = obj1.onesComplement();
            temp.display();
            cout << nL;
            cout << "2st number: ";
            obj2.display();
            cout << nL;
            cout << "1's complement: ";
            Binary temp2 = obj2.onesComplement();
            temp2.display();
            cout << nL;
            break;
        }
        case 2:
        {
             cout << "*********************" << endl;
            cout << "1st number: ";
            obj1.display();
            cout << nL;
            cout << "2's complement: ";
            Binary temp = obj1.twosComplement();
            temp.display();
            cout << nL;
            cout << "2st number: ";
            obj2.display();
            cout << nL;
            cout << "2's complement: ";
            Binary temp2 = obj2.twosComplement();
            temp2.display();
            cout << nL;
            break;
        }
        case 3:
        {
            cout << "*********************" << endl;
            Binary temp = obj1.Add(obj2);
            cout << "1st number: ";
            obj1.display();
            cout << nL;
            cout << "2nd number: ";
            obj2.display();
            cout << nL;
            cout << "Addition: " ;
            temp.display();
            cout << nL;
            break;
        }
        case -1:
        {
            cout << "Exit" << endl;
            usersChoice = -1;
            break;
        }
        default:
        {
            cout << "Enter valid Choice";
            break;
        }
        }
    }


    cout << "Convert a number into binary" << nL;
    cout << "Enter a number ";

    int number = 0;
    cin >> number;
    Binary obj;
    obj.inputDecimal(number);
    obj.display();

    return 0;
}