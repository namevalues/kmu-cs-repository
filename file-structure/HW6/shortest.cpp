#include <stdio.h>
#include <limits.h>
#include <iostream>

#define V 7

int minDistance(int dist[], bool visited[])
{
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++)
    if (visited[v] == false && dist[v] <= min)
    {
      if (dist[v] != min)
      {
        min = dist[v], min_index = v;
      }
    }
  return min_index;
}


void shortest(int graph[V][V], int src)
{
  int dist[V];

  bool visited[V];

  int parent[V];

  for (int i = 0; i < V; i++)
  {
    parent[0] = -1;
    dist[i] = INT_MAX;
    visited[i] = false;
  }

  dist[src] = 0;

  for (int count = 0; count < V - 1; count++)
  {
    int u = minDistance(dist, visited);

    if (count > 0)
    {
      std::cout << "     (Selected Node : " << u << ")" << std::endl;
    }

    visited[u] = true;

    for (int v = 0; v < V; v++)

      if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
      {
        parent[v] = u;
        dist[v] = dist[u] + graph[u][v];
      }

    std::cout << "DIST : ";
    for (int i = 0; i < V; ++i)
    {
      std::cout << dist[i] << " ";
    }
  }
  for (int i = 0; i < V; ++i)
  {
    if (visited[i] == false)
    {
      std::cout << "     Selected Node : " << i << std::endl;
    }
  }
}

int main()
{
  int graph[V][V] = {
      {100, 2, 4, 5, 100, 100, 100},
      {100, 100, 100, 2, 7, 100, 100},
      {100, 100, 100, 1, 100, 4, 100},
      {100, 2, 1, 100, 4, 3, 100},
      {100, 7, 100, 4, 100, 1, 5},
      {100, 100, 4, 3, 1, 100, 7},
      {100, 100, 100, 100, 7, 5, 100}};

  for (int i = 0; i < V; ++i)
  {
    for (int j = 0; j < V; ++j)
    {
      std::cout << graph[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  shortest(graph, 0);
  return 0;
}