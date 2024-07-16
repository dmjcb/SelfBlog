#include <stdio.h>
int main()
{
    int c, i;
    int sumWrite = 0, sumOther = 0;
    int sumNumber[10] = {0};
    while ((c = getchar()) != EOF)
    {
        if (c >= '0' || c <= '9')
        {
            // ַתΪ
            ++sumNumber[c - '0'];
        }
        else if (c == ' ' || c == '\n' || c == '\t')
        {
            ++sumWrite;
        }
        else
        {
            ++sumOther;
        }
    }
    printf("Dights:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d : %d\n", i, sumNumber[i]);
    }
    printf("%d %d\n", sumWrite, sumOther);
    return 0;
}
