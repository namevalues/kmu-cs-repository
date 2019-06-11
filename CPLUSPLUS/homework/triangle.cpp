#include<iostream>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int m;
    cin >> m;
    for(int k = 1; k <= m; k++) {
      int temp = m-1;
      int a = k;
      cout << k << " ";
      for(int l = 1; l < k; l++) {
        a += temp;
        cout << a << " ";
        temp--;
      }
      cout << endl;
    }
  }
}