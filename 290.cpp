#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        if (!s.size() && !pattern.size())
            return true;
        if (!s.size())
            return false;
        s += " ";
        unordered_map<char, string> hashmap;
        for (int i = 0; i < pattern.size(); ++i)
        {
            int pos = s.find(" ");
            auto str = s.substr(0, pos);
            s = s.substr(pos + 1, s.size() - pos);
            if (hashmap[pattern[i]] != "" && hashmap[pattern[i]] != str)
                return false;
            hashmap[pattern[i]] = str;
        }
        if (s.size())
            return false;
        unordered_set<string> hashset;
        for (auto it : hashmap)
        {
            if (it.second != "")
                hashset.insert(it.second);
            else
                return false;
        }
        if (hashset.size() == hashmap.size())
            return true;
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.wordPattern("a", "aa");
    return 0;
}