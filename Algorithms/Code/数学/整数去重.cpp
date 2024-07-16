#include <iostream>
using namespace std;
int main()
{
    int n, t, a[20000] = {0}, b[101] = {0}, i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> t;
        b[t]++;
        // ǵһγʱ
        if (b[t] == 1)
        {
            a[i] = t;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            cout << a[i] << " ";
        }
    }
    return 0;
}
