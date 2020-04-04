#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int cnt = 0;

        for(int i = 0; i < (int)nums.size(); ++i)
        {
            if(nums[i]!=0) nums[cnt++] = nums[i];
        }

        while(cnt<nums.size()) nums[cnt++] = 0;
    }
};

int main(int argc, char const *argv[])
{
    auto test = Solution();
    vector<int> inp = {0,1,0,3,12};

    test.moveZeroes(inp);
    
    for(int i = 0; i < (int)inp.size(); ++i) cout<<inp[i]<<" \n"[i==inp.size()-1];

    inp = {1,1,0,3,12};

    test.moveZeroes(inp);
    
    for(int i = 0; i < (int)inp.size(); ++i) cout<<inp[i]<<" \n"[i==inp.size()-1];

    inp = {0,0,0,3,12};

    test.moveZeroes(inp);
    
    for(int i = 0; i < (int)inp.size(); ++i) cout<<inp[i]<<" \n"[i==inp.size()-1];

    inp = {-1,1,0,0,12};

    test.moveZeroes(inp);
    
    for(int i = 0; i < (int)inp.size(); ++i) cout<<inp[i]<<" \n"[i==inp.size()-1];

    return 0;
}
