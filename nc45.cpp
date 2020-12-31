#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution
{
public:
    /**
     *
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    void frontTraverse(TreeNode *root, vector<int> &vec)
    {
        if (root)
        {
            vec.emplace_back(root->val);
            frontTraverse(root->left, vec);
            frontTraverse(root->right, vec);
        }
    }
    void midTraverse(TreeNode *root, vector<int> &vec)
    {
        if (root)
        {
            midTraverse(root->left, vec);
            vec.emplace_back(root->val);
            midTraverse(root->right, vec);
        }
    }
    void backTraverse(TreeNode *root, vector<int> &vec)
    {
        if (root)
        {
            backTraverse(root->left, vec);
            backTraverse(root->right, vec);
            vec.emplace_back(root->val);
        }
    }
    vector<vector<int>> threeOrders(TreeNode *root)
    {
        vector<vector<int>> returnVec(3, vector<int>(0));
        auto p = root;
        frontTraverse(p, returnVec[0]);
        p = root;
        midTraverse(p, returnVec[1]);
        p = root;
        backTraverse(p, returnVec[2]);
        return returnVec;
    }
};