typedef long long ll;
ll mod = 1e9;
// 快速乘法
ll mult(ll a, ll b)
{
    a %= mod;
    b %= mod;
    ll s = a, sum = 0;
    while (b)
    {
        if (b & 1)
        {
            sum += s;
            if (sum >= mod)
            {
                sum -= mod;
            }
        }
        b >>= 1;
        s <<= 1;
        if (s >= mod)
        {
            s -= mod;
        }
        return sum;
    }
}

// 方法一
ll power(ll a, ll b)
{
    ll s = a, sum = 1;
    while (b)
    {
        if (b & 1)
        {
            sum = mult(sum, s);
        }
        b >>= 1;
        s = mult(s, s);
    }
    return sum;
}