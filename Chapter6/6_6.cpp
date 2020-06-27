#include <iostream>
#include <vector>

using namespace std;

vector<int> StockDates(vector<int> &stocks)
{
    if (stocks.size() < 1)
    {
        return {0};
    }
    int curr_max = 0;
    int first_idx = 0;
    int last_idx = 0;
    int temp_max = 0;
    int temp_first = 0;

    for (unsigned int i = 1; i < stocks.size(); i++)
    {
        int diff = stocks[i] - stocks[i - 1];

        if (diff >= 1)
        {
            temp_max = stocks[i] - stocks[temp_first];

            if (temp_max > curr_max)
            {
                curr_max = temp_max;
                first_idx = temp_first;
                last_idx = i;
            }
        }
        else if (stocks[i] < stocks[first_idx])
        {
            temp_max = 0;
            temp_first = i;
        }
    }

    curr_max = stocks[last_idx] - stocks[first_idx];

    return {curr_max};
}

int main()
{
    vector<int> stocks = {7,6,4,3,1};
    vector<int> ans = StockDates(stocks);

    for (const int &i : ans)
    {
        cout << i << " ";
    }
}