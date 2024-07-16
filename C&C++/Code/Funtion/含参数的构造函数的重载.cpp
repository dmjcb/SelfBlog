/*
 * @Description:
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:
 * @Date: 2024-07-06 20:33:32
 * @LastEditors: dmjcb
 * @LastEditTime: 2024-07-06 20:50:25
 */
#include <iostream>
using namespace std;
class Box
{
public:
    Box();
    Box(int h = 10, int w = 12, int len = 15) : height(h), width(w), length(len) {}
    int volume();

private:
    int height;
    int width;
    int length;
};

int Box::volume()
{
    return (height * width * length);
}

int main()
{
    Box a[3] = {
        Box(10, 12, 15),
        Box(15, 18, 20),
        Box(16, 20, 26)};
    cout << a[0].volume() << endl;
    cout << a[1].volume() << endl;
    cout << a[2].volume() << endl;
}
