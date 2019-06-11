#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

int main(void)
{

  int count;
  
  cin >> count;

  while (count--)
  {

    int data;

    const unsigned int umax = 0xffffffff;

    vector<unsigned int> arr;

    int count = 0;

    int temp, temp1;

    cin >> data;

    for (unsigned int k = 1;; k *= 2)
    {

      for (unsigned int l = k;; l *= 3)
      {

        for (unsigned int m = l;; m *= 5)
        {

          arr.push_back(m);

          if (m > umax / 5)
            break;
        }

        if (l > umax / 3)
          break;
      }

      if (k > umax / 2)
        break;
    }

    sort(arr.begin(), arr.end());

    cout << arr[data - 1] << endl;
  }

  return 0;
}