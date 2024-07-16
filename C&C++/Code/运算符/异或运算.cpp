/*
 * @Description:
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-03-29 21:57:16
 * @LastEditors: dalao
 * @LastEditTime: 2022-03-29 22:12:24
 */
#include <iostream>
using namespace std;
int add(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    // 位与
    int p1 = a & b;
    // cout<<"a&b="<<p1<<endl;
    // 这两句只考虑进位
    p1 = p1 << 1;
    // cout<<"p1<<1="<<p1<<endl;
    // 位异或。不考虑进位
    int p2 = a ^ b;
    // 结束的标志是a为0了，或者b为0了
    // cout<<"p1="<<p1<<" "<<"P2="<<p2<<endl;
    return add(p2, p1);
}
int main()
{
    int x = 3, y = 2;
    int sum = 0;
    sum = add(x, y);
    cout << sum << endl;
}
