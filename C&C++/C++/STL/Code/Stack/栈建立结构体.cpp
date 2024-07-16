#include <iostream>
#include <stack>
typedef int ElemType;

typedef struct
{
    ElemType data;
    char alphat;
} Slem;

using namespace std;
int main()
{
    stack<Slem> S;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Slem e;
        cin >> e.data >> e.alphat;
        // ջ
        S.push(e);
    }
    while (!S.empty())
    {

        cout << S.top().data << " " << S.top().alphat << endl;

        S.pop();
    }
    cout << endl;
    return 0;
}
