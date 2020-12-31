#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> yanghui(numRows, vector<int>(1, 1));
        yanghui[0][0] = 1;
        yanghui[1].resize(2);
        yanghui[1][0] = yanghui[1][1] = 1;
        for (int i = 2; i < numRows; ++i)
        {
            auto pre = 1;
            auto last = 2;
            yanghui[i].resize(i + 1);
            for (; last < yanghui[i].size() - 1; ++last, ++pre)
                yanghui[i + 1][last] = yanghui[i][pre] + yanghui[i][last];
        }
        return yanghui;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> ans = s.generate(5);
    return 0;
}