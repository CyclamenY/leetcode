#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        unordered_map<char, int> hashmap;
        for (int i = 0; i < t.size(); ++i)
        {
            if (!++hashmap[t[i]])
                hashmap.erase(t[i]);
            if (i < s.size())
            {
                if (!--hashmap[s[i]])
                    hashmap.erase(s[i]);
            }
        }
        return hashmap.begin()->first;
    }
};

int main()
{
    Solution s;
    cout << s.findTheDifference("yeyy", "yyyey");
    return 0;
}