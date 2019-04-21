#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
const int stackSize = 3;
int stack[stackSize];
int top;
void create_stack();
void push(int);
void traverse_stack();
void displayStack();
int pop();
int isFull();
int isEmpty();
int isCheck(string);
int main()
{
    int num;
    char input[50];
    string filePath = "lab3.txt";
    ifstream openFile(filePath.data());
    if (openFile.is_open())
    {
        string line;
        while (getline(openFile, line))
        {
            create_stack();
            if (isCheck(line))
            {
                cout << "valid" << endl;
            }
            else
            {
                cout << "invalid" << endl;
            }
        }
        openFile.close();
    }
}
void create_stack() { top = -1; }
int isFull()
{
    if (top == stackSize - 1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
void push(int num)
{
    ++top;
    stack[top] = num;
}
int pop()
{
    return (stack[top--]);
}
void displayStack()
{
    int sp;
    if (isEmpty())
        cout << "Stack is empty!" << endl;
    else
    {
        sp = top;
        while (sp != -1)
        {
            cout << stack[sp] << " ";
            sp--;
        }
        cout << endl;
    }
}
int isCheck(string exp)
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            if (exp[i] == '(')
                push(')');
            else if (exp[i] == '{')
                push('}');
            else if (exp[i] == '[')
                push(']');
        }
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty())
            {
                cout << "(UnBalanced parentheses)";
                return 0;
            }
            else
            {
                char temp = pop();
                if (temp != exp[i])
                {
                    cout << "(mismatched parentheses)";
                    return 0;
                }
            }
        }
    }
    if (isEmpty())
    {
        return 1;
    }
    else
    {
        cout << "(UnBalanced parentheses)";
        return 0;
    }
}