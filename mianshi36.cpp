#include <cstdlib>
#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};
class Solution
{
    Node *pre;  //创建全局变量，用以保存当前节点的前驱
    Node *head;  //创建一个全局变量，用以保存双向链表首

public:
    //根据二叉搜索树的性质，对其使用中序遍历即可得到题中所要的双向链表顺序
    void change2List(Node *cur)
    {
        //特殊情况，空树直接返回
        if (!cur)
            return;
        /*  左   */
        change2List(cur->left);
        //这里作特殊情况，假如当前节点不为第一节点，则将前一节点的下一节点设为当前节点
        /*  根  */
        if (pre)
            pre->right = cur;  //前驱连接
        else
            head = cur;  //如果pre为空，说明当前并不是链表首
        cur->left = pre;  //后驱连接
        pre = cur;
        /*  右  */
        change2List(cur->right);
    }
    Node *treeToDoublyList(Node *root)
    {
        if (!root)
            return nullptr;
        change2List(root);
        head->left = pre;  //首尾连接
        pre->right = head;  //尾首连接
        return head;
    }
};