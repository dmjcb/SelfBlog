/*
 * @Description:
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:
 * @Date: 2024-07-19 16:00:27
 * @LastEditors: dmjcb
 * @LastEditTime: 2024-07-23 19:33:12
 */
#include <iostream>
using namespace std;
class Matrix
{
public:
    Matrix() {};
    friend Matrix operator+(Matrix &a, Matrix &b);
    void display_Value();

private:
    float matr[2][3];
};

Matrix operator+(Matrix &a, Matrix &b)
{
    return Matrix(a + b);
}
void Matrix::display_Value()
{
    Matrix c;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << c.matr[i][j];
        }
        cout << endl;
    }
}
int main()
{
    Matrix a, b, c;
    c = a + b;
    c.display_Value();
}
