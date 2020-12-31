#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    /*vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> targetVector;
        vector<int> numVector;
        int sum=0;
        for(int i=1;i<=(target/2+1);) {
            if(sum<target) {
                numVector.push_back(i);
                sum+=i++;
                continue;
            }
            if(sum==target) {
                targetVector.push_back(numVector);
                sum=sum-*numVector.begin();
                numVector.erase(numVector.begin());
                continue;
            }
            if(sum>target) {
                sum=sum-*numVector.begin();
                numVector.erase(numVector.begin());
            }
        }
        return targetVector;
    }*/
};
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> vec;
        vector<int> res;
        int sum=0,limit=(target-1)/2; //(target-1)/2 等效于target/2下取整
        for (int x=1;x<=limit;++x) {
            long long delta=1-4*(x-1ll*x*x-2*target);       //求根公式中的Δ
            if(delta<0) continue;
            int delta_sqrt=(int)sqrt(delta+0.5);
            if(1ll*delta_sqrt*delta_sqrt==delta && (delta_sqrt-1)%2==0) {   //判断根号Δ为整数且求根分子为偶数
                int y=(-1+delta_sqrt)/2; // 另一个解(-1-delta_sqrt)/2必然小于0，不用考虑
                if (x<y) {
                    res.clear();
                    for (int i = x; i <= y; ++i) res.emplace_back(i);
                    vec.emplace_back(res);
                }
            }
        }
        return vec;
    }
};