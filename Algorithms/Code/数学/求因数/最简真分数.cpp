#include<bits/stdc++.h>
using namespace std;
int main() {
    int a[1001],n,i,j,sum=0;
    cin>>n;
    for(i=0; i<n; i++) {
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]<a[j]&&a[j]%a[i]!=0){
                sum++;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
    
}
