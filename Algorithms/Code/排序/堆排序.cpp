#include <iostream>
#include <algorithm>
using namespace std;

// ΪСѺ
void siftDown(int testData[], int start, int end)
{
    int parent = start;
    int child = 2 * start + 1;
    // tempݴڵ
    int temp = testData[parent];
    // ӱδյ
    while (child < end)
    {
        // ҶӱС
        if (child + 1 < end && testData[child] < testData[child + 1])
        {
            // childΪҶ
            ++child;
        }
        // ڵȶӽڵС,Ҫ
        if (temp >= testData[child])
        {
            break;
        }
        // Ӻ˫׵λ
        testData[parent] = testData[child];
        // ƱΪ˫
        parent = child;
        //
        child = 2 * child + 1;
    }
    // ˫׵ֵ
    testData[parent] = temp;
}

//
void heapSort(int testData[], int len, int n)
{
    for (int i = (len - 2) / 2; i >= 0; i--)
    {
        // һС
        siftDown(testData, i, len);
    }
    for (int i = len - 1; i > 0; i--)
    {
        // һԪ,
        swap(testData[0], testData[i]);
        siftDown(testData, 0, i);
    }
}

int a[10000];
int n, k;
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    heapSort(a, n, n);
    cout << a[n - k] << endl;
}
