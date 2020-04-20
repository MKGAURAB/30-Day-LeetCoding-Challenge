#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();

        if (n < 1)
            return -1;

        int lo = 0, hi = n - 1;

        while (lo < hi)
        {
            int mid = (lo + hi) >> 1;
            if (target == nums[mid])
                return mid;
            if (nums[mid] < nums[hi])
            {
                if (target > nums[mid] && target <= nums[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            else
            {
                if (target >= nums[lo] && target < nums[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }

        return nums[lo] == target ? lo : -1;
    }
};

int main(int argv, const char **argc)
{
    vector<int> inp = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    auto test = Solution();

    cout << test.search(inp, target) << endl;
    target = 3;
    cout << test.search(inp, target) << endl;
    return 0;
}