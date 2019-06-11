/*
원형 연결 리스트 (Circular Linked List)
*/
#include<iostream>

using namespace std;

#define null NULL

typedef struct node
{
  int data;
  node *next;
} Node;

typedef struct list
{
  int countIndex;
  Node *tail; // 원형리스트는 head가 아닌 tail노드를 가진다.
} List;

List *CreateList()
{
  List *list = (List *)malloc(sizeof(List));

  if (list == null)
  {
    cout << ("error\n") << endl;
  }
  else
  {
    list->tail = null;
    list->countIndex = 0;
  }

  return list;
}

void AddNode(List *list, int position, node element)
{
  Node *preNode = list->tail;
  Node *newNode = (Node *)malloc(sizeof(Node));

  //데이터 삽입
  newNode->data = element.data;

  if (list->countIndex == 0)
  {
    newNode->next = newNode;
    list->tail = newNode;
  }
  else
  {
    for (int i = 0; i < position; i++)
    {
      preNode = preNode->next;
    }

    newNode->next = preNode->next;
    preNode->next = newNode;

    if (position == list->countIndex)
    {
      list->tail = newNode;
    }
  }

  list->countIndex++;
}

void DelNode(List *list, int position)
{
  Node *preNode = list->tail;
  Node *delNode = list->tail;

  if (list->countIndex == 0)
  {
    cout << ("노드가 없습니다.") << endl;
  }
  else
  {
    for (int i = 0; i < position; i++)
    {
      preNode = preNode->next;
    }

    delNode = preNode->next;
    preNode->next = delNode->next;
    free(delNode);

    if (position == list->countIndex - 1)
    {
      list->tail = preNode;
    }

    list->countIndex--;
  }
}

void display(List *list)
{
  int i;
  Node *node;

  for (node = list->tail->next, i = 0; i < list->countIndex; i++, node = node->next)
  {
    printf("%d ", node->data);
  }
}

int main()
{
  List *list;
  Node node;
  list = CreateList();

  printf("\n정답 : 0 1 2 3 4 5\n");
  printf("출력 : ");
  node.data = 0;
  AddNode(list, 0, node);
  node.data = 1;
  AddNode(list, 1, node);
  node.data = 2;
  AddNode(list, 2, node);
  node.data = 3;
  AddNode(list, 3, node);
  node.data = 4;
  AddNode(list, 4, node);
  node.data = 5;
  AddNode(list, 5, node);
  display(list);

  printf("\n--------------------------\n");

  printf("\n정답 : 1 2 5\n");
  printf("출력 : ");
  DelNode(list, 0);
  DelNode(list, 3);
  DelNode(list, 2);
  display(list);
  printf("\n--------------------------\n");

  printf("\n정답 : 7 8 9\n");
  printf("출력 : ");
  node.data = 9;
  AddNode(list, 0, node);
  node.data = 8;
  AddNode(list, 0, node);
  node.data = 7;
  AddNode(list, 0, node);
  DelNode(list, 5);
  DelNode(list, 4);
  DelNode(list, 3);
  display(list);
  printf("\n--------------------------\n");

  return 0;
}