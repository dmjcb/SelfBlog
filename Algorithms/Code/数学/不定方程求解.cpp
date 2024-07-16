#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    int count=0;
    cin>>a>>b>>c;
    for(int i=0;i<=c/a;i++){
        if((c-a*i)%b==0){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
} 
