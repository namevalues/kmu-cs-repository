#include <iostream>

using namespace std;

int main(void)
{
  int count;
  cin >> count;

  for (int i = 0; i < count; i++)
  {
    int gak;
    cin >> gak;
    int *arr = new int[gak*2];
    for (int j = 0; j < gak * 2; j++)
    {
      cin >> arr[j];
    }
    int area = (arr[gak*2-2]+arr[0])*(arr[1]-arr[gak*2-1]);
    // 0 10 1 1 10 0 1 -1 0 -10 -1 -1 -10 0 -1 1

    for (int j = 0; j < gak - 1; j++)
    {
      area += ((arr[2 * j] + arr[2 * (j + 1)]) * (arr[2 * (j + 1) + 1] - arr[2 * j + 1]));
    }

    if (area > 0)
    {
      cout << area << " " << 1 << endl;
    }
    else
    {
      cout << -1 * area << " " << -1 << endl;
    }
  }
}