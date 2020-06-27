#include <iostream>

int Reverse(int original)
{
    int ans = 0;
    int absolute_original = abs(original);

    while (absolute_original)
    {
        ans *= 10;
        ans += absolute_original % 10;
        absolute_original /= 10;
    }
    
    return original < 0 ? -ans : ans;
}

main()
{
    int ans = Reverse(-2311);
    std::cout << ans;
}