/*
    Name: ڸص
    Copyright:
    Author: Ԫ
    Date: 11/05/18 14:55
    Description:
*/

#include <iostream>
using namespace std;
class Complex
{
public:
    Complex()
    {
        real = 0;
        imag = 0;
    }
    Complex(float r, float i)
    {
        real = r;
        imag = i;
    }
    /*ΪԪ*/
    friend istream &operator>>(istream &, Complex &);
    friend ostream &operator<<(ostream &, Complex &);
    /*ΪԪ*/
    friend Complex operator+(Complex &c1, Complex &c2);
    friend Complex operator-(Complex &c1, Complex &c2);
    friend Complex operator*(Complex &c1, Complex &c2);
    friend Complex operator/(Complex &c1, Complex &c2);

private:
    float real;
    float imag;
};
/* >>*/
istream &operator>>(istream &input, Complex &c)
{
    cout << "ʵ鲿";
    input >> c.real >> c.imag;
    return input;
}
/* <<*/
ostream &operator<<(ostream &ouput, Complex &c)
{
    ouput << "(" << c.real << "+" << c.imag << "i)";
    return ouput;
}
/* +*/
Complex operator+(Complex &c1, Complex &c2)
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
/*-*/
Complex operator-(Complex &c1, Complex &c2)
{

    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}
/* **/
Complex operator*(Complex &c1, Complex &c2)
{
    return Complex(c1.real * c2.real - c1.imag * c2.imag, c1.imag * c2.real + c1.real * c2.imag);
}
/* /*/
Complex operator/(Complex &c1, Complex &c2)
{
    return Complex((c1.real * c2.real + c1.imag * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag), (c1.imag * c2.real - c1.real * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag));
}

int main()
{
    Complex c1, c2, c[4];
    while (1)
    {
        cin >> c1 >> c2;
        c[0] = c1 + c2;
        c[1] = c1 - c2;
        c[2] = c1 * c2;
        c[3] = c1 / c2;
        cout << "ΪΪ" << c[0] << endl;
        cout << "ΪΪ" << c[1] << endl;
        cout << "ΪΪ" << c[2] << endl;
        cout << "ΪΪ" << c[3] << endl;
        cout << "                             " << endl;
    }
}
