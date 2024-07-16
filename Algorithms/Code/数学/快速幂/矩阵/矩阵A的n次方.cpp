// A^m
#include <iostream>
#include <string>
#define N 100
using namespace std;
typedef long long ll;
ll c[N][N];
ll d[N][N];

// A(n)(m)*B(m)(k)
void matrixMultiplication(ll a[][N], ll b[][N], int n, int m, int k)
{
    d[N][N] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            // 㵥c[][]ֵ
            for (int x = 0; x < m; x++)
            {
                d[i][j] += (a[i][x] * b[x][j]);
            }
        }
    }
    if (m == n && k == n)
    {
        a[n][n] = d[n][n];
    }
}

void matrixFastPower(ll a[][N], int n, ll b)
{
    if (b == 0)
    {
        a[n][n] = {0};
    }
    while (b)
    {
        if (b & 1)
        {
            return;
        }
        b >>= 1;
        matrixMultiplication(a, a, n, n, n);
    }
}

int main()
{
    ll a[N][N];
    int n, b;
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    matrixFastPower(a, n, b);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
}
