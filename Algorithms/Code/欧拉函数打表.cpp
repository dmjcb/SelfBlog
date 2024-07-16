#include <iostream>
#include <string.h>
#define size 1000001
int euler[size];
void init()
{
    memset(euler, 0, sizeof(euler));
    euler[1] = 1;
    for (int i = 2; i < size; i++)
    {
        if (!euler[i])
        {
            for (int j = i; j < size; j += i)
            {
                if (!euler[j])
                {
                    euler[j] = j;
                }
                euler[j] = euler[j] / i * (i - 1);
            }
        }
    }
}

int main()
{
    init();
    for (int i = 1; i < 100; i++)
    {
        printf("%d %d\n", i, euler[i]);
    }
    return 0;
}
