#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        int size = arr.size();
        if (!size)
            return true;
        unordered_map<int, int> arrMap;
        for (int i = 0; i < size; ++i)
        {
            if (!arrMap.count(arr[i]))
            {
                arrMap.insert(make_pair(arr[i], 1));
            }
            else
            {
                arrMap[arr[i]]++;
            }
        }
        unordered_set<int> arrSet;
        for (auto it = arrMap.begin(); it != arrMap.end(); ++it)
            arrSet.insert(it->second);
        return arrSet.size() == arrMap.size() ? true : false;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    cout << s.uniqueOccurrences(vec);
}