#include<iostream>
#include<cstring>

using namespace std;

char *new_strncat(char dest[], const char source[], int num)
{
  int dest_len = 0;
  while(dest[dest_len] != 0)
  {
    dest_len++;
  }

  char *result = new char[dest_len + num + 1];

  for(int i = 0; i < dest_len; i++)
  {
    result[i] = dest[i];
  }

  for(int k = 0; k < num; k++)
  {
    result[dest_len + k] = source[k];
  }
  result[dest_len + num] = '\0';
  return result;
}

int main(void)
{
  char dest[6] = "led ";
  char *p;
  p = new_strncat(dest, "zepplin", 5);
  cout << p << endl;
  delete []p; 
}