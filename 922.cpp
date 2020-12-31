#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        int size = A.size();
        if (!size)
            return {};
        vector<int> oddNum;
        vector<int> evenNum;
        vector<int> errorIndex;
        for (int i; i < size; ++i)
        {
            if (i % 2 && !(A[i] % 2))
            {
                evenNum.emplace_back(A[i]);
                errorIndex.emplace_back(i);
            }
            if (!(i % 2) && A[i] % 2)
            {
                oddNum.emplace_back(A[i]);
                errorIndex.emplace_back(i);
            }
        }
        for (auto it = errorIndex.cbegin(); it != errorIndex.cend(); ++it)
        {
            if ((*it) % 2)
            {
                A[*it] = *(oddNum.cend() - 1);
                oddNum.pop_back();
            }
            else
            {
                A[*it] = *(evenNum.cend() - 1);
                evenNum.pop_back();
            }
        }
        return A;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {4, 2, 5, 7};
    vector<int> A = s.sortArrayByParityII(vec);

    return 0;
}