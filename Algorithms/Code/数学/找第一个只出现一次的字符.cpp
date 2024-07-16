#include<iostream>
using namespace std;
int main(){
    string str;
    bool flag=true;
    int i,j,count;
    cin>>str;
    for(i=0;str[i]!='\0';i++){
        flag=false;
        for(j=0;str[j]!='\0';j++){
            if(str[i]==str[j]&&i!=j){
                flag=false;
                break;
            }
        }
        if(flag=true){
            cout<<str[i]<<endl;
            break;
        }
    }
    if(flag==false){
        cout<<"no"<<endl;
    }
    
}
