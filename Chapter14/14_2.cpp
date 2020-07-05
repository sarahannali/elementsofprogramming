#include <iostream>

using namespace std;

void MergeSorted(int A[], int sizeA, int B[], int sizeB)
{
    int size = sizeA + sizeB - 1;

    int j = sizeA - 1;
    int k = sizeB - 1;

    while(j >= 0 && k >= 0)
    {
       A[size--] =  A[j] > B[k] ? A[j--] : B[k--];
    }

    while (k >= 0)
    {
        A[size--] = B[k--];
    }
}

int main()
{
    int A[8] = {5, 13, 17};
    int B[4] = {3, 7, 11, 19};

    MergeSorted(A, 3, B, 4);

    for (int i : A)
    {
        cout << i << ',';
    }
}