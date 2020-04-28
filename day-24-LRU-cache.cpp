#include <bits/stdc++.h>

using namespace std;

class LRUCache
{
private:
    list<pair<int, int>> values;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    int cap;

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        values.clear();
        map.clear();
    }

    int get(int key)
    {
        if (map.find(key) == map.end())
            return -1;

        auto it = map.find(key);
        values.splice(values.begin(), values, it->second);
        return it->second->second;
    }

    void put(int key, int value)
    {
        if (map.find(key) == map.end())
        {
            if (values.size() == cap)
            {
                auto last = values.back();
                values.pop_back();
                map.erase(last.first);
            }
        }
        else
            values.erase(map[key]);

        values.push_front({key, value});
        map[key] = values.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char const *argv[])
{
    LRUCache cache = LRUCache(2);

    cache.put(1, 1);
    cache.put(2, 2);

    cout << cache.get(1) << endl;

    cache.put(3, 3);
    cout << cache.get(2) << endl;

    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    cache = LRUCache(1);
    cache.put(2, 1);
    cout << cache.get(2) << endl;
    cache.put(3, 2);
    cout << cache.get(2) << endl;
    cout << cache.get(3) << endl;

    return 0;
}
