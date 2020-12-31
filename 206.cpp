/*链表反转*/

#include <stdlib.h>

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
    ListNode *reverseList(ListNode *head)
    {
        /*      迭代式链表反转*/
        //特殊情况，如果链表内根本没有节点或者只有一个节点，那么根本不需要反转，直接返回即可
        if (!head || !head->next)
            return head;
        //初始化，prev cur temp顺序排列，
        //赋予初值第一第二第三节点（如果第三节点不存在也无所谓，null即可）
        auto prev = head;
        auto cur = head->next;
        auto temp = head->next->next;
        while (cur)
        {
            //将临时变量步进
            temp = cur->next;
            //将当前节点的next指向前一个节点
            cur->next = prev;
            //将prev步进（按原链表顺序），采用直接指向的操作
            prev = cur;
            //将现节点步进（按原链表顺序），采用直接指向的操作
            cur = temp;
        }
        //最后将head的next置空
        head->next = NULL;
        //返回的是prev，并非cur
        return prev;
    }
};