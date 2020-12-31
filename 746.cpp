#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp(cost.size());
        dp[0] = dp[1] = 0;
        for (int i = 2; i <= cost.size(); ++i)
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        return dp[cost.size()];
    }
};

int main()
{
    Solution s;
    vector<int> vec = {10, 15, 20};
    cout << s.minCostClimbingStairs(vec);
    return 0;
}