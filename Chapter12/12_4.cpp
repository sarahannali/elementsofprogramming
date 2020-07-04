#include <iostream>
#include <vector>

using namespace std;

int IntRoot(int square)
{
    int L = 0, U = square;

    while (L <= U)
    {
        int M = L + (U - L) / 2;

        if ((M * M) > square)
        {
            U = M - 1;
        }
        else if ((M * M) < square)
        {
            L = M + 1;
        }
        else
        {
            return M;
        }
    }
    return U;
}

int main()
{
    cout << IntRoot(300);
}