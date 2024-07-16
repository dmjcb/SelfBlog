#include <iostream>
using namespace std;
int main()
{
    int sum(int a, int b);
    long sum(long a, long b);
    double sum(double a, double b);
    float sum(float a, float b);
    int i1, i2, i;
    cin >> i1 >> i2;
    i = sum(i1, i2);
    cout << "int_sum= " << i << endl;
    long j1, j2, j;
    cin >> j1 >> j2;
    j = sum(j1, j2);
    cout << "long_sum= " << j << endl;
    double k1, k2, k;
    cin >> k1 >> k2;
    k = sum(k1, k2);
    cout << "double_sum= " << k << endl;
    float l1, l2, l;
    cin >> l1 >> l2;
    l = sum(l1, l2);
    cout << "float_sum= " << l << endl;
}
int sum(int a, int b)
{
    return (a + b);
}
long sum(long a, long b)
{
    return (a + b);
}
double sum(double a, double b)
{
    return (a + b);
}
float sum(float a, float b)
{
    return (a + b);
}
