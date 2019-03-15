#include<iostream>
#include<string>

using namespace std;

int main() {
	cout.setf(ios_base::fixed);
	float fvalue = 1234567890.12345678901234567890;
	double dvalue = 1234567890.12345678901234567890;
	float x = 1e39;
	float y = 1.23456e-46;
	double b;
	b = (1.0e20 + 5.0) - 1.0e20;
	cout << "float : " << fvalue << endl;
	cout << "double : " << dvalue << endl;
	cout << "3.14's size : " << sizeof(3.14) << endl;
	cout << x << endl;
	cout << y << endl;
	cout << b << endl;
	return 0;
}