#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    unordered_map<int, long long> numsMap;
    long long digui(int n)
    {
        if (n == 0 || n == 1)
        {
            numsMap.insert(make_pair(n, 1));
            return 1;
        }
        if (numsMap.find(n - 1) == numsMap.end())
        {
            numsMap.insert(make_pair(n - 1, digui(n - 1) % 1000000007));
        }
        if (numsMap.find(n - 2) == numsMap.end())
        {
            numsMap.insert(make_pair(n - 2, digui(n - 2) % 1000000007));
        }
        return (numsMap[n - 1] + numsMap[n - 2]) % 1000000007;
    }
    int numWays(int n)
    {
        return digui(n);
    }
};

int main()
{
    Solution s;
    cout << s.numWays(44) << endl;
}