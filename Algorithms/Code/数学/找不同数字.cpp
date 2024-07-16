/*N֣ͬҵвֵͬĸ*/
#include <iostream>
#define N 10
using namespace std;
int main()
{
    int a[N], i, j, n = 0;
    for (i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < N; i++)
    { // ζȡNֵֵ
        for (j = 0; j < i; j++)
        { // ڶͷʼi,֮ǰÿ,j<iԼҲͬ
            if (a[i] == a[j] && i != j)
            {          // ֵͬλòͬ϶Ϊһֳ
                n++;   // ͬ1
                break; // Ҵֲѭһλãظ
            }
        }
    } // ˣҳNnȫ֣ͬ11 22
    cout << "ָͬΪ" << N - n;
    return 0;
}
