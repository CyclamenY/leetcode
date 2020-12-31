#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int sum = 0;
        int size = prices.size();
        for (int i = 1; i < size; ++i)
        {
            sum += max(0, prices[i] - prices[i - 1]);
        }
        return sum;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {1, 2, 3, 4, 5};
    s.maxProfit(vec);
}