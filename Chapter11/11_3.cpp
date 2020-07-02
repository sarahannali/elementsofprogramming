#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> SortKArray(vector<int> given_array, int k)
{
    priority_queue<int, vector<int>, greater<int>> min_heap;
    vector<int>::const_iterator current;

    for (int i = 0; i < k+1; i++)
    {
        min_heap.push(given_array[i]);
    }

    unsigned int x = k + 1;
    vector<int> result;
    while (x < given_array.size())
    {
        result.push_back(min_heap.top());
        min_heap.pop();
        min_heap.push(given_array[x]);
        x++;
    }

    while(!min_heap.empty())
    {
        result.push_back(min_heap.top());
        min_heap.pop();
    }

    return result;
}

int main()
{
    vector<int> A = {3, -1, 2, 6, 4, 5, 8};
    vector<int> ans = SortKArray(A, 2);

    for (const int i : ans)
    {
        cout << i << '\n';
    }
}