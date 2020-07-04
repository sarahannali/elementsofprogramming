#include <iostream>
#include <vector>

using namespace std;

int SmallestInCycle(vector<int> v)
{
    int L = 0, U = v.size() - 1;

    while (L < U)
    {
        int M = L + (U - L) / 2;

        if (v[M] > v[U])
        {
            L = M + 1;
        }
        else if (v[M] < v[U])
        {
            U = M;
        }
    }

    return L;
}

int main()
{
    vector<int> v = {378, 478, 550, 631, 103, 203, 220, 234, 279, 368};

    cout << SmallestInCycle(v);
}