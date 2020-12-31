#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        if (!prices.size())
            return ans;
        vector<pair<int, int>> maxpair;
        vector<pair<int, int>> minpair;
        maxpair.push_back(
            make_pair(prices[prices.size() - 1], prices.size() - 1));
        minpair.push_back(make_pair(prices[0], 0));
        for (int i = 1; i < prices.size() - 1; ++i)
        {
            if (prices[i - 1] >= prices[i] && prices[i] < prices[i + 1])
                minpair.push_back(make_pair(prices[i], i));
            if (prices[i - 1] <= prices[i] && prices[i] > prices[i + 1])
                maxpair.push_back(make_pair(prices[i], i));
        }
        for (int i = 0; i < minpair.size(); ++i)
        {
            for (auto it : maxpair)
            {
                if (it.second > minpair[i].second &&
                    it.first > minpair[i].first)
                    ans = ans > it.first - minpair[i].first ?
                              ans :
                              it.first - minpair[i].first;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> test = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << s.maxProfit(test);
    return 0;
}