#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        string sp = "", tp = "";

        for (auto a : S)
        {
            if (a == '#' && !sp.empty())
                sp.pop_back();
            else if (a != '#')
                sp += a;
        }

        for (auto a : T)
        {
            if (a == '#' && !tp.empty())
                tp.pop_back();
            else if (a != '#')
                tp += a;
        }
        return sp == tp;
    }
};

int main(int argv, const char *argc[])
{
    string S, T;
    auto test = Solution();

    S = "ab#c", T = "ad#c";
    cout << boolalpha << test.backspaceCompare(S, T) << endl;

    S = "ab##", T = "c#d#";
    cout << boolalpha << test.backspaceCompare(S, T) << endl;

    S = "a##c", T = "#a#c";
    cout << boolalpha << test.backspaceCompare(S, T) << endl;

    S = "a#c", T = "b";
    cout << boolalpha << test.backspaceCompare(S, T) << endl;

    S = "y#fo##f", T = "y#f#o##f";
    cout << boolalpha << test.backspaceCompare(S, T) << endl;
    return 0;
}