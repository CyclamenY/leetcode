#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    void LenChange(vector<vector<int>> &A, int len)
    {
        for (auto it : A[len])
            it = !it;
    }
    void RowChange(vector<vector<int>> &A, int row)
    {
        for (int len = 0; len < A.size(); ++len)
            A[len][row] = !A[len][row];
    }
    int ans = 0;

public:
    int matrixScore(vector<vector<int>> &A)
    {
        int lenMax = A.size();
        int rowMax = A[0].size();
        for (int len = 0; len < lenMax; ++len)
        {
            int lenAns = 0;
            for (int row = 0; row < rowMax; ++row)
                lenAns += A[len][row] * pow(2, rowMax - row - 1);
            if (lenAns < (pow(2, rowMax) - 1) / 2)
                LenChange(A, len);
        }
        for (int row = 0; row < rowMax; ++row)
        {
            int count = 0;
            for (int len = 0; len < lenMax; ++len)
            {
                if (A[len][row] == 0)
                    ++count;
            }
            if (count < lenMax / 2)
                RowChange(A, row);
        }
        for (int len = 0; len < lenMax; ++len)
        {
            for (int row = 0; row < rowMax; ++row)
                ans += A[len][row] * pow(2, rowMax - row - 1);
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> A = {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
    Solution s;
    cout << s.matrixScore(A);
    return 0;
}