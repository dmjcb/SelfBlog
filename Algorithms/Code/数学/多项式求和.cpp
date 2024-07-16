#include <iostream>
using namespace std;
double sumValue(int n)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || i % 2 != 0)
        {
            sum += 1.0 / n;
        }
        else if (i % 2 == 0)
        {
            sum += -1.0 / n;
        }
    }
    return sum;
}

int main()
{
    int m, n;
    int a[100];
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        printf("%.2lf\n", sumValue(a[i]));
    }
}
