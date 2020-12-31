#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        vector<pair<int, int>> judgetVec;
        int weight = points.size();
        for (int i = 0; i < weight; ++i)
            judgetVec.emplace_back(
                make_pair((pow(points[i][0], 2) + pow(points[i][1], 2)), i));
        sort(judgetVec.begin(), judgetVec.end());
        vector<vector<int>> returnVec;
        for (int i = 0; i < K; ++i)
            returnVec.emplace_back(points[judgetVec[i].second]);
        return returnVec;
    }
};

int main()
{
    vector<vector<int>> vec = {{1, 3}, {-2, 2}};
    Solution s;
    s.kClosest(vec, 1);
}