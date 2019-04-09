#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//Stack
const int stackSize = 2;
char stack[stackSize]; 
int top;
void create_stack();
void push(char);
void displayStack();
char pop();
int isStackFull(); 
int isStackEmpty();


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

//Circular Queue
int circularQueue[sizeQueue];
int cfront, crear;
void create_cqueue();
void c_enqueue(int);
int c_dequeue();
int iscFull();
int iscEmpty();
void print_cqueue();


int main()
{
	create_stack();
	create_queue();
   	push('a');
   	enqueue('b');
   	enqueue('c');
   	enqueue('d');
   	push('e');

   	push('F');
   	enqueue('G');

   	cout << endl;

   	displayStack();

   	print_queue();

   	cout << pop() << " " << dequeue() << " " << dequeue() << " " << dequeue() << " " << pop() << endl;

   	cout << pop() << ", " << dequeue() << endl;

   	create_cqueue();

   	c_enqueue('A');
   	c_enqueue('B');
   	c_enqueue('C');
   	c_dequeue();
   	c_enqueue('D');

   	print_cqueue();

   	c_dequeue();
   	c_dequeue();
   	c_dequeue();
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
		cout << "Queue Full";
		return 1;
	}
	else {
		return 0;
	}
}

int isQueueEmpty() {
	if(front == rear) {
		cout << "QueueEmpty";
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
		cout << "Queue : ";
		while(i <= rear) {
			cout << (char)queue[i] << " ";
			i = i + 1;
		}
		cout << endl;
	}
}

void create_cqueue() {
	cfront = -1;
	crear = -1;
}

void c_enqueue(int item) {
	if(iscFull()) {
		cout << "QueueFull" << endl;
	}
	else {
		circularQueue[++crear] = item;
	}
}

int c_dequeue() {
	if(iscEmpty()) {
		cout << "QueueEmpty" << endl;
		return 0;
	}
	else {
		cfront = (cfront+1) % sizeQueue;
		return circularQueue[front];
	}
}

int iscFull() {
	int tmp = (crear+1) % sizeQueue;
	if(tmp == cfront) {
		return 1;
	}
	else {
		return 0;
	}
}

int iscEmpty() {
	if(cfront == crear) {
		return 1;
	}
	else {
		return 0;
	}
}

void print_cqueue() {
	int i;

	if(iscEmpty()) {
		cout << "Queue is Empty!" << endl;
	}
	else {
		i = cfront + 1;
		while(i <= crear) {
			cout << (char)circularQueue[i] << " ";
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
   	cout << "StackEmpty";
	return 1;
   } 
   else return 0;
}

void push(char item) {
	if(isStackFull()) {
		cout << "Stack Full,  ";
	}
	else {
   		++top;
   		stack[top] = item;
	}
}

char pop() {
	if(isStackEmpty()) {
		
		return (stack[top--]);
	}
	else {
		return (stack[top--]);
	}
}

void displayStack()
{
   int sp;
   if (isStackEmpty()) cout << "" << endl;
   else {
   	cout << "Stack : ";
      sp = top; // sp = temporary pointer
      while (sp != -1) {
         cout << stack[sp] << " "; 
         sp--;
      }

   }
}