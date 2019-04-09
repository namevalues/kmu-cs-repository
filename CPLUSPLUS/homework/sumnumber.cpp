#include<iostream>

using namespace std;

int main() {
	int count,num,item;
	cin >> count;
	for(int i = 0; i < count; i++) {
		cin >> num;
		int sum = 0;
		for(int j = 0; j < num; j++) {
			cin >> item;
			sum += item;
		}
		cout << sum << endl;
	}
	return 0;
}