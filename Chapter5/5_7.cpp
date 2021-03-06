#include <iostream>

double Power(double x, int y)
{
    double result = 1.0;
    long long power = y;
    if (y < 0)
    {
        power = -power;
        x = 1 / x;
    }
    while (power)
    {
        if (power & 1)
        {
            result *= x;
        }
        x *= x;
        power >>= 1;
    }
    return result;
}

main()
{
    double ans = Power(1.0, -2147483648);
    std::cout << ans;
}