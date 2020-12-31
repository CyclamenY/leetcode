#include <vector>

using namespace std;

class Solution
{
public:
    int jumpFloor(int number)
    {
        vector<int> vec(number + 1);
        vec[0] = 1;
        vec[1] = 1;
        for (int i = 2; i <= number; ++i)
        {
            vec[i] = vec[i - 1] + vec[i - 2];
        }
        return vec[number];
    }
};

int main()
{
    Solution s;
    s.jumpFloor(4);
}