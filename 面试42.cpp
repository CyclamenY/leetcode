#include <vector>

using namespace std;

class Solution {
public:
    int maxNum(int x,int y) {
        return x>=y?x:y;
    }
    //若前一个数大于0，则该数与前面的一个数相加放入数组中，反之保持不变，然后比较sum与该数
    //该数比sum大就将sum值改写为该值，反之保持不变
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        for(int i=1;i<nums.size();++i) {
            nums[i]+=maxNum(nums[i-1],0);
            sum=maxNum(sum,nums[i]);
        }
        return sum;
    }
};