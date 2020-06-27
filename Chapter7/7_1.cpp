#include <iostream>
#include <math.h>

using namespace std;

int StringToInt(string str)
{
    int ans = 0;
    bool is_neg = str[0] == '-';
    for (int i = is_neg ? 1 : 0; i < str.size(); i++)
    {
        int digit = str[i] - '0';
        ans += digit;
        ans *= 10;
    }

    return is_neg ? -ans / 10 : ans / 10;
}

int main()
{
    string str = "-23239";
    int ans = StringToInt(str);
    cout << ans;
}