#include <bits/stdc++.h>

using namespace std;

class FirstUnique
{
private:
    list<int> q;
    unordered_map<int, list<int>::iterator> s;

public:
    FirstUnique(vector<int> &nums)
    {
        q.clear();
        s.clear();
        for (auto a : nums)
        {
            add(a);
        }
    }

    int showFirstUnique()
    {
        return q.empty() ? -1 : q.front();
    }

    void add(int a)
    {
        if (s.count(a) == 0)
        {
            q.push_back(a);
            s[a] = --q.end();
        }
        else if (s[a] != q.end())
        {
            q.erase(s[a]);
            s[a] = q.end();
        }
    }
};

int main(int argv, const char **argc)
{
    return 0;
}