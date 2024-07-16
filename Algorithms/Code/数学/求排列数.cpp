#include<iostream>
#include<algorithm>
using namespace std;
int a[5] = {1,2,3,4,5};
int main(){
    sort(a,a+5);
    int sum = 0;
    do{
        /*for(int i = 0;i<2;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;*/
        sum++;
    }while(next_permutation(a,a+5));
    cout<<sum<<endl;
}
