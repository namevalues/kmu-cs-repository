#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

char prec[4][2] = {'*', 2, '/', 2, '+', 1, '-', 1};

using namespace std;

class Node
{
private:
  char data;
  int prio;
  Node *left;
  Node *right;
  Node(char value) : data(value), prio(100), left(NULL), right(NULL) {}
  Node(char value, int prio_) : data(value), prio(prio_), left(NULL), right(NULL) {}
  friend class Tree;
};

class Tree
{
private:
  Node *root;

public:
  void evalprint();
  void print(int num);
  void insert(char num);
  void operator_(char num, int prio);
  void operand_(char num);
  int evalTree(Node *p);
  int check(char num);
  void inorder(Node *ptr);
  void postorder(Node *ptr);
  void preorder(Node *ptr);
  void parenthese(Node *ptr);
  void del();
  void delete_(Node *ptr);
  void DrawTree(Node *ptr, int);
  Tree() { root = 0; }
  ~Tree(){};
};

void Tree::evalprint()
{
  Node *ptr = root;
  if (ptr != NULL)
  {
    cout << evalTree(ptr) << endl;
  }
  else
    cout << "입력된 수식이 없습니다." << endl;
}
int Tree::check(char num)
{
  for (int i = 0; i < 4; ++i)
  {
    if (prec[i][0] == num)
      return 0;
  }
  return 1;
}
int Tree::evalTree(Node *p)
{
  int value = 0;
  int left = 0;
  int right = 0;
  if (p != NULL)
  {
    if (check(p->data))
      value = p->data - '0';
    else
    {
      left = evalTree(p->left);
      right = evalTree(p->right);
      switch (p->data)
      {
      case '+':
        value = left + right;
        break;
      case '-':
        value = left - right;
        break;
      case '*':
        value = left * right;
        break;
      case '/':
        value = left / right;
        break;
      }
    }
  }
  return value;
}
void Tree::insert(char num)
{
  for (int i = 0; i < 4; ++i)
    if (prec[i][0] == num)
    {
      operator_(num, prec[i][1]);
      return;
    }
  operand_(num);
}

void Tree::operand_(char num)
{
  Node *temp = new Node(num);
  if (root == NULL)
    root = temp;
  else
  {
    Node *p = root;
    while (p->right != NULL)
      p = p->right;
    p->right = temp;
  }
}
void Tree::operator_(char num, int prio)
{
  Node *temp = new Node(num, prio);
  Node *p = root;
  if (root->prio >= temp->prio)
  {
    temp->left = root;
    root = temp;
  }
  else
  {
    temp->left = root->right;
    root->right = temp;
  }
}
void Tree::print(int num)
{
  Node *ptr = root;
  switch (num)
  {
  case 0:
    inorder(ptr);
    break;
  case 1:
    postorder(ptr);
    break;
  case 2:
    preorder(ptr);
    break;
  case 3:
    parenthese(ptr);
    break;
  case 4:
    DrawTree(ptr, 1);
    break;
  defalut:
    cout << endl;
  }
  cout << endl;
}

void Tree::inorder(Node *ptr)
{
  if (ptr)
  {
    inorder(ptr->left);
    cout << ptr->data << " ";
    inorder(ptr->right);
  }
}

void Tree::parenthese(Node *ptr)
{
  if (ptr)
  {
    if (!isdigit(ptr->data))
      cout << "(";
    parenthese(ptr->left);
    cout << ptr->data << " ";
    parenthese(ptr->right);
    if (!isdigit(ptr->data))
      cout << ")";
  }
}

void Tree::postorder(Node *ptr)
{
  if (ptr)
  {
    postorder(ptr->left);
    postorder(ptr->right);
    cout << ptr->data << " ";
  }
}
void Tree::preorder(Node *ptr)
{
  if (ptr)
  {
    cout << ptr->data << " ";
    preorder(ptr->left);
    preorder(ptr->right);
  }
}

void Tree::del()
{
  Node *ptr = root;
  delete_(ptr);
  cout << "트리가 삭제 됐습니다. " << endl;
  root = NULL;
}

void Tree::delete_(Node *ptr)
{
  if (ptr == NULL)
    return;

  delete_(ptr->left);
  delete_(ptr->right);

  delete ptr;
}

void Tree::DrawTree(Node *ptr, int level) {
  if(ptr!=0) 
  {
    DrawTree(ptr->right, level+1);
    for(int i = 1; i <= level-1; i++)
    {
      cout << "    ";
    }
    cout << ptr->data;
    if(ptr->left != 0 && ptr->right != 0)
    {
      cout << " < ";
    }
    else if(ptr->right != 0) 
    {
      cout << " / ";
    }
    else if(ptr->left != 0)
    {
      cout << " \\ ";
    }
    cout << endl;
    DrawTree(ptr->left, level + 1);
  }
}

int main()
{


  ifstream infile;
  char buffer[80];

  infile.open("data", ios::in);
  if (infile.fail())
  {
    cout << "can't open the input file" << endl;
    exit(1);
  }

  int i = 1;

  while (infile.getline(buffer, 80))
  {
    Tree mtree;
    string problem(buffer);
    for (int i = 0; i < problem.length(); ++i)
    {
      mtree.insert(problem[i]);
    }

    cout << i << " : " << problem << endl;

    cout << "Inorder : ";
    mtree.print(0);

    cout << "PostOrder : ";
    mtree.print(1);

    cout << "PreOrder : ";
    mtree.print(2);

    cout << "Evaluation : ";
    mtree.evalprint();

    cout << "Tree structure" << endl;
    mtree.print(4);
    i++;
    cout << endl;
  }

  return 0;
}