/*
    Name:求几个数的最大值
    Copyright:
    Author:
    Date: 08/04/18 22:40
    Description:
*/
#include <iostream>
using namespace std;
int main()
{
    int max(int a, int b, int c, int d);
    int max(int a, int b, int c);
    int max(int a, int b);
    int a = 23, b = 12, c = -74, d = 69;
    cout << "max(a,b,c,d)= " << max(a, b, c, d) << endl;
    cout << "max(a,b,c)= " << max(a, b, c) << endl;
    cout << "max(a,b)= " << max(a, b) << endl;
}

int max(int a, int b, int c, int d)
{
    if (b > a)
        a = b;
    if (c > a)
        a = c;
    if (d > a)
        a = d;
    return a;
}

int max(int a, int b, int c)
{
    if (b > a)
        a = b;
    if (c > a)
        a = c;
    return a;
}

int max(int a, int b)
{
    return a > b ? a : b;
}
