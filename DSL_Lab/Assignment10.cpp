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

template <typename T>
class Node
{
private:
public:
    T data;
    Node<T> *next;
    explicit Node(T data, Node<T> *next = nullptr) : data(data), next(next){};

    // friend class Stack;
};

template <typename T>
class Stack
{
private:
    Node<T> *top;

public:
    Stack() : top(nullptr){};

    void push(T data)
    {
        auto *temp = new Node<T>(data);
        temp->next = top;
        top = temp;
    }

    T pop()
    {
        if (top == nullptr)
        {
            return '1';
        }
        else
        {
            Node<T> *temp = top;
            top = top->next;
            temp->next = nullptr;
            T x = temp->data;
            delete temp;
            return x;
        }
    }

    bool isEmpty()
    {
        return top == nullptr ? true : false;
    }

    T getTop()
    {
        return top->data;
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

float calculate(float a, float b, char x)
{
    float result = 0;
    if (x == '*')
        return a * b;
    else if (x == '/')
        return a / b;
    else if (x == '+')
        return a + b;
    else if (x == '-')
        return a - b;
    return 0;
}

int main()
{
    Stack<char> operatorStack;
    Stack<float> operandStack;
    float result = 0;
    string expression;
    cout << "Enter a expression ";
    getline(cin, expression);
    for (auto i : expression)
    {
        if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9')) // case for characters and numbers
        {
            cout << i;
            operandStack.push(i);
        }
        else // last case : if it is an operator
        {
            while (!operatorStack.isEmpty() && prec(i) <= prec(operatorStack.getTop())) // till empty and less than the precedence of top
            {
                float a, b;
                a = operandStack.pop() - 48;
                b = operandStack.pop() - 48;
                float result1 = calculate(a, b, operatorStack.getTop());
                operandStack.push(result1 + 48);
                cout << operatorStack.getTop();
                operatorStack.pop();
            }
            operatorStack.push(i);
        }
    }
    while (!operatorStack.isEmpty())
    {
        float a, b;
        b = operandStack.pop() - 48;
        a = operandStack.pop() - 48;
        float result1 = calculate(a, b, operatorStack.getTop());
        operandStack.push(result1 + 48);
        cout << operatorStack.getTop();
        operatorStack.pop();
    }
    cout << "\n Evaluation is: " << operandStack.pop() - 48;
    return 0;
}