#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int
    fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        int size = C.size();
        if (!size)
            return 0;
        unordered_map<int, int> hashmap;
        int count = 0;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                auto temp = C[i] + D[j];
                if (!hashmap.count(temp))
                    hashmap.insert(make_pair(temp, 1));
                else
                    ++hashmap[temp];
            }
        }
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                auto temp = -(A[i] + B[j]);
                if (hashmap.count(temp))
                {
                    // if (!--hashmap[temp])
                    //    hashmap.erase(temp);
                    count += hashmap[temp];
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> A = {-1, -1};
    vector<int> B = {-1, 1};
    vector<int> C = {-1, 1};
    vector<int> D = {1, -1};
    int ans = s.fourSumCount(A, B, C, D);
    return 0;
}