#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &A)
    {
        int size = A.size();
        if (size < 3)
            return false;
        int cur = 0;
        bool flag = 0;
        if (A[cur] > A[cur + 1])
            return false;
        for (cur = 1; cur < size - 1; ++cur)
        {
            if (A[cur] > A[cur + 1])
                break;
            if (A[cur] == A[cur + 1] || cur == size - 2)
                return false;
        }
        for (; cur < size - 1; ++cur)
        {
            if (A[cur] < A[cur + 1] || A[cur] == A[cur + 1])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    cout << s.validMountainArray(vec);

    return 0;
}