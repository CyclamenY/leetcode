#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        if (s.empty())
            return -1;
        unordered_map<char, int> hashmap;
        for (auto it : s)
            ++hashmap[it];
        for (int i = 0; i < s.size(); ++i)
        {
            if (hashmap[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    cout << s.firstUniqChar("aaaaaaa");
    return 0;
}