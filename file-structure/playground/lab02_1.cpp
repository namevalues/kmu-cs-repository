// Binary Search 일반 방법과 Recursive한 방법.

#include <iostream>

using namespace std;

int binary_search(int array[], int left, int right, int target)
{
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (array[middle] == target)
        {
            return middle;
        }
        else if (array[middle] > target)
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }
    return -1;
}

int recursive_binary_search(int array[], int left, int right, int target)
{
    int middle = (left + right) / 2;
    if (left <= right)
    {
        if (array[middle] == target)
        {
            return middle;
        }
        else if (array[middle] > target)
        {
            return recursive_binary_search(array, left, middle - 1, target);
        }
        else
        {
            return recursive_binary_search(array, middle + 1, right, target);
        }
    }
    return -1;
}

int main(void)
{
    int array[5] = {1, 3, 5, 6, 8};
    int input;
    cin >> input;
    cout << binary_search(array, 0, 4, input) << endl;
    cin >> input;
    cout << recursive_binary_search(array, 0, 4, input) << endl;
}