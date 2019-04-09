#include<iostream>

using namespace std;

int main() {
	int var = 65;
	int *iptr = &var;
	char *cptr;
	cptr = (char *)&var;
	cout << "iptr = " << iptr << endl;
	cout << "*iptr = " << *iptr << endl;
	cout << "(void *)cptr = " << (void *)cptr << endl;  //Character 포인터는 문자열을 출력하게 되어있음. void: 타입은 필요하지만 타입이 결과에 크게 상관 없는경우.
	cout << "*cptr = " << *cptr << endl;

	return 0;
}