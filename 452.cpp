#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());
        if (!points.size())
            return 0;
        int curMax = points[0][1];
        int count = 0;
        for (auto it = points.begin(); it != points.end(); ++it)
        {
            if ((*it)[0] <= curMax)
            {
                curMax = min(curMax, (*it)[1]);
            }
            else
            {
                ++count;
                curMax = (*it)[1];
            }
        }
        ++count;
        return count;
    }
};

int main()
{
    vector<vector<int>> vec = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    Solution s;
    cout << s.findMinArrowShots(vec);
    return 0;
}