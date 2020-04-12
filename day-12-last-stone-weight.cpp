#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int, vector<int>, less<int>> Q(begin(stones), end(stones));
        while (Q.size() > 1)
        {
            int firstHeaviest = Q.top();
            Q.pop();
            int secondHeaviest = Q.top();
            Q.pop();
            if (firstHeaviest != secondHeaviest)
            {
                Q.push(firstHeaviest - secondHeaviest);
            }
        }
        return !Q.empty() ? Q.top() : 0;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> stones = {2, 7, 4, 1, 8, 1};

    auto test = Solution();

    cout << test.lastStoneWeight(stones) << endl;

    stones = {2, 2, 2, 2, 2, 2};
    cout << test.lastStoneWeight(stones) << endl;
    return 0;
}
