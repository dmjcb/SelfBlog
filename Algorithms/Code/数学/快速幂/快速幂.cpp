#include<iostream>
using namespace std;
typedef long long ll;

ll fastPower(int a,int b) {
    if(a==0) {
        return 0;
    }
    if(b==0) {
        return 1;
    }
    ll res = 1;
    while(b) {
        cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl<<endl;
        if(b&1) {
            int t = res;
            int s = a;
            res*=a;
            cout<< "res = "<<res <<" = "<<t<<" * "<<s<<endl<<endl;
        }
        b>>=1;
        a*=a;
    }
    return res;

}
int main() {

    fastPower(3,13);
    return 0;
}
