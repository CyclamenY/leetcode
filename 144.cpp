#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};
class Solution
{
    vector<int> returnVec;

public:
    void visit(TreeNode *root, vector<int> &vec)
    {
        if (root)
        {
            vec.emplace_back(root->val);
            visit(root->left, vec);
            visit(root->right, vec);
        }
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        visit(root, returnVec);
        return returnVec;
    }
};