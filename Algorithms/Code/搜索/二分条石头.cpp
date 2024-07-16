#include<iostream>
#define MAX_SIZE 100000
typedef long long ll;
using namespace std;

int a[MAX_SIZE];
int main(){
    int len;
    int n;
    int m;
    scanf("%d%d%d",&len,&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    a[n+1] = len;
    int left = 0;
    int right = len;
    int ans;
    while(left<=right){
        int mid = (left+right)/2;
        int last = 0;
        int sum = 0;
        for(int i = 1;i<=n+1;i++){
            if(a[i]-last<mid){
                sum++;
            }
            else{
                last = a[i];
            }
        }
        if(sum>m){
            right = mid-1;
        }
        else{
            ans = mid;
            left = mid+1;
        }
    }
    cout<<ans<<endl;
}
