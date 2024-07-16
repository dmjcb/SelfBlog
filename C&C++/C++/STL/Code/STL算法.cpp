#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(2);
    v.push_back(7);
    const int n = sizeof(v) / sizeof(int);
    // 输出最小值的位置
    vector<int>::iterator iter = min_element(v.begin(), v.end());
    cout << iter - v.begin() << endl;
    return 0;
}
