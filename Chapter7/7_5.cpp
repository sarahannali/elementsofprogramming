#include <iostream>

using namespace std;

bool Palindromic(string str)
{
    int first_char = 0;
    int last_char = str.size();

    for (int i = 0; i < str.size() / 2; i++)
    {
        last_char--;

        while (!isalnum(str[first_char]))
        {
            ++first_char;
        }
        while (!isalnum(str[last_char]))
        {
            --last_char;
        }

        if (tolower(str[first_char]) != tolower(str[last_char]))
        {
            return false;
        }

        first_char++;
    }

    return true;
}

int main()
{
    string str = "Able was I, ere I saw Elba!";
    cout << Palindromic(str);
}