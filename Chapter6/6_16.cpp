#include <iostream>
#include <set>

using namespace std;

bool CheckSudoku(int board[9][9])
{
    // check rows:
    for (int i = 0; i < 9; i++)
    {
        int check[9] = {0};
        for (int j = 0; j < 9; j++)
        {
            int curr_val = board[i][j] - 1;

            if (check[curr_val] == 1)
            {
                cout << "issue in row " << i << '\n';
                return false;
            }
            else
            {
                check[curr_val] += 1;
            }
        }
    }

    // check columns:
    for (int i = 0; i < 9; i++)
    {
        int check[9] = {0};
        for (int j = 0; j < 9; j++)
        {
            int curr_val = board[j][i] - 1;

            if (check[curr_val] == 1)
            {
                cout << "issue in column " << i << '\n';
                return false;
            }
            else
            {
                check[curr_val] += 1;
            }
        }
    }

    // check boxes:
    int offset_x = 0;
    int offset_y = 0;

    for (int k = 0; k < 9; k++)
    {
        int check[9] = {0};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int curr_val = board[i + offset_y][j + offset_x] - 1;

                if (check[curr_val] == 1)
                {
                    cout << "issue in box " << k << '\n';
                    return false;
                }
                else
                {
                    check[curr_val] += 1;
                }
            }
        }

        offset_x >= 6 ? offset_x = 0 : offset_x += 3;

        if (k != 0 && k % 3 == 2)
        {
            offset_y += 3;
        }
    }

    return true;
}

int main()
{
    int A[9][9] =
        {
            {1, 4, 2, 0, 0, 0, 0, 0, 3},
            {2, 5, 0, 0, 0, 1, 0, 0, 0},
            {3, 0, 9, 0, 0, 0, 0, 0, 0},
            {0, 8, 0, 0, 2, 0, 0, 0, 4},
            {0, 0, 0, 4, 1, 0, 0, 2, 0},
            {9, 0, 0, 0, 0, 0, 6, 0, 0},
            {0, 0, 3, 0, 0, 0, 0, 0, 9},
            {4, 0, 0, 0, 0, 2, 0, 0, 0},
            {0, 0, 1, 0, 0, 8, 0, 0, 7},
        };

    cout << CheckSudoku(A);
}