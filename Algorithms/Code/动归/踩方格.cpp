/*
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-03-29 21:57:16
 * @LastEditors: dalao
 * @LastEditTime: 2022-03-29 22:03:51
 */
//一个无限大的方格矩阵，能向北、东、西三个方向走。
//问走N步共有多少种不同的方案。
#include<iostream>
using namespace std;
/*Ii = Ni+Ei+Wi;Ni=Ni-1+Ei-1+Wi-1;
  Ei = Ni-1+Ei-1;Wi = Ni-1+Wi-1;

*/

int main(){
    int a[21];
    int n;
    a[1] = 3;
    a[2] = 7;   //3+2+1+1
    cin>>n;
    for(int i=3;i<=n;i++){
        a[i]=2*a[i-1]+a[i-2];
    } 
    cout<<a[n];
}

