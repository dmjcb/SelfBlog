#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const int MaxN=1000100;

ll  fastPow(ll  a,ll b,ll mod) {
    ll ans=1;
    a %= mod;
    while(b) {
        if(b&1) {
            ans = (ans*a)%mod;
        }
        b >>= 1;
        a = (a*a)%mod;
    }
    return ans;
}

ll  eulerfun(ll x) {  //欧拉函数
    ll n = x;
    for(ll i = 2; i*i <= x; i++) {
        if(x % i == 0) {
            n = n / i * (i-1);
            while(x % i == 0) {
                x /= i;
            }
        }
    }
    if(x > 1) {
        n = n / x * (x-1);
    }
    return n;
}

ll droppws(ll a,char b[],ll c) {  
    ll num = eulerfun(c);  //c的欧拉函数值
    ll pows=0;  //存储降了之后的幂
    for(ll i=0,len = strlen(b); i<len; ++i) {
        pows=(pows*10+b[i]-'0') % num;
    }
    //b mod &(c) + &(c) 
    pows += num;
    return fastPow(a,pows,c); //快速幂
}


int main() {
    ll a,c;
    char b[MaxN];
    while(~scanf("%lld%s%lld",&a,b,&c)) { // a 的 b 次方对c取模
        printf("%lld\n",eulerDropPow(a,b,c));
    }
    return 0;
}
