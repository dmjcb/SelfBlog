/*
 * @Description: 
 * @Version: 1.0
 * @Author: dmjcb
 * @Email: 
 * @Date: 2024-07-19 16:00:27
 * @LastEditors: dmjcb
 * @LastEditTime: 2024-07-30 13:55:13
 */
#include <iostream>
using namespace std;


bool isLeapYear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        return true;
    }
    return false;
}

int dayOfYear(int y, int m, int d)
{
    int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, sum = 0;
    if (isLeapYear(y) && m > 2)
    {
        sum += 1;
    }
    for (int i = 1; i < m; i++)
    {
        sum += a[i];
    }
    sum += d;
    return sum;
}

int GetDateDiffer(int ey, int em, int ed, int sy, int sm, int sd)
{
    int syDay, eyDay;
    if (ey == sy)
    {
        return dayOfYear(ey, em, ed) - dayOfYear(sy, sm, sd);
    }
    else
    {
        int date = 365, i, sumDay = 0;
        for (i = sy + 1; i < ey; i++)
        {
            if (isLeapYear(i))
            {
                date = 366;
                ;
            }
            sumDay += date;
            date = 365;
        }
        if (isLeapYear(sy))
        {
            date = 366;
        }
        syDay = date - dayOfYear(sy, sm, sd);
        return sumDay + syDay + dayOfYear(ey, em, ed);
    }
}
int main()
{
    int syear, smonth, sday, eyear, emonth, eday;
    cin >> syear >> smonth >> sday >> eyear >> emonth >> eday;
    cout << GetDateDiffer(eyear, emonth, eday, syear, smonth, sday) << endl;
    return 0;
}
