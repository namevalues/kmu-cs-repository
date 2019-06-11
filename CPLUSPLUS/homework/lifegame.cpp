#include <iostream>

using namespace std;

int main(void)
{
  int count;
  cin >> count;
  for (int i = 0; i < count; i++)
  {
    int a, b;
    cin >> a >> b;
    int *life = new int[a];
    int *original = new int[a];
    for (int j = 0; j < a; j++)
    {
      int x;
      cin >> x;
      life[j] = x;
      original[j] = x;
    }
    for (int j = 0; j < b; j++)
    {
      for (int k = 0; k < a; k++)
      {
        original[k] = life[k];
      }
      for (int k = 0; k < a; k++)
      {
        if (k == 0)
        {
          if (original[k + 1] < 3 || original[k + 1] > 7)
          {
            if (original[0] != 0)
            {
              life[0]--;
            }
          }
          else if (original[k + 1] > 3 && original[k + 1] <= 7)
          {
            if (original[0] != 9)
              life[0]++;
          }
        }
        else if (k == a - 1)
        {
          if (original[k - 1] < 3 || original[k - 1] > 7)
          {
            if (original[k] != 0)
            {
              life[k]--;
            }
          }
          else if (original[k - 1] > 3 && original[k - 1] <= 7)
          {
            if (original[k] != 9)
              life[k]++;
          }
        }
        else
        {
          if (original[k + 1] + original[k - 1] < 3 || original[k + 1] + original[k - 1] > 7)
          {
            if (original[k] != 0)
            {
              life[k]--;
            }
          }
          else if (original[k + 1] + original[k - 1] > 3 && original[k + 1] + original[k - 1] <= 7)
          {
            if (original[k] != 9)
              life[k]++;
          }
        }
      }
    }
    for (int l = 0; l < a; l++)
    {
      cout << life[l] << " ";
    }
    cout << endl;
  }
}