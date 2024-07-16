#include<iostream>
#include<> 
#include<vector>
using namespace std;

void swap(char &a,char &b) {
    a^=b;
    b^=a;
    a^=b;
}
//allElemtype(v,0,v.size());
void allElemtype(vector<char> &v,int begin,int end) {
    if(begin>=end) {
        for(int i=0; i<end; i++) {
            cout<<v[i];
        }
        cout<<endl;
    } else {
        for(int i=begin; i<end; i++) {
            if(i!=begin) {
                swap(v[begin],v[i]);
            }
            allElemtype(v,begin+1,end);
            if(i!=begin) {
                swap(v[begin],v[i]);
            }
        }
    }
}

int main() {
    string str;
    cin>>str;
    vector<char> v;
    int length=str.size();
    for(int i=0; i<length; i++) {
        v.push_back(str[i]);
    }
    allElemtype(v,0,v.size());
    return 0;
}











