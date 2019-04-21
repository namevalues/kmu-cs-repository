/*
*********************************************************
* Name: 하준혁
* Student ID : 20181705
* Program ID : hw1-1
* Description: Sparse Matrix Transpose 
* Algorithm : Fast Transpose Algorithm
*
* Variables:
* - MAX_COL : 최대 칼럼 수
* - term: row,col,value를 저장하는 구조체
**********************************************************
*/

#include <iostream>
#include <fstream>
#include <sstream>

#define MAX_COL 100

using namespace std;

typedef struct
{
    int row;
    int col;
    int value;
} term;

// a는 입력받은 term, b는 출력할 term
void fast_transpose(term a[], term b[])
{
    int row_terms[MAX_COL], starting_pos[MAX_COL];
    int i, j, num_col = a[0].col, num_terms = a[0].value;

    b[0].row = num_col;
    b[0].col = a[0].row;
    b[0].value = num_terms;

    if (num_terms > 0)
    {
        for (i = 0; i < num_col; i++)
        {
            row_terms[i] = 0;
        }
        for (i = 1; i < num_terms; i++)
        {
            row_terms[a[i].col]++;
        }

        starting_pos[0] = 1;
        for (i = 1; i < num_col; i++)
        {
            starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
        }

        for (i = 1; i <= num_terms; i++)
        {
            j = starting_pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }

    for (int c = 0; c < MAX_COL; c++)
    {
        cout << b[c].row << " " << b[c].col << " " << b[c].value << endl;
    }
}

int main()
{
    term a[MAX_COL], b[MAX_COL];
    string filePath = "hw1-1.txt";
    ifstream openFile(filePath.data());
    if (openFile.is_open())
    {
        string line;
        int line_count = 0;
        while (getline(openFile, line))
        {
            stringstream ss(line);
            int txt;
            int string_count = 0;
            while (ss >> txt)
            {
                // 라인의 첫번째 정보는 row다.
                if (string_count == 0)
                {
                    a[line_count].row = txt;
                    string_count++;
                }
                // 라인의 두번째 정보는 col이다.
                else if (string_count == 1)
                {
                    a[line_count].col = txt;
                    string_count++;
                }
                // 라인의 마지막 정보는 value이다.
                else
                {
                    a[line_count].value = txt;
                    string_count = 0;
                }
            }
            line_count++;
        }
        openFile.close();
    }
    fast_transpose(a, b);
    return 0;
}