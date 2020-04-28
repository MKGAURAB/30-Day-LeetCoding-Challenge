#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, 0);
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i] = max(dp[i - 1] - 1, nums[i - 1]);
            if (dp[i] <= 0)
                return false;
        }
        return true;
    }
};

int main(int argv, const char **argc)
{
    vector<int> input = {2, 3, 1, 1, 4};

    auto test = Solution();

    cout << boolalpha << test.canJump(input) << endl;

    input = {3, 2, 1, 0, 4};
    cout << boolalpha << test.canJump(input) << endl;
    return 0;
}