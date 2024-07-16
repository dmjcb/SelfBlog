#include <iostream>
using namespace std;

// ð
void bubbleSort3(int testData[], int len)
{
    // һ

    for (int j = 0; j < len - 1; j++)
    {
        // жǷ
        bool exchange = false;
        for (int i = 0; i < len - 1; i++)
        {
            if (testData[i] > testData[i + 1])
            {

                // exchangeΪ true
                exchange = true;
                // Ԫ
                swap(testData[i], testData[i + 1]);
            }
        }
        // ˴ɨûз˵Ѿ
        if (exchange == false)
        {
            break;
        }
        cout << "" << j << " ";
        for (int i = 0; i < 10; i++)
        {
            cout << testData[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int i;
    int a[10];
    for (i = 0; i < 10; i++)
    {
        cin >> a[i];
    }

    bubbleSort3(a, 10);
    for (i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
