#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int kingNum=0;
        for(auto iter=nums.begin();iter!=nums.end()-1;++iter)
        {
            if(*iter==0)
            {
                ++kingNum;
                continue;
            }
            if((*iter)+1==*(iter+1)) continue;
            int  intervalNum=*(iter+1)-*iter-1;
            if(intervalNum==-1) return false;
            if(intervalNum<=kingNum)
            {
                kingNum-=intervalNum;
            }
            else return false;
        }
        return true;
    }
};

int main()
{
    Solution a;
    vector<int> vec={0,0,1,2,5};
    cout<<a.isStraight(vec);
}