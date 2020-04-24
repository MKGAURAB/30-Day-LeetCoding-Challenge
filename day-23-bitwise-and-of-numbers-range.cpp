#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        int cnt = 0;

        while (m != n)
            m >>= 1, n >>= 1, cnt++;

        return m << cnt;
    }
};

int main(int argv, const char **argc)
{
    int m = 0, n = 1;
    auto test = Solution();

    cout << test.rangeBitwiseAnd(m, n) << endl;

    m = 5, n = 7;

    cout << test.rangeBitwiseAnd(m, n) << endl;
    return 0;
}