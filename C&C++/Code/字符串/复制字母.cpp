#include<stdio.h>
int main()
{
    char s1[100];char s2[50];
    gets(s2);
    for(int i=0;s2[i]!='\0';i++)
    {
        s1[i]=s2[i];
    }
    s1[100]='\0';
    printf("s1:");
    puts(s1);
    return 0;
}
