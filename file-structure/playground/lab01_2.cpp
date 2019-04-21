// int 배열에서 max, min 값과 index 값 출력하기.

#include<iostream>

using namespace std;

int main(void)
{
    int array[8] = {21,32,13,44,25,76,18,29};
    int min = 100, min_index = 0;
    int max = 0, max_index = 0;
    for(int i = 0; i < sizeof(array) / sizeof(int); i++) {
        if(max < array[i]) {
            max = array[i];
            max_index = i;
        }
        if(min > array[i]) {
            min = array[i];
            min_index = i;
        }
    }

    cout << "MIN : " << min << " min index : " << min_index+1 << endl;
    cout << "MAX : " << max << " max index : " << max_index+1 << endl;
}