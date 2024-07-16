#include <iostream>
using namespace std;
int main()
{
    long n, num = 0;
    cin >> n;
    // ۼӸָλϵĺ
    while (n != 0)
    {
        num += n % 10;
        n /= 10;
        // λۼҵõһλ
        if (num >= 10 && n == 0)
        {
            n = num;
            num = 0;
        }
    }
    cout << num << endl;
    return 0;
}
