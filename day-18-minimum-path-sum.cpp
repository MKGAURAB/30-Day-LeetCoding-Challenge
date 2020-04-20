#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> memo(m, vector<int>(n, 0));

        memo[0][0] = grid[0][0];

        for (int i = 1; i < m; ++i)
            memo[i][0] = memo[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; ++j)
            memo[0][j] = memo[0][j - 1] + grid[0][j];

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                memo[i][j] = min(memo[i - 1][j], memo[i][j - 1]) + grid[i][j];

        return memo[m - 1][n - 1];
    }
};

int main(int argv, const char **argc)
{
    vector<vector<int>> inp = {{1, 3, 1},
                               {1, 5, 1},
                               {4, 2, 1}};

    auto test = Solution();

    cout << test.minPathSum(inp) << endl;
    return 0;
}