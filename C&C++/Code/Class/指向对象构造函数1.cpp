#include <iostream>
using namespace std;
class Time
{
public:
    Time(int, int, int);
    int hour;
    int minute;
    int sec;
    void get_time();
};
Time::Time(int h, int m, int s)
{
    hour = h;
    minute = m;
    sec = s;
}

void Time::get_time()
{
    cout << hour << ":" << minute << ":" << sec << endl;
}

int main()
{
    Time t1(10, 13, 56);
    int *p1 = &t1.hour; // ָݵָP1ʹָt1.hour
    cout << *p1 << endl;
    t1.get_time();        // öt1һԱget_time()
    Time *p2 = &t1;       // ָTimeһt1ָʹp2ָt1
    p2->get_time();       // p2ָt1ĳԱget_time
    void (Time::*p3)();   // ָTimeԱһָp3
    p3 = &Time::get_time; // p3->get_time,p3ָget_time
    (t1.*p3)();           // t1.get_time
}
