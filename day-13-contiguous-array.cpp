#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int ans = 0, sum = 0;
        unordered_map<int, int> lastFound;
        lastFound[0] = -1;

        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i] ? 1 : -1;
            if (lastFound.count(sum))
                ans = max(ans, i - lastFound[sum]);
            else
                lastFound[sum] = i;
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> inp = {0, 1, 0};
    auto test = Solution();

    cout << test.findMaxLength(inp) << endl;

    inp = {0, 1};
    cout << test.findMaxLength(inp) << endl;

    inp = {1, 0, 0, 1, 1};
    cout << test.findMaxLength(inp) << endl;

    inp = {1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1};
    cout << test.findMaxLength(inp) << endl;

    return 0;
}
