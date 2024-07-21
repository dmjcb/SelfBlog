/*
 * @Description:
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:
 * @Date: 2022-03-29 21:57:16
 * @LastEditors: dmjcb
 * @LastEditTime: 2024-07-21 23:11:25
 */
// T代表总共能够用来采药的时间,M代表山洞里的草药的数目。
// 接下来的M行每行包括两个在1到100之间（包括1和100）的的
// 整数,分别表示采摘某株草药的时间和这株草药的价值。
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int M, T;
int t[101], m[101];
int dp[101][101];
// 从第i个物品中找出总时间小于j的部分

int main()
{
    cin >> T >> M;
    for (int j = 0; j <= T; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> t[i] >> m[i];
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j <= T; j++)
        {
            // 如果不能选
            if (t[i] > j)
            {
                dp[i + 1][j] = dp[i][j];
            }
            else
            {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - t[i]] + m[i]);
            }
        }
    }
    cout << dp[M][T] << endl;
    return 0;
}
