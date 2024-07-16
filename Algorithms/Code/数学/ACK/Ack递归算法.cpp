#include<iostream>
using namespace std;

int Ack[100][100];
int Ack1(int m,int n) {
    /*    if(m==0){
            return n+1;
        }
        else if(n==0){
            return Ack(m-1,1);
        }
        else{
            return Ack(m-1,Ack(m,n-1));
        }*/

    //int Ack[m][n];
    int i,j;
    for(j=0; j<n; j++) {
        Ack[0][j]=j+1;
    }
    for(i=1;i<m;i++){
        Ack[i][0]=Ack[i-1][1];
        for(j=1;j<n;j++){
            Ack[i][j]=Ack[i-1][Ack[i][j-1]];
        }
    }
    return Ack[m][n]; 
}

int main() {
    int m,n;
    cin>>m>>n;
    cout<<Ack1(m,n);
    return 0;
}
