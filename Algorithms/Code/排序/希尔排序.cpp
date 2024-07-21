/*
 * @Description:
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:
 * @Date: 2022-03-29 21:57:16
 * @LastEditors: dmjcb
 * @LastEditTime: 2022-03-29 22:05:45
 */
#include <iostream>
#include <stdio.h>
#include <process.h>
using namespace std;

void shellSort(int a[], int len)
{
    int h, i, j, temp;
    // 控制增量
    for (h = len / 2; h > 0; h /= 2)
    {
        // 这个for循环就是前面的直接插入排序
        for (i = h; i < len; i++)
        {
            temp = a[i];
            // 循环打印数组的每个元素
            for (j = i - h; j >= 0 && temp < a[j]; j -= h)
            {
                a[j + h] = a[j];
            }
            a[j + h] = temp;
        }
    }
}

// 输出函数
void printArray(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int *a, n;
    cout << "请输入要排序的数目" << endl; // 决定一共对几个数字排序
    cin >> n;
    a = new int[n];
    cout << "请输入要排序的数字" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "shell排序前:";
    printArray(a, n);
    shellSort(a, n);
    cout << "shell排序后(正序):";
    printArray(a, n);
    delete[] a;
    return 0;
    system("pause");
}
