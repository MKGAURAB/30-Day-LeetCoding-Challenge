#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int answer = 0;
        for_each(begin(nums), end(nums), [&](int &a) { answer ^= a; });
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    auto sn = Solution();
    cout << sn.singleNumber(nums) << endl;
    return 0;
}
