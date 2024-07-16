/*һѾź,һ,ҪԭĹɽ*/
#include <iostream>
using namespace std;
int main()
{
    int a[10] = {12, 23, 45, 66, 78, 89, 97, 99, 100, 154};
    int i, j, n, number, temp1, temp2;
    for (i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cin >> n;
    if (n > a[9])
    {              /*ֱ*/
        a[10] = n; /*ֱӱΪһ*/
    }
    else
    { /*ǣ*/
        for (i = 0; i < 10; i++)
        { /*ÿһԪ*/
            if (number < a[i])
            { /*numberһԪСôͲԪصλ֮ǰ*/
                temp1 = a[i];
                a[i] = number; /*numberȡԭa[i]Ϊa[i]*/
                for (j = i + 1; j < 11; j++)
                { /*ӲλÿʼԪƶһλ*/
                    temp2 = a[j];
                    a[j] = temp1; /*ԭǰһԪأΪһԪ*/
                    temp1 = temp2;
                }
            }
            break; /*ƶֱ֮ѭ*/
        }
    }
    for (i = 0; i < 11; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
