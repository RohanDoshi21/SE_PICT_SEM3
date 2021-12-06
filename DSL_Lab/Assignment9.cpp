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
    Node(char bracket = ' ', Node *next = nullptr) : bracket(bracket), next(next){};

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
        if (top = nullptr)
        {
            top = temp;
        }
        else
        {
            top->next = temp;
            top = temp;
        }
    }

    char pop()
    {
        if (top == nullptr)
        {
            return ' ';
        }
        else
        {
            char bracket = top->bracket;
            auto temp = top->next;
            delete top;
            top = temp;
            return bracket;
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
    getline(cin, expression);
    for (auto i : expression)
    {
        if (i == '(' || i == '[' || i == '{')
        {
            if (s1.isEmpty())
            {
                s1.push(i);
            }
            else
            {
                char top = s1.getTop();
                if (top == '(' && i == ')')
                {
                    s1.pop();
                }
                else if (top == '[' && i == ']')
                {
                    s1.pop();
                }
                else if (top == '{' && i == '}')
                {
                    s1.pop();
                }
                else if (top == '(' && i != ')' || i != '[' || i != '{' || i != '(')
                {
                    cout << "Not well parenthesized" << endl;
                    return 0;
                }
                else if (top == '[' && i != ']' || i != '[' || i != '{' || i != '(')
                {
                    cout << "Not well parenthesized" << endl;
                    return 0;
                }
                else if (top == '{' && i != '}' || i != '[' || i != '{' || i != '(')
                {
                    cout << "Not well parenthesized" << endl;
                    return 0;
                }
                else
                {
                    s1.push(i);
                }
            }
        }
    }
    cout << "Well Parenthesized" << endl;
    return 0;
}