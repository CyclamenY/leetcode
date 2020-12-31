#include <vector>
using namespace std;

class Solution {
    vector<int> array=vector<int>(101,-1);
    long div=1000000007;
    public:
        int fib(int n) {
            if(n==0) return 0;
            if(n==1) return 1;
            array[0]=0;
            array[1]=1;
            for(int i=2;i<=n;++i) {
                array[i]=(array[i-1]+array[i-2])%div;
            }
            return array[n];
        }
};