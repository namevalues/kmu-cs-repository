#include<iostream>
#include<climits>

using namespace std;

int main() {
	short year = SHRT_MAX;
	int sale = INT_MAX;
	long total_sale = LONG_MAX;

	cout <<"short 형의 크기"<<sizeof(short)<<endl;
	cout <<"int 형의 크기"<<sizeof(int)<<endl;
	cout <<"long 형의 크기"<<sizeof(long)<<endl;
	return 0;
}