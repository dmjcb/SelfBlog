#include<iostream>
using namespace std;
typedef long long ll;
//a*b
ll rapidMultiplication(int a,int b) {
    ll ans = 0;
    while(b) {
        //若b的二进制末位为1,即b为奇数时 
        if(b&1) {
            //将结果暂存在ans中 
            ans+=a;
        }
        //拆b 
        b>>=1;
        //扩a 
        a<<=1;
    }
    return ans;
}
int main() {
    int a,b;
    cin>>a>>b;
    cout<<rapidMultiplication(a,b)<<endl;
}
