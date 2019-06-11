#include <iostream>
#include <vector>
using namespace std;

enum CELLS
{
  CELL_EMPTY,
  CELL_BOX
};

class Position
{
public:
  int x, y;
  Position(int y = 0, int x = 0) : x(x), y(y) {}
  bool operator==(const Position &p)
  {
    return (x == p.x && y == p.y);
  }
};
#define ROWS 30
#define COLS 30
int map[ROWS][COLS];

bool isGameOver(vector<Position>& t)
{
  vector<Position>::iterator iter;
  for(iter = t.begin(); iter < t.end(); iter++) {
    if(map[iter->y][iter->x] == CELL_EMPTY) {
      return false;
    }
  }
  return true;
}

int main()
{
  int x, y;
  vector<Position> t;
  for (y = 0; y < ROWS; y++)
  {
    for (x = 0; x < COLS; x++)
    {
      map[y][x] = CELL_EMPTY;
    }
  }

  t.push_back(Position(3, 3));
  t.push_back(Position(4, 3));
  t.push_back(Position(5, 3));
  cout << isGameOver(t) << endl;

  map[3][3] = CELL_BOX;
  map[4][3] = CELL_BOX;
  map[5][3] = CELL_BOX;
  cout << isGameOver(t) << endl;
}