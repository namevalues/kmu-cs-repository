#include <iostream>

using namespace std;


// 1 1 1 5 4 1 
void getSpace(int arr[])
{
  int answer = (arr[2] - arr[0]) * (arr[5] - arr[1]) - (arr[4] - arr[0]) * (arr[3] - arr[1]);
  if(answer < 0)
    cout << answer * -1 << " " << -1 << endl;
  else if(answer == 0)
    cout << 0 << " " << 0 <<endl;
  else
    cout << answer << " " << 1 << endl;
}

int main(void)
{
  int count;
  cin >> count;
  for (int i = 0; i < count; i++)
  {
    int arr[6];
    for (int j = 0; j < 6; j++)
    {
      cin >> arr[j];
    }
    getSpace(arr);
  }
}