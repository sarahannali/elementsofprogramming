#include <iostream>
#include <unordered_map>

using namespace std;

bool MagazineToLetter(string magazine, string letter)
{
    unordered_map<char, int> letter_chars;

    for (char c : letter)
    {
        letter_chars[c]++;
    }

    for (char c : magazine)
    {
        auto it = letter_chars.find(c);
        if (it != letter_chars.cend())
        {
            it->second--;
            if (it->second == 0)
            {
                letter_chars.erase(it);
                if (letter_chars.empty())
                {
                    break;
                }
            }
        }
    }

    return letter_chars.empty();
}

int main()
{
    string magazine = "This is the magazine string";
    string letter = "This is the string";

    cout << MagazineToLetter(magazine, letter);
}