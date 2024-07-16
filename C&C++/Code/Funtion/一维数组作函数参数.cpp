#include <stdio.h>
int averageArray(int array[10])
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += array[i];
    }
    return sum / 10;
}
int averP(int *p, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(p + i);
    }
    return sum / n;
}
int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int aver1 = averageArray(a);
    int n, *p = a;
    scanf("%d", &n);
    int aver2 = averP(p, n);
    printf("averA=%d\n", aver1);
    printf("averP=%d\n", aver2);
    return 0;
}
