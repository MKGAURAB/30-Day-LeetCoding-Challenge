#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;

        freq[0] = 1;
        int sum = 0, res = 0;

        auto getValue = [&](int key) -> int {
            if (freq.count(key))
                return freq[key];
            return 0;
        };

        for (auto a : nums)
        {
            sum += a;

            res += getValue(sum - k);

            freq[sum] = getValue(sum) + 1;
        }

        return res;
    }
};

int main(int argv, const char **argc)
{
    vector<int> inp = {1, 1, 1};
    int k = 2;

    auto test = Solution();

    cout << test.subarraySum(inp, k) << endl;

    inp = {1, 0, 1};
    k = 2;

    cout << test.subarraySum(inp, k) << endl;
    return 0;
}