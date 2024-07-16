#include<iostream>
using namespace std;
int main() {
    long n,i;
    cin>>n;
    for(i=2;i<=n;i++){
        if(n%i==0){
            cout<<n/i<<endl;
            break;
        }
    }
    return 0;
}
