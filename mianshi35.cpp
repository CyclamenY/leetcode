#include <cstdlib>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution
{
public:
    //利用哈希表关联容器的深拷贝来解答
    Node *copyRandomList(Node *head)
    {
        //边界条件
        if (!head)
        {
            return head;
        }
        unordered_map<Node *, Node *> mp;  //利用哈希表寻找关系
        Node *t = head;  //遍历所使用的临时变量
        while (t)
        {
            mp[t] = new Node(t->val);
            t = t->next;
        }
        t = head;
        while (t)
        {
            if (t->next)
            {
                mp[t]->next = mp[t->next];
            }
            if (t->random)
            {
                mp[t]->random = mp[t->random];
            }
            t = t->next;
        }
        return mp[head];
    }
};