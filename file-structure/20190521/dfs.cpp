#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 10;

int gp[6][6] = {{0, 0, 0, 0, 1, 1}, {0, 0, 1, 1, 0, 1}, {0, 1, 0, 1, 1, 0}, {0, 1, 1, 0, 0, 0}, {1, 0, 1, 0, 0, 1}, {1, 1, 0, 0, 1, 0}};

class Node
{
private:
  int vertex;
  Node *next;

public:
  Node(int num) : vertex(num), next(NULL) {}
  friend class Graph;
};

class Graph
{
private:
  Node *graph[MAX];
  bool visited[MAX];
  Node *front;
  Node *rear;

public:
  Graph() : front(NULL), rear(NULL) {}
  void Graph_graph_init();
  void Graph_visited_init();
  void Graph_insert(int num1, int num2);
  void Graph_display();
  void enqueue(int v);
  int dequeue();
  void bfs(int v);
  void dfs(int v);
};

void Graph::Graph_graph_init()
{
  for (int i = 0; i < MAX; i++)
    graph[i] = NULL;
}

void Graph::Graph_visited_init()
{
  for (int i = 0; i < MAX; i++)
    visited[i] = 0;
}

void Graph::Graph_insert(int num1, int num2)
{
  if (graph[num1] == NULL)
  {
    Node *temp_1 = new Node(num1);
    graph[num1] = temp_1;
  }
  if (graph[num2] == NULL)
  {
    Node *temp_2 = new Node(num2);
    graph[num2] = temp_2;
  }

  Node *p = graph[num1];
  Node *temp1 = new Node(num2);
  while (p->next != NULL)
    p = p->next;
  p->next = temp1;

  p = graph[num2];
  Node *temp2 = new Node(num1);
  while (p->next != NULL)
    p = p->next;
  p->next = temp2;
}

void Graph::Graph_display()
{
  cout << "v";
  for (int i = 0; i < MAX; i++)
  {
    if (graph[i] != NULL)
    {
      Node *p = graph[i];
      int cnt = 0;
      while (p != NULL)
      {
        cout << p->vertex << " ";
        p = p->next;
        cnt++;
        if (cnt > 3)
        {
          break;
        }
      }
      cout << endl;
      cout << "v";
    }
  }
}

void Graph::enqueue(int v)
{
  Node *temp = new Node(v);
  if (front == NULL)
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

int Graph::dequeue()
{
  Node *p;
  int v;
  p = front;
  front = p->next;
  v = p->vertex;
  delete (p);
  return v;
}

void Graph::bfs(int v)
{
  Node *p;
  enqueue(v);
  visited[v] = 1;
  cout << "v" << v << " ";

  while (front)
  {
    v = dequeue();
    for (p = graph[v]; p; p = p->next)
    {
      if (!visited[p->vertex])
      {
        enqueue(p->vertex);
        visited[p->vertex] = 1;
        cout << "v" << p->vertex << " ";
      }
    }
  }
}

void Graph::dfs(int v)
{
  Node *p;
  visited[v] = 1;
  cout << "v" << v << " ";

  for (p = graph[v]; p; p = p->next)
  {
    if (!visited[p->vertex])
      dfs(p->vertex);
  }
}

int main(void)
{
  Graph g;
  g.Graph_graph_init();
  g.Graph_visited_init();
  ifstream inStream;
  inStream.open("input.txt");
  int num1, num2;
  for (int i = 0; i < 10; i++)
  {
    inStream >> num1 >> num2;
    g.Graph_insert(num1, num2);
  }

  cout << "Graph Data:" << endl;
  g.Graph_display();
  cout << "Depth First Search Output (starting from v0)" << endl;
  g.dfs(0);
  cout << endl;
  /*
	cout << "------------------------------" << endl;
	cout << "DFS 출력" << endl;
	g.dfs(0);
	cout << endl;
	cout << "BFS 출력" << endl;
	g.Graph_visited_init();
	g.bfs(0);
	cout << endl;
  */
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      cout << gp[i][j] << " ";
    }
    cout << endl;
  }
g.Graph_visited_init();
  g.bfs(0);

  inStream.close();
  return 0;
}