#include <iostream>
#include <vector>
using namespace std;

int lis(vector<int> &v, int n)
{
    // b[i]г
    vector<int> v2;
    // Ԫ
    for (int i = 0; i < n; i++)
    {
        // ʼ1
        v2.push_back(1);
        for (int j = 0; j < i; j++)
        {
            if (v[j] < v[i] && v2[j] + 1 > v2[i])
                v2[i] = v2[j] + 1;
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++)
        if (max < v2[i])
        {
            max = v2[i];
        }
    return max;
}

int main()
{
    long n;
    int item;
    cin >> n;
    vector<int> v1;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        v1.push_back(item);
    }
    cout << lis(v1, n);
}
