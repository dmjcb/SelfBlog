#include <iostream>
#include <cstring>
#include <ctime>
#define MAX 1001
using namespace std;
int main()
{

    int a[MAX];
    int tot = 0;
    bool b[MAX];
    // ȿʼ
    memset(b, true, sizeof(b));
    for (int i = 2; i < MAX; i++)
    {
        // Ļ
        if (b[i] == true)
        {
            // 浽a[]
            a[tot++] = i;
        }
        // Ϊa[j],i֮һ
        for (int j = 0; j < tot && i * a[j] < MAX; j++)
        {
            // Ϊfalse
            b[i * a[j]] = false;
            // ia[j]ʱѭ.Ϊi=a[j]*ĳ,i*a[j+1]=a[j]*ĳ*a[j+1].
            // a[j]ضСa[j+1], i*a[j+1]رa[j]*ĳɸٴѭ
            if (i % a[j] == 0)
            {
                break;
            }
        }
    }
    return 0;
}
