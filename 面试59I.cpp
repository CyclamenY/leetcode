#include <deque>
#include <iostream>
#include <vector>

using namespace std;
// using namespace std::literals::chrono_literals;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> deq;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            //新元素入队时如果比队尾元素大的话就替代队尾元素
            //注意，这里入的是元素下标
            while (!deq.empty() && nums[i] > nums[deq.back()])
            {
                deq.pop_back();
            }
            //检查队首的index是否在窗口内，不在的话需要出队
            if (!deq.empty() && deq.front() < i - k + 1)
            {
                deq.pop_front();
            }
            deq.push_back(i);
            if (i >= k - 1)
            {
                ans.push_back(nums[deq.front()]);
            }
        }
        return ans;
    }
};
