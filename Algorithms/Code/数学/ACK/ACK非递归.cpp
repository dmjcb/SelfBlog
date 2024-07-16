#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int m, n;
    stack<int> mystack;
    while (cin >> m >> n)
    {
        if (m == 0)
        {
            cout << "£" << endl;
            cout << n + 1 << endl;
        }
        else
            while (true)
            {
                if (m != 0 && n != 0)
                {
                    mystack.push(m - 1);
                    n--;
                }
                else if (m == 0)
                {
                    m = mystack.top();
                    n++;
                    mystack.pop();
                }
                else if (n == 0)
                {
                    m -= 1;
                    n = 1;
                }
                if (mystack.empty() && m == 0)
                {
                    n++;
                    break;
                }
            }
        cout << "£" << endl;
        cout << n << endl;
    }
    return 0;
}
