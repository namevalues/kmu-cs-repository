#include <iostream>
#include <cstdlib>

using namespace std;

#define MaxSize 7
/*
struct hashtable
{
  int num = NULL;
  bool empty = true;
};
*/

int hash(int num) { return num % MaxSize; }

class Node
{
private:
  int data;
  Node *link;
  Node(int value)
  {
    data = value;
    link = 0;
  }
  friend class Htable;
};

class Htable
{
private:
  Node *head;

public:
  Htable() { head = 0; }
  int findKey(int);
  void insertKey(int);
  void deleteKey(int);
  void printable(int);
};

int Htable::findKey(int data)
{
  Node *p;

  if (head != 0)
  {
    p = head;
    while (p != 0 && p->data != data)
    {
      p = p->link;
    }
    if (p)
      cout << p->data << " is Found" << endl;
    else
      cout << data << " is not in the list." << endl;
  }
  else
    cout << "List is Empty" << endl;
}

void Htable::insertKey(int data)
{
  Node *temp = new Node(data);
  Node *p, *q;

  if (head == 0)
    head = temp;
  else
  {
    p = head;
    while ((p != 0))
    {
      q = p;
      p = p->link;
    }
    if (p != 0)
    {
      temp->link = p;
      q->link = temp;
    }
    else
    {
      q->link = temp;
    }
  }
}

void Htable::deleteKey(int data)
{
  Node *p, *q;
  if (head->data == data)
  {
    p = head;
    head = head->link;
    delete p;
  }
  else
  {
    p = head;
    while (p != 0 && p->data != data && p->link != 0)
    {
      q = p;
      p = p->link;
    }
    if (p != 0)
    {
      q->link = p->link;
    }
    else
    {
      cout << data << " is not in the list" << endl;
    }
  }
}

void Htable::printable(int i)
{
  Node *p;
  cout << "HTable [" << i << "]: ";
  p = head;
  while ((p != 0))
  {
    cout << p->data << "-> ";
    p = p->link;
  }
  cout << endl;
}

/*
hashtable htable[MaxSize];

int hash(int num) { return num % MaxSize; }

int findKey(int num, int &index) // Linear Probing으로 확장/num가 있는지
{

  int found = 0;
  index = hash(num); //인덱스를 재설정한다.
  int loop = 0;
  int index_ = index; //처음 인덱스를 index_에 저장한다.

  //해당 htable이 비어있고 아직 못찾았으며 loop를 다 안 돌았을 때까지
  while (found == false && loop == false)
  {

    if (htable[index].empty == true)
    { //해당 배열이 비어있다면
      found = 1;
      return found;
    }
    if (htable[index].empty == false && loop == false)
    { //해당 배열이 차있다면
      index = (index + 1) % MaxSize;
      if (index == index_)
      {
        loop = true;
        return found;
      }
    }
  }
}

int insertKey(int num)
{
  int index = 0;

  bool check = findKey(num, index); //num이 있는지 없는지

  if (check == false) //배열안에 넣을 공간을 못찾았다면
    return false;     // 이미 있으므로 insert 실패
  else                //배열안에 넣을 공간을 찾았다면
  {
    htable[index].num = num;
    htable[index].empty = false;
    return true; //insert 완료했다는 표시
  }
}

int deleteKey(int num)
{
  int index = 0;

  for (int i = 0; i < MaxSize; ++i)
  {
    if (htable[i].num == num)
    {
      htable[i].num = NULL;
      htable[i].empty = true; // 해당 htable을 empty시켜준다.
      return true;            //delete완료
    }
  }
  int check = findKey(num, index);

  if (check == false)
  {
    cout << "Key not found" << endl;
    return false; //delete실패
  }
  else
  {
    htable[index].num = 0;
    htable[index].empty = true; // 해당 htable을 empty시켜준다.
    return true;                //delete완료
  }
}

void printtable()
{
  cout << "(";
  for (int i = 0; i < MaxSize; ++i)
  {
    if (htable[i].empty == false) //차있다면
      cout << htable[i].num;
    else
      cout << "_";
    if (i != MaxSize - 1)
      cout << ",";
  }
  cout << ")" << endl;
}

void search(int num)
{

  bool find = false;
  for (int i = 0; i < MaxSize; ++i)
  {
    if (htable[i].num == num)
    {
      find = true;
    }
  }
  if (find == true)
  {
    cout << "Found " << num << endl;
  }
  else
  {
    cout << "Not Found" << endl;
  }
}
*/
int main()
{

  int input = 0; //명령 번호
  int num = 0;   //넣는 수
  int index = 0;
  Htable table[MaxSize];

  while (true)
  {
    cout << " [1.Find, 2.Insert, 3.Delete, 4.Quit] " << endl;
    cout << "Enter Key : ";
    cin >> input;
    switch (input)
    {
    case 1:
      cout << "찾으시는 수를 써주세요 : ";
      cin >> num;
      table[num % MaxSize].findKey(num);
      break;
    case 2:
      cout << "넣고 싶은 수를 써주세요 : ";
      cin >> num;
      table[num % MaxSize].insertKey(num);
      table[0].printable(0);
      table[1].printable(1);
      table[2].printable(2);
      table[3].printable(3);
      table[4].printable(4);
      table[5].printable(5);
      table[6].printable(6);
      break;
    case 3:
      cout << "지우고 싶은 수를 써주세요 : ";
      cin >> num;
      table[num % MaxSize].deleteKey(num);
      table[0].printable(0);
      table[1].printable(1);
      table[2].printable(2);
      table[3].printable(3);
      table[4].printable(4);
      table[5].printable(5);
      table[6].printable(6);
      break;
    case 4:
      cout << "프로그램을 종료 합니다. "
           << " ";
      exit(1);
    defalut:
      cout << "잘못 입력하셨습니다." << endl;
    }
  }
  return 0;
}