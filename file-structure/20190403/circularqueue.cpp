#include<iostream>
#define Queue_size 3

using namespace std;

int queue[Queue_size];
int front, rear;
void create_queue();
void enqueue(int);
int dequeue();
int isFull();
int isEmpty();
void print_queue();

int main() {
	create_queue(); //front = -1 rear = -1
	enqueue('a'); //rear = 0 front = -1
	enqueue('b'); //rear = 1 front = -1
	enqueue('c'); //rear = 2 front = -1
	dequeue();    //rear = 2 front = 0
	enqueue('a'); //rear = 0 front = 0
	print_queue();
	dequeue();
	dequeue();
	dequeue();
	return 0;
}

void create_queue() {
	front = -1;
	rear = -1;
}

void enqueue(int item) {
	if(isFull()) {
		cout << "Queue is Full" << endl;
	}
	else {
		queue[++rear] = item;
	}
}

int dequeue() {
	if(isEmpty()) {
		cout << "Queue is Empty" << endl;
		return 0;
	}
	else {
		front = (front+1) % Queue_size;
		return queue[front];
	}
}

int isFull() {
	int tmp = (rear+1) % Queue_size;
	if(tmp == front) {
		return 1;
	}
	else {
		return 0;
	}
}

int isEmpty() {
	if(front == rear) {
		return 1;
	}
	else {
		return 0;
	}
}

void print_queue() {
	int i;

	if(isEmpty()) {
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