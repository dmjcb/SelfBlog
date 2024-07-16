#include<iostream>
#include<cstring>
#include<ctime>
#define MAX 1001
//true表式该式是素数
bool isPrime[MAX];
int prime[MAX];

using namespace std;
int main() {    
    for(int i = 1; i<MAX; i++) {
        prime[i] = i;
    }
    //先开始假设所有数都是素数
    memset(isPrime,true,sizeof(isPrime));
    isPrime[2]=false;
    int index = 0;
    for(int i=2; i<MAX; i++) {
        //如果这个数是素数的话
        if(isPrime[i]==true) {
            prime[index]=i;
            index++;
            for(int j=2*i; j<MAX; j+=i) {
                isPrime[j]=false;
            }
        }
    }
    
    for(int i = 0; i<index; i++) {
        cout<<prime[i]<<endl;
    }
    return 0;
}
