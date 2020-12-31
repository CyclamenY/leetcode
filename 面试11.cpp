#include <vector>

using namespace std;

class Solution
{
    public:
        int minArray(vector<int> &numbers)
        {
            int i=1;
            int size=numbers.size();
            for(;i<size && numbers[i]>=numbers[i-1];++i);
            return i==size?numbers[0]:numbers[i];
        }
};