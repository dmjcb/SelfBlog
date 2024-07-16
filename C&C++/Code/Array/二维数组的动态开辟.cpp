#include <iostream>
using namespace std;
int main()
{
    int i, j, k = 0;
    int X, Y;
    cin >> X >> Y;
    int **a = new int *[Y];
    for (i = 0; i < X; i++)
    {
        a[i] = new int[X];
    }
    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            cin >> a[i][j];
        }
    }
    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    // ͷſռ
    for (i = 0; i < X; i++)
    {
        delete a[i];
    }
    delete[] a;
    return 0;
}
