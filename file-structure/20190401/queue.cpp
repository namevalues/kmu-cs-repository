#include<iostream>

using namespace std;

const int sizeQueue = 10;
int queue[sizeQueue];
int front, rear;
void create_queue();
void enqueue(int);
int dequeue();
int isFull();
int isEmpty();
void print_queue();

int main() {
	create_queue();
	while(true) {
		int input;
		cin >> input;
		enqueue(input);
		print_queue();
	}
	return 0;
}

void create_queue() {
	front = -1;
	rear = -1;
}

void enqueue(int item) {
	if(rear == sizeQueue - 1) {
		isFull();
		return ;
	}
	queue[++rear] = item;
}

int dequeue() {
	if(front == rear){
		return isEmpty();
	}
	return queue[++front];
}

int isFull() {
	if(rear == sizeQueue - 1) {
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
			cout << queue[i] << " ";
			i = i + 1;
		}
		cout << endl;
	}
}