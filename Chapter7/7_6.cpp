#include <iostream>
#include <vector>
#include <string>

using namespace std;

string ReverseWords(string& str)
{
    str += " ";
    vector<string> string_v = {};
    string new_string = "";
    for (unsigned int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ')
        {
            new_string += str[i];
        }
        else
        {
            string_v.push_back(new_string);
            new_string = "";
        }
    }

    for (unsigned int i = 0; i < string_v.size(); i++)
    {
        if (i < string_v.size() / 2)
        {
            swap(string_v[i], string_v[string_v.size()-1-i]);            
        }

        new_string += string_v[i];
        new_string += " ";
    }

    return new_string;
}

int main()
{
    string str = "Bob likes Alice";
    string ans = ReverseWords(str);

    cout << ans;
}