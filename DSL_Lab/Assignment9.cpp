//! Author: Rohan Doshi
//? Problem statement Group C - 21

/*
In any language program mostly syntax error occurs due to unbalancing delimiter such as
(),{},[]. Write C++ program using stack to check whether given expression is well
parenthesized or not.
*/

#include <iostream>
using namespace std;

class Node
{
private:
    char bracket;
    Node *next;

public:
    explicit Node(char bracket = ' ', Node *next = nullptr) : bracket(bracket), next(next){};

    friend class Stack;
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(nullptr){};

    void push(char bracket)
    {
        Node *temp = new Node(bracket);
        temp->next = top;
        top = temp;
    }

    char pop()
    {
        if (top == nullptr)
        {
            return '1';
        }
        else
        {
            Node *temp = top;
            top = top->next;
            temp->next = nullptr;
            char x = temp->bracket;
            delete temp;
            return x;
        }
    }

    bool isEmpty()
    {
        return top == nullptr ? true : false;
    }

    char getTop()
    {
        return top->bracket;
    }
};

int main()
{
    Stack s1;
    string expression;
    cout << "Enter a expression ";
    getline(cin, expression);
    for (auto i : expression)
    {
        if (i == '(' || i == '[' || i == '{')
        {
            s1.push(i);
            cout << "PUSHING " << i << endl;
        }
        else
        {
            if (i == ')')
            {
                if (!s1.isEmpty())
                {
                    if (s1.getTop() == '(')
                    {
                        cout << "POPING " << s1.getTop() << endl;
                        s1.pop();
                    }
                    else
                    {
                        cout << "Matching opening brace '(' is not found" << endl;
                        return 0;
                    }
                }
                else
                {
                    cout << "Stack is Empty" << endl;
                    return 0;
                }
            }
            if (i == ']')
            {
                if (!s1.isEmpty())
                {
                    if (s1.getTop() == '[')
                    {
                        cout << "POPING " << s1.getTop() << endl;
                        s1.pop();
                    }
                    else
                    {
                        cout << "Matching opening brace '[' is not found" << endl;
                        return 0;
                    }
                }
                else
                {
                    cout << "Stack is Empty" << endl;
                    return 0;
                }
            }
            if (i == '}')
            {
                if (!s1.isEmpty())
                {
                    if (s1.getTop() == '{')
                    {
                        cout << "POPING " << s1.getTop() << endl;
                        s1.pop();
                    }
                    else
                    {
                        cout << "Matching opening brace '{' is not found" << endl;
                        return 0;
                    }
                }
                else
                {
                    cout << "Stack is Empty" << endl;
                    return 0;
                }
            }
        }
    }
    if (s1.isEmpty())
    {
        cout << "Expression is well parenthesized" << endl;
    }
    else
    {
        if (s1.getTop() == '(')
        {
            cout << "Matching closing brace ')' is not found" << endl;
            return 0;
        }
        if (s1.getTop() == '{')
        {
            cout << "Matching closing brace '}' is not found" << endl;
            return 0;
        }
        if (s1.getTop() == '[')
        {
            cout << "Matching closing brace ']' is not found" << endl;
            return 0;
        }

        cout << "Expression is not well parenthesized" << endl;
    }
    return 0;
}
