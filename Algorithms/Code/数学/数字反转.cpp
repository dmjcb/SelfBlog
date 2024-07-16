#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long num;
    // flagʾǲǸ,falseʾ
    bool flag = false;
    cin >> num;
    if (num < 0)
    {
        num *= -1;
        flag = true;
    }
    int a[11];

    for (int i = 0; num != 0; num /= 10)
    {
        a[i++] = num % 10;
    }
    if (flag = true)
    {
        cout << "-";
    }
    for (int i = 0; i < 11; i++)
    {
        if (i == 0 && a[i] == 0)
        {
            continue;
        }
        else
        {
            cout << a[i];
        }
    }
    return 0;
}
