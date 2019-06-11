#include <stdio.h>
#include <limits.h>
#include <iostream>

//그래프의 정점 수
#define V 7

//최단 경로 트리에 아직 포함되지 않은 정점 집합으로부터
//최소 거리 값을 갖는 정점을 찾는 함수
int minDistance(int dist[], bool visited[])
{

  // 최솟값을 초기화 합니다.
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++)
    if (visited[v] == false && dist[v] <= min)
    { //방문하지 않았고 dist중에서 최소 거리라면
      if (dist[v] != min)
      {
        min = dist[v], min_index = v;
      }
    }
  return min_index; //최소 거리 인덱스 반환
}

// 부모 배열을 사용하여 소스에서 j까지 최단 경로를 출력하는 함수
void printPath(int parent[], int j)
{

  // Base Case : If j is source
  if (parent[j] == -1)
    return;

  printPath(parent, parent[j]);

  printf("%d ", j);
}

// 구성된 거리 배열을 인쇄하는 함수
/*
void printSolution(int dist[], int n, int parent[])
{
	int src = 0;
	printf("Vertex\t\t Distance\tPath");
	for (int i = 1; i < V; i++)
	{
		if (dist[i] == INT_MAX)		//dist[i] 값이 없다면
		{
			printf("\n%d -> %d \t\t no Way\t\tno Way", src, i);
		}
		else
		{
			printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
			printPath(parent, i);
		}
	}
}
*/

void shortest(int graph[V][V], int src)
{

  std::cout << "Beginning Dist : ";

  // 거리 배열. dist [i]는 src에서 i까지 최단 거리를 유지합니다.
  int dist[V];

  // visited 배열
  bool visited[V];

  // 최단 경로 트리를 저장하는 부모 배열
  int parent[V];

  // 모든 거리를 INFINITE로 초기화하고 visited[]을 false로 초기화합니다.
  for (int i = 0; i < V; i++)
  {
    parent[0] = -1;
    dist[i] = INT_MAX;
    visited[i] = false;
  }

  // 소스 정점의 거리 자체는 항상 0입니다.
  dist[src] = 0;

  // 모든 정점의 최단 경로 찾기
  for (int count = 0; count < V; count++)
  {

    //아직 처리되지 않은 정점 세트에서 최소 거리를 가져옵니다.
    int u = minDistance(dist, visited);

    if (count > 0)
    {
      std::cout << std::endl << "Select:(" << u << ")  dist : ";
    }

    // 선택된 꼭지점을 처리 된 것으로 표시합니다.
    visited[u] = true;

    // 선택된 정점의 인접 정점의 dist 값을 업데이트합니다.
    for (int v = 0; v < V; v++)

      // visited에없는 경우에만 dist [v]를 업데이트하고,

      // u에서 v까지의 모서리가 있고 u를 통해 src에서 v까지 경로의 총 가중치가 dist [v]의 현재 값보다 작은 경우에만 업데이트합니다.
      if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
      {
        parent[v] = u;
        dist[v] = dist[u] + graph[u][v];
      }

    //업데이트 된 distance 배열 출력
    for (int i = 0; i < V; ++i)
    {
      std::cout << dist[i] << " ";
    }
  }
  for (int i = 0; i < V; ++i)
  {
    if (visited[i] == false)
    {
      std::cout << std::endl << "Selected Node : " << i << "     " << std::endl;
    }
  }

  // 구성된 distance 배열을 출력한다.
  //printSolution(dist, V, parent);
}

int main()
{
  int graph[V][V] = {
      {0, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
      {300, 0, 10000, 10000, 10000, 10000, 10000, 10000},
      {1000, 800, 0, 10000, 10000, 10000, 10000, 10000},
      {10000, 10000, 1200, 0, 10000, 10000, 10000, 10000},
      {10000, 10000, 10000, 1500, 0, 250, 10000, 10000},
      {10000, 10000, 10000, 1000, 10000, 0, 900, 1400},
      {10000, 10000, 10000, 10000, 10000, 10000, 0, 1000},
      {1700, 10000, 10000, 10000, 10000, 10000, 10000, 0}};

  for (int i = 0; i < V; ++i)
  {
    for (int j = 0; j < V; ++j)
    {
      std::cout << graph[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  shortest(graph, 4);
  return 0;
}