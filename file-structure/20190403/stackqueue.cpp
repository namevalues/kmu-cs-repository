#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


//Queue
const int sizeQueue = 3;
int queue[sizeQueue];
int front, rear;
void create_queue();
void enqueue(char);
char dequeue();
int isQueueFull();
int isQueueEmpty();
void print_queue();


//Stack
const int stackSize = 2;
char stack[stackSize]; 
int top;
void create_stack();
void push(char);
void traverse_stack();
void displayStack();
char pop();
int isStackFull(); 
int isStackEmpty();

int main()
{
   	int num;
   	char input[10];

	string filePath = "stackqueue.txt";
	ifstream openFile(filePath.data());
	if( openFile.is_open() ){
		string line;
		while(getline(openFile, line)){
			create_queue();
			create_stack();
			// 1번 검사
			push(line[0]);
			enqueue(line[1]);
			enqueue(line[2]);
			enqueue(line[3]);
			push(line[4]);
			push(line[0]); // Stack Full
			enqueue(line[0]); // Queue Full

			// 2번 검사
			displayStack();

			// 3번 검사
			print_queue();

			// 4번 검사
			cout << pop() << dequeue() << dequeue() << dequeue() << pop() << endl;

			// 5번 검사
			pop();
			dequeue();
		}
		openFile.close();
	}
}

void create_queue() {
	front = -1;
	rear = -1;
}

void enqueue(char item) {
	if(rear == sizeQueue - 1) {
		isQueueFull();
		return ;
	}
	queue[++rear] = item;
}

char dequeue() {
	if(front == rear){
		return isQueueEmpty();
	}
	return queue[++front];
}

int isQueueFull() {
	if(rear == sizeQueue - 1) {
		cout << "Queue is Full!" << endl;
		return 1;
	}
	else {
		return 0;
	}
}

int isQueueEmpty() {
	if(front == rear) {
		
		return 1;
	}
	else {
		return 0;
	}
}

void print_queue() {
	int i;

	if(isQueueEmpty()) {
		cout << "Queue is Empty!" << endl;
		
	}
	else {
		i = front + 1;
		cout << "-- Print Queue --" << endl;
		while(i <= rear) {
			cout << (char)queue[i] << " ";
			i = i + 1;
		}
		cout << endl;
	}
}



void create_stack() { top = -1; } //stack create

int isStackFull() {
   if (top == stackSize - 1) {
   	return 1;
   }
   else return 0;
}

int isStackEmpty() {
   if (top == -1) {
   	cout << "Stack is empty!" << endl;
	return 1;
   } 
   else return 0;
}

void push(char item) {
	if(isStackFull()) {
		cout << "Stack is Full!" << endl;
	}
	else {
   		++top;
   		stack[top] = item;
	}
}

char pop() {
	return (stack[top--]);
}

void displayStack()
{
   int sp;
   if (isStackEmpty()) cout << "" << endl;
   else {
   	cout << "-- Print Stack --" << endl;
      sp = 0; // sp = temporary pointer
      while (sp <= top) {
         cout << stack[sp] << " "; 
         sp++;
      }
      cout << endl;
   }
}