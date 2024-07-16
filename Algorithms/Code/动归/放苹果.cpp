#include<iostream>
#include<cstring>
using namespace std;
int dp[11][11];
int main(){
    int m,n;
    cin>>m>>n;
    memset(dp,0,sizeof(dp));
    for(int j = 0;i<n;j++){
        dp[0][j] = 1;
    }
    for(int i = 0;i<m;i++){
        dp[i][1] = 0;
    }
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n ;j++){
            if(n>m){
                dp[i+1][j]=dp[j][j];
            }
            else{
                dp[i+1][j]=dp[i-1][j]+dp[i-j][j];
            }
        }
    }
}
