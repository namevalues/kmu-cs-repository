#include<iostream>
 using namespace std;

 int recursive_addition(int a, int b)
 {
 	if (a == 0) {
 		return b-a;
 	}
 	else {
 		return recursive_addition(a-1, b+1);
 	}
 }

 int recursive_difference(int a, int b)
 {
 	if (a == 0)
 	{
 		return b-a;
 	}
 	else
 	{
 		return recursive_difference(a-1, b-1);
 	}
 }

 int recursive_sum(int a, int sum)
 {
 	if (a == 0) {
 		return sum;
 	}
 	else {
 		if (a != 1)
 		{
 			cout << a << " + ";
 		}
 		else {
 			cout << a << " = ";
 		}
 		return recursive_sum(a-1, sum+a);
 	}
 }

 int main() {
 	int a,b,c;
 	cout << "Enter Number 1 : ";
 	cin >> a;
 	cout << "Enter Number 2 : ";
 	cin >> b;
 	cout << "Addition Result is : " << recursive_addition(a,b) << endl;
 	cout << "Difference Result : " << recursive_difference(a,b) << endl;
 	cout << "Enter a number: ";
 	cin >> c;
 	cout << "Result is : " << recursive_sum(c,0) << endl;

 	return 0;
 }