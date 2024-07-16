/*
    Name:
    Copyright:
    Author:
    Date: 10/04/18 12:56
    Description:
*/

#include <iostream>
using namespace std;
void shell(int &x, int &y)
{
    int temp;
    if (x > y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    cout << x << " " << y << endl;
}
void shell(int x, int y, int z)
{
    int a[3] = {x, y, z}, t;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3 - i; j++)
        {
            if (a[i] > a[i + 1])
            {
                t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void shell(int x, int y, int z, int w)
{
    int a[4] = {x, y, z, w}, t;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (a[i] > a[i + 1])
            {
                t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int a = 99, b = 56, c = -88, d = 45;
    shell(a, b);
    shell(a, b, c);
    shell(a, b, c, d);
    return 0;
}
