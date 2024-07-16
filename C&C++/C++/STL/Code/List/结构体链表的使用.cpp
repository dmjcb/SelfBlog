#include <iostream>
#include <list>
using namespace std;
typedef struct
{
    int num;
    char symbol;
} Linklist;
int main()
{
    list<Linklist> link;
    int n;
    Linklist lin;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> lin.num >> lin.symbol;
        link.push_back(lin);
    }
    for (list<Linklist>::iterator it = link.begin(); it != link.end(); it++)
    {
        cout << it->num << " " << it->symbol << endl;
    }
    return 0;
}
