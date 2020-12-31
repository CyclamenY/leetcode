#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        unordered_set<int> numsSet1;
        unordered_set<int> numsSet2;
        vector<int> returnVec;
        int i = 0;
        int j = 0;
        while (i != size1 || j != size2)
        {
            if (i != size1)
            {
                numsSet1.insert(nums1[i]);
                ++i;
            }
            if (j != size2)
            {
                numsSet2.insert(nums2[j]);
                ++j;
            }
        }
        int setSize = numsSet1.size();
        for (auto it = numsSet1.cbegin(); it != numsSet1.cend(); ++it)
        {
            if (numsSet2.find(*it) != numsSet2.end())
                returnVec.push_back(*it);
        }
        return returnVec;
    }
};

int main()
{
    Solution s;
    vector<int> vec1 = {4, 9, 5};
    vector<int> vec2 = {9, 4, 9, 8, 4};
    auto vec3 = s.intersection(vec1, vec2);

    return 0;
}