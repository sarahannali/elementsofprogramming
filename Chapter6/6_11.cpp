#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

void Subset(vector<int>& array, int size)
{
    srand(time(0));

    for(int i = 0; i < size; i++)
    {
        int new_idx = rand() % (array.size() - i) + i;
        array[new_idx] = -1;
        swap(array[i], array[new_idx]);
    }
}

main()
{
    vector<int> A = {1,2,3,4,5,6,2,2,2,3,4,5};
    Subset(A,3);

    for (unsigned int i = 0; i < A.size(); i++)
    {
        cout << A[i] << ",";
    }
}