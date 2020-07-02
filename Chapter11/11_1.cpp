#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct IteratorCurrentAndEnd
{
    bool operator>(const IteratorCurrentAndEnd &that) const
    {
        return *current > *that.current;
    }

    vector<int>::const_iterator current;
    vector<int>::const_iterator end;
};

vector<int> SortedUnion(vector<vector<int>> given_unions)
{
    priority_queue<IteratorCurrentAndEnd, vector<IteratorCurrentAndEnd>, greater<IteratorCurrentAndEnd>> min_heap;

    for (const vector<int> &given_union : given_unions)
    {
        if (!given_union.empty())
        {
            min_heap.push(IteratorCurrentAndEnd{given_union.cbegin(), given_union.cend()});
        }
    }

    vector<int> result;
    while (!min_heap.empty())
    {
        IteratorCurrentAndEnd min = min_heap.top();
        min_heap.pop();
        if (min.current != min.end)
        {
            result.push_back(*min.current);
            min_heap.push(IteratorCurrentAndEnd{next(min.current), min.end});
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> Unions = {{3, 5, 7}, {0, 6}, {0, 6, 28}};
    vector<int> ans = SortedUnion(Unions);

    for (const int i : ans)
    {
        cout << i << '\n';
    }
}