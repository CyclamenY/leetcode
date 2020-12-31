#include <stdlib.h>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
    从宏观来看，这个问题有三种情况：
    1是要找的节点分列于现指向节点的两侧、或者要找的节点之一就是现指向节点，这种情况下该节点即为最近公共祖先
    2是要找的节点均存在于现指向节点的左侧，这种情况下应当向左寻找
    3是要找的节点均存在于现指向节点的右侧，这种情况下应当向右寻找
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //分别表示
        //如果寻找到底
        //如果指向与p相等
        //如果与q相等
        //那就直接返回root
        if(root==NULL || root==p || root==q)
            {return root;}
        //向左寻找节点，依据具体情况返回
        TreeNode *leftNode=lowestCommonAncestor(root->left,p,q);
        //向左寻找节点，依据具体情况返回
        TreeNode *rightNode=lowestCommonAncestor(root->right,p,q);
        //如果左节点返回了一个null，那说明左节点不是我们要找的，答案一定在右节点中
        if(leftNode==NULL)
            {return rightNode;}
        //同理，如果右节点返回了一个null，那说明右节点不是我们要找的，答案一定在左节点中
        if(rightNode==NULL)
            {return leftNode;}
        //如果两个都返回了有效值，那说明当前节点就是我们要找的公共祖先，返回该节点
        return root;
    }
};