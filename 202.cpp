#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        if (!n)
            return 0;
        vector<bool> num(n, true);
        int count = 0;
        num[0] = num[1] = false;
        for (int i = 2; i < n; ++i)
        {
            if (num[i])
            {
                ++count;
                for (long j = pow(i, 2); j < n; j += i)
                    num[j] = false;
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    cout << s.countPrimes(20);
    return 0;
}