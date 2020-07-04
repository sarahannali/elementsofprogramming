#include <iostream>
#include <vector>
#include <random>

using namespace std;

int PartitionVector(vector<int> &given_vector, int L, int U, int idx)
{
    int pivot_val = given_vector[idx];
    int partition = L;
    swap(given_vector[U], given_vector[idx]);

    for (int i = L; i < U; i++)
    {
        if (given_vector[i] < pivot_val)
        {
            swap(given_vector[i], given_vector[partition]);
            partition++;
        }
    }

    swap(given_vector[U], given_vector[partition]);

    return partition;
}

int FindK(vector<int> &given_vector, int k)
{
    int L = 0, U = given_vector.size();

    int result;
    int greater_length;

    random_device rd;
    mt19937 gen(rd());

    while (greater_length != k-1)
    {
        int rand_idx = uniform_int_distribution<int>{L,U}(gen);
        int partition = PartitionVector(given_vector, L, U, rand_idx);

        greater_length = given_vector.size() - partition - 1;
        result = partition;

        if (greater_length < k-1)
        {
            U = partition-1;
        }
        else if (greater_length > k-1)
        {
            L = partition+1;
        }
    }

    return given_vector[result];
}

int main()
{
    vector<int> A = {3, 2, 1, 5, 4};
    int k = 1;

    cout << FindK(A, k);
}