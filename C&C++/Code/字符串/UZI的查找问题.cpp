#include<iostream>
using namespace std;
int main() {
    string str;
    cin>>str;
    int u=0,z=0,i=0;
    for(int j =str.size()-1; j>=0; j--) {
        if(str[j] == 'U') {
            u+=z;
        } else if(str[j] == 'Z') {
            z+=i;
        } else if(str[j] == 'I') {
            i++;
        }
    }
    cout<<u<<endl;
}
