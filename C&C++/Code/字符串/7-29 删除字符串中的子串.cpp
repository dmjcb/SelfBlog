#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1, s2;
    getline(cin, s1);
    cin >> s2;
    int indexS1;
    int lengthS2;
    while (s1.find(s2, 0) != string::npos)
    {
        // ҵִλ
        indexS1 = s1.find(s2, 0);
        lengthS2 = s2.size();
        s1.erase(indexS1, lengthS2);
    }

    cout << s1;
    return 0;
}
