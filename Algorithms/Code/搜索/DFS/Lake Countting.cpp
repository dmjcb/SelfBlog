#include <iostream>
using namespace std;

int n = 3, m = 3;
int a[3][6] = {
    {1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1}};

void dfs(int x, int y)
{
    // ˴Ϊ1
    a[x][y] = 1;
    //(-1,-1),(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(0,0)ʾ˸
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            // nx,nyƶ֮λ
            int nx = x + dx, ny = y + dy;
            // λھֵΪ0ʱ
            if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] == 0)
            {
                // DFS
                dfs(nx, ny);
            }
        }
    }
}

int main()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                dfs(i, j);
                sum++;
            }
        }
    }
    cout << sum << endl;
}
