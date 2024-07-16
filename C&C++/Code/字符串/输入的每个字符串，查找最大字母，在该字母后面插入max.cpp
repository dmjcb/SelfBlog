#include<iostream>
using namespace std;
int main() {
    string str;
    cin>>str;
    int size = str.size();
    char max = str[0];
    for(int i=1; i<size; i++) {
        if(str[i]>max){
            max = str[i];
        }
    }
    for(int i=0; i<size; i++){
        cout<<str[i];
        if(str[i]==max){
            cout<<"(max)";
        }
    }
    return 0;
}
