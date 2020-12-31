#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> constructArr(vector<int>& a) {
            if(a.empty()) return a;
            vector<int> front;
            vector<int> last;
            vector<int> returnArray;
            int size=a.size();
            front.push_back(a[0]);
            last.push_back(a[size-1]);
            for(int i=2;i<size;++i) {
                front.push_back(front[i-2]*a[i-1]);
                last.push_back(last[i-2]*a[size-i]);
            }
            returnArray.push_back(last[size-2]);
            for(int i=0;i<size-2;++i) {
                returnArray.push_back(front[i]*last[size-3-i]);
            }
            returnArray.push_back(front[size-2]);
            return returnArray;
        }
};