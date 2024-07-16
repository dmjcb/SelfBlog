#include<iostream>
#include<math.h>
using namespace std;
bool isPrime(int n) {
    for(int i=2; i<=sqrt(n); i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}

bool isNumber(int n) {
    int a;
    if(n<100) {
        a=n/10;
    } 
    else if(n<1000) {
        a=n/100;
    }
    if(a==n%10) {
        return true;
    } 
    else{
        return false;
    }
}
int main() {
    int n,count=0;
    cin>>n;
    for(int i=11; i<=n; i++) {
        if(isPrime(i)&&isNumber(i)) {
            count+=1;
        }
    }
    cout<<count<<endl;
    return 0;
}

