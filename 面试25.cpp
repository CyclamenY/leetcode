struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        ListNode *l3=new ListNode(0);
        ListNode *p3=l3;
        ListNode *p1=l1;
        ListNode *p2=l2;
        while(p1 && p2) {
            if(p1->val<=p2->val) {
                p3->next=p1;
                p3=p1;
                p1=p1->next;
            }
            else if(p1->val>p2->val) {
                p3->next=p2;
                p3=p2;
                p2=p2->next;
            }
            p1?p3->next=p1:p3->next=p2;
        }
        return l3;
    }
};