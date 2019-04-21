// Recursive addition / Recursive Difference / Recursive Sum

#include <iostream>

using namespace std;

int recursive_addition(int a, int b)
{
    if(a == 0)
        return b;
    else
    {
        return recursive_addition(a-1, b+1);
    }   
}

int recursive_difference(int a, int b)
{
    if(a == 0)
    {
        if(b < 0)
            return -b;
        else
        {
            return b;
        }
    }
    else
    {
        return recursive_difference(a-1,b-1);
    }
}

int recursive_sum(int a, int sum = 0)
{
    if(a == 0)
        return sum;
    if(a == 1)
    {
        cout << a << " = ";
        return recursive_sum(0,sum + 1);
    }
    else
    {
        cout << a << " + ";
        return recursive_sum(a-1, sum + a);
    }
}

int main(void)
{
    cout << recursive_addition(2,5) << endl;
    cout << recursive_difference(2,5) << endl;
    cout << recursive_sum(5) << endl;
}