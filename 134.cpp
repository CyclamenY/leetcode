#include <vector>

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        for (int i = 0; i < n; ++i)
        {
            int j = i;
            int oil = gas[i];
            while (oil - cost[j] >= 0)
            {
                oil = oil - cost[j] + gas[(j + 1) % n];
                j = (j + 1) % n;
                if (j == i)
                {
                    return i;
                }
            }
            if (j < i)
            {
                return -1;
            }
        }
    }
};

int main()
{
    vector<int> gas = {4};
    vector<int> cost = {5};
    Solution s;
    int i = s.canCompleteCircuit(gas, cost);

    return 0;
}