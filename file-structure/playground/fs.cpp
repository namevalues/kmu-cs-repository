// Stack

#include <iostream>

#define stackSize 10
#define queueSize 3

using namespace std;

class Stack
{
private:
  int stack[stackSize];
  int top = NULL;

public:
  void createStack();
  void push(int);
  int pop();
  bool isEmpty();
  bool isFull();
  void printStack();
};

class Queue
{
private:
  int queue[queueSize];
  int front = NULL, rear = NULL;

public:
  void create_queue();
  void enqueue(int);
  int dequeue();
  bool isFull();
  bool isEmpty();
  void printQueue();
};

class CircularQueue
{
private:
  int circularQueue[queueSize];
  int front = NULL, rear = NULL;

public:
  void create_queue();
  void enqueue(int);
  int dequeue();
  bool isFull();
  bool isEmpty();
  void printQueue();
};

class Node
{
private:
  int data;
  Node *next;
  friend class SinglyLinkedList;
  friend class LinkedStack;
  friend class LinkedQueue;
  friend class CircularLinkedList;

public:
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};

class SinglyLinkedList
{
private:
  Node *head;

public:
  SinglyLinkedList()
  {
    head = 0;
  }
  ~SinglyLinkedList();
  void insertNode(int);
  void deleteNode(int);
  bool isEmpty();
  void printList();
};

class LinkedStack
{
private:
  Node *head;

public:
  LinkedStack() { head = 0; }
  ~LinkedStack();
  void push(int);
  int pop();
  bool isEmpty();
  void printStack();
};

class LinkedQueue
{
private:
  Node *front;
  Node *rear;

public:
  LinkedQueue()
  {
    front = 0;
    rear = 0;
  }
  void enqueue(int);
  int dequeue();
  bool isEmpty();
  void printQueue();
};

class CircularLinkedList
{
private:
  Node *tail;
  int countIndex;

public:
  CircularLinkedList()
  {
    tail = NULL;
    countIndex = 0;
  }
  void insertNode(int);
  void deleteNode(int);
  bool isEmpty();
  void printList();
};

class DLL_Node
{
private:
  int data;
  DLL_Node *next = NULL;
  DLL_Node *prev = NULL;
  friend class DoubleLinkedList;

public:
  DLL_Node()
  {
  }
  DLL_Node(int data)
  {
    this->data = data;
    next = NULL;
    prev = NULL;
  }
};

class DoubleLinkedList
{
private:
    DLL_Node *head = NULL;

public:
    void insert(int num);
    void deleteNode(int num);
    bool isempty();
    void insearch(int num);
    void forward();
    void backward();
    int get_length();
    void insertafter(int index, int num);
    void insertbefore(int index, int num);
    DLL_Node *Find(int num);
    void remove(int index);
    void findNth(int index);
};

void Stack::createStack()
{
  top = -1;
}

void Stack::push(int data)
{
  stack[++top] = data;
}

int Stack::pop()
{
  return stack[top--];
}

bool Stack::isEmpty()
{
  return (top == -1);
}

bool Stack::isFull()
{
  return (top == stackSize - 1);
}

void Stack::printStack()
{
  int sp;
  if (isEmpty())
    cout << "" << endl;
  else
  {
    cout << "Stack : ";
    sp = top; // sp = temporary pointer
    while (sp != -1)
    {
      cout << stack[sp] << " ";
      sp--;
    }
  }
}

void Queue::create_queue()
{
  front = -1;
  rear = -1;
}

void Queue::enqueue(int data)
{
  if (rear == queueSize - 1)
  {
    isFull();
    return;
  }
  queue[++rear] = data;
}

int Queue::dequeue()
{
  if (front == rear)
  {
    return isEmpty();
  }
  return queue[++front];
}

bool Queue::isEmpty()
{
  if (front == rear)
  {
    cout << "Queue Empty" << endl;
    return 1;
  }
  else
  {
    return 0;
  }
}

bool Queue::isFull()
{
  if (rear == queueSize - 1)
  {
    cout << "Queue Full";
    return 1;
  }
  else
  {
    return 0;
  }
}

void Queue::printQueue()
{
  int i;

  if (isEmpty())
  {
    cout << "Queue is Empty!" << endl;
  }
  else
  {
    i = front + 1;
    cout << "Queue : ";
    while (i <= rear)
    {
      cout << (char)queue[i] << " ";
      i = i + 1;
    }
    cout << endl;
  }
}

void CircularQueue::create_queue()
{
  front = -1;
  rear = -1;
}

void CircularQueue::enqueue(int data)
{
  if (rear == queueSize - 1)
  {
    isFull();
    return;
  }
  circularQueue[++rear] = data;
}

int CircularQueue::dequeue()
{
  if (front == rear)
  {
    return isEmpty();
  }
  return circularQueue[++front];
}

bool CircularQueue::isEmpty()
{
  if (front == rear)
  {
    cout << "Queue Empty" << endl;
    return 1;
  }
  else
  {
    return 0;
  }
}

bool CircularQueue::isFull()
{
  if (rear == queueSize - 1)
  {
    cout << "Queue Full";
    return 1;
  }
  else
  {
    return 0;
  }
}

void CircularQueue::printQueue()
{
  int i;

  if (isEmpty())
  {
    cout << "Queue is Empty!" << endl;
  }
  else
  {
    i = front + 1;
    while (i <= rear)
    {
      cout << circularQueue[i] << " ";
      i = i + 1;
    }
    cout << endl;
  }
}

bool SinglyLinkedList::isEmpty()
{
  return head == 0;
}

void SinglyLinkedList::insertNode(int data)
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

void SinglyLinkedList::deleteNode(int data)
{
  Node *p, *q;
  if (head->data == data)
  {
    p = head;
    head = head->next;
    delete p;
  }

  else
  {
    p = head;
    while (p != 0 && p->data != data)
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
      cout << data << " is not in the list" << endl;
  }
}

void SinglyLinkedList::printList()
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
    cout << "List is Empty" << endl;
}

SinglyLinkedList::~SinglyLinkedList()
{
  Node *p;

  while (head != 0)
  {
    p = head;
    head = head->next;
    delete p;
  }
}

void LinkedStack::push(int data)
{
  Node *temp = new Node(data);
  if (head == 0)
    head = temp;
  else
  {
    temp->next = head;
    head = temp;
  }
}

int LinkedStack::pop()
{
  Node *p;
  int num = head->data;
  p = head;
  head = head->next;
  delete p;
  return num;
}

bool LinkedStack::isEmpty()
{
  return head != 0;
}

void LinkedStack::printStack()
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
    cout << "Stack is Empty" << endl;
}

void LinkedQueue::enqueue(int data)
{
  Node *temp = new Node(data);
  if (front == 0)
  {
    front = temp;
    rear = temp;
  }
  else
  {
    rear->next = temp;
    rear = temp;
  }
}

int LinkedQueue::dequeue()
{
  Node *p;
  int num = front->data;
  p = front;
  if (front == rear)
  {
    front = 0;
    rear = 0;
  }
  else
  {
    front = front->next;
  }
  delete p;
  return num;
}

void LinkedQueue::printQueue()
{
  Node *p;
  if (!isEmpty())
  {
    p = front;
    while (p)
    {
      cout << p->data << " ";
      p = p->next;
    }
    cout << endl;
  }
  else
    cout << "Queue is Empty" << endl;
}

bool LinkedQueue::isEmpty()
{
  return !front;
}

void CircularLinkedList::insertNode(int data)
{
  Node *preNode = tail;
  Node *temp = new Node(data);
  if (countIndex == 0)
  {
    temp->next = temp;
    tail = temp;
  }
  else
  {
    temp->next = preNode->next;
    preNode->next = temp;
  }
  countIndex++;
}

void CircularLinkedList::deleteNode(int data)
{
  Node *preNode = tail;
  Node *delNode = tail;

  if (countIndex == 0)
  {
    cout << ("노드가 없습니다.") << endl;
  }
  else
  {
  }
}

int DoubleLinkedList::get_length()
{

    DLL_Node *p = NULL;
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
void DoubleLinkedList::forward()
{
    DLL_Node *p = NULL;

    if (isempty())
        cout << "not list" << endl;
    else
    {
        p = head;
        while (p != 0)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}
void DoubleLinkedList::backward()
{
    DLL_Node *p = NULL;

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
            cout << p->data << " ";
            p = p->prev;
        }
        cout << endl;
    }
}
void DoubleLinkedList::insearch(int num)
{
    DLL_Node *p = NULL;
    DLL_Node *q = NULL;

    p = head;
    if (!isempty())
    {
        if (p->data == num)
        {
            cout << "찾는 수 " << p->data << "은(는) 리스트 안에 있습니다." << endl;
        }
        else
        {
            while (p != 0 && p->data != num)
            {
                q = p;
                p = p->next;
            }
            if (p != 0)
            {
                cout << "찾는 수 " << p->data << "은(는) 리스트 안에 있습니다." << endl;
            }
            else
            {
                cout << "해당 숫자는 리스트 안에 없습니다." << endl;
            }
        }
    }
    else
        cout << "List is empty" << endl;
}



void DoubleLinkedList::deleteNode(int num)
{
    DLL_Node *p = NULL;
    DLL_Node *q = NULL;
    p = head;
    if (!isempty())
    {
        if (p->data == num)
        {
            q = p;
            p = p->next;
            head = p;
            cout << q->data << "을(를) 리스트에서 삭제했습니다. " << endl;
            delete q;
        }
        else
        {
            while (p != 0 && p->data != num)
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
                cout << p->data << "을(를) 리스트에서 삭제했습니다. " << endl;
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

void DoubleLinkedList::remove(int index)
{
    int checkIndex = 0;
    DLL_Node *p = NULL;
    DLL_Node *q = NULL;
    p = head;
    if (!isempty())
    {
        if (checkIndex == index)
        {
            q = p;
            p = p->next;
            head = p;
            cout << q->data << "을(를) 리스트에서 삭제했습니다. " << endl;
            delete q;
        }
        else
        {
            while (p != 0 && checkIndex != index)
            {
                q = p;
                p = p->next;
                ++checkIndex;
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
                cout << p->data << "을(를) 리스트에서 삭제했습니다. " << endl;
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

DLL_Node *DoubleLinkedList::Find(int index)
{

    DLL_Node *temp = head;

    for (int i = 1; i < index; ++i)
    {
        temp = temp->next;
    }
    return temp;
}

void DoubleLinkedList::insertafter(int index, int num)
{

    DLL_Node *find = Find(index);
    DLL_Node *newNode = new DLL_Node(num);
    newNode->next = find->next;
    newNode->prev = find;
    find->next = newNode;
    newNode->next->prev = newNode;
}

void DoubleLinkedList::insertbefore(int index, int num)
{

    DLL_Node *find = Find(index);
    DLL_Node *newNode = new DLL_Node(num);
    newNode->next = find;
    newNode->prev = find->prev;
    find->prev = newNode;
    newNode->prev->next = newNode;
}

void DoubleLinkedList::insert(int num)
{
    DLL_Node *p = NULL;
    DLL_Node *q = NULL;
    DLL_Node *temp = new DLL_Node();
    temp->data = num;

    if (head == 0)
        head = temp;
    else
    {
        p = head;
        if (temp->data <= head->data)
        {
            temp->next = p;
            p->prev = temp;
            head = temp;
        }
        else
        {
            while (p != 0 && temp->data > p->data)
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

bool DoubleLinkedList::isempty()
{
    if (head == 0)
        return 1;
    else
        return 0;
}

void DoubleLinkedList::findNth(int index)
{
    DLL_Node *temp = head;
    for(int i = 0; i < index; i ++)
    {
        temp = temp -> next;
    }
    cout << temp->data << endl;
}

int main(void)
{
}