#include <stdio.h>
#include <math.h>
int main()
{
    int n, i, j, order = 0, primeNumber;
    scanf("%d", &n);
    // orderֵڼ
    for (i = 2; order != n; i++)
    {
        for (j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        // iһʱ,iֵprimeУorderһ
        if (j > sqrt(i))
        {
            primeNumber = i;
            order++;
        }
    }
    printf("%d\n", primeNumber);
    return 0;
}
