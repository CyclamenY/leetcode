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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        auto pre = head;
        auto last = head->next;
        auto even = head->next;  //常驻指针
        while (pre || last)
        {
            if (pre->next)
            {
                pre->next = last->next;
                if (!pre->next)
                {
                    pre->next = even;
                    break;
                }
                pre = pre->next;
            }
            if (last->next)
            {
                last->next = pre->next;
                last = last->next;
            }
            if (!last)
            {
                pre->next = even;
                break;
            }
        }
        return head;
    }
};