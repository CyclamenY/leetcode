#include "stdlib.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head) return NULL;
        ListNode *p=head;
        while(p->next) {
            if(p->val==val) {
                p->val=p->next->val;
                p->next=p->next->next;
                return head;
            }
            if(!p->next->next && p->next->val) {
                p->next=NULL;
                return head;
            }
            p=p->next;
        }
        return head;
    }
};