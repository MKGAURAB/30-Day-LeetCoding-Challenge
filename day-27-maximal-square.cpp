#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int H = matrix.size();
        if (H == 0)
            return 0;
        int W = matrix[0].size();
        if (W == 0)
            return 0;
        vector<vector<int>> memo(H + 1, vector<int>(W + 1));
        int answer = 0;
        for (int i = 1; i <= H; ++i)
        {
            for (int j = 1; j <= W; ++j)
            {
                if (matrix[i - 1][j - 1] == '1')
                    memo[i][j] = min({memo[i - 1][j], memo[i][j - 1], memo[i - 1][j - 1]}) + 1;
                answer = max(answer, memo[i][j]);
            }
        }

        return answer * answer;
    }
};

int main(int argv, const char **argc)
{
    return 0;
}