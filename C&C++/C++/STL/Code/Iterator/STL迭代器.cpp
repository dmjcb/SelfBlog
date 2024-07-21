/*
 * @Description:
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:
 * @Date: 2022-03-29 21:57:16
 * @LastEditors: dmjcb
 * @LastEditTime: 2022-03-29 22:19:12
 */
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(3); // 数组尾部插入3
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    cout << " 下标 " << v[3] << endl;
    cout << " 迭代器 " << endl;
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    // 在第一个元素之前插入111  insert begin+n是在第n个元素之前插入
    v.insert(v.begin(), 111);
    // 在最后一个元素之后插入222 insert end + n 是在n个元素之后插入
    v.insert(v.end(), 222);
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;

    vector<int> arr(10);
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    for (vector<int>::iterator i = arr.begin(); i != arr.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;

    // 删除 同insert
    arr.erase(arr.begin()); // 删除了开头元素
    for (vector<int>::iterator i = arr.begin(); i != arr.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    arr.erase(arr.begin(), arr.begin() + 5); // 删除了下标5(含)之前的元素
    for (vector<int>::iterator i = arr.begin(); i != arr.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}
