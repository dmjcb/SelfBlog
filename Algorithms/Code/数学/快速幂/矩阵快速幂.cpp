#include<iostream>
#include<string.h>
#define N 10
using namespace std;

typedef struct Matrix {
    int m[N][N];
    int x;  //矩阵的行数
    int y;  //矩阵的列数
    Matrix operator * (Matrix &b) {  //重载*运算符
        Matrix ans;
        memset(ans.m,0,sizeof(ans.m));
        ans.x = x;
        ans.y = b.y;
        for(int i=0; i<=ans.x; i++) {
            for(int j = 0; j<=ans.y; j++) {
                for(int k =0; k<=y; k++) {
                    ans.m[i][j]+=(m[i][k]*b.m[k][j]);
                }
            }
        }
        return ans;
    }
} Matrix;

Matrix fastPower(Matrix &a,int b) { //快速幂
    Matrix ans;
    memset(ans.m,0,sizeof(ans.m));
    for(int i = 0; i<a.x; i++) {
        ans.m[i][i] = 1;
    }
    ans.x = a.x;
    ans.y = a.y;
    while(b) {
        if(b&1) {
            ans=ans*a;
        }
        a=a*a;
        b>>=1;
    }
    return ans;
}

void display(Matrix &a) {
    for(int i = 0; i<a.x; i++) {
        for(int j = 0; j<a.y; j++) {
            cout<<a.m[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    Matrix m1 = {{{0,1},{1,1}},2,2};
    Matrix m2 = {{{0},{1}},2,1};
    int n;
    cin>>n;
    m1 = fastPower(m1,n);
    m1 = m1*m2;
    cout<<m1.m[0][0];
}

ll gdc(ll x,ll y){
    return y ==0 ?x:gdc(y,x%y)
}


