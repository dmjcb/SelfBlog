#include<bits/stdc++.h>
using namespace std;
int main() {
    int a[1000],n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int *left,*right;
    left=a;
    right=a+n;
    bool flag=false;
    while(*left<=*right){
        if(*left+*right==k){
            flag=true;
            break;
        }
        else if(*left+*right>k){
            right--;
        }
        else{
            left++;
        }
    }
    if(flag=true){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    return 0;
}
