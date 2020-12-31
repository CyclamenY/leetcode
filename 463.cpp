#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int length = grid[0].size();
        int weight = grid.size();
        int len = 0;
        for (int i = 0; i < weight; ++i)
        {
            for (int j = 0; j < length; ++j)
            {
                if (grid[i][j] == 0)
                    continue;
                if (i - 1 < 0 || grid[i - 1][j] == 0)
                    len += 1;
                if (i + 1 >= weight || grid[i + 1][j] == 0)
                    len += 1;
                if (j - 1 < 0 || grid[i][j - 1] == 0)
                    len += 1;
                if (j + 1 >= length || grid[i][j + 1] == 0)
                    len += 1;
            }
        }
        return len;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> vec = {{1, 0}};
    cout << s.islandPerimeter(vec);
}