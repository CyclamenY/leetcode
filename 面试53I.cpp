#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int searchDa(vector<int>& nums, int target)
        {
            int front=0,back=nums.size()-1;
            int returnNum=0;
            if(nums[back/2]>target)
            {
                back/=2;
            }
            else if(nums[back/2]<target)
            {
                front=back/2;
            }
            else
            {
                int indexfront=back/2;
                int indexback=back/2;
                for(;indexback<=nums.size()-1 && nums[indexback]==target;++indexback);
                for(;indexfront>=0 && nums[indexfront]==target;--indexfront);
                return indexback-indexfront-1;
            }
            for(;front<=back;++front)
            {
                if(nums[front]==target)
                {
                    ++returnNum;
                }
            }
            return returnNum;
        }
        int searchXiao(vector<int>& nums, int target)
        {
            int returnNum=0;
            for(int i=0;i<nums.size();++i)
            {
                if(nums[i]==target)
                {
                    returnNum++;
                }
            }
            return returnNum;
        }
        int search(vector<int>& nums, int target) 
        {
            if(nums.empty()) return 0;
            int front=0,back=nums.size()-1;
            if(back==0)
            {
                if(nums[back]==target) return 1;
                else return 0;
            }
            switch(back/10)
            {
                case 0:
                case 1:
                    return searchXiao(nums,target);
                    break;
                default:
                    return searchDa(nums,target);
                    break;
            }
            return 1;
        }
};


int main()
{
    vector<int> vec={1,3};
    Solution s;
    cout<<s.search(vec,1)<<endl;
}