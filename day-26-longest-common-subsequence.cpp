#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if (i == 0 || j == 0)
                    memo[i][j] = 0;
                else if (text1[i - 1] == text2[j - 1])
                    memo[i][j] = memo[i - 1][j - 1] + 1;
                else
                    memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }

        return memo[m][n];
    }
};

int main(int argv, const char **argc)
{
    auto test = Solution();

    cout << test.longestCommonSubsequence("abcde", "ace") << endl;
    return 0;
}