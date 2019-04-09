#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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
	
	create_stack();

	string filePath = "Palindrome.txt";
	ifstream openFile(filePath.data());
	if( openFile.is_open() ){
		string line;
		while(getline(openFile, line)){
			int i = 0;
			int len = line.length();
			cout << len << endl;
			
			if(len % 2 == 0) {
				while(i < len/2) {
					push(line[i]);
					i++;
				}
			}
			else {
				while(i < len/2 ) {
					push(line[i]);
					i++;
				}
				i++;
			}
			while(line[i] != '\0') {
				if(line[i] != pop()) {
					cout << "not a palindrome" << endl;
					break;
				}
				else {
					i++;
				}
				if(isEmpty()) {
					cout << "Palindrome" << endl;
				}
			}
			
		}
		openFile.close();
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