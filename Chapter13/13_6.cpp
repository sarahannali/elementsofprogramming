#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

int NearestPairs(vector<string> words)
{
    unordered_map<string, int> word_map;
    int nearest_distance = numeric_limits<int>::max();

    for (unsigned int i = 0; i < words.size(); i++)
    {
        auto it = word_map.find(words[i]);
        if (it != word_map.cend())
        {
            int distance = i - it->second;
            if (distance < nearest_distance)
                nearest_distance = distance;
        }

        word_map[words[i]] = i;
    }

    return nearest_distance;
}

int main()
{
    vector<string> words = {"All", "work", "and", "no", "play", "makes", "for", "no", "works", "no", "fun", "and", "no", "results"};

    cout << NearestPairs(words);
}