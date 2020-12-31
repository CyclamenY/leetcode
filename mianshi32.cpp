#include <deque>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> levelOrder(TreeNode *root)
    {
        vector<int> returnVec;
        if (!root)
            return returnVec;
        deque<TreeNode *> nodeDeque;
        nodeDeque.push_back(root);
        while (!nodeDeque.empty())
        {
            auto node = nodeDeque.front();
            nodeDeque.pop_front();
            returnVec.push_back(node->val);
            if (node->left)
                nodeDeque.push_back(node->left);
            if (node->right)
                nodeDeque.push_back(node->right);
        }
        return returnVec;
    }
};