//分离出一个数字的所有因子
#include<iostream>
using namespace std;
void divide(int n) {
    //1肯定为一个数的因子
    cout<<n<<"=1*";
    for(int i=2; i<n; i++) {
        while(n!=i) {
            if(n%i==0) {
                cout<<i<<"*";
                n/=i;
            } else
                break;
        }
    }
    cout<<n<<endl;
}

int main() {
    int n,i;
    cin>>n;
    divide(n);
    return 0;
}

