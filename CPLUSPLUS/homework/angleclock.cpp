#include<iostream>

using namespace std;

int angleClock(int h, int m);

int main(void) {
	int t;
	int h, m;
    cin >> t;
    for(int i=0; i<t; i++)
	{
        cin >> h >> m;
        cout << angleClock( h, m ) << endl;
    }
    return 0;
}

int angleClock(int h, int m) {
	float value = 30 * h - 5.5 * m;
	if(value < 0) {
		value *= -1;
	}
	if (value > 180) {
		value = 360 - value;
	}
	return (int)value;
}