#include<iostream>

using namespace std;

int main() {
	int count,num;
	cin >> count;
	for(int i = 0; i < count; i++) {
		cin >> num;
		int sum = 0;
		while(num > 0){
			sum += num%10;
			num /= 10;
		}
		cout << sum << endl;
	}
	return 0;
}