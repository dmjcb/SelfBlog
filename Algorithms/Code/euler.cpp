#include<iostream>
using namespace std;
typedef long long ll;
ll eulerFunction(ll n){
    ll res = n;
    for(ll i= 2;i*i<=n ;i++){
        if(n%i==0){
            res = res/i*(i-1);
            while(n%i==0){
                n/=i;
            }
        }
    } 
    if(n>1){
        res = res/n*(n-1);
    }
    return res;
}
int main() {
    ll n;
    scanf("%ld",&n);
    printf("%ld\n",eulerFunction(n));
    return 0;
}