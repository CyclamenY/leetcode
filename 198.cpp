#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size=nums.size();
        int count1=0,count2=0;
        for(int i=0;i<size;i++) {
            if(i%2==0)
                count1+=nums[i];
            else
                count2+=nums[i];
        }
        return count1>count2?count1:count2;
    }
};