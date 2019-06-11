#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Node
{
private:
  string name;
  string weight;
  string height;

  Node *next = NULL;
  Node *prev = NULL;
  friend class List;

public:
  Node()
  {
  }
  Node(string name, string weight, string height)
  {
    this->name = name;
    this->weight = weight;
    this->height = height;
    next = NULL;
    prev = NULL;
  }
};

class List
{
private:
  Node *head = NULL;

public:
  void insert(string, string, string);
  void deleteNode(string);
  bool isempty();
  void insearch(string);
  void forward();
  void backward();
  int get_length();
  void insertafter(int index, string, string, string);
  void insertbefore(int index, string, string, string);
  Node *Find(int num);
  void remove(int index);
  void findNth(int index);
};

int List::get_length()
{
  Node *p = NULL;
  int length = 0;

  if (isempty())
    cout << "not list" << endl;
  else
  {
    p = head;
    while (p != 0)
    {
      length += 1;
      p = p->next;
    }
  }

  return length;
}

void List::forward()
{
  Node *p = NULL;

  if (isempty())
    cout << "not list" << endl;
  else
  {
    p = head;
    while (p != 0)
    {
      cout << p->name << " " << p->weight << " " << p->height << " ";
      p = p->next;
      cout << endl;
    }
    cout << endl;
  }
}
void List::backward()
{
  Node *p = NULL;

  if (isempty())
    cout << "not list" << endl;
  else
  {
    p = head;
    while (p->next != 0)
    {
      p = p->next;
    }
    while (p != 0)
    {
      cout << p->name << " " << p->weight << " " << p->height << " " << endl;
      p = p->prev;
    }
    cout << endl;
  }
}
void List::insearch(string name)
{
  Node *p = NULL;
  Node *q = NULL;

  p = head;
  if (!isempty())
  {
    if (p->name.compare(name) == 0)
    {
      cout << p->name << endl;
      cout << "Found" << endl;
    }
    else
    {
      while (p != 0 && p->name.compare(name) != 0)
      {
        q = p;
        p = p->next;
      }
      if (p != 0)
      {
        cout << "HERE2" << endl;
        cout << "Found" << endl;
      }
      else
      {
        cout << "HERE3" << endl;
        cout << "Not Found" << endl;
      }
    }
  }
  else
    cout << "List is empty" << endl;
}

void List::deleteNode(string name)
{
  Node *p = NULL;
  Node *q = NULL;
  p = head;
  if (!isempty())
  {
    if (p->name.compare(name) == 0)
    {
      q = p;
      p = p->next;
      head = p;
      cout << q->name << "을(를) 리스트에서 삭제했습니다. " << endl;
      delete q;
    }
    else
    {
      while (p != 0 && p->name.compare(name) != 0)
      {
        q = p;
        p = p->next;
      }
      if (p != 0)
      {
        if (p->next != 0)
        {
          q->next = p->next;
          p->next->prev = q;
        }
        else
        {
          q->next = NULL;
        }
        cout << p->name << "을(를) 리스트에서 삭제했습니다. " << endl;
        delete p;
      }
      else
      {
        cout << "해당 숫자는 리스트 안에 없습니다." << endl;
      }
    }
  }
  else
  {
    cout << "LIst is Empty" << endl;
  }
}

Node *List::Find(int index)
{

  Node *temp = head;

  for (int i = 1; i < index; ++i)
  {
    temp = temp->next;
  }
  return temp;
}

void List::insertafter(int index, string name, string weight, string height)
{

  Node *find = Find(index);
  Node *newNode = new Node(name, weight, height);
  newNode->next = find->next;
  newNode->prev = find;
  find->next = newNode;
  newNode->next->prev = newNode;
}

void List::insertbefore(int index, string name, string weight, string height)
{

  Node *find = Find(index);
  Node *newNode = new Node(name, weight, height);
  newNode->next = find;
  newNode->prev = find->prev;
  find->prev = newNode;
  newNode->prev->next = newNode;
}

void List::insert(string name, string weight, string height)
{
  Node *p = NULL;
  Node *q = NULL;
  Node *temp = new Node();
  temp->name = name;
  temp->weight = weight;
  temp->height = height;

  if (head == 0)
    head = temp;
  else
  {
    p = head;
    if (temp->name <= head->name)
    {
      temp->next = p;
      p->prev = temp;
      head = temp;
    }
    else
    {
      while (p != 0 && temp->name > p->name)
      {
        q = p;
        p = p->next;
      }
      if (p != 0)
      {
        q->next = temp;
        temp->prev = q;
        temp->next = p;
        p->prev = temp;
      }
      else
      {
        q->next = temp;
        temp->prev = q;
      }
    }
  }
}

bool List::isempty()
{
  if (head == 0)
    return 1;
  else
    return 0;
}

void List::findNth(int index)
{
  Node *temp = head;
  for (int i = 0; i < index; i++)
  {
    temp = temp->next;
  }
  cout << temp->name << " " << temp->weight << " " << temp->height << endl;
}

vector<string> split(string str, char delimiter)
{
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;

  while (getline(ss, tok, delimiter))
  {
    internal.push_back(tok);
  }

  return internal;
}

int main(void)
{
  List mList;
  ifstream infile;
  char buffer[80];

  infile.open("data1", ios::in);
  if (infile.fail())
  {
    cout << "can't open the input file" << endl;
    exit(1);
  }

  while (infile.getline(buffer, 80))
  {
    string str(buffer);
    vector<string> line = split(str, ' ');
    mList.insert(line[0], line[1], line[2]);
  }

  mList.forward();
  cout << "Search" << endl;
  mList.insearch("lee");
  cout << endl;
  cout << "Delete" << endl;
  mList.deleteNode("lee");
  cout << endl;
  cout << "insert after" << endl;
  mList.insertafter(2, "Park", "73", "176");
  cout << "find nth" << endl;
  mList.findNth(1);
  cout << endl;
  cout << "backward" << endl;
  mList.backward();
}