#include <iostream>
#include <cstdlib>
#define SZ 80

using namespace std;

class KString
{
public:
  char *m;
  KString()
  {
    m = new char[1];
    m[0] = '\0';
  }
  KString(const char str[])
  {
    int str_length = 0;
    while (str[str_length] != '\0')
    {
      str_length++;
    }
    m = new char[str_length+1];
    for(int i = 0; i < str_length; i++) {
      m[i] = str[i];
    }
    m[str_length] = '\0';
  }
  KString(KString& s) {
    int i, len = s.size();
    m = new char[len+1];
    for(i =0;i<len;i++){
      m[i]=s.m[i];
    }
    m[i]='\0';
    /*
    m = NULL;
    cpy(s.m);
    */
  }

  void print() {
    cout << this << " " << m << endl;
  }

  KString& operator=(const KString& s)
  {
    //CPY 로 구현
    cpy(s.m);
    return *this;
  }

  KString operator+(const KString& s)
  {
    //CAT 참조
    KString temp(this->m);
    temp.cat(s.m);
    return temp;
  }

  friend ostream& operator<<(ostream& os, const KString& s) {
    os << s.m << " ";
    return os;
  }
  
  ~KString()
  {
    delete[] m;
  }
  int size() const
  {
    int i = 0;
    while (m[i] != '\0')
    {
      i++;
    }
    return i;
  }
  void cpy(const char str[])
  {
    int str_length = 0;
    while (str[str_length] != '\0')
    {
      str_length++;
    }
    delete[] m;
    m = new char[str_length+1];
    for(int i = 0; i < str_length; i++) {
      m[i] = str[i];
    }
    m[str_length] = '\0';
  }
  void cat(const char str[])
  {
    int str_length = 0;
    while (str[str_length] != '\0')
    {
      str_length++;
    }
    int originalSize = this->size();
    char *temp = new char[originalSize];
    for(int i = 0; i < originalSize; i++) {
      temp[i] = m[i];
    }
    for(int j = originalSize; j < originalSize + str_length; j++) {
      temp[j] = str[j-originalSize];
    }
    delete[] m;
    m = new char[originalSize + str_length + 1];
    m = temp;
  }

  int cmp(const char str[]) const
  {
    int i = 0;

    while (i < size())
    {
      if (m[i] < str[i])
      {
        return -1;
      }
      else if (m[i] > str[i])
      {
        return 1;
      }
      else
      {
        i++;
      }
    }
    if(str[i] == '\0') {
      return 0;
    }
    else {
      return -1;
    }
  }

  char& operator[](int i)
  {
    return m[i];
  }

  friend int operator<(const KString& s1, const KString s2)
  {
    return s2.cmp(s1.m);
  }

  operator char*()
  {
    return m;
  }
};

KString foo(KString s) {
  return s;
}

class EString:public KString 
{
public:
  EString() {
    m = new char[1];
    m[0] = '\0';
  }

  EString(const char str[]) {
    int str_length = 0;
    int cpy_length = 0;
    while (str[str_length] != '\0')
    {
      if(int(str[str_length]) >= 97 && int(str[str_length]) <= 122) {
        cpy_length++;
      }
      str_length++;
    }
    delete[] m;
    m = new char[cpy_length+1];
    int a = 0;
    for(int i = 0; i < str_length; i++) {
      if(int(str[i]) >= 97 && int(str[i]) <= 122) {
        m[a] = str[i];
        a++;
      }
    }
    m[cpy_length] = '\0';
  }

  void print() {
    cout << this << " : EString " << m << endl;
  }
};

int main(int argc, char *argv[])
{
  if(argc != 3) {
    cerr << "usage : ./estringtext k/2 s0meStr1ng \n";
    exit(1);
  }
  if(argv[1][0] == 'e') {
    EString e(argv[2]);
    e.print();
  } 
  else if(argv[1][0] == 'k') {
    KString e(argv[2]);
    e.print();
  }
}