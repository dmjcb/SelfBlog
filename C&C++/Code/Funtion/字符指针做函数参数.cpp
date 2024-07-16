#include <stdio.h>
void copyString1(char from[], char to[])
{
    int i = 0;
    while (from[i] != '\0')
    {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}

void copyString2(char *from, char *to)
{
    while ((*to++ = *from++) != '\0')
        ;
    *to = '\0';
}

int main()
{
    char *p1 = "adfasd";
    char b[] = "213124";
    char *p2 = b;
    copyString2(p1, p2);
    printf("*p1:%s\n*p2:%s\n", p1, p2);

    return 0;
}
