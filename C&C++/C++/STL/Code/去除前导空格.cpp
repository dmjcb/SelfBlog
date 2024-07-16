/*
 * @Description:
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-03-29 21:57:16
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-08 21:23:28
 */
#include <iostream>
using namespace std;
int main()
{
    string strOld;
    string strNew;
    getline(cin, strOld);
    cout << strOld << endl;
    // 如果没有前导空格，直接复制
    if (strOld[0] != ' ')
    {
        strNew = strOld;
    }
    // 如果第二个字符不是空格，将这个字符复制过去
    else if (strOld[1] != ' ')
    {
        strNew[0] = strOld[1];
    }
    // 从
    for (int i = 2, j = 0, length = strOld.size(); i < length; i++)
    {
        if (strOld[i] != ' ')
        {
            strNew[j++] = strOld[i];
        }
        else
        {
            if (strOld[i - 1] != ' ' || strOld[i + 1] != ' ')
            {
                strNew[j++] = strOld[i];
            }
        }
    }
}
cout << strNew << endl;
return 0;
}
