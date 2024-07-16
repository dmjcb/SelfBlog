#include <string.h>
typedef long long ll;
const int MAX = 1000100;

ll eulerDropPower(ll a, char b[], ll c)
{
    // 求出c的欧拉函数
    ll ans = c;
    for (ll i = 2; i * i <= c; i++)
    {
        if (c % i == 0)
        {
            ans = ans / i * (i - 1);
            while (c % i == 0)
            {
                c /= i;
            }
        }
    }
    if (c > 1)
    {
        ans = ans / c * (c - 1);
    }

    // 降幂,n代表降了之后的幂
    ll n = 0;
    for (ll i = 0, len = strlen(b); i < len; i++)
    {
        n = (n * 10 + b[i] - '0') % ans;
    }

    // 快速幂
    ll ant = 1;
    a %= c;
    while (ans)
    {
        if (ans & 1)
        {
            ans = (ans * a) % c;
        }
        ans >>= 1;
        a = (a * a) % c;
    }
    return ant;
}