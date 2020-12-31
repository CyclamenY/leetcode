#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        auto size = s.size();
        if (size != t.size())
            return false;
        unordered_map<char, short> hashmap;
        for (char it : s)
        {
            if (!hashmap.count(it))
                hashmap.emplace(make_pair(it, 1));
            else
                ++hashmap[it];
        }
        for (char it : t)
        {
            if (hashmap.find(it) == hashmap.end())
                return false;
            --hashmap[it];
            if (!hashmap[it])
                hashmap.erase(it);
        }
        if (hashmap.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    Solution s;
    cout << s.isAnagram("cat", "rat");

    return 0;
}