#include <iostream>
#include <stdlib.h>
using namespace std;
double fun(double x, double y)
{
    if (y == 0)
    {
        throw y;
    }
    return x / y;
}

int main()
{
    double res;
    try
    {
        res = fun(2, 3);
        cout << "The result of x/y is:" << res << endl;
        res = fun(4, 0);
    }
    catch (double)
    {
        cerr << "Error of dividing zero." << endl;
        exit(1);
    }
}
