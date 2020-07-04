#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int FirstOccurrence(const vector<int> &sorted_array, int key)
{
    int L = 0, U = sorted_array.size() - 1, result = -1;

    while (L <= U)
    {
        int M = L + (U - L) / 2;

        if (sorted_array[M] < key)
            L = M + 1;
        else if (sorted_array[M] == key)
        {
            result = M;
            U = M - 1;
        }
        else
            U = M - 1;
    }

    return result;
}

int main()
{
    vector<int> sorted_array = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
    int key = 285;
    cout << FirstOccurrence(sorted_array, key);
}
