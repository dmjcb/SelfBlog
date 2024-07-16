#include<iostream>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int size = str.size();
    if('a'<=str[0]&&str[0]<='z'){
        str[0]-=32;
    }
    for(int i=1;i<size;i++){
        if(str[i-1]==' '){
            str[i]-=32;
        }
    }
    cout<<str;
    return 0;
}
