#include<iostream>

using namespace std;

int main() {
	int a[2][3];
	a[0][0] = 10;
	a[0][1] = -1;
	a[0][2] = 3;
	a[1][0] = 2;
	a[1][1] = 5;
	a[1][2] = 6;

	int (*numPtr)[3] = a;



	for(int i = 0; i < 2; i ++) {
		for(int j = 0; j < 3; j++) {
			cout << "a["<<i<<"]["<<j<<"]="<<a[i][j]<<" at "<<&a[i]<<endl;
		}
	}

	return 0;
}