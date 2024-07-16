#include<iostream>
using namespace std;
typedef long long ll;
ll power(int x,int n) {
    if(n%2==0) {
        return power(x*x,n/2);
    }
    return x*power(x,n-1);
}

int main() {
    int x,n;
    cin>>x>>n;
    cout<<power(x,n)<<endl;
}
