#include <iostream>
#include <unordered_map>

using namespace std;

bool PalindromicPermutation(string word)
{
    unordered_map<int, int> letters;
    for (char c : word)
    {
        letters[c]++;
    }

    bool found_single = false;
    for (const auto &l : letters)
    {
        if (l.second % 2 != 0)
        {
            if (found_single) 
            {
                return false;
            }

            found_single = true;
        }
    }

    return true;
}

int main()
{
    string word = "foofbaraboof";
    cout << PalindromicPermutation(word);
}