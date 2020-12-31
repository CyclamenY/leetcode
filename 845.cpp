#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestMountain(vector<int> &A)
    {
        auto size = A.size();
        if (!size)
            return 0;
        vector<int> maxBuffer;
        int count = 0;
        for (int i = 1; i < size - 1; ++i)
        {
            if (A[i] > A[i - 1] && A[i] > A[i + 1])
                maxBuffer.push_back(i);
        }
        while (!maxBuffer.empty())
        {
            auto left = *(maxBuffer.rbegin()) - 1;
            auto right = *(maxBuffer.rbegin()) + 1;
            maxBuffer.pop_back();
            while (left != 0 && A[left] > A[left - 1])
            {
                --left;
            }
            while (right != size - 1 && A[right] > A[right + 1])
            {
                ++right;
            }
            count = max(count, right - left + 1);
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {875, 884, 239, 731, 723, 685};
    cout << s.longestMountain(vec);

    return 0;
}