#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
    if(n==2) {
        return true;
    }
    for(int i=2; i<=sqrt(n); i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}

int main() {
    int m,n,i,j,k=0,b[5000];
    cin>>m>>n;
    for(i=m; i<=n; i++) {
        if(isPrime(i)) {
            b[k++]=i;
        } else {
            for(j=i-1; j>1; j--) {
                if(i%j==0) {
                    b[k++]=j;
                    break;
                }
            }
        }
    }
    for(i=0; i<k-1; i++) {
        cout<<b[i]<<",";
    }
    cout<<b[k-1]<<endl;
    return 0;
}
