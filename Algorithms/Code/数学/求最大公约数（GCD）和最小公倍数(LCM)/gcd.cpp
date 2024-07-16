int gcd(int a, int b) {
    return a == 0 ? b : gcd(b % a, a);
}
/*最小公倍数=两整数的乘积 ÷最大公约数*/
