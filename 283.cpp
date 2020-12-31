#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int zerop = 0;
        int curp = 0;
        int size = nums.size();
        if (!size || size == 1)
            return;
        while (zerop < size && nums[zerop] != 0)
            ++zerop;
        curp = zerop;
        while (curp < size && nums[curp] == 0)
            ++curp;
        if (curp == size || zerop == size)
            return;
        while (curp < size || zerop < size)
        {
            while (curp < size && nums[curp] == 0)
                ++curp;
            if (curp == size || zerop == size)
                break;
            swap(nums[curp], nums[zerop]);
            ++zerop;
        }
    }
};

int main()
{
    vector<int> vec = {2, 1};
    Solution s;
    s.moveZeroes(vec);
    return 0;
}