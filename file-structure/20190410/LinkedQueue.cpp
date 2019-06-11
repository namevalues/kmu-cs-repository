
// Linked Queue

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
  friend class linkedQueue;
};
class linkedQueue
{
private:
  Node *front;
  Node *rear;

public:
  linkedQueue()
  {
    front = 0;
    rear = 0;
  }
  ~linkedQueue(){};
  void createQueue();
  void enqueue(int);
  int dequeue();
  int isEmpty();
  void displayQueue();
  void searchQueue(int);
};

int linkedQueue::isEmpty()
{
  if (front == 0)
    return 1;
  else
    return 0;
}

void linkedQueue::createQueue()
{
  front = 0;
  rear = 0;
}

void linkedQueue::enqueue(int data)
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

int linkedQueue::dequeue()
{
  Node *p;
  int num;
  num = front->data;
  p = front;
  if (front == rear)
  {
    front = 0;
    rear = 0;
  }
  else
    front = front->next;
  delete p;
  return num;
}

void linkedQueue::displayQueue()
{
  Node *p;
  if (!isEmpty())
  {
    p = front;
    while (p)
    {
      cout << p->data;
      p = p->next;
    }
    cout << endl;
  }
  else
    cout << "Queue is empty!\n";
}