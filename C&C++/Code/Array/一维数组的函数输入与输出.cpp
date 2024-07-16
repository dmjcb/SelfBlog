#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
    void inputArray(int(*p)[10]);
    void outputArray(int(*p)[10]);
    int array[10][10];
    // ָpָ10Ԫصһά
    int(*p)[10];
    p = array;
    inputArray(p);
    outputArray(p);
    return 0;
}

void inputArray(int (*p)[10])
{
    int i, j, k = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            *(*(p + i) + j) = k++;
        }
    }
}

void outputArray(int (*p)[10])
{
    int i, j, k = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%5d", *(*(p + i) + j));
            Sleep(1000);
        }
        cout << endl;
    }
}
