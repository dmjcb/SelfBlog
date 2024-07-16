#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    vector<int> v;
    int temp;
    for(int i = 0 ;  i< 5 ; i++) {
        scanf("%d",&temp);
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for(int i = 0 ;  i< 5 ; i++) {
        printf("%d ",v[i]);
    }
    return 0;
}
