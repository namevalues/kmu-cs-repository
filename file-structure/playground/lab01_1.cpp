// 파일을 읽어서 단어의 개수 세기.

#include <iostream>
#include <fstream>  // for ifstream, open
#include <stdlib.h> // for exit

using namespace std;

int main(void)
{
    void countWord(char buffer[], int &wc);

    ifstream infile;
    char buffer[80];
    int wc;
    int total = 0;

    infile.open("lab01_1.txt", ios::in);
    if (infile.fail())
    {
        cout << "can't open the input file" << endl;
        exit(1);
    }

    while (infile.getline(buffer, 80))
    {
        cout << buffer << endl;
        countWord(buffer, wc);
        cout << "The number of words : " << wc << endl;
        total = total + wc;
    }
    cout << endl
         << endl
         << "The total number of words: " << total << endl
         << endl;
}

void countWord(char buffer[], int &wc)
{

    const int IN = 1;
    const int OUT = 0;

    int i = 0;
    int state = OUT;

    wc = 0;

    while (buffer[i] != '\0')
    {
        if (isalpha(buffer[i]))
        {
            if (state == OUT)
            {
                ++wc;
                state = IN;
            }
        }
        else if (buffer[i] == ' ')
            state = OUT;
        i++;
    }
}
