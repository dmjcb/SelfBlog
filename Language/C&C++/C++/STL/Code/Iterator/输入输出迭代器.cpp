#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    int temp;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &temp);
        v.push_back(temp);
    }
    // 只读迭代器
    for (vector<int>::const_iterator iter = v.begin(); iter != v.end(); iter++)
    {
        printf("%d ", *iter);
    }
    cout << endl;

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}