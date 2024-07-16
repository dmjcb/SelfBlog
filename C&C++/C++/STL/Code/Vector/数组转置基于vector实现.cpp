#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v;
    for (int i = 0, temp; i < 10; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    //
    reverse(v.begin(), v.end());
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
