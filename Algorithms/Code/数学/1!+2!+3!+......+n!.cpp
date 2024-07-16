#include<iostream>
using namespace std;
int main() {
    for(long sum = 0,t = 1,int i = 1; i<=10; i++,t*=i,sum+=t)
        ;
    cout<<sum<<endl;
}
