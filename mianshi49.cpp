#include <vector>

using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int a = 0;
        int b = 0;
        int c = 0;
        vector<int> returnVec(n);
        returnVec[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            int uglyNum2 = 2 * returnVec[a];
            int uglyNum3 = 3 * returnVec[b];
            int uglyNum5 = 5 * returnVec[c];
            returnVec[i] = min(min(uglyNum2, uglyNum3), uglyNum5);
            if (returnVec[i] == uglyNum2)
                ++a;
            if (returnVec[i] == uglyNum3)
                ++b;
            if (returnVec[i] == uglyNum5)
                ++c;
        }
        return returnVec[n - 1];
    }
};