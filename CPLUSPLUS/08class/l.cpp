#include<iostream>
using namespace std;

class KString{
private:
  char *m;
public:
  KString() {
    m = new char[1];
    m[0] = '\0';
    cout << this << ": KString() called" << endl;
  }

  KString(const char str[]) {
    m = NULL;
    cpy
  }
}

int main(void) {

}