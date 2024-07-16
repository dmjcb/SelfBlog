#include<iostream>
#include<cstdio> 
#include<queue>
using namespace std;

typedef long long ll;

ll n,k;
bool b[100001];

typedef struct A {
    int x;
    int m;
    A(int xx,int mm) {
        x = xx;
        m = mm;
    }
} A;

queue<A> q;
ll bfs(ll x) {
    q.push(A(x,0));
    b[x] = true;
    while(!q.empty()) {
        A a = q.front();
        q.pop();
        if(a.x==k) {
            return a.m;
        }
        ll y;
        for(int i = 0 ;i<3;i++){
            if(i==0){
                y = a.x+1;
            }
            else if(i==1){
                y = a.x-1;
            }
            else if(i==2){
                y = a.x*2;
            }
            if(y>=0&&y<=100000&&!b[y]){
                q.push(A(y,a.m+1));
                b[y]=true;
            }
        }
    }
}

int main() {

    scanf("%lld%lld",&n,&k);
    printf("%lld\n",bfs(n));
    return 0;
}
