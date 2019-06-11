#include <iostream>
#include <cstring>
#include <fstream>
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
  void inorder(Node *);
  void postorder(Node *);
  void preorder(Node *);
  void treestructure(Node *, int);
  Node *searching(Node *, int);
  Node *inserting(Node *, int);
  Node *deleting(Node *, int);
  Node *find_min(Node *);

  void insert(int);
  void del(int);
  void search(int);
  void inorderPrint();
  void postorderPrint();
  void preorderPrint();
  void treePrint();
  int leaf(Node *);
  void leafPrint();
  bool isEmpty();
};

int Tree::leaf(Node *ptr)
{
  int count = 0;
  if (ptr)
  {
    if ((ptr->left == NULL) && (ptr->right == NULL))
      count++;
    else
      count = leaf(ptr->left) + leaf(ptr->right);
  }
  return count;
}

void Tree::leafPrint()
{
  if (root == NULL)
  {
    cout << "leaf : 0" << endl;
  }
  else
  {
    cout << "leaf : " << leaf(root) << endl;
  }
}

bool Tree::isEmpty()
{
  return (root == NULL);
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

Node *Tree::searching(Node *ptr, int key)
{
  if (ptr == NULL)
  {
    return '\0';
  }
  else
  {
    if (key == ptr->data)
    {
      return ptr;
    }
    else if (key < ptr->data)
    {
      ptr = searching(ptr->left, key);
    }
    else if (key > ptr->data)
    {
      ptr = searching(ptr->right, key);
    }
    return ptr;
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
Node *Tree::deleting(Node *ptr, int key)
{
  Node *p, *temp;
  if (ptr != NULL)
  {
    if (key < ptr->data)
    {
      ptr->left = deleting(ptr->left, key);
    }
    else if (key > ptr->data)
    {
      ptr->right = deleting(ptr->right, key);
    }
    else if ((ptr->left == NULL) && ptr->right == NULL)
    {
      ptr = NULL;
    }
    else if (ptr->left == NULL)
    {
      p = ptr;
      ptr = ptr->right;
      delete (p);
    }
    else if (ptr->right == NULL)
    {
      p = ptr;
      ptr = ptr->left;
      delete (p);
    }
    else
    {
      temp = find_min(ptr->right);
      ptr->data = temp->data;
      ptr->right = deleting(ptr->right, ptr->data);
    }
  }
  else
  {
    cout << "Not Found" << endl;
  }
  return ptr;
}
Node *Tree::find_min(Node *p)
{
  if (p->left == NULL)
  {
    return p;
  }
  else
  {
    find_min(p->left);
  }
}

void Tree::treestructure(Node *p, int level)
{
  int i;
  if (p != 0)
  {
    treestructure(p->right, level + 1);
    for (i = 1; i <= level - 1; i++)
    {
      cout << "    ";
    }
    cout << p->data;
    if (p->left != 0 && p->right != 0)
    {
      cout << " < ";
    }
    else if (p->right != 0)
    {
      cout << "/";
    }
    else if (p->left != 0)
    {
      cout << "\\";
    }
    cout << endl;
    treestructure(p->left, level + 1);
  }
}

void Tree::inorderPrint()
{
  cout << "inorder"
       << " "
       << ": ";
  if (root == NULL)
  {
    cout << "tree is empty";
  }
  else
  {
    inorder(root);
  }
  cout << endl;
}
void Tree::postorderPrint()
{
  cout << "Postorder"
       << " "
       << ": ";
  if (root == NULL)
  {
    cout << "tree is empty";
  }
  else
  {
    postorder(root);
  }
  cout << endl;
}
void Tree::preorderPrint()
{
  cout << "Preorder"
       << " "
       << ": ";
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
void Tree::search(int k)
{
  Node *p;
  cout << "search : " << k << endl;
  p = searching(root, k);
  if (p == NULL)
  {
    cout << "Not Found";
  }
  else
  {
    cout << "Found";
  }
  cout << endl;
}

void Tree::insert(int k)
{
  cout << "insert : " << k << endl;
  root = inserting(root, k);
}
void Tree::del(int k)
{
  if (root == NULL)
  {
    cout << "Tree is Empty" << endl;
  }
  else
  {
    root = deleting(root, k);
  }
}
void Tree::treePrint()
{
  cout << "Tree structure" << endl;
  treestructure(root, 1);
}

int main()
{
  Tree tree;

  int input;

  while (true)
  {
    cout << "1. Insert, 2. Delete, 3.Search, 4.Print 5. Traverse 6. Leaf 7. Quit" << endl;
    cin >> input;
    switch (input)
    {
    case 1:
      int insert;
      cout << "Enter number to insert: ";
      cin >> insert;
      tree.insert(insert);
      tree.treePrint();
      break;
    case 2:
      int deleteNum;
      if (tree.isEmpty())
        cout << "Tree is Empty" << endl;
      else
      {
        cout << "Enter number to delete: ";
        cin >> deleteNum;
        tree.del(deleteNum);
        tree.treePrint();
      }
      break;
    case 3:
      int search;
      if (tree.isEmpty())
        cout << "Tree is Empty" << endl;
      else
      {
        cout << "Enter number to search: ";
        cin >> search;
        tree.search(search);
      }
      break;
    case 4:
      tree.treePrint();
      break;
    case 5:
      if (tree.isEmpty())
        cout << "Tree is Empty" << endl;
      else
      {
        tree.inorderPrint();
        tree.preorderPrint();
        tree.postorderPrint();
      }
      break;
    case 6:
      tree.leafPrint();
      break;
    case 7:
      exit(1000);
    }
  }
}