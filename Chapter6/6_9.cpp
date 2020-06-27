#include <iostream>

using namespace std;

void Permute(int A[], int P[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int next = i;
        while (P[next] >= 0)
        {
            swap(A[i], A[P[next]]);
            int temp = P[next];
            P[next] -= n;
            next = temp;
        }
    }
}

int main()
{
    int A[] = {1, 2, 3, 4}; // 2,3,1,4
    int P[] = {2, 0, 1, 3};
    int n = sizeof(A) / sizeof(int);

    Permute(A, P, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}