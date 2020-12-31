#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> array;
        int size=nums.size();
        for(int i=0;i<size-1;++i) {
            if(nums[i]+*nums.end()<target) {
                continue;
            }
            else if(nums[i]+*nums.end()==target) {
                array.push_back(nums[i]);
                array.push_back(*nums.end());
                return array;
            }
            for(int j=i+1;j<size;++j) {
                if(nums[i]+nums[j]==target) {
                    array.push_back(nums[i]);
                    array.push_back(nums[j]);
                    return array;
                }
            }
        }
        return array;
    }
};