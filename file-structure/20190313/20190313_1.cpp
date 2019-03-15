#include<iostream>

using namespace std;

int recursive_binary_search(int list[], int search_num, int left, int right)
{
	int middle;
	if (left <= right)
	{
		middle = (right + left) / 2;
		if(list[middle] > search_num) 
		{
			return recursive_binary_search(list, search_num, left, middle -1);
		}
		else if (list[middle] == search_num) {
			return middle;
		}
		else {
			return recursive_binary_search(list, search_num, middle + 1, right);
		}

	}
	return -1;
}

int main() {
	int list[] = {10,20,30,40,50,60,70,80,90,100 };
	int search_input, search_method;
	cout << "Enter an integer to search: ";
	cin >> search_input;
	cout << "Enter method of search: (1. Binary Search 2. Recursive binary search):  ";
	cin >> search_method;
	if(search_method == 1)
	{
		int left = 0,right = 9, middle;
		while(left <= right) 
		{
			middle = (left + right) / 2;
			if(list[middle] > search_input) {
				right = middle - 1;
			}
			else if (list[middle] == search_input) {
				cout << search_input << " is at position " << middle << endl;
				break;
			}
			else {
				left = middle + 1;
			}
			if (left == right) {
				cout << search_input << " is NOT FOUND" << endl;
			}
		}
	}
	else
	{
		if(recursive_binary_search(list,search_input,0,9) == -1) {
			cout << search_input << " is NOT FOUND" << endl;
		}
		else {
			cout << search_input << " is at position " << recursive_binary_search(list,search_input,0,9) << endl;
		}
	}
	return 0;
}