#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    multimap<int, int> presence;
    int getSumOfSquares(int n)
    {
        int sum = 0;

        while (n)
        {
            int digit = n % 10;
            n /= 10;
            sum += (digit * digit);
        }
        return sum;
    }

public:
    bool isHappy(int n)
    {
        if (n == 1)
            return true;

        if (presence.count(n))
            return false;

        presence.insert({n, 1});

        return isHappy(getSumOfSquares(n));
    }
};

int main(int argc, char const *argv[])
{
    int number;
    while (cin >> number)
    {
        auto test = Solution();
        if (test.isHappy(number))
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
