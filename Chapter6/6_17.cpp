#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> SpiralOrder(vector<vector<int>> arr)
{
    int x = 0;
    int y = 0;
    int side = 0;
    int sideLength = arr.size();
    vector<int> spiralVector = {};

    for (unsigned int i = 0; i < arr.size() * arr.size(); i++)
    {
        spiralVector.push_back(arr[x][y]);
        switch (side)
        {
        case 0:
            y++;
            if (y == sideLength - 1)
            {
                side++;
            }
            break;
        case 1:
            x++;
            if (x == sideLength - 1)
            {
                side++;
            }
            break;
        case 2:
            y--;
            if (x + y == arr.size()-1)
            {
                side++;
            }
            break;
        case 3:
            x--;
            if (x == y)
            {
                x++;
                y++;
                side = 0;
                sideLength -= 1;
            }
            break;
        }
    }

    return spiralVector;
}

int main()
{
    vector<vector<int>> A = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    vector<int> ans = SpiralOrder(A);

    cout << "ans: ";
    for (const int i : ans)
    {
        cout << i << " ";
    }
}