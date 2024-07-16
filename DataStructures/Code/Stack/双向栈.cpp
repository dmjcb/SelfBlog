#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct
{
    int top[2];
    int bot[2];
    int *value;
    int m;
} DouStack;

void initialize(DouStack &s)
{
    s.m = MAXSIZE;
    s.value = (int *)malloc(MAXSIZE * sizeof(DouStack));
    s.bot[0] = s.top[0] = -1;
    s.bot[1] = s.top[1] = s.m;
}

bool isStackEmpty(DouStack &s, int num)
{
    if (num == 0 && s.top[num] == -1)
    {
        return true;
    }
    else if (num == 1 && s.top[num] == s.m)
    {
        return true;
    }
    return false;
}

bool isStackFull(DouStack &s)
{
    if (s.top[1] - s.top[0] == 1 && (s.top[0] != -1 || s.top[1] != s.m))
    {
        return true;
    }
    return false;
}

void push(DouStack &s, int num, int &e)
{
    if (isStackEmpty(s, num))
    {
        return;
    }
    int index = s.top[num];
    if (num == 0)
    {
        index++;
    }
    else
    {
        index--;
    }
    s.value[index] = e;
}

int pop(DouStack &s, int num)
{
    if (isStackEmpty(s, num))
    {
        return -1;
    }
    int index = s.top[num];
    int e;
    e = s.value[index];
    s.value[index] = -1;
    if (num == 0)
    {
        s.top[index]--;
    }
    else
    {
        s.top[index]++;
    }
    return e;
}
int main()
{
}
