#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}

int main()
{
    int a = 3, b = 4;
    swap(a, b);

    cout << "a=" << a << " " << "b=" << b << endl;
    return 0;
}
