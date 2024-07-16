#include<iostream>
using namespace std;

int factorial(int n) {
    int t=1;
    for(int i=1; i<=n; i++) {
        t*=i;
    }
    return t;
}

int main() {
    int m,n;
    cin>>m>>n;
    int t= factorial(n)*factorial(m-1);
    cout<<factorial(m+n-1)/t;
    return 0;

}
