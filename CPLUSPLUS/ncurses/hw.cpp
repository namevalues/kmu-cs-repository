#include <ncurses.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
//0 : street
//1 : wall
//2 : box
//3 : destination
//4 : outside
//5 : character
#define N 100
struct Pos
{
  int xpos;
  int ypos;
  unsigned char z;
  chtype z2;
};
int lev = 1;
int boxes = 0;
int arrive = 0;
int moving = 0;
int boxmoving = 0;
struct Pos pos[N] = {};
struct Pos des[N] = {};
void style()
{
  init_pair(0, COLOR_WHITE, COLOR_BLACK);
  init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_BLACK, COLOR_YELLOW);
}
void map(int *height, int *wide, int y, int x, int *arr, int level)
{
  if (level == 1)
  {
    int map1[5][5] = {
        {1, 1, 1, 1, 4},
        {1, 3, 2, 0, 1},
        {1, 3, 2, 0, 1},
        {1, 5, 0, 0, 1},
        {1, 1, 1, 1, 1},
    };
    *height = 5;
    *wide = 5;
    *arr = map1[y][x];
  }
  else if (level == 2)
  {
    int map1[8][8] = {
        {1, 1, 1, 1, 4, 4, 4},
        {1, 0, 3, 3, 0, 4, 4},
        {1, 1, 5, 0, 0, 4, 4},
        {1, 1, 0, 2, 3, 4, 4},
        {1, 1, 0, 0, 0, 0, 1},
        {4, 1, 2, 2, 0, 0, 1},
        {4, 1, 0, 0, 0, 0, 1},
        {4, 1, 1, 1, 1, 1, 4},
    };
    *height = 8;
    *wide = 8;
    *arr = map1[y][x];
  }
  else if (level == 3)
  {
    int map1[9][7] = {
        {1, 1, 1, 1, 4, 4, 4},
        {1, 3, 0, 0, 1, 4, 4},
        {1, 3, 5, 0, 0, 4, 4},
        {1, 3, 0, 2, 0, 4, 4},
        {1, 1, 2, 0, 1, 1, 1},
        {4, 1, 0, 2, 0, 0, 1},
        {4, 1, 0, 0, 0, 0, 1},
        {4, 1, 0, 0, 1, 1, 1},
        {4, 1, 1, 1, 1, 4, 4},

    };
    *height = 9;
    *wide = 7;
    *arr = map1[y][x];
  }
  else if (level == 4)
  {
    int map1[9][7] = {
        {1, 1, 1, 1, 4, 4, 4},
        {1, 0, 0, 1, 1, 4, 4},
        {1, 3, 5, 0, 1, 4, 4},
        {1, 3, 0, 2, 1, 4, 4},
        {1, 1, 2, 3, 1, 1, 1},
        {4, 1, 0, 2, 0, 0, 1},
        {4, 1, 0, 0, 0, 0, 1},
        {4, 1, 0, 0, 0, 1, 1},
        {4, 1, 1, 1, 1, 4, 4},

    };
    *height = 9;
    *wide = 7;
    *arr = map1[y][x];
  }
}

void levelTest(int level)
{
  clear();
  int i = 0, j = 0, h = 1, w = 1, mp;
  moving = 0;
  arrive = 0;
  boxes = 0;
  boxmoving = 0;
  mvprintw(1, 1, "Push Game");
  mvprintw(2, 1, "Map -> %d", level);
  mvprintw(15, 1, "Character Move -> %d", moving);
  mvprintw(15, 25, "Box Move -> %d", boxmoving);
  mvprintw(3, 1, "Move : W A S D, Restart : R,  Previous Map : 1, Next Map : 2, Exit : Q");
  for (j = 0; j < h; j++)
  {
    for (i = 0; i < w; i++)
    {
      map(&h, &w, j, i, &mp, level);
      if (mp == 0) //street case
      {
        mvaddch(j + 6, i + 6, '0' | COLOR_PAIR(0));
      }
      else if (mp == 1) //wall case
      {
        mvaddch(j + 6, i + 6, '1' | COLOR_PAIR(1));
      }
      else if (mp == 2) //box case
      {
        mvaddch(j + 6, i + 6, '0' | COLOR_PAIR(0));
        boxes++;
        pos[boxes].z2 = mvinch(j + 6, i + 6);
        pos[boxes].ypos = j + 6;
        pos[boxes].xpos = i + 6;
        pos[boxes].z = '2';
        mvaddch(pos[boxes].ypos, pos[boxes].xpos, pos[boxes].z | COLOR_PAIR(2));
      }
      else if (mp == 3) //destination
      {
        mvaddch(j + 6, i + 6, '3' | COLOR_PAIR(3));
        des[arrive].ypos = j + 6;
        des[arrive].xpos = i + 6;
        arrive++;
      }
      else if (mp == 4) //outsice case
      {
        mvaddch(j + 6, i + 6, '4' | COLOR_PAIR(4));
      }
      else if (mp == 5) //character case
      {
        mvaddch(j + 6, i + 6, '0' | COLOR_PAIR(0));
        pos[0].z2 = mvinch(j + 6, i + 6);
        pos[0].ypos = j + 6;
        pos[0].xpos = i + 6;
        pos[0].z = 'P';
        mvaddch(pos[0].ypos, pos[0].xpos, pos[0].z | COLOR_PAIR(5));
      }
    }
  }
  move(pos[0].ypos, pos[0].xpos);
}
void playgame(char num)
{
  chtype up, left, down, right, up2, left2, down2, right2, check;
  int restart = 0, n = 0;

  up = (mvinch(pos[0].ypos - 1, pos[0].xpos) & A_CHARTEXT);
  left = (mvinch(pos[0].ypos, pos[0].xpos - 1) & A_CHARTEXT);
  down = (mvinch(pos[0].ypos + 1, pos[0].xpos) & A_CHARTEXT);
  right = (mvinch(pos[0].ypos, pos[0].xpos + 1) & A_CHARTEXT);

  up2 = (mvinch(pos[0].ypos - 2, pos[0].xpos) & A_CHARTEXT);
  left2 = (mvinch(pos[0].ypos, pos[0].xpos - 2) & A_CHARTEXT);
  down2 = (mvinch(pos[0].ypos + 2, pos[0].xpos) & A_CHARTEXT);
  right2 = (mvinch(pos[0].ypos, pos[0].xpos + 2) & A_CHARTEXT);

  for (int i = 0; i < arrive; i++)
  {
    check = (mvinch(des[i].ypos, des[i].xpos) & A_CHARTEXT);
    if (check == '2')
    {
      n++;
    }
  }
  for (int i = 0; i <= boxes; i++)
  {
    mvaddch(pos[i].ypos, pos[i].xpos, pos[i].z2);
  }

  if (n == arrive)
  {
    restart = 1;
    if (lev < 4)
    {
      lev += 1;
    }
    else
    {
      lev = 1;
    }
    levelTest(lev);
  }
  else if (num == 'w' || num == 'W')
  {
    if (up != '1' && up != '4')
    {

      if (up == '2' && (up2 == '0' || up2 == '3'))
      {
        moving++;
        boxmoving++;
        pos[0].ypos -= 1;
        for (int j = 1; j <= boxes; j++)
        {
          if ((pos[0].ypos == pos[j].ypos) && (pos[0].xpos == pos[j].xpos))
          {
            pos[j].ypos -= 1;
          }
        }
      }
      else if (up != '2')
      {
        moving++;
        pos[0].ypos -= 1;
      }
    }
    mvprintw(15, 1, "Character Move -> %d", moving);
    mvprintw(15, 25, "Box Move -> %d", boxmoving);
  }
  else if (num == 'a' || num == 'A')
  {
    if (left != '1' && left != '4')
    {
      if (left == '2' && (left2 == '0' || left2 == '3'))
      {
        moving++;
        boxmoving++;
        pos[0].xpos -= 1;
        for (int j = 1; j <= boxes; j++)
        {
          if ((pos[0].ypos == pos[j].ypos) && (pos[0].xpos == pos[j].xpos))
          {
            pos[j].xpos -= 1;
          }
        }
      }
      else if (left != '2')
      {
        moving++;
        pos[0].xpos -= 1;
      }
    }
    mvprintw(15, 1, "Character Move -> %d", moving);
    mvprintw(15, 25, "Box Move -> %d", boxmoving);
  }
  else if (num == 's' || num == 'S')
  {
    if (down != '1' && down != '4')
    {

      if (down == '2' && (down2 == '0' || down2 == '3'))
      {
        moving++;
        boxmoving++;
        pos[0].ypos += 1;
        for (int j = 1; j <= boxes; j++)
        {
          if ((pos[0].ypos == pos[j].ypos) && (pos[0].xpos == pos[j].xpos))
          {
            pos[j].ypos += 1;
          }
        }
      }
      else if (down != '2')
      {
        moving++;
        pos[0].ypos += 1;
      }
    }
    mvprintw(15, 1, "Character Move -> %d", moving);
    mvprintw(15, 25, "Box Move -> %d", boxmoving);
  }
  else if (num == 'd' || num == 'D')
  {
    if (right != '1' && right != '4')
    {

      if (right == '2' && (right2 == '0' || right2 == '3'))
      {
        moving++;
        boxmoving++;
        pos[0].xpos += 1;
        for (int j = 1; j <= boxes; j++)
        {
          if ((pos[0].ypos == pos[j].ypos) && (pos[0].xpos == pos[j].xpos))
          {
            pos[j].xpos += 1;
          }
        }
      }
      else if (right != '2')
      {
        moving++;
        pos[0].xpos += 1;
      }
    }
    mvprintw(15, 1, "Character Move -> %d", moving);
    mvprintw(15, 25, "Box Move -> %d", boxmoving);
  }
  else if (num == '1')
  {
    restart = 1;
    if (lev > 1)
    {
      lev--;
    }
    levelTest(lev);
  }
  else if (num == '2')
  {
    restart = 1;
    if (lev < 4)
    {
      lev += 1;
    }
    levelTest(lev);
  }
  else if (num == 'r' || num == 'R')
  {
    restart = 1;
    levelTest(lev);
  }
  if (!restart)
  {
    for (int i = 0; i <= boxes; i++)
    {
      pos[i].z2 = mvinch(pos[i].ypos, pos[i].xpos);
      mvaddch(pos[i].ypos, pos[i].xpos, pos[i].z | ((i == 0) ? COLOR_PAIR(5) : COLOR_PAIR(2)));
    }
    move(pos[0].ypos, pos[0].xpos);
  }
  else
  {
    restart = 0;
  }
}
int main()
{
  char c;
  int num;
  initscr();
  start_color();
  style();
  levelTest(lev);

  while (1)
  {
    c = getch();
    if (c == 'q')
    {
      break;
    }
    playgame(c);
  }
  endwin();
  return 0;
}