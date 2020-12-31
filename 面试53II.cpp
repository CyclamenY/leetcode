#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int add(int x)
    {
        if (x == 0)
        {
            return 0;
        }
        if (x == 1)
        {
            return 1;
        }
        else
        {
            return x + add(x - 1);
        }
    }
    int missingNumber(vector<int> &nums)
    {
        int numSum = 0;
        if (nums[0] != 0)
            return 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            numSum += nums[i];
        }
        int numAdd = add(nums[nums.size() - 1]);
        if (numSum == numAdd)
        {
            return nums[nums.size() - 1] + 1;
        }
        else
            return numAdd - numSum;
    }
};