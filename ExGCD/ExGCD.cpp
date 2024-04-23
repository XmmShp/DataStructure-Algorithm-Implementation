int ExGCD(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int d = ExGCD(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return d;
}

/*
Test Region
*/
#include <cstdio>
int main()
{
    int a = 114514, b = 1919810, x = 0, y = 0;
    int gcd = ExGCD(a, b, x, y);
    printf("%d*%d+%d*%d=%d\n", a, x, b, y, gcd);
    return 0;
}