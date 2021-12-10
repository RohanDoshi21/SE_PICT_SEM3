//! Author: Rohan Doshi
//? Problem statement Group D - 27

/*
Implement C++ program for expression conversion as infix to postfix and its evaluation 
using stack based on given conditions: 
1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
3. Only '+', '-', '*' and '/ ' operators are expected.
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

int prec(char c)
{
    if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

int main()
{
    Stack s1;
    string expression;
    cout << "Enter a expression ";
    getline(cin, expression);
    for (auto i : expression)
    {

        if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9')) // case for characters and numbers
            cout << i;
        else if (i == '(') // bracket case
            s1.push('(');
        else if (i == ')') // closing bracket case
        {
            while (s1.getTop() != '(')
            {
                cout << s1.getTop();
                s1.pop();
            }
            s1.pop();
        }
        else // last case : if it is a operator
        {
            while (!s1.isEmpty() && prec(i) <= prec(s1.getTop()))  // till empty and less than the precedence of top
            {
                cout << s1.getTop();
                s1.pop();
            }
            s1.push(i);
        }
    }
    while (!s1.isEmpty())
    {
        cout << s1.getTop();
        s1.pop();
    }
    return 0;
}