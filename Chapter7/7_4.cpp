#include <iostream>

using namespace std;

void ReplaceRemove(char *arr, int size)
{
    int write_idx = 0;
    int a_count = 0;
    for (int i = 0; i < size; i++)
    {
       if (arr[i] != 'b')
       {
           arr[write_idx++] = arr[i];
       }
       if (arr[i] == 'a')
       {
           ++a_count;
       }
    }

    int curr_idx = write_idx + 1;
    write_idx = curr_idx + a_count - 1;

    while (curr_idx >= 0)
    {
        if (arr[curr_idx] == 'a')
        {
            arr[write_idx--] = 'd';
            arr[write_idx--] = 'd';
        }
        else
        {
            arr[write_idx--] = arr[curr_idx];
        }

        --curr_idx;
        
    }
}

int main()
{
    char A[10] = {'a', 'c', 'a', 'a', 'b', 'c', 'a', 'b', 'c', 'c'};
    int size = 7;

    ReplaceRemove(A, size);

    cout << "answer: " << A;
}