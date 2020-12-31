#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> returnArray;
        sort(arr.begin(),arr.end());
        //这里是k的原因在于insert的机制问题，insert是左闭右开区间
        returnArray.insert(returnArray.end(),arr.begin(),arr.begin()+k);
        return returnArray;
    }
};