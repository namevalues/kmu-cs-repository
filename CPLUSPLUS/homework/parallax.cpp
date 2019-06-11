#include <iostream>

using namespace std;

int crossCheck(int,int,int,int,int,int,int,int);

int main(void)
{
  int k;
  cin >> k;
  for (int i = 0; i < k; i++)
  {
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    cout << crossCheck(x1,y1,x2,y2,x3,y3,x4,y4) << endl;
  }
}

int crossCheck(int x1,int y1, int x2,int y2, int x3,int y3, int x4,int y4) {

  if((x1 == x3 || x1 == x4) && y3 <= y1 && y1 <= y4) {
    return 2;
  }
  else if((x1<x3<x2)&&(y3<y2<y4)) {
    return 1;
  }
  else 
    return 0;
}
