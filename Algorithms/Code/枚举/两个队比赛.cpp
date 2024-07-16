#include <stdio.h>
int main()
{
    /*i---A j---B k---C*/
    char i, j, k;
    for (i = 'X'; i <= 'Z'; i++)
    {
        if (i != 'X')
        {
            for (j = 'X'; j <= 'Z'; j++)
            {
                for (k = 'X'; k <= 'Z'; k++)
                {
                    if (k != 'X' && k != 'Z' && i != j && i != k && j != k)
                    {
                        printf("A--%c\nB--%c\nC--%c\n", i, j, k);
                        return 0;
                    }
                }
            }
        }
    }
}
