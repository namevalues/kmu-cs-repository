#include<iostream>

using namespace std;

int factorial(int n) {
    if (n == 1)
        return 1;
    else
        return factorial(n-1) * n;
}

int main()
{
    int input;
    cin >> input;
    cout << factorial(input) << endl;
    return 0;
}