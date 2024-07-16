/*
Ϊ2Ϊԣ571719
ȣĿҪҳnԡ

һn1 <= n <= 10000

СڵnԡÿһУ
õոûҵκԣempty
*/
#include <iostream>
#include <math.h>
using namespace std;
int isPrime(int n)
{
    int i;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n, i;
    bool a = false;
    cin >> n;
    for (i = 2; i <= n - 2; i++)
    {
        if (isPrime(i) && isPrime(i + 2))
        {
            cout << i << " " << i + 2 << endl;
            a = true;
        }
    }
    if (a = false)
    {
        cout << "empty" << endl;
    }
    return 0;
}
