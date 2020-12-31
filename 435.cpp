#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int count = 0;
        if (!intervals.size())
            return count;
        sort(intervals.begin(), intervals.end());
        int pre = intervals[0][0];
        int last = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][1] < last && intervals[i][0] > pre)
            {
                pre = intervals[i][0];
                last = intervals[i][1];
                ++count;
            }
            else if (intervals[i][0] < last)
                ++count;
            else
                last = intervals[i][1];
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> vec = {{1, 2}, {2, 3}};
    cout << s.eraseOverlapIntervals(vec);
    return 0;
}