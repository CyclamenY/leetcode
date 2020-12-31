#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int judge(TreeNode *root) {         //将bool值转化为int类型的-1，以统一返回变量类型
        if(!root) return 0;
        int left=judge(root->left);
        if(left==-1) return -1;         //宣告在左子树上存在某个节点子树不平衡
        int right=judge(root->right);
        if(right==-1) return -1;        //宣告在右子树上存在某个节点子树不平衡
        return abs(left-right)<2?max(left,right)+1:-1;
    }
    bool isBalanced(TreeNode* root) {
        return judge(root)!=-1;
    }
};