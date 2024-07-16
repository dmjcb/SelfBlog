#include<stdio.h>
int main(){
    double a,b;
    scanf("%lf%lf",&a,&b);
    double r;
    int k;
    k=a/b;
    r=a-k*b;
    printf("%g",r);
    return 0;
} 
