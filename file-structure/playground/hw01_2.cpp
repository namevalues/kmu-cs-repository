/*
*********************************************************
* Name: 하준혁
* Student ID : 20181705
* Program ID : hw1-2
* Description: 도형 면적 구하기 
* Algorithm : Fast Transpose Algorithm
*
* Variables:
* - MAX_ITEM : 최대 도형 수
* - Shape : 도형 정보를 저장하는 구조체
* - type : 도형 정보
* - size : 도형 면적
**********************************************************
*/

#include <iostream>
#include <fstream>
#include <sstream>
#define MAX_ITEM 50

using namespace std;

typedef struct
{
    string type;
    double a;
    double b;
    double size;
} Shape;

int main()
{
    Shape shape[MAX_ITEM];
    string filePath = "hw1-2.txt";
    ifstream openFile(filePath.data());
    cout << fixed;
    cout.precision(2); // 소수점 2번째자리까지 출력.
    if (openFile.is_open())
    {
        string line;
        int line_count = 0;
        while (getline(openFile, line))
        {
            stringstream ss(line);
            string txt;
            int string_count = 0;
            while (ss >> txt)
            {
                // 줄의 첫번째 정보는 도형의 type 이다.
                if (string_count == 0)
                {
                    shape[line_count].type = txt;
                    string_count++;
                }
                // 줄의 두번째 정보는 도형의 정보이다.
                else if (string_count == 1)
                {
                    shape[line_count].a = stod(txt);
                    string_count++;
                }
                // 원은 세번째 정보가 없다.
                else
                {
                    shape[line_count].b = stod(txt);
                }
            }
            line_count++;
        }
        openFile.close();
    }

    for (int i = 0; i < MAX_ITEM; i++)
    {
        if (shape[i].a == 0)
        {
        }
        //원의 넓이 구하기.
        else if (shape[i].b == 0)
        {
            cout << shape[i].type << " " << shape[i].a << " " << shape[i].a * shape[i].a * 3.14 << endl;
        }
        else
        {
            // 삼각형의 넓이 구하기
            if (shape[i].type == "triangle")
            {
                cout << shape[i].type << " " << shape[i].a << " " << shape[i].b << " " << shape[i].a * shape[i].b / 2 << endl;
            }

            // 사각형의 넓이 구하기
            else
            {
                cout << shape[i].type << " " << shape[i].a << " " << shape[i].b << " " << shape[i].a * shape[i].b << endl;
            }
        }
    }
    return 0;
}