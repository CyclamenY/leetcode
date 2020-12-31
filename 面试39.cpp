#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size=nums.size();
        unordered_map<int,int> hashmap;
        for(int i=0;i<size;++i) {
            if(hashmap.count(nums[i])<=0) {
                hashmap.insert(make_pair(nums[i],1));
            }
            else {
                hashmap[nums[i]]++;
            }
        }
        for(auto it=hashmap.begin();it!=hashmap.end();++it) {
            if(it->second>=(size+1)/2)
                return it->first;
        }
        return 0;
    }
};