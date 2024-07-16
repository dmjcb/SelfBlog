#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<char> s;
    char str;
    int sum = 0;
    cin >> str;
    s.push(str);
    while (cin >> str)
    {
        if (str == s.top())
        {
            s.push(str);
        }
        else
        {
            s.pop();
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}
