#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    deque<int> dq;

public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int i = 0;
        for (int num : pushed)
        {
            dq.push_back(num);
            while (!dq.empty() && dq.back() == popped[i])
            {
                dq.pop_back();
                ++i;
            }
        }
        return dq.empty();
    }
};

int main()
{
    Solution s;
    vector<int> vec1 = {0, 2, 1};
    vector<int> vec2 = {0, 1, 2};
    cout << s.validateStackSequences(vec1, vec2);
    return 0;
}