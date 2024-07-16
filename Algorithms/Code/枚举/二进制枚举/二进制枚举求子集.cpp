/*
 * @Description:
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:
 * @Date: 2024-07-06 20:32:28
 * @LastEditors: dmjcb
 * @LastEditTime: 2024-07-06 21:15:31
 */
#include <iostream>
#include <cstdlib>
using namespace std;
int a[3] = {2, 3, 4};
int main()
{
    for (int i = 1; i <= (1 << 3); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i & (1 << j))
            {
                cout << a[j] << " ";
            }
        }
        cout << endl;
    }
}
