#include <bits\stdc++.h>
using namespace std;
int main()
{
    string str("heoolo sdaa ss");
    /*صӴλáڶǲҵʼλã
    Ҳͷstring::npos*/

    if (str.find("as", 0) == string::npos)
    {
        cout << "ҲӴ" << endl;
    }
    else
    {
        cout << str.find("as", 0) << endl;
    }
}
