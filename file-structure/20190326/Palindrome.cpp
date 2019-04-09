#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

const int stackSize = 3;
int stack[stackSize]; int top;
void create_stack();
void push(int);
void traverse_stack();
void displayStack();
int pop(); 
int isFull(); 
int isEmpty();
int main()
{
   	int num; 
   	char input[10];
	
	while (1) {
   		cout << "Check PALINDROME : ";
   		create_stack();
      	cin >> input;
      
      	if(strlen(input) % 2 == 0) {
   			for(int i = 0; i < strlen(input) / 2; i++) {
   				push(input[i]);
   			}

   			for(int i = strlen(input) / 2; i < strlen(input); i++) {
      		if(input[i] == pop()) {

      		}
      		else {
      			cout << "NOT PALINDROME" << endl;
      			break;
      		}
      		if(isEmpty()) {
      			cout << "PALINDROME" << endl;
      		}
      	}
      	}
   		else {
      		for(int i = 0; i < strlen(input) / 2; i++) {
      			push(input[i]);
      		}

      		for(int i = strlen(input) / 2 + 1; i < strlen(input); i++) {
      		if(input[i] == pop()) {

      		}
      		else {
      			cout << "NOT PALINDROME" << endl;
      			break;
      		}
      		if(isEmpty()) {
      			cout << "PALINDROME" << endl;
      		}
      	}
      	}

      	
      	displayStack();
   }
}
void create_stack() { top = -1; } //stack create
int isFull() {
   if (top == stackSize - 1) return 1;
   else return 0;
}
int isEmpty() {
   if (top == -1) return 1;
   else return 0;
}
void push(int num) {
   ++top;
   stack[top] = num;
}
int pop() {
   return (stack[top--]);
}
void displayStack()
{
   int sp;
   if (isEmpty()) cout << "Stack is empty!" << endl;
   else {
      sp = top; // sp = temporary pointer
      while (sp != -1) {
         cout << stack[sp] << " "; 
         sp--;
      }
      cout << endl;
   }
}