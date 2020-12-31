#include <deque>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
    {
        vector<vector<bool>> flagVec(R, vector<bool>(C, false));
        vector<vector<int>> returnVec;
        deque<vector<int>> dq;
        returnVec.emplace_back(vector<int>{r0, c0});
        flagVec[r0][c0] = true;
        if (r0 - 1 >= 0)
            dq.emplace_back(vector<int>{r0 - 1, c0});
        if (r0 + 1 < R)
            dq.emplace_back(vector<int>{r0 + 1, c0});
        if (c0 - 1 >= 0)
            dq.emplace_back(vector<int>{r0, c0 - 1});
        if (c0 + 1 < C)
            dq.emplace_back(vector<int>{r0, c0 + 1});
        while (!dq.empty())
        {
            auto len = dq.front()[0];
            auto row = dq.front()[1];
            dq.pop_front();
            if (flagVec[len][row])
                continue;
            flagVec[len][row] = true;
            returnVec.push_back(vector<int>{len, row});
            if (len - 1 >= 0 && !flagVec[len - 1][row])
                dq.push_back(vector<int>{len - 1, row});
            if (len + 1 < R && !flagVec[len + 1][row])
                dq.push_back(vector<int>{len + 1, row});
            if (row - 1 >= 0 && !flagVec[len][row - 1])
                dq.push_back(vector<int>{len, row - 1});
            if (row + 1 < C && !flagVec[len][row + 1])
                dq.push_back(vector<int>{len, row + 1});
        }
        return returnVec;
    }
};

int main()
{
    Solution s;
    s.allCellsDistOrder(5, 5, 0, 0);

    return 0;
}