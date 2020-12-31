#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<pair<int, int>> data;
        int size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            data.emplace_back(nums[i], i);
        }
        sort(data.begin(), data.end());
        auto returnVec = vector<int>(size, 0);
        int prev = -1;
        for (int i = 0; i != size; ++i)
        {
            if (prev == -1 || data[i].first != data[i - 1].first)
            {
                prev = i;
            }
            returnVec[data[i].second] = prev;
        }
        return returnVec;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {7, 7, 7, 7};
    s.smallerNumbersThanCurrent(vec);
}