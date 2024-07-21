/*
 * @Description:
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:
 * @Date: 2022-03-29 21:57:16
 * @LastEditors: dmjcb
 * @LastEditTime: 2022-03-29 22:40:30
 */
/*
pair是将2个数据组合成一个数据,当需要这样的需求时就可以使用pair,
如stl中的map就是将key和value放在一起来保存。另一个应用是,当一个
函数需要返回2个数据的时候,可以选择pair。 pair的实现是一个结构体
,主要的两个成员变量是first second 因为是使用struct不是class,所
以可以直接使用pair的成员变量。

pair将一对值组合成一个值,这一对值可以具有不同的数据类型
(T1和T2),两个值可以分别用pair的两个公有函数first和second访问。
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    pair<int, double> p1;
    pair<int, double> p2;
    p1.first = 1;
    p1.second = 2.5;

    p2 = make_pair(2, 2.2);

    pair<int, double> p3 = p1;

    cout << "p1" << " " << p1.first << " " << p1.second << endl;
    cout << "p2" << " " << p2.first << " " << p2.second << endl;
    cout << "p3" << " " << p3.first << " " << p3.second << endl;
}
