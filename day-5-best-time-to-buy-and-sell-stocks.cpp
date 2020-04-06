#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxPrft = 0;
        // This algorithm is called Peak-Valley Algorithm in Stock Market
        // Don't get greedy and skip next Peak to get more profit, because it will
        // result in loss in contribution to the overall profit.
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i - 1])
                maxPrft += (prices[i] - prices[i - 1]);
        }

        return maxPrft;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> inp = {7, 1, 5, 3, 6, 4};
    auto test = Solution();

    cout << test.maxProfit(inp) << endl;

    inp = {1, 2, 3, 4, 5};

    cout << test.maxProfit(inp) << endl;

    inp = {7, 6, 4, 3, 1};

    cout << test.maxProfit(inp) << endl;

    return 0;
}
