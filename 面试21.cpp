#include <vector>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> returnArray;
        vector<int> array1;
        vector<int> array2;
        for(auto it=nums.begin();it!=nums.end();++it) {
            if(*it%2!=0) {
                array1.push_back(*it);
            }
            else {
                array2.push_back(*it);
            }
        }
        returnArray.insert(returnArray.end(),array1.begin(),array1.end());
        returnArray.insert(returnArray.end(),array2.begin(),array2.end());
        return returnArray;
    }
};