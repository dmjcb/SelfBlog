/*
 * @Description:
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:
 * @Date: 2022-03-29 21:57:16
 * @LastEditors: dmjcb
 * @LastEditTime: 2022-03-29 22:05:57
 */
#include <iostream>
using namespace std;
// 选择排序
void selectionSort(int testData[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        // 起始基准码为表头元素位置
        int index = i;
        // 遍历之后所有元素
        for (int j = i + 1; j <= len - 1; j++)
        {
            // 如果某位置元素小于基准位置元素
            if (testData[j] < testData[index])
            {
                // 更新基准码
                index = j;
            }
        }
        // 如果基准码不是开始的那个,说明现位置的元素最小
        if (index != i)
        {
            // 将最小的元素交换到起始位置
            swap(testData[i], testData[index]);
        }
        cout << "第" << i + 1 << "趟 ";
        for (int i = 0; i < len; i++)
        {
            cout << testData[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int a[10], i;
    cout << "enter array :" << endl;
    for (i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    selectionSort(a, 10);
    cout << "The sorted array:" << endl;
    for (i = 0; i < 10; i++)
    {
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
