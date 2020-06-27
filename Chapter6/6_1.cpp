#include <iostream>
#include <vector>

using namespace std;

vector<int> Partition(vector<int> arr, int value)
{
    // int temp = arr[arr.size() - 1];
    // arr[arr.size() - 1] = arr[partition];
    // arr[partition] = temp;

    // const int NEW_PARTITION = arr.size() - 1;

    int lesser = 0;
    int equal = 0;

    for (unsigned int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 1)
        {
            swap(arr[i], arr[equal]);
            swap(arr[equal], arr[lesser]);
            lesser++;
            equal++;
        }
        else if (arr[i] == 1)
        {
            swap(arr[i], arr[equal]);
            equal++;
        }
    }
    return arr;
}

int main()
{
    vector<int> A = {2, 0, 2, 1, 1, 0};
    vector<int> ans = Partition(A, 1);
    for (unsigned int i = 0; i < A.size(); i++)
    {
        cout << A[i];
    }

    cout << '\n';

    for (unsigned int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
}