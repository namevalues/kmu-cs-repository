// Magic Square

#include <iostream>

using namespace std;

void magic(int n)
{
    int square[n][n];
    // Square 초기화
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            square[i][j] = 0;
        }
    }

    // 항상 (0,n/2) 의 값은 1이다.
    int i = 0;
    int j = n/2;
    square[i][j] = 1;
    
    //square에 들어가는 값은 2부터 시작이다.
    int key = 2;

    // 넣을 숫자의 위치를 계산해주기위한 변수
    int row, col;

    // square 에 들어갈 수 있는 숫자는 n*n 까지이다.
    while(key <= n*n)
    {
        // i는 항상 1보다 커야함.
        if(i-1 < 0)
            row = n - 1;
        else
            row = i - 1;
        if(j-1 < 0)
            col = n - 1;
        else
            col = j - 1;
        
        // 만약에 square[row][col]에 값이 존재한다면
        if(square[row][col])
            i = (i+1)%n;
        else
        {
            i = row;
            j = col;
        }

        square[i][j] = key++;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << square[i][j] << " ";
        }
        cout << endl;
    }

}

int main(void)
{
    magic(5);
}