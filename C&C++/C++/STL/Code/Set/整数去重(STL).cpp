/*
 * @Description:
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:
 * @Date: 2024-07-06 20:33:50
 * @LastEditors: dmjcb
 * @LastEditTime: 2024-07-06 20:38:24
 */
#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> s1;
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        s1.insert(temp);
    }
    for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}
