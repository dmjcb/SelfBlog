#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<string> v;
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        string s1;
        cin>>s1;
        int flag=1;
        for(int i=0,j=s1.size()-1; i<s1.size(); i++,j--) {
            if(s1[i]!=s1[j]) {
                flag=0;
                break;
            }
        }
        if(flag==0) {
            v.push_back("No");
        } 
        else {
            v.push_back("Yes");
        }
    }
    for(int i=0; i<v.size(); i++) {
        cout<<v[i]<<endl;
    }
    return 0;
}


