/*
* Name: 하준혁
* Student ID : 20181705
* Program ID : HW#3
* Description: Singular Linked List Example
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Node
{
private:
  int name;
  int score;
  string major;
  int grade;
  Node *next;
  Node(int i_name, int i_score, string i_major, int i_grade)
  {
    name = i_name;
    score = i_score;
    major = i_major;
    grade = i_grade;
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
  void insertNode(int, int, string, int);
  void searchByMajor(string);
  void searchByGrade(int);
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

void List::insertNode(int name, int score, string major, int grade)
{
  Node *temp = new Node(name, score, major, grade);
  Node *p, *q;

  if (head == 0)
    head = temp;
  else if (temp->name < head->name)
  {
    temp->next = head;
    head = temp;
  }
  else
  {
    p = head;
    while ((p != 0) && (p->name < temp->name))
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

void List::traverseList()
{
  Node *p;

  if (!isEmpty())
  {
    p = head;
    while (p)
    {
      cout << (char)p->name << " " << p->score << " " << p->major << " " << (char)p->grade << endl;
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

void List::searchByMajor(string major)
{
  Node *p;

  if (head != 0)
  {
    p = head;
    while (p != 0)
    {
      if (p->major == major)
      {
        cout << (char)p->name << " " << p->score << " " << p->major << " " << (char)p->grade << endl;
        p = p->next;
      }
      else
      {
        p = p->next;
      }
    }
  }
  else
    cout << "List is Empty" << endl;
  cout << endl;
}

void List::searchByGrade(int grade)
{
  Node *p;

  if (head != 0)
  {
    p = head;
    while (p != 0)
    {
      if (p->grade == grade)
      {
        cout << (char)p->name << " " << p->score << " " << p->major << " " << (char)p->grade << endl;
        p = p->next;
      }
      else
      {
        p = p->next;
      }
    }
  }
  else
    cout << "List is Empty" << endl;
  cout << endl;
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
  List l;

  ifstream infile1, infile2;
  char buffer[80];

  infile1.open("data1", ios::in); 
  if (infile1.fail())
  {
    cout << "can't open the input file" << endl;
    exit(1);
  }

  while (infile1.getline(buffer, 80))
  {
    string str(buffer);
    vector<string> line = split(str, ' ');
    l.insertNode(buffer[0], stoi(line[1]), line[2], buffer[9]);
  }
  l.traverseList();
  l.searchByGrade('A');

  infile2.open("data2", ios::in);
  if (infile2.fail())
  {
    cout << "can't open the input file" << endl;
    exit(1);
  }

  while (infile2.getline(buffer, 80))
  {
    string str(buffer);
    vector<string> line = split(str, ' ');
    l.insertNode(buffer[0], stoi(line[1]), line[2], buffer[9]);
  }

  l.searchByMajor("CS");
}