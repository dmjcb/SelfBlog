#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int priceStart;
    double discountRate;
    cin>>priceStart>>discountRate;
    printf("%.0lf\n",floor(priceStart*discountRate*0.1));
    return 0;
}
