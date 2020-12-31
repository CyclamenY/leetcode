#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (!s.size())
            return true;
        unordered_map<char, char> hashmaps;
        unordered_map<char, char> hashmapt;
        for (int i = 0; i < s.size(); ++i)
        {
            if (!hashmaps[s[i]])
                hashmaps[s[i]] = t[i];
            else
            {
                if (hashmaps[s[i]] != t[i])
                    return false;
            }
            if (!hashmapt[t[i]])
                hashmapt[t[i]] = s[i];
            else
            {
                if (hashmapt[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isIsomorphic("ab", "aa");
    return 0;
}