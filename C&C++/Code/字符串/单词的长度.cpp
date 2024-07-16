#include<iostream>
#include<vector>
using namespace std;
int main() {
    string str;
    getline(cin,str);
    vector<int> v;
    int size = 0;
    for(int i=0; str[i]!='\0'; i++) {
        if(str[i]!=' ') {
            size++;
        } else if(str[i+1]!=' ') {
            v.push_back(size);
            size=0;
        }
        if(str[i+1]=='\0') {
            v.push_back(size);
        }
    }
    for(int i=0; i<v.size()-1; i++) {
        cout<<v[i]<<",";
    }
    cout<<v[v.size()-1]<<endl;
    return 0;
}
