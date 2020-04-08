#include <bits/stdc++.h>

using namespace std;

class Solution
{
    multimap<string, vector<string>> result;

public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        result.clear();
        for (auto a : strs)
        {
            string root = a;
            sort(begin(root), end(root));
            auto item = result.find(root);
            if (item != result.end())
                item->second.push_back(a);
            else
                result.insert(pair<string, vector<string>>(root, {a}));
        }

        vector<vector<string>> res;
        transform(begin(result), end(result), back_inserter(res), [](pair<string, vector<string>> const &item) { return item.second; });

        return res;
    }
};

void printGroupedAnagrams(vector<vector<string>> result)
{
    for (auto a : result)
    {
        for (auto str : a)
        {
            cout << str << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    vector<string> inp = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto test = Solution();

    printGroupedAnagrams(test.groupAnagrams(inp));

    return 0;
}
