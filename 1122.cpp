#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        int size1 = arr1.size();
        unordered_map<int, int> hashmap;
        for (int i = 0; i < size1; ++i)
        {
            if (!hashmap.count(arr1[i]))
            {
                hashmap.insert(make_pair(arr1[i], 1));
            }
            else
            {
                ++hashmap[arr1[i]];
            }
        }
        int size2 = arr2.size();
        vector<int> returnVec;
        for (int i = 0; i < size2; ++i)
        {
            int times = hashmap[arr2[i]];
            returnVec.insert(returnVec.end(), times, arr2[i]);
            hashmap.erase(arr2[i]);
        }
        auto cur = returnVec.size();
        for (auto it = hashmap.begin(); it != hashmap.end(); ++it)
        {
            int times = it->second;
            returnVec.insert(returnVec.end(), times, it->first);
        }
        auto curit = returnVec.begin() + cur;
        sort(curit, returnVec.end());
        return returnVec;
    }
};

int main()
{
    vector<int> vec1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> vec2 = {2, 1, 4, 3, 9, 6};
    Solution s;
    s.relativeSortArray(vec1, vec2);
}