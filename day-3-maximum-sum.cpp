#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> nums)
    {
        int running_max, max_so_far;
        running_max = max_so_far = nums[0];

        for (int i = 1; i < (int)nums.size(); ++i)
        {
            running_max = max(nums[i], running_max + nums[i]);
            max_so_far = max(max_so_far, running_max);
        }

        return max_so_far;
    }
};

int main(int argc, char const *argv[])
{
    auto test = Solution();
    cout << test.maxSubArray((vector<int>){1, 2, 3, 4, 5}) << "\n";
    cout << test.maxSubArray((vector<int>){-2, 1, -3, 4, -1, 2, 1, -5, 4}) << "\n";
    cout << test.maxSubArray((vector<int>){-1, 0, -2, -3, -10}) << "\n";
    cout << test.maxSubArray((vector<int>){-10, -11, -1, -5}) << "\n";
    return 0;
}
