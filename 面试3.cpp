#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,bool> hashmap;
        for(auto it=nums.begin();it!=nums.end();++it) {
            if(hashmap.count(*it)) {
                return *it;
            }
            else {
                hashmap.insert(make_pair(*it,true));
            }
        }
        return 0;
    }
};