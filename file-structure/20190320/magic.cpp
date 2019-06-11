#include <iostream>

using namespace std;

void magic(int n) {
    int square[n][n], k, l, row,col;
    for(k=0; k < n; k++) {
        for(l=0; l<n; l++) {
            square[k][l] = 0;
        }
    }
    int key = 2;
    int i = 0;
    int j = n/2;
    square[0][n/2] = 1;

    while(key <= n * n) {
        if(i - 1 < 0) row = n - 1; else row = i - 1;
        if(j - 1 < 0) col = n - 1; else col = j - 1;
        if(square[row][col]) i = (i + 1) % n;
        else { i = row; j = col;}
        square[i][j] = key++;
    }

    for(k=0; k < n; k++) {
        for(l=0; l<n; l++) {
            cout << square[k][l] << " ";
        }
        cout << "\n";
    }
}

int main(void)
{
    magic(5);
}