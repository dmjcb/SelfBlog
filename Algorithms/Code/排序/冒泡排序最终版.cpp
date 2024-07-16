#include <iostream>
using namespace std;
int main()
{
    int n, i, j, *a;
    a = new int[n];
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // 用来记录最后一次交换的位置
    int lastExchangeIndex = 0;
    // 无序数列的边界，每次比较只需比到这为止
    int sortBorder = n - 1;
    for (i = 0; i < n; i++)
    {
        // 每一轮开始时默认为有序排序，标记为ture
        bool isSorted = true;
        for (j = 0; j < sortBorder; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                // 有元素交换，说明不是有序，标记变为false
                isSorted = false;
                // 记录最后一次交换的位置
                lastExchangeIndex = j;
            }
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }

        // 把无序数列边界更新为最后一次交换元素的位置
        sortBorder = lastExchangeIndex;
        // 若内侧一轮排序后仍为有序，说明排序完成，结束
        if (isSorted)
        {
            break;
        }
    }

    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
