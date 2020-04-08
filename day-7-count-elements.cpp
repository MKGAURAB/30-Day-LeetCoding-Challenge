#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int arr[1500];

public:
    int countElements(vector<int> &inp)
    {
        memset(arr, 0, sizeof arr);
        for (auto a : inp)
            arr[a] = 1;

        return count_if(begin(inp), end(inp), [&](int const &num) { return arr[num + 1]; });
    }
};

int main(int argc, char const *argv[])
{
    vector<int> inp = {1, 1, 3, 3, 5, 5, 7, 7};

    auto test = Solution();

    cout << test.countElements(inp) << endl;

    inp = {1, 2, 3};
    cout << test.countElements(inp) << endl;

    inp = {1, 3, 2, 3, 5, 0};
    cout << test.countElements(inp) << endl;

    inp = {1, 1, 2, 2};
    cout << test.countElements(inp) << endl;

    return 0;
}
