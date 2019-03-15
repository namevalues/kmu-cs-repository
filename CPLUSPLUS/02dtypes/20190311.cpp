#include<iostream>

using namespace std;

int main() {
	const int MONTHS = 12;
	double m_salary = 0, y_salary;

	cout << "월급을 입력하세요 : ";
	cin >> m_salary;

	y_salary = 12 * m_salary;
	cout << "연봉은 " << y_salary << "입니다." << endl;
	return 0;
}