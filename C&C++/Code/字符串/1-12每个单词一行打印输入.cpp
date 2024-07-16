#include<stdio.h>
int main() {
    char c;
    int n=0;
    while((c=getchar()) != EOF) {
        if(c != ' ') {
            putchar(c);
        } else {
            printf("\n");
        }
    }
    return 0;
}
