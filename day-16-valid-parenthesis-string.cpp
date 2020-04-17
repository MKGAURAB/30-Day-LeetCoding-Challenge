#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<vector<int>> memo;

    bool rec(string &s, int pos, int cnt)
    {
        if (cnt < 0)
            return 0;
        if (pos == s.length())
            return cnt == 0;
        int &ret = memo[pos][cnt];
        if (~ret)
            return ret;
        if (s[pos] == '(')
            return ret = rec(s, pos + 1, cnt + 1);
        else if (s[pos] == ')')
            return ret = rec(s, pos + 1, cnt - 1);
        else
            return ret = rec(s, pos + 1, cnt + 1) || rec(s, pos + 1, cnt - 1) || rec(s, pos + 1, cnt);
    }

public:
    bool checkValidString(string s)
    {
        int n = s.length();
        memo = vector<vector<int>>(n, vector<int>(n + 1, -1));
        return rec(s, 0, 0);
    }
};

int main(int argv, const char *argc)
{
    string str = "(*))";
    auto test = Solution();

    cout << boolalpha << test.checkValidString(str) << endl;

    str = "()";
    cout << boolalpha << test.checkValidString(str) << endl;

    str = ")*";
    cout << boolalpha << test.checkValidString(str) << endl;

    return 0;
}