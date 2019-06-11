#include <iostream>

using namespace std;

template <typename T>
class Swap
{
public:
  void doIt(T &i, T &j);
};

template<class T>
void Swap<T>::doIt(T& a, T& b) {
  T temp;
  temp = a;
  a = b;
  b = temp;
}

int main()
{
  Swap<int> a;
  int i = 1, j = 2;

  cout << i << " " << j << endl;
  a.doIt(i, j);
  cout << i << " " << j << endl;
}