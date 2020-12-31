#include <algorithm>
#include <set>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head)
            return head;
        multiset<int> numSet;
        auto p = head;
        while (p)
        {
            numSet.emplace(p->val);
            p = p->next;
        }
        p = head;
        for (auto it = numSet.begin(); it != numSet.end(); ++it)
        {
            p->val = *it;
            p = p->next;
        }
        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(4);
    ListNode *p1 = new ListNode(2);
    ListNode *p2 = new ListNode(1);
    ListNode *p3 = new ListNode(3);
    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    Solution s;
    s.sortList(head);
    return 0;
}