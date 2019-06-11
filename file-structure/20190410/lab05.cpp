
// Single Linked List

#include <iostream>

using namespace std;

class Node
{
private:
  int data;
  Node *next;
  Node(int value)
  {
    data = value;
    next = 0;
  }
  friend class List;
};

class List
{
private:
  Node *head;

public:
  List() { head = 0; }
  ~List();
  void insertNode(int);
  void deleteNode(int);
  void searchList(int);
  bool isEmpty();
  void traverseList();
  void printLast();
  void printNth(int);
  void invertList();
};

bool List::isEmpty()
{
  if (head == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void List::insertNode(int data)
{
  Node *temp = new Node(data);
  Node *p, *q;

  if (head == 0)
    head = temp;
  else if (temp->data < head->data)
  {
    temp->next = head;
    head = temp;
  }
  else
  {
    p = head;
    while ((p != 0) && (p->data < temp->data))
    {
      q = p;
      p = p->next;
    }
    if (p != 0)
    {
      temp->next = p;
      q->next = temp;
    }
    else
    {
      q->next = temp;
    }
  }
}

void List::deleteNode(int num)
{

  Node *p, *q;
  if (head->data == num)
  {
    p = head;
    head = head->next;
    delete p;
  }
  else
  {
    p = head;
    while (p != 0 && p->data != num && p->next != 0)
    {
      q = p;
      p = p->next;
    }
    if (p != 0)
    {
      q->next = p->next;
    }
    else
    {
      cout << num << " is not in the list" << endl;
    }
  }
}

void List::traverseList()
{
  Node *p;

  if (!isEmpty())
  {
    p = head;
    while (p)
    {
      cout << p->data << " ";
      p = p->next;
    }
    cout << endl;
  }
  else
  {
    cout << "List is Empty!" << endl;
  }
}

List::~List()
{
  Node *p;

  while (head != 0)
  {
    p = head;
    head = head->next;
    delete p;
  }
}

void List::searchList(int num)
{
  Node *p;

  if (head != 0)
  {
    p = head;
    while (p != 0 && p->data != num)
    {
      p = p->next;
    }
    if (p)
      cout << p->data << " is Found" << endl;
    else
      cout << num << " is not in the list." << endl;
  }
  else
    cout << "List is Empty" << endl;
}

void List::printLast()
{
  Node *p;
  if (!isEmpty())
  {
    p = head;
    while (p != 0 && p->next != 0)
    {
      p = p->next;
    }
    cout << p->data << endl;
  }
  else
  {
    cout << "List Empty" << endl;
  }
}

void List::printNth(int n)
{
  Node *p;
  int item;
  if (head != 0)
  {
    p = head;
    for (int i = 0; i < n; i++)
    {
      if (p != 0)
      {
        p = p->next;
      }
      else
      {
        cout << "not found" << endl;
        break;
      }
    }
    if (p != 0)
    {
      item = p->data;
      cout << item << endl;
    }
  }
  else
  {
    cout << "List Empty" << endl;
  }
}

void List::invertList()
{
  Node *p;
  int count = 0;

  if (!isEmpty())
  {
    p = head;
    while (p)
    {
      count += 1;
      p = p->next;
    }
    int array[count];
    int i = 1;
    p = head;
    while (p)
    {
      array[count-i] = p->data;
      i++;
      p = p->next;
    }
    for(int k = 0; k < count; k++)
    {
      cout << array[k] << " ";
    }
    cout << endl;
  }
  else
  {
    cout << "List is Empty!" << endl;
  }
}

int main(void)
{
  List l;
  List();
  bool a = true;
  int menu;
  while (a)
  {
    cout << "메뉴 (1. insert, 2. delete, 3. list, 4. search, 5. PrintLast 6. PrintNth 7. InvertList 8. Quit) : ";
    cin >> menu;
    switch (menu)
    {
      int input;
    case 1:
      cout << "insert ";
      cin >> input;
      l.insertNode(input);
      break;
    case 2:
      cout << "Delete ";
      cin >> input;
      l.deleteNode(input);
      break;
    case 3:
      l.traverseList();
      break;
    case 4:
      cin >> input;
      l.searchList(input);
      break;
    case 5:
      l.printLast();
      break;
    case 6:
      cin >> input;
      l.printNth(input);
      break;
    case 7:
      l.invertList();
      break;
    case 8:
      a = false;
      l.~List();
      break;
    }
  }
}