#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        auto size = arr.size();
        if (!size)
            return {};
        vector<pair<int, int>> pairVec;
        vector<int> returnVec;
        vector<int> standardNum;
        for (int i = 1; i < 10000; i *= 2)
            standardNum.emplace_back(i);
        for (auto it : arr)
        {
            auto tmp = it;
            auto count = 0;
            for (int num = 13; num != -1; --num)
            {
                if (tmp - standardNum[num] >= 0)
                {
                    tmp -= standardNum[num];
                    ++count;
                }
            }
            pairVec.emplace_back(make_pair(count, it));
        }
        sort(pairVec.begin(), pairVec.end());
        for (auto it : pairVec)
            returnVec.emplace_back(it.second);
        return returnVec;
    }
};

int main()
{
    vector<int> vec = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    Solution s;
    s.sortByBits(vec);
}