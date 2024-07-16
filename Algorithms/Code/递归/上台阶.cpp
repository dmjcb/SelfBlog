#include <iostream>
#include <vector>
using namespace std;
int a[100];

int main()
{
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    for (int i = 4; i < 100; i++)
    {
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }
    int n;
    vector<int> v;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        v.push_back(a[n]);
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}
