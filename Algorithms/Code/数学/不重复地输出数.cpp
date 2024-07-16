#include<iostream>
using namespace std;
int main(){
    int n,a[32768]={0},t,i;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>t;
        a[t]++;
    }
    for(i=0;i<32768;i++){
        if(a[i]!=0){
            cout<<i<<" ";
        }
    } 
    cout<<endl;
    return 0;
}
