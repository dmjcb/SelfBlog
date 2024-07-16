/*
 * @Description:
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:
 * @Date: 2024-07-06 20:32:28
 * @LastEditors: dmjcb
 * @LastEditTime: 2024-07-06 20:35:31
 */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> light(0);

    for (int i = 2; i < n; i += 2)
    {
        light[i] = 1;
    }
    for (int i = 3; i <= m; i++)
    {
        for (int j = i; j < n; j += i)
        {
            if (light[j] == 0)
            {
                light[j] = 1;
            }
            else if (light[j] == 1)
            {
                light[j] = 0;
            }
        }
    }
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        if (light[i] == 0)
        {
            v.push_back(i);
        }
    }
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << ",";
    }
    cout << v[v.size() - 1] << endl;
    return 0;
}
