#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    //本质上就是尽可能寻找某个字母出现的最后一个位置
    vector<int> partitionLabels(string S)
    {
        int last[26];  //记录26个字母最后一次出现的位置的数组
        int length = S.size();
        for (int i = 0; i < length; i++)
        {
            last[S[i] - 'a'] = i;
        }
        vector<int> partition;
        int start = 0, end = 0;
        //固定起点，不断步进，直到当前值等于数组中的位置
        //说明此时这个字母在该位置出现最后一次
        for (int i = 0; i < length; i++)
        {
            end = max(end, last[S[i] - 'a']);
            if (i == end)
            {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
};
