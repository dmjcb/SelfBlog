/*
ҳ M  N ֮䣨N С M
Ķ壺һ P Ϊ䷴Ҳ
Ϊô P Ϊ磬1113 Ϊ
Ϊ11ķΪ1113 ķΪ 31 ҲΪ
*/
#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(int n)
{
    int i;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int inverNum(int n)
{
    int num = 0;
    while (n)
    {
        num = num * 10 + n % 10;
        n /= 10;
    }
    return num;
}

int main()
{
    int M, N, i, a[100001], j = 0;
    bool b = false;
    cin >> M >> N;
    for (i = M; i <= N; i++)
    {
        if (isPrime(i) && isPrime(inverNum(i)))
        {
            b = true;
            a[j] = i;
            j += 1;
        }
    }
    for (i = 0; i < j - 1; i++)
    {
        cout << a[i] << ",";
    }
    cout << a[j - 1] << endl;

    if (b = false)
    {
        cout << "No" << endl;
    }
    return 0;
}
