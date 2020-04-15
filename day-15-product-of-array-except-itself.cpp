#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> prod(nums.size(), 1);

        int temp = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            prod[i] *= temp;
            temp *= nums[i];
        }

        temp = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            prod[i] *= temp;
            temp *= nums[i];
        }

        return prod;
    }
};

int main(int argv, const char *argc)
{
    vector<int> inp = {1, 2, 3, 4};
    auto test = Solution();
    auto result = test.productExceptSelf(inp);
    for_each(begin(result), end(result), [](const int &a) { cout << a << " "; });
    cout << endl;

    inp = {-1, -2, -3, 4};
    result = test.productExceptSelf(inp);
    for_each(begin(result), end(result), [](const int &a) { cout << a << " "; });
    cout << endl;

    inp = {1, 0, -3, 4};
    result = test.productExceptSelf(inp);
    for_each(begin(result), end(result), [](const int &a) { cout << a << " "; });
    cout << endl;

    return 0;
}