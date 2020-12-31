#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode *pHead = new ListNode(0);
        pHead->next = head;
        auto lastSorted = head;
        auto curr = head->next;
        while (curr)
        {
            if (lastSorted->val <= curr->val)
            {
                lastSorted = lastSorted->next;
            }
            else
            {
                auto prev = pHead;
                while (prev->next->val <= curr->val)
                {
                    prev = prev->next;
                }
                lastSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = lastSorted->next;
        }
        return pHead->next;
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
    s.insertionSortList(head);
    return 0;
}