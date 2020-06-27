#include <iostream>
#include <vector>

using namespace std;

vector<int> PlusOne(const vector<int> &arr)
{
    vector<int> ans = arr;
    bool greaterThanNine = true;
    int lastDigit = ans.size() - 1;

    while (greaterThanNine)
    {
        ans[lastDigit] += 1;

        if (ans[lastDigit] > 9)
        {
            ans[lastDigit] = 0;
            lastDigit--;

            if (lastDigit < 0)
            {
                ans[0] = 1;
                ans.push_back(0);
                greaterThanNine = false;
            }
        }
        else
        {
            greaterThanNine = false;
        }
    }
    return ans;
}

int main()
{
    vector<int> A = {9, 9, 9, 9, 9, 9};
    vector<int> ans = PlusOne(A);
    for (const int i : A)
    {
        cout << i;
    }

    cout << '\n';

    for (const int i : ans)
    {
        cout << i;
    }
}