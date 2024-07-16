#include<iostream>
using namespace std;
class rect
{
    public:
        rect();
        rect(int l,int w):len(l),wid(w){}
        int area();
    private:
        int len;
        int wid,j;
};
rect::rect()
{
    len=10;
    wid=5;
}

int rect::area()
{
    return len*wid;
}

int main()
{
    rect r1;
    cout<<r1.area()<<endl;
    rect r2(1,2);
    cout<<r2.area()<<endl;
}
