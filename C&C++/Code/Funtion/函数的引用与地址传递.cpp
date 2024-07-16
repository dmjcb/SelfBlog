#include <iostream>
#define SIZE 10
using namespace std;
void maxAndMin(int a[], int &maximum, int &minimum)
{
    maximum = a[0];
    minimum = a[0];
    for (int i = 1; i < SIZE; i++)
    {
        if (maximum < a[i])
        {
            maximum = a[i];
        }
        if (minimum > a[i])
        {
            minimum = a[i];
        }
    }
}

int main()
{
    int numbers[SIZE], maxValue, minValue;
    cout << "Please input " << SIZE << " numbers:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cin >> numbers[i];
    }
    maxAndMin(numbers, maxValue, minValue);
    cout << "The maximum is: " << maxValue << endl;
    cout << "The minimum is: " << minValue << endl;
    return 0;
}
