#include <iostream>
using namespace std;
void outputZigZag(int n, int k);
int main(void)
{
int t;
int n, k;
    cin >> t;
    for(int i=0; i<t; i++)
	{
        cin >> n >> k;
        outputZigZag( n, k );
    }
    return 0;
}
void outputZigZag(int n, int k)
{
	int sum = 0;
	if(k%2 == 0) {
		for(int i = k; i > 0; i--) {
			sum += i;
		}
		cout << sum;
		for(int j = 1; j < k; j++) {
			cout << "*" << --sum;
		}
		cout << "\n";
	}
	else {
		for(int i = k-1; i > 0; i--) {
			sum += i;
		}
		cout << ++sum;
		for(int j = 1; j < k; j++) {
			cout << "*" << ++sum;
		}
		cout << endl;
	}
}