#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;
        vector<int> numVec;
        for (auto p = head; p; p = p->next)
        {
            numVec.push_back(p->val);
        }
        auto pre = numVec.begin();
        auto last = numVec.end() - 1;
        while (pre < last)
        {
            if (*pre != *last)
                return false;
            ++pre;
            --last;
        }
        return true;
    }
};