#include <iostream>
using namespace std;

void sorts(int data[], int n)
{
    // 用来记录左侧和右侧最后一次交换的位置
    int leftIndex;
    int rightIndex;
    // 无序数列的左右边界,每次比较只需比到这里为止
    int leftBorder = 0;
    int rightBorder = n - 1;

    for (int i = 0; i < n / 2; i++)
    {
        // 每一轮开始时默认为有序排序,标记为ture
        bool isSorted = true;
        // 奇数轮,从左向右进行比较和交换
        for (int j = leftBorder; j < rightBorder; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                // 有元素交换,说明不是有序,标记变为false
                isSorted = false;
                // 记录左侧最后一次交换的位置
                leftIndex = j;
            }
        }
        // 将右侧无序数列的边界更新为左侧最后一次交换的位置
        rightBorder = leftIndex;
        // 若排序后仍为有序,说明排序完成,则结束
        if (isSorted)
        {
            break;
        }
        // 每一轮开始时默认为有序排序,标记为ture
        isSorted = true;
        // 偶数轮,从右往左进行比较和交换
        for (int j = rightBorder; j > leftBorder; j--)
        {
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - i]);
                // 有元素交换,说明不是有序,标记变为false
                isSorted = false;
                // 记录右侧最后一次交换的位置
                rightIndex = j;
            }
        }
        // 将左侧无序数列的边界更新为右侧最后一次交换的位置
        leftBorder = rightIndex;
        // 若排序后仍为有序,说明排序完成,则结束
        if (isSorted)
        {
            break;
        }
    }
}

int main()
{
    int *a;
    a = new int[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
