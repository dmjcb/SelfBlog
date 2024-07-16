#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    int a[4] = {1, 2, 3, 4};
    string str;
    for (int i = 0; i < 4; i++)
    {
        str.push_back(a[i] + '0');
    }
    cout << str << endl;
    return 0;
}
