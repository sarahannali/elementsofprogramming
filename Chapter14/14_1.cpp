#include <iostream>
#include <vector>

using namespace std;

vector<int> Intersection(const vector<int>& A, const vector<int>& B)
{
    vector<int> result {};

    int size = A.size() < B.size() ? A.size() : B.size();
    int i = 0;
    int j = 0;

    while (i < size || j < size)
    {
        while (A[i] < B[j])
        {
            i++;
        }

        while (A[i] > B[j])
        {
            j++;
        }

        if (A[i] == B[j])
        {
            if (result.empty() || result.back() != A[i])
            {
                result.push_back(A[i]);
            }
            i++;
            j++;
        }
    }
    

    return result;
}

int main()
{
    vector<int> A = {2,3,3,5,5,6,7,7,8,12};
    vector<int> B = {5,5,6,8,8,9,10};

    vector<int> ans = Intersection(A, B);

    cout << "answer:";
    for (int i : ans)
    {
        cout << i << ',';
    }
}