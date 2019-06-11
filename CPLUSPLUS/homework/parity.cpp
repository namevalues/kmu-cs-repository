#include<iostream>

using namespace std;

int parity(int i)
{
  int count = 0;
  while(i > 0)
  {
    if(i%2)
    {
      count++;
    }
    i/=2;
  }
  return count;
}

int main(void)
{
  int count;
  cin >> count;
  for(int i = 0; i < count; i++)
  {
    int item;
    cin >> item;
    if(parity(item) % 2 == 0)
    {
      cout << item << endl;
    }
    else {
      unsigned int answer = 2147483648;
      cout << answer + item << endl;
    }
  }
}