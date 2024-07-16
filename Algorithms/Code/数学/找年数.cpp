#include <stdio.h>
struct date
{
    int year;
    int month;
    int day;
};
int main()
{
    struct date num;
    printf(":\n");
    scanf("%d%d%d", &num.year, &num.month, &num.day);
    int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((num.day <= 31) && (num.month <= 12))
    {
        for (int i = 0; i < num.month - 1; i++)
        {
            num.day += a[i];
        }
        if ((num.year % 4 == 0 && num.year % 100 != 0) || (num.year % 400 == 0) && (num.month > 2))
        {
            printf("%dĵ%d\n", num.year, num.day + 1);
        }
        else
        {
            printf("%dĵ%d\n", num.year, num.day);
        }
    }
    else
    {
        printf("·ݻ!\n");
    }
    return 0;
}
