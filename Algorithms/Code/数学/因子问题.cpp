#include<iostream>
using namespace std;
int main(){
    long n,m,a;
    bool flag=false;
    cin>>n>>m;
    for(a=1;a<n;a++){
        if(n%a==0&&n%(m-a)==0){
            flag=true;
            break;
        }
    }
    if(flag=false||a==1){
        cout<<"-1"<<endl;
    }
    else{
        cout<<a<<endl;
    }
    return 0;
}
