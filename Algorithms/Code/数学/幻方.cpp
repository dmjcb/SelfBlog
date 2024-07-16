#include <iostream>
#include <cstdio>
#define N 50
using namespace std;
int a[N][N];
int main()
{
    int n, i, x = 0, y;
    cin >> n;
    int dn = n * n;
    y = n / 2;
    a[x][y] = 1;
    for (i = 2; i <= dn; i++)
    {
        if (x == 0 && y != n - 1)
        {
            a[n - 1][y + 1] = i;
            x = n - 1;
            y = y + 1;
        }
        else if (y == n - 1 && x != 0)
        {
            a[x - 1][0] = i;
            x = x - 1;
            y = 0;
        }
        else if (x == 0 && y == n - 1)
        {
            a[x + 1][y] = i;
            x = x + 1;
        }
        else if (x != 0 && y != n - 1)
        {
            if (a[x - 1][y + 1] == 0)
            {
                a[x - 1][y + 1] = i;
                x = x - 1;
                y = y + 1;
            }
            else
            {
                a[x + 1][y] = i;
                x = x + 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", a[i][j]);
            if (j != n - 1)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }
    }
    return 0;
}
