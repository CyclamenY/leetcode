#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> splitIntoFibonacci(string S)
    {
        vector<int> list;
        backtrack(list, S, S.length(), 0, 0, 0);
        return list;
    }

    bool backtrack(vector<int> &list,
                   string S,
                   int length,
                   int index,
                   long long sum,
                   int prev)
    {
        //回溯算法结束点
        if (index == length)
        {
            //到底了里面的数字都不大于2个，说明这是个无效的序列，返回false
            return list.size() >= 3;
        }
        long long curr = 0;
        //回溯算法过程
        for (int i = index; i < length; i++)
        {
            //遇见0直接抛弃，除了i=index的情况
            if (i > index && S[index] == '0')
            {
                break;
            }
            curr = curr * 10 + S[i] - '0';
            if (curr > INT_MAX)
            {
                //如果分割出来的数大于int最大值，抛弃
                break;
            }
            //如果list里面已经有两个数据
            if (list.size() >= 2)
            {
                if (curr < sum)
                {
                    //若现在的数据小于sum，小于继续分割
                    continue;
                }
                else if (curr > sum)
                {
                    //大于sum，已经不符合要求，抛弃
                    break;
                }
            }
            list.push_back(curr);
            if (backtrack(list, S, length, i + 1, prev + curr, curr))
            {
                return true;
            }
            list.pop_back();
        }
        return false;
    }
};

int main()
{
    Solution s;
    s.splitIntoFibonacci("1101111");

    return 0;
}