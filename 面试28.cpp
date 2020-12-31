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
    bool judge(TreeNode *left,TreeNode *right) {
        if(!left && !right) return true;
        if(!left || !right || left->val!=right->val) return false;
        return judge(left->left,right->right) && judge(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return !root?true:judge(root->left,root->right);
    }
};