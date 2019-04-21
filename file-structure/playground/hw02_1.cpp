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
int lastElement();
void displayStack();
string infix_to_postfix(string);
int postfix_evaluation(string);
int pop();
int isFull();
int isEmpty();
int exp_operator(int);
int main()
{
    string filePath = "infix-postfix.txt";
    ifstream openFile(filePath.data());
    if (openFile.is_open())
    {
        string line;
        while (getline(openFile, line))
        {
            string postfix;
            cout << "Echo Data (infix form) : " << line << endl;
            postfix = infix_to_postfix(line);
            cout << "Conversion (postfix form):" << postfix << endl;
            cout << "Result : " << postfix_evaluation(postfix) << endl;
        }
        openFile.close();
    }
}

void create_stack() { top = -1; } //stack create

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

void push(int item)
{
    ++top;
    stack[top] = item;
}

int pop()
{
    return (stack[top--]);
}

int lastElement()
{
    return (stack[top - 1]);
}

void displayStack()
{
    int sp;
    if (isEmpty())
        cout << "Stack is empty!" << endl;
    else
    {
        sp = top; // sp = temporary pointer
        while (sp != -1)
        {
            cout << stack[sp] << " ";
            sp--;
        }
        cout << endl;
    }
}

// 0 1 2 3 4 5 6 7
// * = 5
// - = 4
int exp_operator(int x)
{
    char op[] = {'\0', '(', ')', '+', '-', '*', '/', '%'};
    int i;

    for (i = 1; i < 8; i++)
        if (op[i] == (char)x)
            return i;
    return 0;
}

// 7*8-(2+3)
// 7 8 * 2 3 + -

string infix_to_postfix(string line)
{
    string postfix = "";
    create_stack();
    int len = line.length();
    for (int i = 0; i < len; i++)
    {
        if (line[i] == '(')
        {
            push(line[i]);
        }
        else if (line[i] == ')')
        {
            char temp = (char)pop();
            while (temp != '(' && !isEmpty())
            {
                postfix += temp;
                temp = pop();
            }
        }
        else if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/' || line[i] == '%')
        {

            if (isEmpty())
            {
                push(line[i]);
            }
            else if (exp_operator(line[i]) > exp_operator(lastElement()))
            {
                char item = (char)pop();
                postfix += item;
                push(line[i]);
            }
            else
            {
                push(line[i]);
            }
        }
        else
        {
            postfix += line[i];
        }
    }
    while (!isEmpty())
    {
        char item = (char)pop();
        postfix += item;
    }
    return postfix;
}

int postfix_evaluation(string postfix)
{
    int len = postfix.length();
    create_stack();
    for (int i = 0; i < len; i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            int item = postfix[i] - '0';
            push(item);
        }
        else
        {
            int a = pop();
            int b = pop();
            switch (postfix[i])
            {
            case '+':
                push(b + a);
                break;
            case '-':
                push(b - a);
                break;
            case '*':
                push(b * a);
                break;
            case '/':
                push(b / a);
                break;
            }
        }
    }
    return pop();
}