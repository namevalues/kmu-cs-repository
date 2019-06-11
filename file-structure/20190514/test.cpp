#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int arr[9];	//배열 사이즈 9
int top;

void create_arr();
int push(int number);
int pop();
int isFull();
int isEmpty();
void displayStack();
void search(int num);

void create_arr() {
	top = 0;
}
int isFull() {
	if (top == 8)
		return 1;
	else
		return 0;
}
int isEmpty() {
	if (top == 0)
		return 1;
	else
		return 0;
}
int push(int num) {
	int i;
	if (isFull()) {
		cout << "Heap is full....\n" << endl;
		return 0;
	}
	i = ++top;
	while ((i != 1) && (num > arr[i / 2]))
	{
		arr[i] = arr[i / 2];
		i = i / 2;
	}
	arr[i] = num;
}
int pop() {
	int parent, child;
	int item, temp;

	item = arr[1];
	temp = arr[top--];
	parent = 1;
	child = 2;
	while (child <= top) {
		if ((child < top) && (arr[child] < arr[child + 1]))
			child++; /* find largest child */
		if (temp >= arr[child]) break;
		arr[parent] = arr[child];
		parent = child;
		child = child * 2;
	}
	arr[parent] = temp;
	return item;
}

void displayStack()
{
	int sp;
	if (isEmpty())
		cout << "Heap is empty!" << endl;
	else
	{
		sp = 1;
		while (sp != top + 1)
		{
			cout << arr[sp] << " ";
			++sp;
		}
		cout << "\t" << endl;
		cout << "Heap Level : " << int(log2(top)) + 1 << endl;
	}
}

void search(int num)
{
	int sp;
	if (isEmpty())
		cout << "Heap is empty!" << endl;
	else
	{
		sp = 1;
		while (sp != top + 1 && arr[sp] != num)
			++sp;
		if (sp != top + 1)
			cout << arr[sp] << endl;
		else
			cout << "not exist" << endl;
	}
}

int main()
{
	create_arr();
	string input;
	int count = 1;

	while (true) {
		cout << "(1. Insert, 2. Delete, 3. Empty, 4. Full, 5. Search , 6. Level and print, 7. Quit) " << endl;
		cout << "원하는 명령을 입력하세요 : ";
		cin >> input;
		if (input == "1") {
			int num;
			cout << "원하는 숫자를 넣어주세요 : ";
			cin >> num;
			push(num);
		}
		else if (input == "2") {
			pop();
			displayStack();
		}
		else if (input == "3")
		{
			if (isEmpty())
				cout << "Heap is empty" << endl;
			else
				cout << "Heap is not empty" << endl;
		}
		else if (input == "4")
		{
			if (isFull())
				cout << "Heap is FULL" << endl;
			else
				cout << "Heap is not FULL" << endl;
		}
		else if (input == "5") {
			int find;
			cout << "찾을 숫자를 입력하세요 : ";
			cin >> find;
			search(find);
		}
		else if (input == "6") {
			displayStack();
		}
		else if (input == "7") {
			break;
		}
		else {
			cout << "다시 입력하세요. " << endl;
		}

	}

	return 0;
}