#include<stdio.h>
#include<string.h>
int main() {
    char a[7]="abcdef";
    char b[4]="ABC";
    strcpy(a,b);
    printf("%s\n",a);
    return 0;
}
