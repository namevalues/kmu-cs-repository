#include <iostream>

using namespace std;

int closestNumber(int n, int m);
int main(void)
{
	int t;
	int n, m;
    cin >> t;
    for(int i=0; i<t; i++)
	{
        cin >> n >> m;
        cout << closestNumber( n, m ) << endl;
    }
    return 0;
}

int closestNumber(int n, int m)
{
	if(n >= 0) {
		if(m >= 0) {
			if(n%m >= m/2) {
				return (n/m + 1) * m;
			}
			else {
				return(n/m) * m;
			}
		}
		else {
			if(n%m >= -1 * m/2) {
				return (n/m - 1) * m;
			}
			else {
				return (n/m) * m;
			} 
		}
	}
	else {
		if(m >= 0) {
			if(n%m * -1 >= m/2) {
				return (n/m - 1) * m;
			}
			else {
				return (n/m) * m;
			}
		}
		else {
			if(n%m*-1 >= m/2 * -1) {
				return (n/m+1) * m;
			}
			else {
				return(n/m) * m;
			}
		}
	}
}