#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    string sortString(string s)
    {
        unordered_map<char, int> hashmap;
        string ans;
        vector<char> stdVec;
        int size = 0;
        for (char it : s)
        {
            if (!hashmap.count(it))
            {
                hashmap.insert(make_pair(it, 1));
                stdVec.push_back(it);
                ++size;
            }
            else
                ++hashmap[it];
        }
        sort(stdVec.begin(), stdVec.end());
        while (ans.size() < s.size())
        {
            for (int i = 0; i < size; ++i)
            {
                if (hashmap.count(stdVec[i]))
                {
                    ans += stdVec[i];
                    if (!--hashmap[stdVec[i]])
                        hashmap.erase(stdVec[i]);
                }
            }
            for (int i = size - 1; i >= 0; --i)
            {
                if (hashmap.count(stdVec[i]))
                {
                    ans += (stdVec[i]);
                    if (!--hashmap[stdVec[i]])
                        hashmap.erase(stdVec[i]);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string ans = s.sortString("ggggggg");
    return 0;
}