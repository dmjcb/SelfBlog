#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void AddNums(char num1[], char num2[], int sum[])
{
    int i, j, length;
    int n2[100] = {0};
    length = max(strlen(num1), strlen(num2));
    // 低位在前,高位在后
    for (i = strlen(num1) - 1, j = 0; i >= 0; i--, j++)
    {
        sum[j] = num1[i] - '0';
    }
    for (i = strlen(num2) - 1, j = 0; i >= 0; i--, j++)
    {
        n2[j] = num2[i] - '0';
    }
    // 相加
    for (i = 0; i <= length; i++)
    {
        sum[i] += n2[i];
        if (sum[i] > 9)
        {
            sum[i] -= 10;
            sum[i + 1]++;
        }
    }
    if (sum[length != 0])
    {
        length++;
    }
    for (i = length - 1; i >= 0; i--)
    {
        cout << sum[i];
    }
}
int main()
{
    char num1[] = "1234567891234567891234"; // 第一个大数
    char num2[] = "2345678912345678913345"; // 第二个大数
    int sum[1000];
    AddNums(num1, num2, sum);
    return 0;
}
