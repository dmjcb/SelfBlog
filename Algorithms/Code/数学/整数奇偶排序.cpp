/*10УҪ:
1.ǰżں2.ӴС
3.żС
*/
#include <iostream>
using namespace std;
int main()
{
    int n, i, b[101] = {0};
    for (i = 0; i < 10; i++)
    {
        cin >> n;
        // b[n]ֵΪֳֵĴ
        b[n]++;
    }
    for (i = 99; i >= 1; i -= 2)
    {
        if (b[i])
        {
            // ظʱ
            while (b[i]--)
            {
                cout << i << " ";
            }
        }
    }
    for (i = 0; i <= 100; i += 2)
    {
        if (b[i])
        {
            while (b[i]--)
            {
                cout << i << " ";
            }
        }
    }
    cout << endl;
    return 0;
}
