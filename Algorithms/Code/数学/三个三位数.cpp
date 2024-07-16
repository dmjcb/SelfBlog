/*
1299ֳ飬ֱ
λʹλ  1:2:3ı
λ

磺λ192384576
*/
#include <iostream>
using namespace std;
int main()
{
    for (int i = 123; i <= 333; i++)
    {
        int a[10] = {0};
        a[i / 100] = 1;
        a[i / 10 % 10] = 1;
        a[i % 10] = 1;
        int j = i * 2;
        a[j / 100] = 1;
        a[j / 10 % 10] = 1;
        a[j % 10] = 1;
        int k = i * 3;
        a[k / 100] = 1;
        a[k / 10 % 10] = 1;
        a[k % 10] = 1;
        int sum = 0;
        for (int m = 0; m < 10; m++)
        {
            sum += a[m];
        }
        // ֵÿλպλ0~9֮䣬Ҷֻһ
        if (sum == 9)
        {
            cout << i << " " << j << " " << k << endl;
        }
    }
    return 0;
}
