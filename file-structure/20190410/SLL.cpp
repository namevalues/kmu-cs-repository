
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
    while (p != 0 && p->data != num)
    {
      q = p;
      p = p->next;
    }
    if (p != 0)
    {
      q->next = p->next;
      delete p;
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

int main(void)
{
  List l;
  l.insertNode(1);
  l.insertNode(2);
  l.insertNode(3);
  l.insertNode(4);
  l.insertNode(5);
  l.deleteNode(2);
  l.traverseList();
  l.searchList(1);
  l.searchList(2);
}