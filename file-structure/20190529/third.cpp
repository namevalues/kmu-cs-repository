#include <iostream>

const int MAX = 9; //간선 갯수
const int V = 6;    //정점 갯수

int unionfind[V] = {
    0,
}; //방문 확인하는 unionfind 배열을 생성합니다.

struct MST
{ //정점 x, 정점 y 그리고 두 정점의 가중치 c를 가지고있는 MST 구조체 생성합니다.
  int x;
  int y;
  int c;
};

MST mst[10]; //데이터 파일로부터 x,y,c를 입력 받아 mst 구조체 배열에 넣습니다.

void unionfindinit()
{ //unionfind 배열을 초기화하는 함수입니다.

  for (int i = 0; i < V; ++i)
  {
    unionfind[i] = i;
  }
}
void originalprint()
{ //정렬이 되지 않은 Original Data를 출력하는 함수입니다.

  printf("Original Data : \n");
  for (int i = 0; i < MAX; ++i)
  {
    printf("%c %d %c\n", mst[i].x + 65, mst[i].c, mst[i].y + 65);
  }
  printf("\n");
}

void sorted()
{ //정렬되지 않은 MST 구조체 배열을 오름차순으로 선택정렬하는 함수입니다.

  for (int i = 0; i < MAX; ++i)
  {
    int min = mst[i].c;
    int minpos = i;
    for (int j = i; j < MAX; ++j)
    {
      if (mst[j].c < min)
      {
        min = mst[j].c;
        minpos = j;
      }
    }
    MST temp;
    temp = mst[i];
    mst[i] = mst[minpos];
    mst[minpos] = temp;
  }
}
void sortedprint()
{ //정렬된 Sorted Data를 출력하는 함수입니다.

  printf("Sorted Data : \n");
  for (int i = 0; i < MAX; ++i)
  {
    printf("%c %d %c\n", mst[i].x + 65, mst[i].c, mst[i].y + 65);
  }
  printf("\n");
}

void kruskal()
{ //Kruskal's MST를 출력하는 함수입니다.

  int sum = 0; //Total Cost를 저장할 sum 변수

  printf("Kruskal's MST : \n");

  for (int i = 0; i < MAX; ++i)
  { //간선의 개수만큼 반복문을 돌립니다.
    if (unionfind[mst[i].x] < unionfind[mst[i].y])
    {                                 //mst[i]의 두 정점을 비교해 mst[i].x의 부모가 mst[i].y의 부모보다 작다면
      int find = unionfind[mst[i].y]; //숫자가 큰 부모를 find라는 변수에 임시 저장합니다.
      for (int j = 0; j < V; ++j)
      {
        if (unionfind[j] == find)
        { //숫자가 큰 부모인 find값과 같은 부모들을 모두 작은 부모 값으로 바꿔줍니다.
          unionfind[j] = unionfind[mst[i].x];
        }
      }
      sum += mst[i].c; //선택된 간선의 가중치를 sum에 더해줍니다.

      printf("%c %d %c\n", mst[i].x + 65, mst[i].c, mst[i].y + 65); //선택된 간선을 출력합니다.
    }
    else if (unionfind[mst[i].x] > unionfind[mst[i].y])
    {                                 //mst[i]의 두 정점을 비교해 mst[i].y의 부모가 mst[i].x의 부모보다 작다면
      int find = unionfind[mst[i].y]; //숫자가 큰 부모를 find라는 변수에 임시 저장합니다.
      for (int j = 0; j < V; ++j)
      {
        if (unionfind[j] == find)
        { //숫자가 큰 부모인 find값과 같은 부모들을 모두 작은 부모 값으로 바꿔줍니다.
          unionfind[j] = unionfind[mst[i].y];
        }
      }
      sum += mst[i].c; //선택된 간선의 가중치를 sum에 더해줍니다.

      printf("%c %d %c\n", mst[i].x + 65, mst[i].c, mst[i].y + 65); //선택된 간선을 출력합니다.
    }
  }
  printf("\n");
  printf("Total Cost : %d\n", sum); //선택된 간선의 가중치가 모두 더해진 sum 변수를 출력합니다.
}

int main()
{
  FILE *f;
  f = fopen("input.txt", "r");

  for (int i = 0; i < MAX; ++i)
  {
    fscanf(f, "%d %d %d", &mst[i].x, &mst[i].y, &mst[i].c); //구조체 속성을 입력 받아 mst 구조체 배열에 순서대로 넣는다.
  }

  int x[9] = {0,1,0,1,2,1,3,2,4};
  int y[9] = {5,6,12,10,17,24,20,30,13};
  int c[9] = {1,2,3,3,3,4,4,5,5};

  for(int i = 0; i < 9; i++) {
    mst[i].x = x[i];
    mst[i].y = c[i];
    mst[i].c = y[i];
  }

  originalprint(); //Original Data 출력하는 함수를 호출합니다.

  sorted(); //Original Data를 정렬하는 함수를 호출합니다.

  sortedprint(); //sorted Data 함수를 호출합니다.

  unionfindinit(); //unionfindinit 함수 호출를 호출합니다.

  kruskal(); //kruskal 함수를 호출합니다.
}