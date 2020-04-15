#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    void rotateLeft(string &str, int d)
    {
        reverse(str.begin(), str.begin() + d);
        reverse(str.begin() + d, str.end());
        reverse(str.begin(), str.end());
    }

    void rotateRight(string &str, int d)
    {
        rotateLeft(str, str.length() - d);
    }

public:
    string stringShift(string s, vector<vector<int>> &shift)
    {
        for (auto a : shift)
        {
            if (!a[0])
                rotateLeft(s, a[1]);
            else
                rotateRight(s, a[1]);
        }
        return s;
    }
};

int main(int argv, const char *argc)
{
    return 0;
}