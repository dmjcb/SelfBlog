#include <iostream>
#include <string>
using namespace std;
int main()
{
    int sum = 0;
    string s1, s2;
    cout << "s1:" << endl;
    cin >> s1;
    cout << "s2:" << endl;
    cin >> s2;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1.find(s2, i) != string::npos)
        {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}
