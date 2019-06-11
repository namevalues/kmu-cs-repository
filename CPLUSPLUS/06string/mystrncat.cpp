#include<iostream>
#include<cstring>

using namespace std;

char *my_strncat(char dest[], char source[], int num)
{
  int dest_length = strlen(dest);
  int source_length = strlen(source);
  for(int i = 0; i < num; i++)
  {
    dest[dest_length+i] = source[i];
  }
  return dest;
}

int main(void)
{
  char dest[6] = "led ";
  char *p;
  p = my_strncat(dest, "zepplin", 4);
  cout << p << endl; 
}
