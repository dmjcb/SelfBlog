// ʮ0-1000еĲͬ
#include <stdio.h>
#define M 1000
#define N 3
int main(void)
{
    int a[N], i;
    int b[M] = {0}; // Ϊʲôֻ0
    for (i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
        b[a[i]]++; // b[i]±꼴
    }
    for (i = 0; i < M; i++)
    {
        if (b[i] != 0)
        {
            printf("%d ", i);
        }
    }
}
