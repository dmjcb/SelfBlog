/*ж϶ַںԴСдͿոǷ*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<char> v1, v2;
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] != ' ')
        {
            if (str1[i] >= 'A' && str1[i] <= 'Z')
            {
                str1[i] += 32;
            }
            v1.push_back(str1[i]);
        }
    }
    for (int i = 0; i < str2.size(); i++)
    {
        if (str2[i] != ' ')
        {
            if (str2[i] >= 'A' && str2[i] <= 'Z')
            {
                str2[i] += 32;
            }
            v2.push_back(str2[i]);
        }
    }
    bool flag = false;
    if (v1.size() == v2.size())
    {
        flag = true;
        int length = str1.size();
        for (int i = 0; i < length; i++)
        {
            if (v1[i] != v2[i])
            {
                flag = false;
                break;
            }
        }
    }
    if (flag == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
