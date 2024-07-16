/*1234,ɶٸͬظֵλ*/
/*ѭǶףпڽɸѡ*/
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int i, j, k, n;
    for (i = 1; i < 5; i++)
    {
        for (j = 1; j < 5; j++)
        {
            for (k = 1; k < 5; k++)
            {
                if (i != j && i != k && j != k)
                {
                    cout << i << j << k << endl;
                    n++;
                }
            }
        }
    }
    printf("һ%d\n", n);
    return 0;
}
