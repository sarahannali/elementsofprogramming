#include <iostream>
#include <string>

using namespace std;

string BaseConvert(int num, int base)
{
    int digit = num % base;
    return num == 0 ? ""
                    : BaseConvert(num / base, base) + (char)(digit >= 10 ? 'A' + digit - 10 : '0' + digit);
}

string StringBaseConverter(string str, int base1, int base2)
{
    int num_base_10 = 0;
    bool is_neg = str[0] == '-';
    for (unsigned int i = is_neg ? 1 : 0; i < str.size(); i++)
    {
        int digit = str[i];
        num_base_10 *= base1;
        num_base_10 += isdigit(digit) ? digit - '0' : digit - 'A' + 10;
    }

    return BaseConvert(num_base_10, base2);
}

int main()
{
    string num = "615";
    int base1 = 7;
    int base2 = 13;

    string ans = StringBaseConverter(num, base1, base2);
    cout << ans;
}