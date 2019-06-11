#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int value)
  {
    data = value;
    left = NULL;
    right = NULL;
  }
  friend class Tree;
};
class Tree
{
private:
  Node *root;

public:
  Tree()
  {
    root = 0;
  }
  void preorder(Node *);
  Node *inserting(Node *, int);

  void insert(int);
  void preorderPrint();
};

void Tree::preorder(Node *ptr)
{
  if (ptr)
  {
    cout << ptr->data << " ";
    preorder(ptr->left);
    preorder(ptr->right);
  }
}

Node *Tree::inserting(Node *ptr, int key)
{
  if (ptr == NULL)
  {
    ptr = new Node(key);
    ptr->data = key;
    ptr->left = NULL;
    ptr->right = NULL;
  }
  else if (key < ptr->data)
  {
    ptr->left = inserting(ptr->left, key);
  }
  else if (key > ptr->data)
  {
    ptr->right = inserting(ptr->right, key);
  }
  return ptr;
}

void Tree::preorderPrint()
{
  if (root == NULL)
  {
    cout << "tree is empty";
  }
  else
  {
    preorder(root);
  }
  cout << endl;
}

void Tree::insert(int k)
{
  cout << "insert : " << k << endl;
  root = inserting(root, k);
}

int arr[8];
int top;
int a;

void create_arr();
int push(int number);
int pop();
int isFull();
int isEmpty();
void displayStack();
void displayTree();
void search(int num);

void create_arr()
{
  top = 0;
  a = 0;
}
int isFull()
{
  if (top == 7)
    return 1;
  else
    return 0;
}
int isEmpty()
{
  if (top == 0)
    return 1;
  else
    return 0;
}
int push(int num)
{
  int i;
  if (isFull())
  {
    cout << "Heap is full or emptyㅇ"<< endl;
    return 0;
  }
  i = ++top;
  while ((i != 1) && (num < arr[i / 2]))
  {
    arr[i] = arr[i / 2];
    i = i / 2;
  }
  arr[i] = num;
  return num;
}

int pop()
{
  int parent, child;
  int item, temp;

  item = arr[1];
  temp = arr[top--];
  parent = 1;
  child = 2;
  while (child <= top)
  {
    if ((child < top) && (arr[child] > arr[child + 1]))
      child++;
    if (temp <= arr[child])
      break;
    arr[parent] = arr[child];
    parent = child;
    child = child * 2;
  }
  arr[parent] = temp;
  return item;
}

void displayStack()
{
  int sp;
  if (isEmpty())
    cout << "Heap is empty!" << endl;
  else
  {
    sp = 1;
    while (sp != top + 1)
    {
      cout << arr[sp] << " ";
      ++sp;
    }
    cout << "\t" << endl;
    cout << "Heap Level : " << int(log2(top)) + 1 << endl;
  }
}



int main()
{
  Tree tree;
  create_arr();
  string input;
  int count = 1;

  while (true)
  {
    cout << "(1. Insert, 2. Delete, 3. Empty, 4. Full, 5. Quit) " << endl;
    cout << "원하는 명령을 입력하세요 : ";
    cin >> input;
    if (input == "1")
    {
      int num;
      cout << "원하는 숫자를 넣어주세요 : ";
      cin >> num;
      push(num);
      tree.insert(num);
    }
    else if (input == "2")
    {
      if (isEmpty())
        cout << "Heap is empty" << endl;
      else
      {
        pop();
        displayStack();
      }
    }
    else if (input == "3")
    {
      if (isEmpty())
        cout << "Heap is empty" << endl;
      else
        cout << "Heap is not empty" << endl;
    }
    else if (input == "4")
    {
      if (isFull())
        cout << "Heap is FULL" << endl;
      else
        cout << "Heap is not FULL" << endl;
    }
    else if (input == "5")
    {
      break;
    }
    else
    {
      cout << "TREE : ";
      tree.preorderPrint();
      cout << "STACK : ";
      displayStack();
    }
  }

  return 0;
}