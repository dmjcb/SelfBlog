#include <iostream>
#include <fstream>
#include <ostream>
#include <list>
using namespace std;
int main()
{
    // ofstream outfile("a.txt");
    list<int> linklist;
    int item, n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        linklist.push_back(item);
        // outfile << item<<endl;
    }
    // ǵ
    while (!linklist.empty())
    {
        // Ԫ
        cout << linklist.front() << endl;
        // ɾԪ
        linklist.pop_front();
    }
    return 0;
}
